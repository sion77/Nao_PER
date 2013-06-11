using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NAO_PER
{
    class CsharpToCppTypeConverter
    {
        public unsafe static sbyte* ToSbytePointer(string s)
        {
            byte[] bytes = Encoding.ASCII.GetBytes(s);
            fixed (byte* p = bytes)
            {
                return (sbyte*)p;
            }
        }
    }
}
