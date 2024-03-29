﻿#pragma once
#include <string>
#include <iostream>
#include "Fruit.h"

//enum class Color { red, green, yellow, black, brown, white };

class MotherPlant
{
	enum plant_size { smalll, medium, tall } _size;
	Color _color;
	size_t _max_fruits;
public:
	//MotherPlant(plant_size size, Color plant_color, size_t max_fruits): _size(size), _color(plant_color), _max_fruits(max_fruits){}
	MotherPlant(size_t size, Color plant_color, size_t max_fruits) : _size(plant_size(size)), _color(plant_color), _max_fruits(max_fruits) {}
	virtual ~MotherPlant() {}

	auto Get_size() { return _size; }
	auto Get_color() { return _color; }
	auto Get_max_fruits() { return _max_fruits; }

	virtual void Info()
	{
		std::cout << "\n_size " << _size;
		std::cout << "\n_color " << int(_color);
		std::cout << "\n_max_fruits " << _max_fruits;
	}
	virtual void Info() const
	{
		std::cout << "\n_size " << _size;
		std::cout << "\n_color " << int(_color);
	}

	virtual Fruit* Get_fruit() = 0;

	virtual size_t Get_fruits_remain() = 0;
	virtual std::string Get_Name() = 0;


	friend std::ostream& operator << (std::ostream& out, const MotherPlant& MotherPlant_obj)
	{
		out << "\n_size " << MotherPlant_obj._size;
		out << "\n_color " << int(MotherPlant_obj._color);
		out << "\n_max_fruits " << MotherPlant_obj._max_fruits;
		return out;
	}

};