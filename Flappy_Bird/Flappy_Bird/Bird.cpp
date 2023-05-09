#include "Bird.h"
#include <raylib.h>
#include <iostream>
#include "Obstacles.h"

flappy::flappy(int wall, int ceiling, float radius, Color color)
	:
	radius(radius),
	color(color),
	ceiling(ceiling),
	wall(wall)
	
{
	gravity = 5;
};



void flappy::DrawBird()
{
	DrawCircle(wall, ceiling, radius, color);
}

void flappy::Draw()
{
	DrawBird();	
}

void flappy::bird_Movement()
{


	
	if(IsKeyDown(KEY_SPACE))
	{
		ceiling -= 5;
		
	}else {
		//y position got updated bt adding the value of the current y position
		// and the gravity
		ceiling = ceiling + gravity;
	}

	if (ceiling + radius >= GetScreenHeight() || ceiling - radius < 0)
	{
		//this is to reverse the gravitational force that make the
		//the object move at the first place
		gravity *= 0;
		
		DrawText("Game Over", 350,  300, 25, BLACK);
		
		
	}
	
	
}

void flappy::setRadius(float radius_in)
{
	radius = radius_in;
}

float flappy::getRadius()
{
	return radius;
}

void flappy::setCeiling(int ceiling_in)
{
	ceiling = ceiling_in;
}

int flappy::getCeiling()
{
	return ceiling;
}









