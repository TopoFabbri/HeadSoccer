#pragma once
#include "Collider.h"
#include "BoxCollider.h"
#include <cmath>

class CircleCollider :
    public Collider
{
protected:
    float radius;

public:
    CircleCollider();
    ~CircleCollider() override;

    void update(Vector2 pos, float size);
    bool collidesWith(Collider* other) override;
    bool circleColliding(Vector2 center, float radius);

    Vector2 getCenter();
    float getRadius();
};