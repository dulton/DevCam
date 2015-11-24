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
  
//返回JPEG大小
static GLOBAL(int) jpeg_mem_size(j_compress_ptr cinfo){
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
    return dest->jpegsize;
} 

int RGB2JPEG(unsigned char *RGBBuf,int imageWidth, int imageHeight, unsigned char *jpegData, int quality){
	int jpeg_image_size; 

	//定义一个压缩对象，这个对象用于处理主要的功能
	jpeg_compress_struct jpeg;
	//用于错误信息
	jpeg_error_mgr jerr;
	//错误输出在绑定
	jpeg.err = jpeg_std_error(&jerr);

	//初始化压缩对象
	jpeg_create_compress(&jpeg);

	//绑定输出
	jpeg_mem_dest(&jpeg, jpegData,imageWidth*imageHeight*2);

	//压缩参数设置。具体请到网上找相应的文档吧，参数很多，这里只设置主要的。
	jpeg.image_width = imageWidth;
	jpeg.image_height = imageHeight;
	jpeg.input_components  = 3;
	jpeg.in_color_space = JCS_EXT_BGR;
	//其它参数设置为默认的！
	jpeg_set_defaults(&jpeg);
	jpeg_set_quality(&jpeg, quality, TRUE );
	//开始压缩。执行这一行数据后，无法再设置参数了！
	jpeg_start_compress(&jpeg, TRUE);
	//定义一个数组，代表图片每一行的数据。3　代表　jpeg.input_components
	unsigned char* oneRowImgData = new unsigned char[jpeg.image_width*3];

	JSAMPROW row_pointer[1];
	row_pointer[0] = oneRowImgData;
	//从上到下，设置图片中每一行的像素值
	for(unsigned int i=0;i<jpeg.image_height;++i ){
		for(unsigned int j = 0;j<jpeg.image_width*3;j++){
			oneRowImgData[j] = RGBBuf[i*jpeg.image_width*3 +j];
		}
		//将一行数据写入！
		jpeg_write_scanlines( &jpeg,row_pointer,1 );
	}
	//结束压缩
	jpeg_finish_compress(&jpeg);

	jpeg_image_size = jpeg_mem_size(&jpeg); 

	//清空对象
	jpeg_destroy_compress(&jpeg);

	delete []oneRowImgData;

	oneRowImgData = NULL;

	return jpeg_image_size;
}