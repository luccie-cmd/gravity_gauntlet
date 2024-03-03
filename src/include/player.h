#if !defined(_GRAVITY_GAUNTLET_PLAYER_)
#define _GRAVITY_GAUNTLET_PLAYER_
#include "types.h"

typedef struct Player{
    Vector2 pos;
    Vector2 size;
} Player;

Player* init_player(int x, int y);
void render_player(Player *player);
#endif // _GRAVITY_GAUNTLET_PLAYER_
