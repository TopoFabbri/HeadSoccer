#include "BoxCollider.h"

BoxCollider::BoxCollider()
{
	type = ColliderType::Box;
	pos = { 0, 0 };

	a1 = { 0, 0 };
	b2 = { 0, 0 };
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::update(Vector2 pos, Vector2 size)
{
	this->pos = pos;

	a1 = { pos.x - size.x / 2, pos.y - size.y / 2 };
	b2 = { pos.x + size.x / 2, pos.y + size.y / 2 };
}

bool BoxCollider::collidesWith(Collider* other)
{
	bool isColliding = false;

	switch (other->getType())
	{
	case ColliderType::None:
		break;

	case ColliderType::Box:
		{
			BoxCollider* otherBox = dynamic_cast<BoxCollider*>(other);
			isColliding = boxColliding(otherBox->getA1(), otherBox->getB2());
		}
		break;

	case ColliderType::Circle:
		{
			CircleCollider* otherCircle = dynamic_cast<CircleCollider*>(other);
			isColliding = boxCircleColliding(otherCircle->getCenter(), otherCircle->getRadius());
		}
		break;

	case ColliderType::Count: break;
	default:;
	}

	return isColliding;
}

bool BoxCollider::boxCircleColliding(Vector2 center, float radius)
{
	bool colliding = true;

	if (center.x + radius < a1.x ||
		center.x - radius > b2.x ||
		center.y + radius < a1.y ||
		center.y - radius > b2.y)
		colliding = false;

	return colliding;
}

bool BoxCollider::boxColliding(Vector2 a1, Vector2 b2)
{
	bool colliding = true;

	if (this->a1.x > b2.x ||
		this->b2.x < a1.x ||
		this->a1.y > b2.y ||
		this->b2.y < a1.y)
		colliding = false;

	return colliding;
}

Vector2 BoxCollider::getA1()
{
	return a1;
}

Vector2 BoxCollider::getB2()
{
	return b2;
}