#include "Bird.h"
#include <raylib.h>

flappy::flappy(const bool* bird, float radius, Color color)
	:
	radius(radius),
	color(color),
	bird(bird)
{
	
};



void flappy::DrawBird() const
{
	DrawCircle(80, GetScreenHeight()/2, (float)radius, color);
}

void flappy::Draw() const
{
	DrawBird();	
}






