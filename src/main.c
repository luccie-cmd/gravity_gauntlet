#define SDL_MAIN_HANDLED // Make windows also happy
#include <stdio.h>
#include <stdlib.h>
#include "include/SDL2/SDL.h"
#include "include/glad/glad.h"
#include "include/player.h"
#include "include/renderer.h"

int main(){
    printf("Hello, World!\n");
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_Window* window = SDL_CreateWindow("Gravity Gauntlet", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
        return -1;
    }
    if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    glViewport(0, 0, 1920, 1080);

    printf("Version: %s\n", (const char*) glGetString(GL_VERSION));
    Player* player = init_player(0, 0);
    
    int quit = 0;
    while(!quit){
        SDL_Event evs = {0};
        while(SDL_PollEvent(&evs)){
            switch(evs.type){
                case SDL_QUIT: quit = 1; break;
                case SDL_KEYDOWN: {
                    switch(evs.key.keysym.sym){
                        case SDLK_SPACE: {
                            // player->velocity = vector2(player->velocity.x, 0.0f);
                            if(player->up_down_dir == DIRECTION_DOWN){
                                player->up_down_dir = DIRECTION_UP;
                            } else{
                                player->up_down_dir = DIRECTION_DOWN;
                            }
                        } break;
                        case SDLK_a: {
                            player->left_right_dir = DIRECTION_LEFT;
                        } break;
                        case SDLK_d: {
                            player->left_right_dir = DIRECTION_RIGHT;
                        } break;
                    }
                } break;
                case SDL_KEYUP: {
                    switch(evs.key.keysym.sym){
                        case SDLK_a:
                        case SDLK_d: {
                            player->left_right_dir = DIRECTION_DOWN;
                            player->velocity.x = 0;
                        } break;
                    }
                } break;
            }
        }
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        render_player(player);
        move_player(player);

        SDL_GL_SwapWindow(window);
    }
    free(player);
}