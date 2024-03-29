﻿#pragma once
#include "MotherPlant.h"
#include "Fruit.h"
#include "raspberry.h"
#include "Service functions.h"



class Raspberry_bush : public MotherPlant
{
	std::string _name_of_current_tree_class_ = "Raspberry bush";
	size_t  _fruits_remain = 0;

public:
	Raspberry_bush(size_t size, Color color, size_t max_fruits) : MotherPlant(size, color, max_fruits) { _fruits_remain = max_fruits; }

	void Info() override
	{
		MotherPlant::Info();
		//std::cout << "\nname of current tree -> " << _name_of_current_tree_class_;
		std::cout << "\n" << _name_of_current_tree_class_;
		std::cout << "\nremain_fruits " << _fruits_remain;
	}

	Fruit* Get_fruit() override
	{
		if (_fruits_remain <= 0) return nullptr;
		Fruit* new_fruit = new raspberry(Get_Random(0.01, 0.05), Color(Get_Random(0, 2)));
		_fruits_remain--;
		return new_fruit;
	}

	size_t Get_fruits_remain() override { return _fruits_remain; }
	std::string Get_Name() override { return _name_of_current_tree_class_; }

};