// SERVICES_UNMANAGED.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "SERVICES_UNMANAGED.h"

using namespace AL;

int ShowVideoWindow()
{
	if(_robotIp == NULL)
		return 0;

	try
	{
		ALVideoDeviceProxy camProxy(*_robotIp, 9559);
		const std::string clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 30);
		cv::Mat imgHeader = cv::Mat(cv::Size(320, 240), CV_8UC3);
		cv::namedWindow("images");
		_videoEnable = 1;
		while (_videoEnable)
		{
			cv::waitKey(30);
			try
			{
				ALValue img = camProxy.getImageRemote(clientName);
				imgHeader.data = (uchar*) img[6].GetBinary();
				camProxy.releaseImage(clientName);
				cv::imshow("images", imgHeader);
			}
			catch(const AL::ALError&)
			{
				_robotIp = NULL;
				cv::destroyWindow("images");
				_videoEnable = 0;
				return 0;
			}
		}
		_videoEnable = 0;
		camProxy.unsubscribe(clientName);
		cv::destroyWindow("images");
	}
	catch(const AL::ALError&)
	{
		return 0;
	}
	return 1;
}

void HideVideoWindow()
{
	_videoEnable = 0;
}


int TryToConnect(char* robotIp)
{
	std::string sRobotIp(robotIp);

	try
	{
		AL::ALMotionProxy motionProxy(sRobotIp,9559);
		motionProxy.setStiffnesses("Body",1.0f);
	}
	catch(const AL::ALError&)
	{
		return 0;
	}
	_robotIp = (std::string*)malloc(sizeof(sRobotIp));
	memcpy(_robotIp,&sRobotIp,sizeof(sRobotIp));
	return 1;
}


int IsConnected()
{
	if(_robotIp == NULL)
		return 0;
	return 1;
}

int IsVideoEnable()
{
	if(_videoEnable)
		return 1;
	return 0;
}

void Disconnect()
{
	if(_robotIp == NULL)
		return;
	try
	{
		AL::ALMotionProxy motionProxy(*_robotIp,9559);
		motionProxy.setStiffnesses("Body",0.0f);
		_robotIp = NULL;
	}
	catch(const AL::ALError&)
	{

	}
}

void SetPosture(char* postureName)
{
	if(_robotIp == NULL)
		return;

	std::string sPostureName(postureName);
	AL::ALRobotPostureProxy posture(*_robotIp,9559);
	posture.goToPosture(postureName,1.0f);

}


void MoveToWard(float x,float y,float angle)
{
	if(_robotIp == NULL)
		return;

	AL::ALMotionProxy motionProxy(*_robotIp,9559);
	motionProxy.moveToward(x,y,angle);
}


void StopMove()
{
	if(_robotIp == NULL)
	return;

	AL::ALMotionProxy motionProxy(*_robotIp,9559);
	motionProxy.stopMove();
}
