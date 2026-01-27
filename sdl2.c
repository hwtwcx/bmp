#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include "bmp.h"
int main(int argc, char *argv[])
{
	 char* pixcels;
	struct bmp_header header;
	int rowsize;
	SDL_Event event;
	load("/home/hwt/out.bmp", &pixcels, &header,&rowsize);

	SDL_Window* window=SDL_CreateWindow("test pixcels", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, header.width, header.height, SDL_WINDOW_SHOWN);
	
	SDL_Renderer* renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_Texture*texture=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ABGR8888 , SDL_TEXTUREACCESS_STREAMING, header.width, header.height);
	
	Uint32 texture_format;/*start getting SDL_PixelFormat*/
	int ___=SDL_PIXELFORMAT_ABGR8888;
	SDL_QueryTexture(texture, &texture_format, &___,&header.width, &header.height);
	SDL_PixelFormat *____=SDL_AllocFormat(texture_format);/*end*/
	void *_;
	int pitch;
	SDL_LockTexture(texture,NULL, &_, &pitch);/*copy pixcels to texture*/
	
	Uint32* pixcels_=(Uint32*)_;
	for (int y; y<header.height; y++) {
		for (int x; x<header.width; x++) {
			
			pixcels_[y * (pitch / 4) + x]=SDL_MapRGBA(____, pixcels[y*rowsize+x].red, .green, __.blue,225);
		}
	}
	SDL_UnlockTexture(texture);/*end*/
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
        
        // 渲染纹理
    SDL_RenderCopy(renderer, texture, NULL, NULL);
        
        // 更新屏幕
    SDL_RenderPresent(renderer);
	free_pixcels(&pixcels,header.height);
	while (1) {
		SDL_PollEvent(&event);
		if (event.type==SDL_QUIT) {
			break;
		}
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
