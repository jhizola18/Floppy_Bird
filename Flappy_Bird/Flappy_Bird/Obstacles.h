#pragma once
#include "raylib.h"

class Pipe {
private:
	int posx;
	int posy;
	const int width;
	int height;
	Color color;
	float tubeSpeed;
	int maxTubes;
	
	

	

public:
	Pipe(int posx, int posy, const int width, int height, Color color);
	void DrawObstacle();
	void Draw();
	void ObstacleMovement();
};