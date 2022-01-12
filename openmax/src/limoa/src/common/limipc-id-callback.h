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

  OpenMAX AL engine implementation - callback ipc ID definitions.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-22 MG
*/

/** @addtogroup limoa_generics
 * @{
 */

#ifndef LIMIPC_ID_CALLBACK_H__
#define LIMIPC_ID_CALLBACK_H__

// callback message ID
#define OX_CALLBACK_PLAY                             MSG(SGMT_CALLBACK, 1)
typedef struct
{
    XAPlayItf caller; /** caller. */
    xaPlayCallback func; /** callback function pointer. */
    void * context; /** user context supplied when callback is registered. */
    XAuint32 event; /** XA_PLAY_EVENT. */
} ox_callback_play_t;

/** @} */
#endif /* LIMIPC_ID_CALLBACK_H__ */
