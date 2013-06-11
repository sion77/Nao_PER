#include "stdafx.h"
#include "SERVICES_UNMANAGED.h"

#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <alproxies/almemoryproxy.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>
#include <qi/log.hpp>


float fBumperState = 0;
char* modulName = "Event_Bumper";



class BumperEvent : public AL::ALModule
{
  public:

    BumperEvent(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

    virtual ~BumperEvent();

    
    //Will be called at module startup. Declares example event and subscribes toit.
    virtual void init();

    //Callback function every time the example event is called.
    void callbackOnBumperPressed();

  private:

    AL::ALMemoryProxy fMemoryProxy;
};



BumperEvent::BumperEvent(boost::shared_ptr<AL::ALBroker> broker,const std::string& name):
      AL::ALModule(broker, name),fMemoryProxy(getParentBroker())
{
  setModuleDescription("This module get right bumperEvent");

  fBumperState = fMemoryProxy.getData("RightBumperPressed");

  functionName("callbackOnBumperPressed", getName(), "Description of the action");

  BIND_METHOD(BumperEvent::callbackOnBumperPressed)
}

BumperEvent::~BumperEvent() 
{
  fMemoryProxy.unsubscribeToEvent("callbackOnBumperPressed", "Bumper");
}

void BumperEvent::init() 
{
  try 
  {
	fMemoryProxy = AL::ALMemoryProxy(getParentBroker());
	fMemoryProxy.subscribeToEvent("RightBumperPressed",modulName,"callbackOnBumperPressed");
  }
  catch (const AL::ALError& e)
  {
    qiLogError("module.example") << e.what() << std::endl;
  }

}


void BumperEvent::callbackOnBumperPressed() 
{
	fBumperState =  fMemoryProxy.getData("RightBumperPressed");
}




int _createModule(boost::shared_ptr<AL::ALBroker> pBroker)
{
	AL::ALBrokerManager::setInstance(pBroker->fBrokerManager.lock());
	AL::ALBrokerManager::getInstance()->addBroker(pBroker);
	AL::ALModule::createModule<BumperEvent>( pBroker, modulName );
	  
	return 0;
}


int IsBumperPressed()
{
	if(fBumperState > 0.5f)
		return 1;
	return 0;
}


void EnableBumperDetection()
{
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


    ALTools::mainFunction(modulName, 6, pChars, sig);
}