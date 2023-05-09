#pragma once
#include <raylib.h>


class flappy
{
private:

	float radius;
	int wall;
	int ceiling;
	int gravity;
	const Color color;
	
	
public:

	flappy(int wall, int ceiling,float radius, Color color);
	void DrawBird();
	void Draw();
	void bird_Movement();
	void setRadius(float radius_in);
	float getRadius();

	void setCeiling(int ceiling_in);
	int getCeiling();

};                 