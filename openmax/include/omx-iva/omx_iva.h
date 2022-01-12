#ifndef __OMX_IVA_H__
#define __OMX_IVA_H__

#include "face_result.h"
#include "wrapper.h"

#define IVA_FACE_MAX_NUM 5
#define IVA_FACE_FEATURE_NUM ONE_FACE_FEATURE_SIZE
#define IVA_FACE_FEATURE_POOL_MAX_NUM FACE_FEATURE_MAX_NUM
#define IVA_FACE_FEATURE_POINT_NUM 25

//#define IVA_FACE_FEATURE_POOL_ADDR 			FACE_FEATURE_ADR
//#define IVA_FACE_FEATURE_MASK_POOL_ADDR 	FACE_MASK_FEATURE_ADR 

typedef struct
{
	int major;
	int minor;
	int revision;
}iva_version_t;


int omx_result_vara_init(TsmFaceResult *A);
int omx_result_vara_cpy(TsmFaceResult *A, TsmFaceResult *B);
void *iva_get_version();

#endif