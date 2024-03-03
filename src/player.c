#include <stdlib.h>
#include "include/player.h"
#include "include/renderer.h"

Player* init_player(int x, int y){
    Player *player = malloc(sizeof(Player));
    player->pos = vector2((float)x, (float)y);
    player->size = vector2(50.0f, 50.0f);
    return player;
}

void render_player(Player *player){
    RenderQuad(player->pos, vector2_add(player->pos, player->size), color(255, 255, 255, 255));
}