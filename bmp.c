#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
int load(const char* path,struct pixcel*** pixcels_,struct bmp_header* header_){
	
	FILE*file=fopen(path, "rb");
	struct bmp_header header;
	
	fread(&header, sizeof(struct bmp_header), 1,file);
	if (header.color_bit!=24) {
	
		
		printf("color bits:%d\n",header.color_bit);
		return 0;

	}
	if(header.compression_type!=0){
		printf("dont support to zip");
	}
	printf("file_size:%d\n",header.file_size);
	int rowSize=((header.width*3+3)/4)*4;
	fseek(file,header.offset_size, SEEK_SET);
	struct pixcel**pixcels;
	pixcels=(struct pixcel**)malloc(header.height*sizeof(struct pixcel*));
	for (int _=0; _<header.height; _++) {
		pixcels[_]=(struct pixcel*)malloc(header.width*sizeof(struct pixcel));

	}
	for (int i=header.height-1; i>=0; i--) {
		fread(pixcels[i], sizeof(struct pixcel), header.width, file);
		fseek(file,rowSize-header.height*3,SEEK_CUR);
	
	}
	fclose(file);
	*pixcels_=pixcels;
	*header_=header;
	return 0;

}

	

