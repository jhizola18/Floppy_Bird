#include "Window_Init.h"
#include <assert.h>
#include <raylib.h>
#include "Bird.h"


MainGame::MainGame(int Width, int Height, int fps, std::string title)
	:
	flap({0}, 24, RAYWHITE)
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
	ClearBackground(BLACK);	
}

void MainGame::Update()
{
	
}

