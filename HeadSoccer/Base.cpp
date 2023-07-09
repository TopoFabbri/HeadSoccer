#include "Base.h"

Base::Base()
{
	active = true;
}

Base::~Base()
{
}

bool Base::getActive()
{
	return active;
}