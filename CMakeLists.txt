cmake_minimum_required(VERSION 3.16)
project(bmp-process-c)
add_compile_options(-g -rdynamic -O0 )
if(DEFINED ENV{bmp_env})
	
	add_executable(bmp-process-c terminal_show.c  bmp.c)

else()
	find_package(SDL2 REQUIRED)
	
	add_executable(bmp-process-c  bmp.c)
	target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL2::SDL2
	)
endif()

