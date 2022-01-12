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

  OpenMAX AL OUTPUT-MIX - front end header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-03 MG
*/

/** @addtogroup limoa_frontend
 * @{
 */

#ifndef OUTPUT_MIX_FE_H__
#define OUTPUT_MIX_FE_H__

#include "OpenMAXAL.h"
#include "limipc.h"
#include "limqlist.h"
#include "engine-fe.h"

typedef struct output_mix_t
{
    // implicit interfaces
    struct XAObjectItf_ * obj_itf;

    // mandated interfaces

    // optional interfaces

    // output mix object private fields
    int objstate;
    engine_t * engine;

    struct XAObjectItf_ objItf;
} output_mix_t;


XAresult output_mix_obj_create (
    XAEngineItf self,
    XAObjectItf * pMix,
    XAuint32 numInterfaces,
    const XAInterfaceID * pInterfaceIds,
    const XAboolean * pInterfaceRequired);

/** @} */
#endif /* OUTPUT_MIX_FE_H__ */
