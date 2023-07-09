#include "Game.h"

Game::Game()
{
	objs[0] = new Map({500, 500});
}

Game::~Game()
{
	for (Object* obj : objs)
		delete obj;
}

void Game::run()
{
	start();

	while (active)
	{
		update();
		draw();
	}
}

void Game::start()
{
}

void Game::update()
{
}

void Game::draw()
{
	BeginDrawing();

	for (Object* obj : objs)
		obj->draw();

	EndDrawing();
}