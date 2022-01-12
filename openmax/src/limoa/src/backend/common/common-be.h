/*
  Copyright (C) 2009 - 2011 SWOAG Technology <www.swoag.com>

  This library is free software; you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation; either version 2.1 of the License, or (at your option)
  any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
  details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St, Fifth Floor, Boston, MA
  02110-1301  USA

  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  LIMOX COMMON - backend common sub module header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-19 MG
*/

/** @addtogroup limoa_backend
 * @{
 */

#ifndef COMMON_BE_H__
#define COMMON_BE_H__

#include "limdeepcopy.h"
#include <OMX_Core.h>
#include <OMX_Audio.h>
#include <OMX_Types.h>
#include <OMX_Component.h>

/** this dictates the engine OMXIL component version requirement. */
#define OMXIL_SPEC_MAJOR     1
#define OMXIL_SPEC_MINOR     1
#define OMXIL_SPEC_REVISION  2
#define OMXIL_SPEC_STEP      0

/** OMXIL specification version helper structure.*/
typedef struct
{
    OMX_U32 nSize; /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion; /**< OMX specification version information */
} omxil_spec_version_t;

/** omxil spec version helper macro. */
static inline void omxil_set_spec_version (void * obj, OMX_U32 bytes)
{
    omxil_spec_version_t * sv = (omxil_spec_version_t *)obj;

    sv->nSize = bytes;
    sv->nVersion.s.nVersionMajor = OMXIL_SPEC_MAJOR;
    sv->nVersion.s.nVersionMinor = OMXIL_SPEC_MINOR;
    sv->nVersion.s.nRevision = OMXIL_SPEC_REVISION;
    sv->nVersion.s.nStep = OMXIL_SPEC_STEP;
}


#define deep_cp_data_sink(d, s, p, o) deep_copy_data_sink(d, s, p, o)
#define deep_cp_data_source(d, s, p, o) deep_copy_data_source(d, s, p, o)

const char * omxil_state_name (int state);

/** @} */
#endif /* COMMON_BE_H__ */
