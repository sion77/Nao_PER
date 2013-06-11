#ifndef SERVICES_H
#define SERVICES_H 


#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>
#include <alproxies/albatteryproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/almotionproxy.h>


// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//global variables
extern std::string* _robotIp;
extern bool _videoEnable;


#include "joystick.h"


//Prototypes
extern "C"
{
	__declspec(dllexport) int ShowVideoWindow();
	__declspec(dllexport) void MoveToWard(float x,float y,float angle);
	__declspec(dllexport) void HideVideoWindow();
	__declspec(dllexport) int IsConnected();
	__declspec(dllexport) int IsVideoEnable();
	__declspec(dllexport) void Disconnect();
	__declspec(dllexport) void SetPosture(char* postureName);
	__declspec(dllexport) void StopMove();
	__declspec(dllexport) int TryToConnect(char* robotIp);
	__declspec(dllexport) void Annimation_TaiChiDance();
	__declspec(dllexport) void Annimation_WaveHand();
	__declspec(dllexport) void Annimation_Wipe();
	__declspec(dllexport) void EnableBumperDetection();
	__declspec(dllexport) int IsBumperPressed();
	__declspec(dllexport) int EnableJoystickControl(JoystickAction* pJoystickAction);
	__declspec(dllexport) int GetLastAxesMoved();
	__declspec(dllexport) InfoJoystick GetGoystickInformation();
	__declspec(dllexport) void DisableJoystick();
	__declspec(dllexport) void SuspendRobotMovement();
	__declspec(dllexport) void ResumeRobotMovement();
	__declspec(dllexport) void SetJoyStickAction(JoystickAction pJoystickAction);
}


#endif SERVICES_H