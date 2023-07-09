#pragma once
#include "Object.h"

class Map :
    public Object
{
protected:
public:
    Map(Vector2 size);
    ~Map() override;

    void start() override;
    void update() override;
};