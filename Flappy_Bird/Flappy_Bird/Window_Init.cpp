#include "Window_Init.h"
#include <assert.h>
#include <raylib.h>
#include "Bird.h"


MainGame::MainGame(int Width, int Height, int fps, std::string title)
	:
	flap(80, Height/2, 24, BLACK)
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
	ClearBackground(LIGHTGRAY);	
}

void MainGame::Update()
{
	flap.bird_Movement();
	
}

