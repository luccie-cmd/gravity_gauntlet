#include <stdlib.h>
#include "include/player.h"
#include "include/renderer.h"
#include <stdio.h>

Player* init_player(int x, int y){
    Player *player = malloc(sizeof(Player));
    player->pos = vector2(x, y);
    player->size = vector2(20.0f, 20.0f);
    player->up_down_dir = DIRECTION_DOWN;
    player->left_right_dir = DIRECTION_NONE;
    player->velocity = vector2(0.0, 0.0);
    return player;
}

void render_player(Player *player){
    RenderQuad(player->pos, vector2_add(player->pos, player->size), color(255, 255, 255, 255));
}

static inline void move_player_down(Player* player){
    Vector2 acceleration = vector2(0.0f, 0.05f);
    player->velocity.y += acceleration.y;
    player->pos.y += player->velocity.y;
}

static inline void move_player_up(Player* player){
    Vector2 acceleration = vector2(0.0f, 0.05f);
    player->velocity.y -= acceleration.y;
    player->pos.y += player->velocity.y;
}

static inline void move_player_left(Player* player){
    Vector2 acceleration = vector2(0.005f, 0.0f);
    player->velocity.x -= acceleration.x;
    player->pos.x += player->velocity.x;
}

static inline void move_player_right(Player* player){
    Vector2 acceleration = vector2(0.005f, 0.0f);
    player->velocity.x += acceleration.x;
    player->pos.x += player->velocity.x;
}

void move_player(Player *player){
    switch(player->up_down_dir){
        case DIRECTION_DOWN: {
            if(player->pos.y + player->size.y < 1080){
                move_player_down(player);
            } else{
                player->pos.y = 1080-player->size.y;
                player->velocity.y = 0;
            }
        } break;
        case DIRECTION_UP: {
            if(player->pos.y > 0){
                move_player_up(player);
            } else{
                player->pos.y = 0;
                player->velocity.y = 0;
            }
        } break;
    }
    switch(player->left_right_dir){
        case DIRECTION_LEFT: {
            if(player->pos.x > 0){
                move_player_left(player);
            } else{
                player->pos.x = 0;
                player->velocity.x = 0;
            }
        } break;
        case DIRECTION_RIGHT: {
            if(player->pos.x + player->size.x < 1920){
                move_player_right(player);
            } else{
                player->pos.x = 1920-player->size.x;
                player->velocity.x = 0;
            }
        } break;
    }
    printf(VECTOR2_FMT "\n", VECTOR2_ARG(player->pos));
}