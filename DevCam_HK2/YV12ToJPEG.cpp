#include "YV12ToJPEG.h"

#pragma comment(lib,"jpeg.lib")

METHODDEF(void) init_destination(j_compress_ptr cinfo){
	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
	dest->pub.next_output_byte = dest->buf;
	dest->pub.free_in_buffer = dest->bufsize;
	dest->jpegsize = 0;
}

METHODDEF(boolean) empty_output_buffer(j_compress_ptr cinfo){
	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
	dest->pub.next_output_byte = dest->buf;
	dest->pub.free_in_buffer = dest->bufsize;

	return FALSE;
}

METHODDEF(void) term_destination(j_compress_ptr cinfo){
	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
	dest->jpegsize = dest->bufsize - dest->pub.free_in_buffer;
}

static GLOBAL(void) jpeg_mem_dest(j_compress_ptr cinfo, JOCTET* buf, size_t bufsize){
	mem_dest_ptr dest;

	if (cinfo->dest == NULL) {
		cinfo->dest = (struct jpeg_destination_mgr *)
			(*cinfo->mem->alloc_small)((j_common_ptr)cinfo, JPOOL_PERMANENT,
			sizeof(mem_destination_mgr));
	}

	dest = (mem_dest_ptr) cinfo->dest;

	dest->pub.init_destination    = init_destination;
	dest->pub.empty_output_buffer = empty_output_buffer;
	dest->pub.term_destination    = term_destination;

	dest->buf      = buf;
	dest->bufsize  = bufsize;
	dest->jpegsize = 0;
}

static GLOBAL(int) jpeg_mem_size(j_compress_ptr cinfo){
	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
	return dest->jpegsize;
}



/* put_jpeg_yv12_memory converts an input image in the YUV420P format into a jpeg image and puts
 * it in a memory buffer.
 * Inputs:
 * - input_image is the image in YV12 format.
 * - width and height are the dimensions of the image
 * Output:
 * - dest_image is a pointer to the jpeg image buffer
 * Returns buffer size of jpeg image     
 */
long put_jpeg_yv12_memory(unsigned char *dest_image,unsigned char *input_image, int width, int height,int quality){
    int i, j, jpeg_image_size;

    JSAMPROW y[16],cb[16],cr[16]; // y[2][5] = color sample of row 2 and pixel column 5; (one plane)
    JSAMPARRAY data[3]; // t[0][2][5] = color sample 0 of row 2 and column 5

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    data[0] = y;
    data[1] = cr;
    data[2] = cb;

    cinfo.err = jpeg_std_error(&jerr);  // errors get written to stderr 
    
    jpeg_create_compress(&cinfo);
    cinfo.image_width = width;
    cinfo.image_height = height/16*16;
    cinfo.input_components = 3;
    jpeg_set_defaults (&cinfo);

    jpeg_set_colorspace(&cinfo, JCS_YCbCr);

    cinfo.raw_data_in = TRUE;                  // supply downsampled data
    cinfo.comp_info[0].h_samp_factor = 2;
    cinfo.comp_info[0].v_samp_factor = 2;
    cinfo.comp_info[1].h_samp_factor = 1;
    cinfo.comp_info[1].v_samp_factor = 1;
    cinfo.comp_info[2].h_samp_factor = 1;
    cinfo.comp_info[2].v_samp_factor = 1;

    jpeg_set_quality(&cinfo, quality, TRUE);
    cinfo.dct_method = JDCT_FASTEST;

    jpeg_mem_dest(&cinfo, dest_image, cinfo.image_width*cinfo.image_height*3/2);    // data written to mem
    
    jpeg_start_compress(&cinfo, TRUE);

    for (j = 0; j < cinfo.image_height; j += 16) {
        for (i = 0; i < 16; i++) {
            y[i] = input_image + width * (i + j);
            if (i%2 == 0) {
                cb[i/2] = input_image + width * height + width / 2 * ((i + j) / 2);
                cr[i/2] = input_image + width * height + width * height / 4 + width / 2 * ((i + j) / 2);
            }
        }
		jpeg_write_raw_data(&cinfo, data, 16);
    }

    jpeg_finish_compress(&cinfo);
    jpeg_image_size = jpeg_mem_size(&cinfo);
    jpeg_destroy_compress(&cinfo);
    
    return jpeg_image_size;
}