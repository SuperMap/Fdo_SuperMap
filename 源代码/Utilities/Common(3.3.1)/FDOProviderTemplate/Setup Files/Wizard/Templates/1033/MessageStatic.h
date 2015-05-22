/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#define S_FDO[!output UPPER_PREFIX]_1 1

#ifdef [!output UPPER_PREFIX]_MESSAGE_DEFINE
// the default message catalog filename
#ifdef _WIN32
char *fdo[!output LOWER_PREFIX]_cat = "[!output UPPER_PREFIX]Message.dll";
#else
char *fdo[!output LOWER_PREFIX]_cat = "[!output UPPER_PREFIX]Message.cat";
#endif
FdoString* NlsMsgGet(int msg_num, char* default_msg, ...)
{
    va_list varargs;
    va_start(varargs, default_msg);
    FdoString* ret = FdoException::NLSGetMessage(msg_num, default_msg, fdo[!output LOWER_PREFIX]_cat, varargs);
    va_end(varargs);

    return ret;
}
#else // [!output UPPER_PREFIX]_MESSAGE_DEFINE
extern char *fdo[!output LOWER_PREFIX]_cat;
extern FdoString* NlsMsgGet(int msg_num, char* default_msg, ...);
#endif // [!output UPPER_PREFIX]_MESSAGE_DEFINE

