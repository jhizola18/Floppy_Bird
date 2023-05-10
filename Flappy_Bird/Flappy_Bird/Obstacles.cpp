#include "Obstacles.h"
#include <raylib.h>
#include  <iostream>


///FIX THE PIPES DISTANCE EACH OTHER
///FIX THE Birds velocity when going down make it more faster not hover like vel;


Pipe::Pipe(Rectangle rec_in, float tubeSpeed_in, int maxTubes_in, Color color_in)
	:
	rec(rec_in),
	color(color_in),
	maxTubes(maxTubes_in),
	tubeSpeed(tubeSpeed_in)



{
	
	std::list<Rectangle>::iterator topitr;

	
	for (int i = 0; i <= maxTubes; ++i)
	{
		float tubeGap = 150.0f;;
		float tubeWidth = 70.0f;
		int minY = tubeGap; //120 min
		int maxY = GetScreenHeight() - tubeGap - minY; //360 max

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

		topPipes.push_back(Rectangle{ rec.x + i * (tubeGap + tubeWidth), 0, tubeWidth, topTubeHeight});
		botPipes.push_back(Rectangle{ rec.x + i * (tubeGap + tubeWidth), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
	}


	
};

void Pipe::Draw()
{

	DrawObstacle();

};




void Pipe::DrawObstacle()
{
	
		for (auto topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
		{
			for (auto botitr = botPipes.begin(); botitr != botPipes.end(); ++botitr)
			{
				
					DrawRectangleRec(*topitr, color);
					DrawRectangleRec(*botitr, color);
				
			}
				
		}
	
};





void Pipe::updateObstacle()
{
	ObstacleMovement();
}


void Pipe::ObstacleMovement()
{
	
	

	for (auto topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
	{
		topitr->x -= tubeSpeed;
	}

	for (auto botitr = botPipes.begin(); botitr != botPipes.end(); ++botitr)
	{
		botitr->x -= tubeSpeed;
	}
	

	//create to if statement for the pipe1 and pipe 2
	if (topPipes.front().x + topPipes.front().width < GetScreenWidth()/15 || topPipes.empty() && botPipes.empty())
	{
		
		float tubeGap = 150.0f;
		float tubeWidth = 70.0f;
		float minY = tubeGap;
		float maxY = GetScreenHeight() - tubeGap - minY;

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;
		

		topPipes.push_back(Rectangle{ topPipes.back().x + tubeGap + tubeWidth, 0,tubeWidth, topTubeHeight });
		topPipes.pop_front();

		botPipes.push_back(Rectangle{ botPipes.back().x + tubeGap + tubeWidth, GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
		botPipes.pop_front();


	}


	if (topPipes.front().x + topPipes.front().width < GetScreenWidth()/15 )
	{
		
			topPipes.push_back(topPipes.front());
			topPipes.pop_front();

			botPipes.push_back(botPipes.front());
			botPipes.pop_front();
			
	}

	
}

void Pipe::setPosX(float posx)
{
	rec.x = posx;
}

float Pipe::getPosX()
{
	 return rec.x;
}















