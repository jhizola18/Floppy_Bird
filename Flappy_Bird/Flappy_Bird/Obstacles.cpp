#include "Obstacles.h"
#include <raylib.h>
#include  <iostream>

Pipe::Pipe(int pos_x, int pos_y, const int rect_Width, int rect_Height, Color color_in)
	:
	posx(pos_x),
	posy(pos_y),
	width(rect_Width),
	height(rect_Height),
	color(color_in)
{
	tubeSpeed = 1;
	maxTubes = 20;
	
};

void Pipe::DrawObstacle()
{
		
		DrawRectangle(posx, posy, width, height, color);
	
};

void Pipe::Draw()
{
	
	DrawObstacle();

};


void Pipe::ObstacleMovement()
{
	posx -= tubeSpeed;
};
