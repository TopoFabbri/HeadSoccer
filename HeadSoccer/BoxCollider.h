#pragma once
#include "Collider.h"
#include "CircleCollider.h"

class BoxCollider :
    public Collider
{
protected:
    Vector2 a1;
    Vector2 b2;

public:
    BoxCollider();
    ~BoxCollider() override;

    void update(Vector2 pos, Vector2 size);
    bool collidesWith(Collider* other) override;
    bool boxCircleColliding(Vector2 center, float radius);
    bool boxColliding(Vector2 a1, Vector2 b2);

    Vector2 getA1();
    Vector2 getB2();
};