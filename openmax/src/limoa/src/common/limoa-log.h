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

  OpenMAX AL engine implementation - log and debug msg support header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-08-19 MG
*/

/** @defgroup limoa_generics limoa generics
 * @ingroup limoa
 */

/** @defgroup limoa_frontend limoa frontend
 * @ingroup limoa
 */

/** @defgroup limoa_backend limoa backend
 * @ingroup limoa
 */

/** @addtogroup limoa_generics
 * @{
 */

#ifndef LIMOA_LOG_H__
#define LIMOA_LOG_H__

#include "limlog.h"
#include "OpenMAXAL.h"

const char * xa_error_string (XAresult res);

/** @} */
#endif /* LIMOA_LOG_H__ */
