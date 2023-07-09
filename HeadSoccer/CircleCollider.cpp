#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	type = ColliderType::Circle;
	pos = { 0, 0 };

	radius = 0;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::update(Vector2 pos, float size)
{
	this->pos = pos;
	radius = size;
}

bool CircleCollider::collidesWith(Collider* other)
{
	bool colliding = false;

	switch (other->getType())
	{
	case ColliderType::None:
		break;

	case ColliderType::Box:
		{
			BoxCollider* otherBox = dynamic_cast<BoxCollider*>(other);
			otherBox->boxCircleColliding(pos, radius);
		}
		break;

	case ColliderType::Circle:
		{
			CircleCollider* otherCircle = dynamic_cast<CircleCollider*>(other);
			circleColliding(otherCircle->getCenter(), otherCircle->getRadius());
		}
		break;

	case ColliderType::Count:
		break;

	default:;
	}
}

bool CircleCollider::circleColliding(Vector2 center, float radius)
{
	float dx = abs(this->pos.x - center.x);
	float dy = abs(this->pos.y - center.y);

	float dis = sqrt(dx * dx + dy * dy);

	if (dis < this->radius + radius)
		return true;
	else
		return false;
}

Vector2 CircleCollider::getCenter()
{
	return pos;
}

float CircleCollider::getRadius()
{
	return radius;
}