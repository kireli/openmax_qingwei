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

  OpenMAX AL PLAYER - front end common sub module header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-19 MG
*/

/** @addtogroup limoa_frontend
 * @{
 */

#ifndef COMMON_FE_H__
#define COMMON_FE_H__

#include "OpenMAXAL.h"
#include "limipc.h"
#include "limdeepcopy.h"
#include "limqlist.h"
#include "engine-fe.h"

#define deep_cp_data_sink(d, s, p) deep_copy_data_sink(d, s, p, NULL)
#define deep_cp_data_source(d, s, p) deep_copy_data_source(d, s, p, NULL)

/** @} */
#endif /* COMMON_FE_H__ */
