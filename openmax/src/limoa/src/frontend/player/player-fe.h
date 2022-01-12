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

  OpenMAX AL PLAYER - front end header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-04 MG
*/

/** @addtogroup limoa_frontend
 * @{
 */

#ifndef PLAYER_FE_H__
#define PLAYER_FE_H__

#include "OpenMAXAL.h"
#include "limipc.h"
#include "limqlist.h"
#include "engine-fe.h"
#include "common-fe.h"

struct player_t;

#define PLAYER_ITF_TYPE(xa_itf, my_itf)         \
    typedef struct {                            \
        struct XA##xa_itf##Itf_ itf;            \
        struct player_t * player;               \
    } my_itf##_itf_t

PLAYER_ITF_TYPE(Play, play);
PLAYER_ITF_TYPE(Seek, seek);

typedef struct player_t
{
    // implicit interfaces
    struct XAObjectItf_ * obj_itf;
    struct XAPlayItf_ * play_itf;

    // mandated interfaces
    struct XASeekItf_ * seek_itf;

    // optional interfaces

    // player object private fields
    int objstate;
    int playstate;
    engine_t * engine;

    struct XAObjectItf_ objItf;
    play_itf_t playItf;
    seek_itf_t seekItf;
} player_t;


XAresult player_obj_create (
    XAEngineItf self,
    XAObjectItf * pPlayer,
    const XADataSource * pDataSrc,
    const XADataSource * pBankSrc,
    const XADataSink * pAudioSnk,
    const XADataSink * pImageVideoSnk,
    const XADataSink * pVibra,
    const XADataSink * pLEDArray,
    XAuint32 numInterfaces,
    const XAInterfaceID * pInterfaceIds,
    const XAboolean * pInterfaceRequired);

void play_interface_init (player_t * player);
void seek_interface_init (player_t * player);

/** @} */
#endif /* PLAYER_FE_H__ */
