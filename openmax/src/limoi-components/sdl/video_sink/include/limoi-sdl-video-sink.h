/*
  Copyright (C) 2010 - 2012 SWOAG Technology <www.swoag.com>

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

  OpenMAX IL implementation - SDL video sink component header.

  REVISION:

    1) initial creation. ----------------------------------------- 2010-02-22 MG
*/

/** @defgroup limoi_component_sdl_vsink limoi sdl video sink component
 * @ingroup limoi_components
 * @{
 */

#ifndef LIMOI_SDL_VIDEO_SINK_H__
#define LIMOI_SDL_VIDEO_SINK_H__

#include "config.h"
#include "limoi.h"
#include <SDL/SDL.h>

/** SDL event thread state. */
typedef enum
{
    SE_INVALID,
    SE_IDLE,
    SE_STOP,
} sdl_video_renderer_event_state_t;

/** SDL video sink component private data structure. */
typedef struct
{
    limoi_video_renderer_t video_renderer; /** inherit limoi video renderer. */
    SDL_Surface * screen;
    SDL_Overlay * yuv;
    int pic_w; /** picture width in pixels. */
    int pic_h; /** picture height in pixels. */
    int disp_w; /** picture display width in pixels. */
    int disp_h; /** picture display height in pixels. */
    int full_screen_w; /** full screen width in pixels. */
    int full_screen_h; /** full screen height in pixels. */
    int prev_disp_w; /** saved picture display width in pixels. */
    int prev_disp_h; /** saved picture display height in pixels. */
    OMX_COLOR_FORMATTYPE color_format;

    lthread_mutex_t mutex;
    lthread_cond_t cond;
    lthread_t event_thread; /** SDL event thread. */
    int event_state; /** SDL event thread state. */
} sdl_video_renderer_private_t;

#define LIMOI_SDL_VIDEO_RENDERER(c) \
    ((sdl_video_renderer_private_t *)OMX_COMPONENT(c))

/** @} */
#endif /* LIMOI_SDL_VIDEO_SINK_H__ */
