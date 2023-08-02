#pragma once
#include "Fruit.h";


class raspberry : public Fruit
{
public:
	raspberry(float weight, Color color) : Fruit("raspberry", weight, color) {}
};