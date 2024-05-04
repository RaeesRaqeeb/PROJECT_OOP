#pragma once
#include<raylib.h>


class BASE_FUNCTION
{
public:

	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Movement() = 0;

};