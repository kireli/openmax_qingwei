/*
  Copyright (C) 2010 - 2011 SWOAG Technology <www.swoag.com>

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

  OpenMAX IL implementation - limoi container muxer component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-05-14 MG
*/

/** @defgroup limoi_base_other_muxer limoi muxer base
 * @ingroup limoi_base_other
 * @{
 */

#ifndef LIMOI_MUXER_COMPONENT_H__
#define LIMOI_MUXER_COMPONENT_H__

#include "limoi-component.h"

/** limoi muxer component callbacks. */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the muxer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the muxer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** muxing function.
     * @return
     *        0: OK
     *       -1: unrecoverable error.
     */
    int (*mux) (OMX_HANDLETYPE hComp,
                CP_PIPETYPE * pipe,
                CPhandle content,
                OMX_BUFFERHEADERTYPE * audio_in,
                OMX_BUFFERHEADERTYPE * video_in);
} limoi_muxer_callbacks_t;

/** opaque limoi content muxer private data structure. */
typedef struct limoi_muxer_priv_t limoi_muxer_priv_t;

/** limoi content muxer component base class. */
typedef struct
{
    limoi_component_t parent;
    limoi_muxer_priv_t * priv; /** opaque private data. */
} limoi_muxer_t;

#define LIMOI_MUXER(c) ((limoi_muxer_t *)OMX_COMPONENT(c))


/** limoi muxer component deinitialization routine.
 * destructs limoi muxer base component.
 *
 * @param hComp
 *        component handle.
 */
OMX_ERRORTYPE limoi_muxer_deinit (OMX_HANDLETYPE hComp);


/** limoi muxer component initialization routine.
 * muxer component will internally query to use OMX_IndexParamContentURI
 * parameter as its output URI.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 */
OMX_ERRORTYPE limoi_muxer_init (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version);


/** set limoi muxer component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_muxer_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_muxer_callbacks_t * callbacks);

/** @} */
#endif /* LIMOI_MUXER_COMPONENT_H__ */
