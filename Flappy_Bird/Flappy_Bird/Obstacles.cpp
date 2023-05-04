#include "Obstacles.h"
#include <raylib.h>
#include  <iostream>




Pipe::Pipe(Rectangle rec_in, float tubeSpeed_in, int maxTubes_in ,Color color_in)
	:
	rec(rec_in),
	color(color_in),
	maxTubes(maxTubes_in),
	tubeSpeed(tubeSpeed_in)
{
	pipes = new Rectangle[maxTubes * 2] ;

	for (int i = 0; i < maxTubes; ++i)
	{
		float tubeGap = 120.0f;
		float tubeWidth = 80.0f;
		float minY = tubeGap;
		float maxY = GetScreenHeight() - tubeGap - minY;

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

		pipes[i * 2] = Rectangle{ rec.x + i * (tubeGap + tubeWidth), 0, tubeWidth, topTubeHeight };
		pipes[i * 2 + 1] = Rectangle{ rec.x + i * (tubeGap + tubeWidth), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight };
	}
};

void Pipe::DrawObstacle()
{	
	for (int i = 0; i < maxTubes; ++i)
	{
		DrawRectangleRec(pipes[i * 2], color);
		DrawRectangleRec(pipes[i * 2 + 1], color);

	}
	
};


void Pipe::Draw()
{
	
	DrawObstacle();
	
};


void Pipe::ObstacleMovement()
{
	rec.x -= tubeSpeed;

	for (int i = 0; i < maxTubes; ++i)
	{
		pipes[i * 2].x -= tubeSpeed;
		pipes[i * 2 + 1].x -= tubeSpeed;
	}

	if (pipes[0].x + pipes[0].width < 0)
	{
		float tubeGap = 120.0f;
		float tubeWidth = 80.0f;
		float minY = tubeGap;
		float maxY = GetScreenHeight() - tubeGap - minY;

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

		pipes[0] = Rectangle{ pipes[maxTubes * 2 - 2].x + tubeGap + tubeWidth, 0, tubeWidth, topTubeHeight };
		pipes[1] = Rectangle{ pipes[maxTubes * 2 - 1].x + tubeGap + tubeWidth, GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight };
	}

	for (int i = 1; i < maxTubes; ++i)
	{
		pipes[i * 2] = pipes[(i - 1) * 2];
		pipes[i * 2 + 1] = pipes[(i - 1) * 2 + 1];
	}
}


void Pipe::updateObstacle()
{
	ObstacleMovement();
}

Pipe::~Pipe()
{
	delete[] pipes;
}



/*void Pipe::setMaxTubes(int maxTubes_in)  const
{
	maxTubes = maxTubes_in;
}
int Pipe::getMaxTubes() const
{
	return maxTubes;
};*/
