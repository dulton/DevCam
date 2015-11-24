#include <stdio.h>
#include "jpeglib.h"

/* The following declarations and 5 functions are jpeg related 
 * functions used by put_jpeg_grey_memory and put_jpeg_UYVY_memory
 */
typedef struct {
    struct jpeg_destination_mgr pub;
    JOCTET *buf;
    size_t bufsize;
    size_t jpegsize;
} mem_destination_mgr;
  
typedef mem_destination_mgr *mem_dest_ptr;

//UYVY to JPEG
long YUV422ToJPEG(unsigned char *yuvData, int image_width, int image_height, unsigned char *jpegData, int quality);