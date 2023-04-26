#pragma once
#include <raylib.h>

class flappy
{
private:

	Vector2 position;
	float radius;
	const Color color;
	const bool* bird;


	
public:
	flappy(const bool* bird,float radius, Color color);
	void DrawBird() const;
	void Draw() const;
	float setRadius();
	float getRadius() const;

};