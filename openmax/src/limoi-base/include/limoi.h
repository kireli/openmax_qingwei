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

  OpenMAX IL base component implementation header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-12-03 MG
*/

/** @defgroup limoi_base_generics limoi base generics
 * @ingroup limoi_base
 */

/** @defgroup limoi_base_component limoi base core
 * @ingroup limoi_base
 * limoi base component root class that all LIM components inherit.
 */

/** @defgroup limoi_base_private limoi base internals
 * @ingroup limoi_base
 * limoi base component class internal implementations.
 */

/** @defgroup limoi_base_audio limoi audio base
 * @ingroup limoi_base
 */

/** @defgroup limoi_base_video limoi video base
 * @ingroup limoi_base
 */

/** @defgroup limoi_base_other limoi other base
 * @ingroup limoi_base
 */

/** @defgroup limoi_base_rm limoi resource manager
 * @ingroup limoi_base
 */

/** @addtogroup limoi_base_generics
 * @{
 */
#ifndef LIMOI_H__
#define LIMOI_H__

#include "limoi-log.h"
#include "limoi-component.h"
#include "limoi-audio.h"
#include "limoi-video.h"
#include "limoi-audio-decoder.h"
#include "limoi-audio-renderer.h"
#include "limoi-video-decoder.h"
#include "limoi-video-renderer.h"
#include "limoi-video-scheduler.h"
#include "limoi-video-src.h"
#include "limoi-video-src01.h"
#include "limoi-video-src03.h"
#include "limoi-video-src02_ir.h"
#include "limoi-video-src02_vis.h"
#include "limoi-video-sink.h"
#include "limoi-video-iva01.h"
#include "limoi-video-iva10.h"
#include "limoi-video-iva11.h"
#include "limoi-video-iva12.h"
#include "limoi-video-iva21.h"
#include "limoi-video-iva10.h"
#include "limoi-video-iva20.h"
#include "limoi-video-iva30.h"
#include "limoi-video-iva22.h"
#include "limoi-video-iva40.h"
#include "limoi-video-split12.h"
#include "limoi-data-split12.h"
#include "limoi-iva40_uvc.h"
#include "limoi-iva50_uvc.h"
#include "limoi-demuxer.h"
#include "limoi-muxer.h"
#include "limoi-audio-encoder.h"
#include "limoi-video-encoder.h"


//#define ENABLE_VERSION_CHECK

#define OMXIL_SPEC_MAJOR     1
#define OMXIL_SPEC_MINOR     1
#define OMXIL_SPEC_REVISION  2
#define OMXIL_SPEC_STEP      0

/** limoi component specification version helper structure.*/
typedef struct
{
    OMX_U32 nSize; /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion; /**< OMX specification version information */
} limoi_spec_version_t;

/** limoi spec version helper macro. */
static inline void limoi_set_spec_version (void * obj, OMX_U32 bytes)
{
    limoi_spec_version_t * sv = (limoi_spec_version_t *)obj;

    sv->nSize = bytes;
    sv->nVersion.s.nVersionMajor = OMXIL_SPEC_MAJOR;
    sv->nVersion.s.nVersionMinor = OMXIL_SPEC_MINOR;
    sv->nVersion.s.nRevision = OMXIL_SPEC_REVISION;
    sv->nVersion.s.nStep = OMXIL_SPEC_STEP;
}

/** limoi spec version check macro. */
static inline int limoi_is_version_compatible(OMX_VERSIONTYPE ver)
{
#ifdef ENABLE_VERSION_CHECK
    //TODO: backward compatible support?
    if (OMXIL_SPEC_MAJOR != ver.s.nVersionMajor
        || OMXIL_SPEC_MINOR != ver.s.nVersionMinor)
    {
        LIMERR("version mismatch, %d.%d.%d.%d : %d.%d.%d.%d\n"
               "\tmaybe you forgot to specify component version?\n",
               OMXIL_SPEC_MAJOR, OMXIL_SPEC_MINOR,
               OMXIL_SPEC_REVISION, OMXIL_SPEC_STEP,
               ver.s.nVersionMajor, ver.s.nVersionMinor,
               ver.s.nRevision, ver.s.nStep);
        return 0;
    }
#endif
    return 1;
}

/** @} */
#endif /* LIMOI_H__ */
