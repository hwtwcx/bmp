#include "bmp.h"
#include <stdio.h>

#include <stdio.h>

int main(int argc, char *argv[])
{
	char *pixcel;
	struct bmp_header header_;
	int rowsize;
	if(!load("/home/hwt/out.bmp", &pixcel, &header_, &rowsize)){
		return 128;
	}
	printf("sig:%c%c\n",header_.sig[0],header_.sig[1]);
	printf("file_size:%d\n",header_.file_size);
	printf("reserved1:%d\n",header_.reserved1);
	printf("reserved2:%d\n",header_.reserved2);
	printf("offset_size:%d\n",header_.offset_size);
	printf("info_header_size:%d\n",header_.info_header_size);
	printf("width:%d\n",header_.width);
	printf("height:%d\n",header_.height);
	printf("plane_num:%d\n",header_.plane_num);
	printf("color_bit:%d\n",header_.color_bit);
	printf("compression_type:%d\n",header_.compression_type);
	printf("compression_size:%d\n",header_.compression_size);
	printf("horizontal_pixel:%d\n",header_.horizontal_pixel);
	printf("vertical_pixel:%d\n",header_.vertical_pixel);
	printf("color_num:%d\n",header_.color_num);
	printf("essentail_num:%d\n",header_.essentail_num);
	return 1;
}
