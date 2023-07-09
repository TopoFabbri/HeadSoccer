#pragma once
class Base
{
protected:
	bool active;

public:
	Base();
	virtual ~Base();

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	bool getActive();
};