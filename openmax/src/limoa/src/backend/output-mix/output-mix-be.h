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

  OpenMAX AL ENGINE - output mix back end header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-17 MG
*/

/** @addtogroup limoa_backend
 * @{
 */

#ifndef OUTPUTMIX_BE_H__
#define OUTPUTMIX_BE_H__

#include "OpenMAXAL.h"
#include "limipc.h"
#include "limqlist.h"
#include "limmemory.h"
#include "ox-session.h"
#include "common-be.h"

typedef struct
{
    // session reference
    ox_session_t * ox;

    // output mix omx handles
    OMX_HANDLETYPE sink_handle;
    OMX_HANDLETYPE mixer_handle;

    // output mix private fields.
    list_t cb_list_head;
    lthread_mutex_t cb_mutex;

    lthread_mutex_t mutex;
    lthread_cond_t cond;
} ox_omix_t;

typedef struct
{
    OMX_CALLBACKTYPE cb;
    OMX_PTR priv_data;
} ox_omix_cb_t;

int omix_parse_packet (
    ox_session_t * ox,
    ipc_packet_t * rqst,
    ipc_packet_t * rsps);

/** create backend output mix object.
 *
 * @param omix
 *        output mix object pointer.
 * @return
 *        OpenMAXAL object realize error code.
 */
XAresult ox_omix_realize (ox_omix_t * omix);


/** destroy backend output mix object.
 *
 * @param omix
 *        output mix object pointer.
 * @return
 *        0 if successful, non-zero otherwise.
 */
int ox_omix_destroy (ox_omix_t * omix);


/** register output mix callbacks.
 *
 * @param omix
 *        output mix object pointer.
 * @param omix_cb
 *        output mix callback.
 * @return
 *        0 if successful, non-zero otherwise.
 */
int ox_omix_register_callback (
    ox_omix_t * omix,
    ox_omix_cb_t * omix_cb);


/** unregister output mix callbacks.
 *
 * @param omix
 *        output mix object pointer.
 * @param omix_cb
 *        output mix callback.
 * @return
 *        0 if successful, non-zero otherwise.
 */
int ox_omix_unregister_callback (
    ox_omix_t * omix,
    ox_omix_cb_t * omix_cb);

/** @} */
#endif /* OUTPUTMIX_BE_H__ */
