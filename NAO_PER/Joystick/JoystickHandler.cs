using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace NAO_PER.Joystick
{

    public struct JoystickAction
    {
        public Int32 idAxe_MoveTowardBackWard;
        public Int32 idAxe_MoveLeftRight;
        public Int32 idAxe_Turn;
    }


    public struct InfoJoystick
    {
        public UInt32 nbButton;
        public UInt32 nbAxes;
    }


    public static class JoystickHandler
    {
        [DllImport("SERVICES_UNMANAGED", EntryPoint = "EnableJoystickControl", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern Int32 EnableJoystickControl(JoystickAction* pJoystickAction);

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "DisableJoystick", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void DisableJoystick();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "GetLastAxesMoved", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern Int32 GetLastAxesMoved();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "GetGoystickInformation", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern InfoJoystick GetGoystickInformation();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "SuspendRobotMovement", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void SuspendRobotMovement();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "ResumeRobotMovement", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void ResumeRobotMovement();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "SetJoyStickAction", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void SetJoyStickAction(JoystickAction pJoystickAction);

        
    }
}
