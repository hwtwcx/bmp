#include <stdio.h>
#include "bmp.h"
int main(int argc, char *argv[])
{
	
	struct pixcel** pixcels;
	load("/home/hwt/out.bmp",&pixcels);	
	printf("hello");
	return 0;
}
