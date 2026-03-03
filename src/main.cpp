/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include <cmath>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

using namespace std;

const int screenWidth = 1980;
const int screenHeight = 1080;

const double speedFactor = 1;
const int infinityDistance = 500;
const int xOffset = 950;
const int yOffset = 600;

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Snake Game");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// game loop
	double i = 0;
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();
		++i;
		double infinityX = (infinityDistance*sqrt(2) * cos(i*speedFactor));
		      infinityX /= (sin(i*speedFactor)*sin(i*speedFactor)+1);
		      infinityX += xOffset;
		double infinityY = (infinityDistance*sqrt(2) * cos(i*speedFactor) * sin(i*speedFactor));
		      infinityY /= (sin(i*speedFactor)*sin(i*speedFactor)+1);
		      infinityY += yOffset;

		// Setup the back buffer for drawing (clear color and depth buffers)
		// ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("O", infinityX,infinityY,20,WHITE);

		if (i >= 1000) {
			i = 0;
			ClearBackground(BLACK);
		}
	
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
