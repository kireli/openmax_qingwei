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

  OpenMAX AL engine implementation - limox main routine header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-12 MG
*/

/** @addtogroup limoa_backend
 * @{
 */

#ifndef OX_MAIN_H__
#define OX_MAIN_H__

#include "limipc.h"
#include "ox-session.h"

/** limox packet parse entry point.
 *
 * @param rqst
 *        request message from client.
 * @param rsps
 *        response going back to client.
 * @return
 *        0 if request is successfully fulfilled, non-zero otherwise.
 */
int ox_parse_packet (
    ox_session_t * ox,
    ipc_packet_t * rqst,
    ipc_packet_t * rsps);


// various OpenMAX IL layer test debug routines.
//#define OX_OMXIL_DEBUG

#ifdef OX_OMXIL_DEBUG
void ox_omxil_debug (void);
#else
#define ox_omxil_debug() do {;} while(0)
#endif

/** @} */
#endif /* OX_MAIN_H__ */
