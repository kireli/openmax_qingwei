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

  OpenMAX IL implementation - limoi video renderer component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-02-21 MG
*/

/** @addtogroup limoi_base_video_renderer
 * @{
 */

#ifndef LIMOI_VIDEO_RENDERER_COMPONENT_H__
#define LIMOI_VIDEO_RENDERER_COMPONENT_H__

#include "limoi-component.h"

#define LIMOI_VIDEO_RENDERER_ROLE "iv_renderer.yuv.overlay"

/** limoi video renderer component callbacks. */
typedef struct
{
    /** component private command preparation handle.
     * if not null, this gets called before the renderer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_prep) (limoi_component_cmd_t * cmd);

    /** component private command post process handle.
     * if not null, this gets called after the renderer processes command within
     * the callback context, without holding the command mutex, nor the
     * component and port mutex.
     */
    OMX_ERRORTYPE (*command_post) (limoi_component_cmd_t * cmd);

    /** rendering function. */
    int (*render) (OMX_HANDLETYPE hComp, OMX_BUFFERHEADERTYPE * buf);

} limoi_video_renderer_callbacks_t;

/** opaque limoi video renderer private data structure. */
typedef struct limoi_video_renderer_priv_t limoi_video_renderer_priv_t;

/** limoi video renderer component base class. */
typedef struct
{
    limoi_component_t parent;
    limoi_video_renderer_priv_t * priv; /** opaque private data. */
} limoi_video_renderer_t;

#define LIMOI_VIDEO_RENDERER(c) ((limoi_video_renderer_t *)OMX_COMPONENT(c))

/** limoi video renderer component deinitialization routine.
 * destructs limoi video renderer base component.
 *
 * @param hComp
 *        component handle.
 */
OMX_ERRORTYPE limoi_video_renderer_deinit (
    OMX_HANDLETYPE hComp);

/** limoi asynchronous video renderer component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 */
OMX_ERRORTYPE limoi_video_renderer_init (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version);

/** limoi synchronous video renderer component initialization routine.
 *
 * @param bytes
 *        size of component private data in bytes.
 * @param comp_name
 *        component name assigned by component implementor.
 * @param comp_version
 *        component version string assigned by component implementor.
 *        format: 'maj.minor.revison.step'.
 */
OMX_ERRORTYPE limoi_video_renderer_init_sync (
    OMX_HANDLETYPE * hComp,
	int bytes,
	const char * comp_name,
	const char * comp_version);

/** set limoi video renderer component callbacks.
 *
 * @param callbacks
 *        limoi_component_callbacks_t callbacks.
 * @return
 *        0 on success, -1 on failure.
 */
int limoi_video_renderer_set_callbacks (
    OMX_HANDLETYPE hComp,
    limoi_video_renderer_callbacks_t * callbacks);

/** @} */
#endif /* LIMOI_VIDEO_RENDERER_COMPONENT_H__ */
