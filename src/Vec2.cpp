#include "Vec2.h"
#include <math.h>

Vec2::Vec2() {
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator+(Vec2 v) {
	Vec2 result;
	result.x = this->x + v.x;
	result.y = this->y + v.y;
	
	return result;
}

Vec2 Vec2::operator-(Vec2 v) {
	Vec2 result;
	result.x = this->x - v.x;
	result.y = this->y - v.y;

	return result;
}

Vec2 Vec2::operator*(float n) {
	Vec2 result;
	result.x = this->x * n;
	result.y = this->y * n;

	return result;
}

float Vec2::GetMagnitude() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Vec2 Vec2::GetNormalized() {
	return Vec2(this->x / this->GetMagnitude(), this->y / this->GetMagnitude());
}

float Vec2::GetDistance(Vec2 v) {
	return sqrt(pow(this->x - v.x, 2) + pow(this->y - v.y, 2));
}

float Vec2::GetAngule() {
	return atan(this->y / this->x);
}

float Vec2::GetLineAngule(Vec2 v){
	return atan((this->y - v.y) / (this->x - v.x));
}

Vec2 Vec2::Rotate(float angule) {
	return Vec2(this->x * cos(angule) - y * sin(angule), this->y * cos(angule) + x * sin(angule));
}