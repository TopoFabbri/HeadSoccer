#pragma once
#include <raylib.h>

enum class ColliderType
{
	None,
	Box,
	Circle,
	Count
};

class Collider
{
protected:
	ColliderType type;
	Vector2 pos;
	
public:
	Collider();
	virtual ~Collider() = 0;

	virtual bool collidesWith(Collider* other) = 0;

	ColliderType getType();
};
