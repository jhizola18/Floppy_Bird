#pragma once
#include "raylib.h"


class Pipe {
private:
	Rectangle rec, *pipes;
	
	Color color;
	bool active;
	int posx;
	float tubeSpeed;
	const int maxTubes = 100;
	
	
	

public:
	Pipe(Rectangle rec_in, float tubeSpeed_in, int maxTubes_in, Color color_in);
	void DrawObstacle();
	void Draw();
	void ObstacleMovement();
	void updateObstacle();
	~Pipe();

	
	
};