#include "Window_Init.h"
#include <assert.h>
#include <raylib.h>
#include <iostream>


MainGame::MainGame(int Width, int Height, int fps, std::string title)
	:
	//get rectangle from the pipe class
	collision(flap.getPos(), flap.getRadius(), pipe),
	flap({80, Height / 2 - (float)20 }, (float)20, BLACK),
	pipe({0,0,0,0}, 3, 4.0f,GREEN)
	
{
	
	assert(!GetWindowHandle());
	InitWindow(Width, Height, title.c_str());
	SetTargetFPS(fps);
};

MainGame::~MainGame() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

bool MainGame::gameShouldClose() const
{
	
	return WindowShouldClose();
}

void MainGame::gameLoop()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void MainGame::Update()
{
	
	flap.bird_Movement();
	pipe.updateObstacle();
	collision.check_Collision();

}

void MainGame::Draw()
{
	flap.Draw();
	pipe.DrawObstacle();
	ClearBackground(LIGHTGRAY);	
}



