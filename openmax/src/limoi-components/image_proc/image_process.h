
#ifndef LIMOI_IMAGE_PROCESS_H__
#define LIMOI_IMAGE_PROCESS_H__

#include "config.h"
#include "limoi.h"


typedef struct
{
    limoi_image_proc_t parent; 

    int inited;
    int has_frame; 

} image_process_private_t;

#define LIMOI_IMAGE_PROCESS(c) ((image_process_private_t *)OMX_COMPONENT(c))

#endif
