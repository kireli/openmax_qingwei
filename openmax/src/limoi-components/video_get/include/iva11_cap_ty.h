/** @addtogroup limoi_component_ffmpeg_enc
 * 
 */

#ifndef _IVA11_CAP_TY_H_
#define _IVA11_CAP_TY_H_

#include "limoi.h"

/** video src camera component private data structure. */
typedef struct
{
    limoi_videoIVA11_t parent; /** inherit limoi video src. */

} iva11_cap_ty_priv_t;

#define IVA11_CAP_TY(c) ((iva11_cap_ty_priv_t *)OMX_COMPONENT(c))

/** @} */
#endif /* _IVA11_CAP_TY_H_ */
