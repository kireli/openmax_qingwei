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

  OpenMAX AL ENGINE - engine front end header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-08-22 MG
*/

/** @addtogroup limoa_frontend
 * @{
 */

#ifndef ENGINE_FE_H__
#define ENGINE_FE_H__

#include "OpenMAXAL.h"
#include "limipc.h"
#include "limqlist.h"

#define OBJ_STATE_UNREALIZED 0
#define OBJ_STATE_REALIZED   1
#define OBJ_STATE_SUSPENDED  2

struct engine_t;

typedef struct
{
    // ipc support internals
    int destroy; // flag to coordinate the shutdown of the ipc thread.
    lthread_mutex_t mutex; // mutex for ipc sock_fd access
    lthread_cond_t cond; // ipc conditional
    lthread_t cb_thread; // ipc callback thread
    ipc_session_t sid; // ipc session id
    limq_handle_t pkt_q; // ipc packet queue id
    int sock_fd; // ipc socket file descriptor
    int sock_read_completed; // flag to denote that sock_fd has nothing left
                             // to be read. Read has been done by the message-
                             // response sequence.
} engine_ipc_t;

typedef struct
{
    struct XAEngineItf_ itf;
    struct engine_t * engine;
} engine_itf_t;

typedef struct engine_t
{
    // implicit interfaces
    struct XAObjectItf_ * obj_itf;
    struct XAEngineItf_ * engine_itf;

    // mandated interfaces

    // optional interfaces

    // engine object private fields
    int objstate;
    engine_ipc_t ipc;

    struct XAObjectItf_ objItf;
    engine_itf_t engineItf;
} engine_t;

XAuint32 engine_query_num_supported_interfaces (void);
XAresult engine_query_interface_id (XAuint32 index, XAInterfaceID * pInterfaceId);
XAresult engine_obj_create (
    XAObjectItf * pEngine,
    XAuint32 numOptions,
    const XAEngineOption * pEngineOptions,
    XAuint32 numInterfaces,
    const XAInterfaceID * pInterfaceIds,
    const XAboolean * pInterfaceRequired);

int engine_ipc_init (engine_t * engine);
int engine_ipc_destroy (engine_t * engine);

/** send IPC packet to limox server.
 * if response is non-NULL, it is caller's responsiblity to release
 * the response packet by calling @ref ipc_release_packet()
 *
 * @param engine
 *        engine handle.
 * @param rqst
 *        request packet.
 * @param rsps
 *        response packet if any is expected, can be NULL.
 *        if response packet is non-null, @ipc_release_packet must
 *        be called on received response.
 * @return
 *        0 if successful, non-zero otherwise.
 */
int engine_ipc_send_packet (
    engine_t * engine,
    ipc_packet_t * rqst,
    ipc_packet_t * rsps);

/** ping to limox engine.
 *
 * @param engine
 *        engine handle.
 * @return
 *        0 if successful, non-zero otherwise.
 */
int engine_ipc_ping (engine_t * engine);

void engine_interface_init (engine_t * engine);

/** parse callback packet from limox.
 *
 * @param packet.
 *        callback packet from limox.
 */
void engine_callback_parser (ipc_packet_t * packet);

/** @} */
#endif /* ENGINE_FE_H__ */
