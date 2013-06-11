#include "stdafx.h"
#include "SERVICES_UNMANAGED.h"

#include <signal.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alcommon/almodule.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/allandmarkdetectionproxy.h>
#include <boost/thread/thread.hpp>

#include <qi/log.hpp>
#include <alproxies/almemoryproxy.h>
#include <alproxies/almotionproxy.h>
#include <windows.h>


namespace AL
{
  class ALBroker;
}

class NaoMarkServiceDetection : public AL::ALModule
{
  public:

    NaoMarkServiceDetection(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

    virtual ~NaoMarkServiceDetection();

    virtual void init();

    void callback(const std::string &key, const AL::ALValue &value, const AL::ALValue &msg);

	void backGroundService();

	void FindMarkArround();

	void TurnToDetectedMark(float angle);

	void MoveHead(float angle);

	void findMark(int markId);

	bool _isMarkFound;


  private:

    AL::ALMemoryProxy fMemoryProxy;

	AL::ALMotionProxy *motionProxy;


	bool _naoMarkDetected;

	bool _isAllowedToMove;

	boost::thread* _pBackGroundThread;

	bool _isThreadRuning;

	int _markToFind;
};




void threadEntry(NaoMarkServiceDetection* pEvent)
{
	pEvent->backGroundService();
}

void NaoMarkServiceDetection::backGroundService()
{ 
	_isThreadRuning = true;
	while(_isThreadRuning)
	{
		_naoMarkDetected = false;
		Sleep((DWORD)1000);
		if(!_naoMarkDetected && _markToFind != -1 && !_isMarkFound)
		{
			motionProxy->moveToward(0,0,0);
			FindMarkArround();
		}
	}
}


NaoMarkServiceDetection::NaoMarkServiceDetection(
  boost::shared_ptr<AL::ALBroker> broker,
  const std::string& name):
      AL::ALModule(broker, name),
      fMemoryProxy(getParentBroker())
{
	setModuleDescription("");
	_naoMarkDetected = false;
	_isAllowedToMove = true;
	_isThreadRuning = false;
	_isMarkFound = false;
	_markToFind = -1;

	motionProxy = new AL::ALMotionProxy(*_robotIp,9559);
	functionName("callback", getName(), "");
	BIND_METHOD(NaoMarkServiceDetection::callback)

	_pBackGroundThread = new boost::thread(threadEntry,this);
  
	//_pBackGroundThread->join();
	//boost::thread::join
}


void NaoMarkServiceDetection::FindMarkArround()
{
	_isAllowedToMove = false;
	MoveHead(-0.7f);
	Sleep((DWORD)50);
	if(_naoMarkDetected)
	{
		TurnToDetectedMark(-0.7f);
		return;
	}

	MoveHead(-1.5f);
	Sleep((DWORD)50);
	if(_naoMarkDetected)
	{
		TurnToDetectedMark(-1.5f);
		return;
	}


	MoveHead(0.7f);
	Sleep((DWORD)50);
	if(_naoMarkDetected)
	{
		TurnToDetectedMark(0.7f);
		return;
	}

	MoveHead(1.5f);
	Sleep((DWORD)50);
	if(_naoMarkDetected)
	{
		TurnToDetectedMark(1.5f);
		return;
	}


	MoveHead(0);
	_isAllowedToMove = true;
	Sleep((DWORD)100);
}

void NaoMarkServiceDetection::TurnToDetectedMark(float angle)
{
	motionProxy->moveTo(0,0,angle);
	MoveHead(0);
	_isAllowedToMove = true;
}


void NaoMarkServiceDetection::MoveHead(float angle)
{
	motionProxy->angleInterpolation("HeadYaw", AL::ALValue(angle), AL::ALValue(1.0f), true);
	motionProxy->stiffnessInterpolation("HeadYaw", 1.0f, 1.0f);
}



NaoMarkServiceDetection::~NaoMarkServiceDetection() {
  fMemoryProxy.unsubscribeToEvent("LandmarkDetected", "Events");
  delete motionProxy;
}

void NaoMarkServiceDetection::init() {
  try 
  {
    fMemoryProxy.subscribeToEvent("LandmarkDetected", "Events", "userDataToIdentifyEvent", "callback");
  }
  catch (const AL::ALError& e) {
    qiLogError("module.example") << e.what() << std::endl;
  }

}


void NaoMarkServiceDetection::findMark(int markId)
{
	_markToFind = markId;
	_isMarkFound = false;

}


void NaoMarkServiceDetection::callback(const std::string &key, const AL::ALValue &value, const AL::ALValue &msg) 
{
	AL::ALValue marks = fMemoryProxy.getData("LandmarkDetected");

	if(marks.getSize() > 0 && !_isMarkFound)
	{
		int TimeStampField = marks[0][1];
		if((int)marks[1][0][1][0] == _markToFind)
		{
			if((float)marks[1][0][0][3] < 0.2f)
			{
				if(_isAllowedToMove)
					motionProxy->moveToward(0.5f,0,marks[1][0][0][1]);
				_naoMarkDetected = true;
			}
			else
			{
				motionProxy->moveToward(0,0,0);
				_isMarkFound = true;
			}
		}
		else
			motionProxy->moveToward(0,0,0);
	}
}

NaoMarkServiceDetection* naoMarkServiceDetection = NULL;

extern "C"
{
	int _createModule(boost::shared_ptr<AL::ALBroker> pBroker)
	{
		AL::ALBrokerManager::setInstance(pBroker->fBrokerManager.lock());
		AL::ALBrokerManager::getInstance()->addBroker(pBroker);
		naoMarkServiceDetection = (AL::ALModule::createModule<NaoMarkServiceDetection>( pBroker, "Events" )).get();

		return 0;
	}
}

void SetMarkToFind(int markId)
{
	if(naoMarkServiceDetection == NULL)
		return;
	naoMarkServiceDetection->findMark(markId);
}

int IsMarkFounded()
{
	if(naoMarkServiceDetection->_isMarkFound)
		return 1;
	return 0;
}


void EnableNaoMarkServiceDetection()
{
	if(naoMarkServiceDetection != NULL)
		return;

	TMainType sig;
    sig = &_createModule;

	char tachar[50];
	memset(tachar,0,sizeof(char)*50);
	for(unsigned int i = 0;i<_robotIp->length();i++)
		tachar[i] = (*_robotIp)[i];
	char** pChars = new char*[6];


	pChars[0] = "--pid";
	pChars[1] = "pBroker";
	pChars[2] = "--broker-ip";
	pChars[3] = "0";
	pChars[4] = "--pip";
	pChars[5] = tachar;

    ALTools::mainFunction("events", 6, pChars, sig);
}



