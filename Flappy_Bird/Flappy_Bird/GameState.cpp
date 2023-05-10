#include "GameState.h"



Collision::Collision(Vector2 flapPosX, float flapRad, Rectangle& rec)
	:
	flap(flap),
	pipe(pipe),
	flapPosX(flap.getPos()),
	flapRad(flap.getRadius()),
	rec(rec)
{
};


void Collision::check_Collision()
{
	if (CheckCollisionCircleRec(flapPosX, flapRad, rec))
	{
		DrawText("Game Over", 350, 300, 25, BLACK);
	}
};
