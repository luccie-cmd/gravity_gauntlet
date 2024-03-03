#if !defined(_GRAVITY_GAUNTLET_TYPES_)
#define _GRAVITY_GAUNTLET_TYPES_

typedef struct{
    float x, y;
} Vector2;
#define VECTOR2_FMT "x: %f y: %f"
#define VECTOR2_ARG(V) V.x, V.y

typedef struct{
    int r, g, b, a;
} Color;

Vector2 vector2(float x, float y);
Vector2 vector2_add(Vector2 add1, Vector2 add2);
Color color(int r, int g, int b, int a);

#endif // _GRAVITY_GAUNTLET_TYPES_
