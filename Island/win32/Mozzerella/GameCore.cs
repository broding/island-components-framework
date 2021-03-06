﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace Mozzerella
{
    class GameCore
    {
        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int OpenWindow();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int CloseWindow();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int Update();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int ChangeTool(int tool);

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static uint GetSelectedEntityId();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr GetSelectedEntityXML();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr GetSceneXML();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr GetComponentXML();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static void SendEntityXML(StringBuilder xml, int size);

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr ClearScene();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static void SendSceneXML(StringBuilder xml, int size);

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr AddEntity();

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr AddComponent(int type);

        [DllImport("Island.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static void SetSelectedEntity(int id);
    }
}
