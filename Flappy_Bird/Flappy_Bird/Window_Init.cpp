#include "Window_Init.h"
#include <assert.h>
#include <raylib.h>
#include <iostream>


MainGame::MainGame(int Width, int Height, int fps, std::string title)
	:
	//What to do with 120 which is the value of the gap
	//between two obstacle
	flap(80, Height / 2, 24, BLACK),
	pipe({300,300, 60, 240},5,4,GREEN)
	
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

void MainGame::Draw()
{
	flap.Draw();
	pipe.DrawObstacle();
	ClearBackground(LIGHTGRAY);	
}

void MainGame::Update()
{
	
	flap.bird_Movement();
	pipe.updateObstacle();
	
}

