#pragma once

#include "Fruit.h";


class Apple : public Fruit
{
public:
	Apple(float weight, Color color) : Fruit("Apple", weight, color) {}
};