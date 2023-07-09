#include "Collider.h"

Collider::Collider()
{
	type = ColliderType::None;
	pos = { 0, 0 };
}

ColliderType Collider::getType()
{
	return type;
}