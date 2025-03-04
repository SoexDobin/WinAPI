#pragma once
#include "pch.h"
#include "assert.h"

struct Vec2 
{
	float x;
	float y;

public:
	Vec2& operator = (POINT _pt)
	{
		x = static_cast<float>(_pt.x);
		y = static_cast<float > (_pt.y);
	};

	float Length()
	{
		return sqrt(x * x + y * y);
	};

	Vec2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;

		return *this;
	};

public:
	Vec2() : x(0.f), y(0.f) { }
	Vec2(float _x, float _y) : x(_x), y(_y) { }
	Vec2(int _x, int _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) { }
	Vec2(POINT _pt)
		: x(static_cast<float>(_pt.x))
		, y(static_cast<float>(_pt.y)) 
	{ };
};

