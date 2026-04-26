#include "pch.h"
#include "MyUtils.h"

Vector2f MyUtils::Normalized(const Vector2f& value)
{
	float scalarValue{ static_cast<float>(sqrt(pow(value.x,2) + pow(value.y,2))) };
	Vector2f normalizedVector{ };
	if (scalarValue > 0.f) 
	{
		normalizedVector = Vector2f{ value.x / scalarValue, value.y / scalarValue };
	}
	return normalizedVector;
}

float MyUtils::Angle(const Vector2f& value)
{
	float angle{ static_cast<float>(atan2f(value.y, value.x))};
	angle = angle * 180 / 3.14;
	return angle;
}

float MyUtils::ToRad(float value)
{
	return value * 3.1415f / 180.f;
}

float MyUtils::Length(const Vector2f& value)
{
	return sqrt(pow(value.x,2) + pow(value.y, 2));
}
