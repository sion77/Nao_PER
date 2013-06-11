using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace NAO_PER
{
    static class NaoHandler
    {
        [DllImport("SERVICES_UNMANAGED", EntryPoint = "ShowVideoWindow")]
        public static extern Int32 ShowVideoWindow();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "MoveToWard", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoveToWard(System.Single x, System.Single y, System.Single angle);

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "TryToConnect", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern Int32 TryToConnect(sbyte* ip);

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "IsConnected", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern Int32 IsConnected();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "StopMove", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void StopMove();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "SetPosture", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void SetPosture(sbyte* ip);

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "Disconnect", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void Disconnect();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "IsVideoEnable", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern Int32 IsVideoEnable();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "HideVideoWindow", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void HideVideoWindow();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "Annimation_TaiChiDance", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void Annimation_TaiChiDance();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "Annimation_WaveHand", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void Annimation_WaveHand();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "Annimation_Wipe", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void Annimation_Wipe();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "EnableBumperDetection", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void EnableBumperDetection();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "IsBumperPressed", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern Int32 IsBumperPressed();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "SetMarkToFind", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void SetMarkToFind(int markId);

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "IsMarkFounded", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern Int32 IsMarkFounded();

        [DllImport("SERVICES_UNMANAGED", EntryPoint = "EnableNaoMarkServiceDetection", CallingConvention = CallingConvention.Cdecl)]
        public static unsafe extern void EnableNaoMarkServiceDetection();
    }
}
