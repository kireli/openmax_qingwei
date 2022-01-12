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

  OpenMAX AL engine implementation - deep copy module header.

  REVISION:

    1) initial creation. ----------------------------------------- 2009-09-19 MG
*/

/** @addtogroup limoa_generics
 * @{
 */

#ifndef LIMDEEPCOPY_H__
#define LIMDEEPCOPY_H__

/** deep copy XADataSource or XADataSink structure
 *
 * @param dst
 *        destination structure
 * @param src
 *        source structure
 * @param dptr
 *        target data buffer.
 * @param ptroff
 *        pointer offset within source structure
 * @return
 *        bytes copied into data buffer pointed to by dptr
 */
int deep_copy_src_snk (void * dst, const void * src, void * dptr, void * ptroff);
#define deep_copy_data_sink(d, s, p, o) deep_copy_src_snk(d, s, p, o)
#define deep_copy_data_source(d, s, p, o) deep_copy_src_snk(d, s, p, o)

/** @} */
#endif /* LIMDEEPCOPY_H__ */
