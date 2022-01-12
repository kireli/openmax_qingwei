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

  OpenMAX AL ENGINE - engine back end header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-12 MG
*/

/** @addtogroup limoa_backend
 * @{
 */

#ifndef ENGINE_BE_H__
#define ENGINE_BE_H__

#include "OpenMAXAL.h"
#include "limipc.h"
#include "limqlist.h"
#include "ox-session.h"

int engine_parse_packet (
    ox_session_t * ox,
    ipc_packet_t * rqst,
    ipc_packet_t * rsps);

/** @} */
#endif /* ENGINE_BE_H__ */
