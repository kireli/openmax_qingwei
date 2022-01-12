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

  OpenMAX AL engine implementation - limox session module header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-08-30 MG
*/

/** @addtogroup limoa_backend
 * @{
 */

#ifndef LIMOX_SESSION_H__
#define LIMOX_SESSION_H__

#include <sys/select.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "limipc.h"
#include "limqlist.h"
#include "limthread.h"
#include "limmemory.h"

/** limox session IPC control structure. */
typedef struct
{
    ipc_session_t sid; /** ipc session id */
    int sock_fd; /** ipc socket file descriptor */
    lthread_mutex_t mutex; /** mutex for ipc sock_fd access */
} ox_ipc_t;

/** limox session structure. */
typedef struct
{
#ifdef LIMOX_ENABLED
    list_t list; /** session list used to walk through multi-sessions. */
    ox_ipc_t ipc; /** session ipc handle. */
#endif
    lim_mem_pool_t pool; /** master memory pool created upon session startup. */
    void * player; /** session player handle. */
    void * omix; /** session output mix handle. */
} ox_session_t;

/** initialize limox session control.
 *
 * @param arg
 *        frontend uses this to pass in the engine ipc handle
 *        when linked with backend.
 * @return
 *         0 if successful, non-zero otherwise.
 */
int ox_session_init (void * arg);


/** return limox session list head.
 *
 * @return
 *          session list head.
 */
list_t * ox_session_list_head (void);


/** create new session.
 *
 * @param fd
 *        connection socket file descriptor.
 * @return
 *        0 if successful, non-zero otherwise.
 */
int ox_session_create (int fd);


/** destroy session.
 *
 * @param ox
 *        session session descriptor.
 */
void ox_session_destroy (ox_session_t * ox);


/** send session packet to client.
 *
 * @param ox
 *        session descriptor.
 * @param pkt
 *        IPC packet.
 * @return
 *        number of bytes sent upon successful, 0 or negative value otherwise.
 */
int ox_session_send_packet (ox_session_t * ox, ipc_packet_t * pkt);


/** parse session IPC packet from client.
 *
 * @param ox
 *        session descriptor.
 * @param pkt
 *        IPC packet.
 * @param rsps_pkt
 *        IPC response packet if non-NULL.
 * @return
 *        0 if packet successfully parsed, non-zero error code otherwise.
 */
int ox_session_parse_packet (
    ox_session_t * ox,
    ipc_packet_t * pkt,
    ipc_packet_t * rsps_pkt);

/** @} */
#endif /* LIMOX_SESSION_H__ */
