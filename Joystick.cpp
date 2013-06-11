#include "stdafx.h"
#include "SERVICES_UNMANAGED.h"
#include <SDL.h>




int EnableJoystick = 1;
int Pause = 0;
JoystickAction SjoystickAction;
InfoJoystick infoJoystick;


int GetLastAxesMoved()
{
	int axeValue = 0;
	SDL_Event event;
	while(EnableJoystick)
	{
		SDL_WaitEvent(&event);

		if(event.jaxis.value > 6600 || event.jaxis.value < -6600)
			return event.jaxis.axis;
	}
	return -1;
}


InfoJoystick GetGoystickInformation()
{
	return infoJoystick;
}

void SuspendRobotMovement()
{
	Pause = 1;
}

void ResumeRobotMovement()
{
	Pause = 0;
}


void SetJoyStickAction(JoystickAction pJoystickAction)
{
	SjoystickAction = pJoystickAction;
}


int EnableJoystickControl(JoystickAction* pJoystickAction)
{
	if(pJoystickAction != NULL)
		SjoystickAction = *pJoystickAction;
	else
	{
		SjoystickAction.idAxe_MoveTowardBackWard = 1;
		SjoystickAction.idAxe_MoveLeftRight = 0;
		SjoystickAction.idAxe_Turn = 3;
	}


	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK);
	EnableJoystick = 1;
	
	AxeValue axesValues;
	memset(&infoJoystick,0,sizeof(infoJoystick));
	memset(&axesValues,0,sizeof(axesValues));
	SDL_Joystick* pJoystick = NULL; 


	if(SDL_NumJoysticks() < 1)
		return 0;
	
	pJoystick = SDL_JoystickOpen(0);
	infoJoystick.nbAxes = SDL_JoystickNumAxes(pJoystick);
    infoJoystick.nbButton = SDL_JoystickNumButtons(pJoystick);
	SDL_Event event;

	while(EnableJoystick)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_JOYAXISMOTION:
			if(event.jaxis.axis == SjoystickAction.idAxe_MoveTowardBackWard)
				axesValues.x = -((float)event.jaxis.value / 33000.f);
			if(event.jaxis.axis == SjoystickAction.idAxe_MoveLeftRight)
				axesValues.y = -((float)event.jaxis.value / 33000.f);
			if(event.jaxis.axis == SjoystickAction.idAxe_Turn)
				axesValues.z = -((float)event.jaxis.value / 33000.f);

			if(axesValues.x < 0.2f && axesValues.x > -0.2f)
				axesValues.x = 0;
			if(axesValues.y < 0.2f && axesValues.y > -0.2f)
				axesValues.y = 0;
			if(axesValues.z < 0.2f && axesValues.z > -0.2f)
				axesValues.z = 0;

			if(Pause == 0)
				MoveToWard(axesValues.x,axesValues.y,axesValues.z);
			break;
			case SDL_JOYBUTTONDOWN:



			break;
		}
	}
	return 1;
}



void DisableJoystick()
{
	EnableJoystick = 0;
}