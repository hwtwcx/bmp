#ifndef bmp_h 
#define bmp_h

#include <stdint.h>
#include <stdlib.h>
typedef struct RGB_revered{
unsigned char blue;
unsigned char green;
unsigned char red;

}RGB_revered;
#pragma pack(push,1)
struct bmp_header {

  char sig[2];
  uint32_t file_size;
  uint16_t reserved1;
  uint16_t reserved2;
  uint32_t offset_size;
  uint32_t info_header_size;
  uint32_t width;
  uint32_t height;
  uint16_t plane_num;
  uint16_t color_bit;
  uint32_t compression_type;
  uint32_t compression_size;
  uint32_t horizontal_pixel;
  uint32_t vertical_pixel;
  uint32_t color_num;
  uint32_t essentail_num;
};
#pragma pack(pop)
int load(const char* path,char**pixcel,struct bmp_header *header_,int *rowsize);
int process(char*pixcel,int mode);
int free_pixcels(char** pixcel);

#endif
