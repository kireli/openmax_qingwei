/** @addtogroup limoi_component_ffmpeg_enc
 * @{
 */

#ifndef _IVA11_DEPTH_TY_H_
#define _IVA11_DEPTH_TY_H_

#include "limoi.h"


typedef struct
{
    limoi_videoIVA11_t parent; /** inherit limoi video src. */

} iva11_depth_ty_priv_t;

#define IVA11_DEPTH_TY(c) ((iva11_depth_ty_priv_t *)OMX_COMPONENT(c))

/** @} */
#endif /* _IVA11_DEPTH_TY_H_ */
