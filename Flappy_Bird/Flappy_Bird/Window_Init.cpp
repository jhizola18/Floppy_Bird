#include "Window_Init.h"
#include <assert.h>
#include <raylib.h>
#include <time.h>



MainGame::MainGame(int Width, int Height, int fps, std::string title)
	:
	//What to do with 120 which is the value of the gap
	//between two obstacle
	flap(80, Height / 2, 24, BLACK),
	obstacle_Up(GetRandomValue(500, 800), 0, 60, 240, BLUE),
	obstacle_Down(GetRandomValue(0, 600) + 240, 360 + GetScreenHeight(), 60, 240, BLUE)

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
	obstacle_Up.Draw();
	obstacle_Down.Draw();
	ClearBackground(LIGHTGRAY);	
}

void MainGame::Update()
{
	flap.bird_Movement();
	obstacle_Up.ObstacleMovement();
	obstacle_Down.ObstacleMovement();
	
	
}

