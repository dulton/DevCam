#include <stdio.h>
#include "jpeglib.h"

#pragma comment(lib,"jpeg.lib")

/* The following declarations and 5 functions are jpeg related 
 * functions used by put_jpeg_grey_memory and put_jpeg_yuv420p_memory
 */
typedef struct {
    struct jpeg_destination_mgr pub;
    JOCTET *buf;
    size_t bufsize;
    size_t jpegsize;
} mem_destination_mgr;
  
typedef mem_destination_mgr *mem_dest_ptr;
  
  
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
  
//����JPEG��С
static GLOBAL(int) jpeg_mem_size(j_compress_ptr cinfo){
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
    return dest->jpegsize;
} 

int RGB2JPEG(unsigned char *RGBBuf,int imageWidth, int imageHeight, unsigned char *jpegData, int quality){
	int jpeg_image_size; 

	//����һ��ѹ����������������ڴ�����Ҫ�Ĺ���
	jpeg_compress_struct jpeg;
	//���ڴ�����Ϣ
	jpeg_error_mgr jerr;
	//��������ڰ�
	jpeg.err = jpeg_std_error(&jerr);

	//��ʼ��ѹ������
	jpeg_create_compress(&jpeg);

	//�����
	jpeg_mem_dest(&jpeg, jpegData,imageWidth*imageHeight*2);

	//ѹ���������á������뵽��������Ӧ���ĵ��ɣ������ܶ࣬����ֻ������Ҫ�ġ�
	jpeg.image_width = imageWidth;
	jpeg.image_height = imageHeight;
	jpeg.input_components  = 3;
	jpeg.in_color_space = JCS_EXT_BGR;
	//������������ΪĬ�ϵģ�
	jpeg_set_defaults(&jpeg);
	jpeg_set_quality(&jpeg, quality, TRUE );
	//��ʼѹ����ִ����һ�����ݺ��޷������ò����ˣ�
	jpeg_start_compress(&jpeg, TRUE);
	//����һ�����飬����ͼƬÿһ�е����ݡ�3������jpeg.input_components
	unsigned char* oneRowImgData = new unsigned char[jpeg.image_width*3];

	JSAMPROW row_pointer[1];
	row_pointer[0] = oneRowImgData;
	//���ϵ��£�����ͼƬ��ÿһ�е�����ֵ
	for(unsigned int i=0;i<jpeg.image_height;++i ){
		for(unsigned int j = 0;j<jpeg.image_width*3;j++){
			oneRowImgData[j] = RGBBuf[i*jpeg.image_width*3 +j];
		}
		//��һ������д�룡
		jpeg_write_scanlines( &jpeg,row_pointer,1 );
	}
	//����ѹ��
	jpeg_finish_compress(&jpeg);

	jpeg_image_size = jpeg_mem_size(&jpeg); 

	//��ն���
	jpeg_destroy_compress(&jpeg);

	delete []oneRowImgData;

	oneRowImgData = NULL;

	return jpeg_image_size;
}