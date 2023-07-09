#pragma once
#include <raylib.h>

#include "Base.h"
#include "Object.h"
#include "Map.h"

class Game :
    public Base
{
public:
	Game();
	~Game() override;

	void run();

protected:
	void start() override;
	void update() override;
	void draw() override;

private:
	static const int objQty = 1;
	Object* objs[objQty];
};
