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

  OpenMAX AL engine implementation - ipc support module header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-08-19 MG
*/

/** @addtogroup limoa_generics
 * @{
 */

#ifndef LIMIPC_H__
#define LIMIPC_H__

#include <sys/select.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <stdint.h>
#include <inttypes.h>
#include "limipc-id.h"

#define LIMOX_SOCKET_PATH "/var/tmp/limox"
#define LIMOA_SOCKET_PATH "/var/tmp/limoa"

#define BUF_BYTES(b, t) ((((b) + sizeof(t) - 1) / sizeof(t)) * sizeof(t))
#define PTR_PADDING(b) BUF_BYTES(b, void *)

#define DEFAULT_IPC_PACKET_POOL_BYTES (1024 * 16)

#define LIMOA_IPC_REQUEST_TO_SERVER  0
#define LIMOA_IPC_RESPONSE_TO_CLIENT 1
#define LIMOA_IPC_CALLBACK_TO_CLIENT 2
#define LIMOA_IPC_RESPONSE_TO_SERVER 3

/** packet ID structure definition. */
typedef struct
{
    unsigned int reserved1 : 6;
    unsigned int direction : 2;
    unsigned int value : 24;
} ipc_packet_id_t;

/** IPC packet header structure definition. */
typedef struct
{
    uint32_t bytes; /** packet data bytes excluding header */
    ipc_packet_id_t id; /** packet ID */
} ipc_packet_header_t;

/** IPC packet structure definition. */
typedef struct
{
    ipc_packet_header_t header;
    void * dptr; /** data pointer */
} ipc_packet_t;

typedef void * ipc_session_t;

/** generic limox IPC acknowledgement response. */
typedef struct
{
    XAresult result; /** acknowledgement result. */
} ipc_standard_rsps_t;


/** macro to initialize IPC request packet.
 * @param rqst
 *        request packet.
 * @param id_val
 *        request ID valude.
 * @param bytes
 *        request data size in bytes.
 * @param dptr
 *        request data pointer.
 */
#define ipc_init_request(rqst, id_val, dat_bytes, dat) do { \
        (rqst)->header.id.value = id_val;                   \
        (rqst)->header.bytes = dat_bytes;                   \
        (rqst)->dptr = dat; } while(0)


/** macro to initialize IPC response packet. */
static inline void * ipc_init_response (
    ipc_packet_t * rsps, int bytes)
{
    rsps->header.bytes = bytes;
    return rsps->dptr;
}


/** macro to initialize default IPC response packet. */
static inline ipc_standard_rsps_t * ipc_init_standard_response (
    ipc_packet_t * rsps)
{
    rsps->header.bytes = sizeof(ipc_standard_rsps_t);
    ((ipc_standard_rsps_t *)rsps->dptr)->result = XA_RESULT_SUCCESS;
    return rsps->dptr;
}


/** initialize IPC session.
 *
 * @param fd
 *        session socket file descriptor.
 * @return
 *        session ID session successfully initialized, NULL otherwise.
 */
ipc_session_t ipc_session_create (int fd);


/** destroy IPC session.
 *
 * @param sid
 *        session ID return by @ref ipc_session_init().
 */
void ipc_session_destroy (ipc_session_t sid);


/** read IPC packet
 * data returned in pkt->dptr must be explicitly released by caller through
 * a call to @ref ipc_release_packet().
 *
 * @param sid
 *        IPC session ID.
 * @param pkt
 *        IPC packet.
 * @return
 *        number of bytes read, negative number to indicate error.
 */
int ipc_read_packet (ipc_session_t sid, ipc_packet_t * pkt);


/** write IPC packet
 *
 * @param sid
 *        IPC session ID.
 * @param pkt
 *        IPC packet.
 * @return
 *        number of bytes written, negative number to indicate error.
 */
int ipc_write_packet (ipc_session_t sid, ipc_packet_t * pkt);


/** release IPC packet data
 *
 * @param sid
 *        IPC session ID.
 * @param pkt
 *         IPC packet, must be the returned by @ref ipc_read_packet().
 */
void ipc_release_packet (ipc_session_t sid, ipc_packet_t * pkt);

/** @} */
#endif /* LIMIPC_H__ */
