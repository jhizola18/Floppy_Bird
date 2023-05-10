#pragma once
#include "raylib.h"
#include <list>
#include "Bird.h"




class Pipe {
private:
	Rectangle rec;
	Color color;

	std::list<Rectangle> topPipes; 
	std::list<Rectangle> botPipes;

	float tubeSpeed;
	const int maxTubes = 100;

	
	

public:
	Pipe(Rectangle rec_in, float tubeSpeed_in, int maxTubes_in, Color color_in);
	Pipe(const Pipe& other) = delete;
	Pipe& operator = (const Pipe& other) = delete;
	void DrawObstacle();
	void Draw();
	void ObstacleMovement();
	void updateObstacle();
	void setPosX(float posx);
	float getPosX();

};