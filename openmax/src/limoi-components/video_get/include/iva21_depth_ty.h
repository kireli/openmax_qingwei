/** 
 * 
 */

#ifndef _IVA21_DEPTH_TY_H_
#define _IVA21_DEPTH_TY_H_

#include "limoi.h"


typedef struct
{
    limoi_videoIVA21_t parent;

} iva21_depth_ty_priv_t;

#define IVA21_DEPTH_TY(c) ((iva21_depth_ty_priv_t *)OMX_COMPONENT(c))


#endif 
