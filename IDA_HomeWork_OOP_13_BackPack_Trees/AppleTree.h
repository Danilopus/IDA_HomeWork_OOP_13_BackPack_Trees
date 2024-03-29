﻿#pragma once
#include "MotherPlant.h"
#include "Apple.h"
#include "Service functions.h"

//extern enum class Color { red, green, yellow, black, brown, white };
//extern enum class Color;


class AppleTree : public MotherPlant
{
	std::string _name_of_current_tree_class_ = "AppleTree";
	size_t  _fruits_remain = 0;

public:
	//AppleTree(plant_size size, Color color, size_t max_fruits): MotherPlant(size, color, max_fruits){}
	AppleTree(size_t size, Color color, size_t max_fruits) : MotherPlant(size, color, max_fruits) { _fruits_remain = max_fruits; }

	void Info() override
	{
		MotherPlant::Info();
		//std::cout << "\nname of current tree -> " << _name_of_current_tree_class_;
		std::cout << "\n" << _name_of_current_tree_class_;
		std::cout << "\nremain_fruits " << _fruits_remain;

	}

	Fruit* Get_fruit() override
	{
		//_fruits_remain--;
		if (_fruits_remain <= 0) return nullptr;
		Fruit* new_fruit = new Apple(Get_Random(0.1, 0.3), Color::red);
		_fruits_remain--;
		return new_fruit;
	}

	size_t Get_fruits_remain() override { return _fruits_remain; }
	std::string Get_Name() override { return _name_of_current_tree_class_; }

};