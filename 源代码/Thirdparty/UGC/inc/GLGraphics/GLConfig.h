#ifndef GLCONFIG_H
#define GLCONFIG_H

#ifdef _WIN32 //win32

#   include <windows.h>
#   include <wingdi.h>
#   include <GL/gl.h>
#   define GL_GLEXT_PROTOTYPES
#   include "glprocs.h"
#   include <GL/glu.h>
// Windows library does not include glSecondaryColorPointer even though it's standard now
#   define glSecondaryColorPointer glSecondaryColorPointerEXT

#else  //none win32

// define GL_GLEXT_LEGACY so that Mesa headers won't try to include their own
// glext.h file.
#   define GL_GLEXT_LEGACY
#   include <GL/gl.h>
#   include <GL/glu.h>
#   define GL_GLEXT_PROTOTYPES
#elif OGRE_PLATFORM == PLATFORM_APPLE
#   define GL_GLEXT_PROTOTYPES
#   ifndef APIENTRY
#       define APIENTRY
#   endif
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>

#endif 

#  include "glext.h"

#endif