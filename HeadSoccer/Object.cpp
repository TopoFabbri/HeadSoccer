#include "Object.h"

Object::Object()
{
	rec = { 0, 0, 10, 10 };
	rot = 0;
	sprite = {};
	tint = WHITE;
}

Object::~Object()
{
}

void Object::start()
{
}

void Object::draw()
{
	Rectangle source = { 0, 0,
		static_cast<float>(sprite.width), static_cast<float>(sprite.height) };
	Vector2 origin = { rec.width / 2, rec.height / 2 };

	if (sprite.width != 0)
		DrawTexturePro(sprite, source, rec, origin, rot, tint);
	else
		DrawRectangleRec(rec, tint);
}