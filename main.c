#include <stdio.h>
#include "bmp.h"
int main(int argc, char *argv[])
{
	
	struct pixcel** pixcels;
	struct bmp_header header;
	load("/home/hwt/out.bmp",&pixcels,&header);	
	printf("hello");
	return 0;
}
