#include <string>
#include "YUV422ToJPEG.h"

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
  
//·µ»ØJPEG´óÐ¡
static GLOBAL(int) jpeg_mem_size(j_compress_ptr cinfo){
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
    return dest->jpegsize;
} 

//UYVY to JPEG
long YUV422ToJPEG(unsigned char *yuvData, int image_width, int image_height, unsigned char *jpegData, int quality){
	int jpeg_image_size; 
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;
	JSAMPIMAGE  buffer;
	int band,i,buf_width[3],buf_height[3], mem_size, max_line, counter;
	unsigned char *yuv[3];
	unsigned char *pSrc, *pDst;

	yuv[0] = new unsigned char [image_width * image_height];
	yuv[1] = new unsigned char [image_width * image_height/2];
	yuv[2] = new unsigned char [image_width * image_height/2];
	for(int i = 0;i<image_width * image_height;i++){
		yuv[0][i] = yuvData[i*2+1];
	}
	for(int i = 0;i<image_width * image_height/2;i++){
		yuv[1][i] = yuvData[i*4];
		yuv[2][i] = yuvData[i*4+2];
	}

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);
	jpeg_mem_dest(&cinfo, jpegData, image_width*image_height*2);

	cinfo.image_width = image_width;	//image width and height, in pixels
	cinfo.image_height = image_height;
	cinfo.input_components = 3;			// # of color components per pixel
	cinfo.in_color_space = JCS_RGB;		//colorspace of input image

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE );

	cinfo.raw_data_in = TRUE;
	cinfo.jpeg_color_space = JCS_YCbCr;
	cinfo.comp_info[0].h_samp_factor = 2;
	cinfo.comp_info[0].v_samp_factor = 1;

	jpeg_start_compress(&cinfo, TRUE);

	buffer = (JSAMPIMAGE) (*cinfo.mem->alloc_small) ((j_common_ptr) &cinfo, JPOOL_IMAGE, 3 * sizeof(JSAMPARRAY));
	for(band=0; band <3; band++){
		buf_width[band] = cinfo.comp_info[band].width_in_blocks * DCTSIZE;
		buf_height[band] = cinfo.comp_info[band].v_samp_factor * DCTSIZE;
		buffer[band] = (*cinfo.mem->alloc_sarray) ((j_common_ptr) &cinfo, JPOOL_IMAGE, buf_width[band], buf_height[band]);
	}
	max_line = cinfo.max_v_samp_factor*DCTSIZE;
	for(counter=0; cinfo.next_scanline < cinfo.image_height; counter++){
		//buffer image copy.
		for(band=0; band <3; band++){
			mem_size = buf_width[band];
			pDst = (unsigned char *) buffer[band][0];
			pSrc = (unsigned char *) yuv[band] + counter*buf_height[band] * buf_width[band];

			for(i=0; i <buf_height[band]; i++){
				memcpy(pDst, pSrc, mem_size);
				pSrc += buf_width[band];
				pDst += buf_width[band];
			}
		}
		jpeg_write_raw_data(&cinfo, buffer, max_line);
	}

	jpeg_finish_compress(&cinfo);
	jpeg_image_size = jpeg_mem_size(&cinfo); 
	jpeg_destroy_compress(&cinfo);

	delete []yuv[0];
	delete []yuv[1];
	delete []yuv[2];
	yuv[0] = NULL;
	yuv[1] = NULL;
	yuv[2] = NULL;

	return jpeg_image_size;
}