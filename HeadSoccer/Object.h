#pragma once
#include <raylib.h>
#include "Base.h"

class Object :
    public Base
{
protected:
    Rectangle rec;
    float rot;
    Texture2D sprite;
    Color tint;

public:
    Object();
    ~Object() override;

    void start() override;
    void draw() override;
};
