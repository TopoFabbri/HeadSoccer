#include <raylib.h>
#include "Game.h"

const int height = 1920;
const int width = 1080;

void defaults();
void runProgram();

int main()
{
	runProgram();
}

void defaults()
{
	InitWindow(width, height, "HeadSoccer");
}

void runProgram()
{
	defaults();
	Game game = Game();
	game.run();
}