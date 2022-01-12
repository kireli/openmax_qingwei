/*
  Copyright (C) 2009 SWOAG Technology <www.swoag.com>

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

  OpenMAX AL engine implementation - ipc ID definitions.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-12 MG
*/

#ifndef LIMIPC_ID_H__
#define LIMIPC_ID_H__

#define LIMOA_IPC_NAK 0x00ffffff

// IPC message ID bitmaps
// bit  23     16 15      0
//     +---------+---------+
//     | SEGMENT | MESSAGE |
//     +---------+---------+
// the following values are reserved for internal system usage,
// 0xffffff, 0xff0000, 0x00ffff, 0x000000
#define MSG(seg, id) (((seg) << 16) | (id))
#define MSG_SEGMENT(msg) (((msg) >> 16) & 0xff)
#define MSG_ID(msg) ((msg) & 0xffff)

// segment definitions.
#define SGMT_ENGINE                                0x01
#define SGMT_OUTPUT_MIX                            0x02
#define SGMT_PLAYER                                0x03

// callback segment can clash with segments defined above.
#define SGMT_CALLBACK                              0xcb

#include "OpenMAXAL.h"
#include "limipc-id-engine.h"
#include "limipc-id-output-mix.h"
#include "limipc-id-player.h"
#include "limipc-id-callback.h"


#endif /* LIMIPC_ID_H__ */
