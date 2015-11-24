#include <stdio.h>
#include "jpeglib.h"

/* The following declarations and 5 functions are jpeg related 
 * functions used by put_jpeg_grey_memory and put_jpeg_yuv_memory
 */
typedef struct {
    struct jpeg_destination_mgr pub;
    JOCTET *buf;
    size_t bufsize;
    size_t jpegsize;
} mem_destination_mgr;

typedef mem_destination_mgr *mem_dest_ptr;

/* put_jpeg_yv12_memory converts an input image in the YUV420P format into a jpeg image and puts
 * it in a memory buffer.
 * Inputs:
 * - input_image is the image in YV12 format.
 * - width and height are the dimensions of the image
 * Output:
 * - dest_image is a pointer to the jpeg image buffer
 * Returns buffer size of jpeg image     
 */
long put_jpeg_yv12_memory(unsigned char *dest_image,unsigned char *input_image, int width, int height,int quality);