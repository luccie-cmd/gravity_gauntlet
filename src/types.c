#include "include/types.h"

Vector2 vector2(float x, float y){
    return (Vector2){x, y};
}
Vector2 vector2_add(Vector2 add1, Vector2 add2){
    return vector2(add1.x+add2.x, add1.y+add2.y);
}

Color color(int r, int g, int b, int a){
    return (Color){r, g, b, a};
}