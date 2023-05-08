#pragma once
#include "raylib.h"
#include "Timer.h"
#include <list>




class Pipe {
private:
	Rectangle rec;
	Color color;

	std::list<Rectangle> topPipes; 
	std::list<Rectangle> botPipes;

	bool active = true;
	int posx;
	float tubeSpeed;
	const int maxTubes = 100;
	
	Timer timer, pipeTimer = { 0 };

public:
	Pipe(Rectangle rec_in, float tubeSpeed_in, int maxTubes_in, Color color_in);
	void DrawObstacle();
	void Draw();
	void ObstacleMovement();
	void startTimer(Timer* timer, float lifetime);
	void updateTimer(Timer* timer);
	bool timerDone(Timer* timer);
	void updateObstacle();
	

};