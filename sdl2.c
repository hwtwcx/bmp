#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "bmp.h"
int main(int argc, char *argv[])
{
	struct pixcel** pixcels;
	struct bmp_header header;
	int rowsize;
	SDL_Event event;
	load("/home/hwt/out.bmp", &pixcels, &header,&rowsize);
	SDL_Window* window=SDL_CreateWindow("test pixcels", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, header.width, header.height, SDL_WINDOW_SHOWN);
	SDL_Renderer* render=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture*texture=SDL_CreateTexture(render,SDL_PIXELFORMAT_ABGR8888 , SDL_TEXTUREACCESS_STREAMING, header.width, header.height);
	free_pixcels(&pixcels,header.height);
	while (1) {
		SDL_PollEvent(&event);
		if (event.type==SDL_QUIT) {
			break;
		}
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
