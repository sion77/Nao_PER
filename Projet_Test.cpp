/**
* Copyright (c) 2011 Aldebaran Robotics. All Rights Reserved
*
* \file movehead.cpp
* \brief Move NAO's head.
*
* A simple example showing how to move NAO's head by using ALMotionProxy.
* This example will make NAO turn its head left and right slowly.
* We use here a specialized proxy to ALMotion.
*/
#include "stdafx.h"
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>

using namespace std;
using namespace AL;

int main(int argc, char* argv[]) {
  // The Robot IP to connect
  string _robotIp("192.168.63.19");

  /** The name of the joints to be moved. */
  const ALValue robotNeck = "HeadYaw";

  /** Target stiffness to Activate motion */
  ALValue stiffnessActivate = 1.0f;

  /** Target stiffness to Disactivate motion */
  ALValue stiffnessDisactivate = 0.0f;

  /** Time (in seconds) to reach the target for motion */
  ALValue timeMotion = 1.0f;
  

  try {
    // Create ALMotionProxy for Nao movements methods calls
	  // --> Ip + port
    ALMotionProxy motion(_robotIp, 9559);

	// Create ALPostureProxy for Nao posture change methods calls
	  // --> Ip + port
	ALRobotPostureProxy posture(_robotIp,9559);

	// Make some display (for help)
	cout << "Position : " << motion.getPosition("RArm", 2, true) << endl;
	cout << "Postures : " << posture.getPostureList() << endl;
	cout << "Joints : " << motion.getJointNames("Arms") << endl;    
    
    /** Make the robot neck able to move like we want to (unlocking joint) */
    motion.stiffnessInterpolation(robotNeck, stiffnessActivate, timeMotion);

    /** Set the target angle list, in radians. */
    ALValue targetAngles = ALValue::array(-1.5f, 1.5f, 0.0f);
    /** Set the corresponding time lists, in seconds. */
    ALValue targetTimes = ALValue::array(3.0f, 6.0f, 9.0f);
    /** Specify that the desired angles are absolute. */
    bool isAbsolute = true;

    // We launch the animation with
    motion.angleInterpolation(robotNeck, targetAngles, targetTimes, isAbsolute);

    /** We need to lock joint again after the motion (it's a security) */
    motion.stiffnessInterpolation(robotNeck, stiffnessDisactivate, timeMotion);

	// The robot stand up (test)
	posture.goToPosture("Stand",1.0f);

	// The robot disactivate the hand collision protection (because he can't catch an object if his hand open each time there is an obstacle)
	motion.setCollisionProtectionEnabled("RArm", true);

	// The robot open and close his hand (test)
	motion.openHand("RHand");
	motion.closeHand("RHand");

	// The robot crouch (test)
	posture.goToPosture("Crouch", 1.0f);
	//motion.setTransform("RArm",

	// Pause to see the console content
	system("pause");

  }
  catch (const AL::ALError& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    exit(1);
  }
  exit(0);
}