#pragma once
#include "Vec2.h"

class Rect {
	public:
		float x, y, w, h;

		Rect();

		Rect(float x, float y, float w, float h);

		Rect operator+(Vec2 vec);

		Vec2 GetCenter();

		float GetDistanceRect(Rect rect);

		bool IsInside(Vec2 vec);
};