#pragma once
#include "Vector2f.h"
class MyUtils
{
public:
	static Vector2f Normalized(const Vector2f& value);
	static float Angle(const Vector2f& value);
	static float ToRad(float value);
	static float Length(const Vector2f& value);
};

