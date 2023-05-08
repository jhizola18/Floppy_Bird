#include "Obstacles.h"
#include <raylib.h>
#include  <iostream>
#include <raymath.h>


///FIX THE PIPES DISTANCE EACH OTHER
///FIX THE Birds velocity when going down make it more faster not hover like vel;


Pipe::Pipe(Rectangle rec_in, float tubeSpeed_in, int maxTubes_in, Color color_in)
	:
	rec(rec_in),
	color(color_in),
	maxTubes(maxTubes_in),
	tubeSpeed(tubeSpeed_in),
	pipeTimer(pipeTimer)

{

	std::list<Rectangle>::iterator topitr;
	
	

	for (int i = 0; i < maxTubes*2; ++i)
	{
		float tubeGap = 120.0f;;
		float tubeWidth = 60.0f;
		float minY = tubeGap;
		float maxY = GetScreenHeight() - tubeGap - minY;

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

		topPipes.push_back(Rectangle{ rec.x + i * (tubeGap + tubeWidth), 0, tubeWidth, topTubeHeight });
		botPipes.push_back(Rectangle{ rec.x + i * (tubeGap + tubeWidth), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
		
	}
};

void Pipe::DrawObstacle()
{
	
		for (auto topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
		{
				startTimer(&pipeTimer, 0.03);

				updateTimer(&pipeTimer);
				if (!timerDone(&pipeTimer))
				{
					DrawRectangleRec(*topitr, color);
		
				}	
		}

		for (auto botitr = botPipes.begin(); botitr != botPipes.end(); ++botitr)
		{
			startTimer(&pipeTimer, 0.03);

			updateTimer(&pipeTimer);
			if (!timerDone(&pipeTimer))
			{
				DrawRectangleRec(*botitr, color);

			}
		}
	
};


void Pipe::Draw()
{
	
	DrawObstacle();
	
};


void Pipe::ObstacleMovement()
{
	
	rec.x -= tubeSpeed;

	for (auto topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
	{
		topitr->x -= tubeSpeed;
	}

	for (auto botitr = botPipes.begin(); botitr != botPipes.end(); ++botitr)
	{
		botitr->x -= tubeSpeed;
	}

	//create to if statement for the pipe1 and pipe 2
	if (topPipes.front().x + topPipes.front().width <= GetScreenWidth() / 7 || topPipes.back().x + topPipes.back().width < GetScreenWidth())
	{
		float tubeGap = 120.0f;
		float tubeWidth = 60.0f;
		float minY = tubeGap;
		float maxY = GetScreenHeight() - tubeGap - minY;

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

		topPipes.push_back(Rectangle{ topPipes.back().x + tubeGap + tubeWidth, 0,tubeWidth, topTubeHeight });
		topPipes.pop_front();

		botPipes.push_back(Rectangle{ botPipes.back().x + tubeGap + tubeWidth, GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
		botPipes.pop_front();

	}


	if (topPipes.front().x + topPipes.front().width <= GetScreenWidth() / 7 || topPipes.back().x + topPipes.back().width < GetScreenWidth())
	{
		startTimer(&pipeTimer, 0.03);

		updateTimer(&pipeTimer);
		// if the timer hasn't expired, spawn new pipe
		if (!timerDone(&pipeTimer))
		{
			topPipes.push_back(topPipes.front());
			topPipes.pop_front();
			
		}
	}


	if (botPipes.front().x + botPipes.front().width <= GetScreenWidth() / 7  || botPipes.back().x + botPipes.back().width < GetScreenWidth())
	{
		startTimer(&pipeTimer, 0.03);

		updateTimer(&pipeTimer);
		// if the timer hasn't expired, spawn new pipe
		if (!timerDone(&pipeTimer))
		{
			
			botPipes.push_back(botPipes.front());
			botPipes.pop_front();
		}
	}
};




void Pipe::updateObstacle()
{
	ObstacleMovement();
}




// start or restart a timer with a specific lifetime
void Pipe::startTimer(Timer* timer, float lifetime)
{
	if (timer != NULL)
	{
		timer->lifetime = lifetime;
	}
}
// check if a timer is done.
bool Pipe::timerDone(Timer* timer)
{
	if (timer != NULL)
	{
		return timer->lifetime <= 0;

		return false;
	}
	
}

// update a timer with the current frame time
void Pipe::updateTimer(Timer* timer)
{
	if (timer != NULL && timer->lifetime > 0)
	{
		// subtract this frame from the timer if it's not allready expired
		timer->lifetime -= GetFrameTime();
	}
}



