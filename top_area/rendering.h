/*===============================================================*/
/*                                                               */
/*                       rendering_sw.h                          */
/*                                                               */
/*              Software version for 3D Rendering                */
/*                                                               */
/*===============================================================*/

#ifndef __RENDERING_H__
#define __RENDERING_H__

#include "../host/typedefs.h"

extern "C" void rendering( bit32 input[3*NUM_3D_TRI], bit32 output[NUM_FB]);

#endif

