#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "bmp.h"
int main(int argc, char *argv[])
{
	struct pixcel** pixcels;
	struct bmp_header header;
	int rowsize;
	load("/home/hwt/out.bmp", &pixcels, &header,&rowsize);
	SDL_Window* window=SDL_CreateWindow("test pixcels", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, header.width, header.height, SDL_WINDOW_SHOWN);
	SDL_Renderer* render=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture*texture=1;
	free_pixcels(&pixcels,header.height);
	return EXIT_SUCCESS;
}
