#pragma once
#include <raylib.h>
#include "Bird.h"
#include "Obstacles.h"

class Collision {
private:
	Vector2 flapPosX;
	float flapRad;
	Rectangle& rec;

	flappy& flap;
	Pipe& pipe;
public:
	Collision(Vector2 flapPosX, float flapRad,  Rectangle& rec);
	void check_Collision();

};
