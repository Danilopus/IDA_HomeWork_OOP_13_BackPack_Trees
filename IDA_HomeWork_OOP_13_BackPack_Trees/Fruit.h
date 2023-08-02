#pragma once
#include <string>
#include <iostream>

enum class Color { red, green, yellow, black, brown, white };


class Fruit
{
	std::string _name;
	float _weight = 0; //kg
	Color _color  = Color::black;
public:
	Fruit(std::string name, float weight, Color color) : _name(name), _weight(weight), _color(color) {}
	//Fruit() = delete;
	//Fruit() = default;
	Fruit();
	//Fruit(const Fruit& fruit) = default;
	//Fruit(Fruit& fruit) = default;
	//Fruit(Fruit&&) = default;
	//Fruit(Fruit&);
	//Fruit(Fruit&&);
	//Fruit(Fruit&) = default;
	//Fruit(const Fruit& fruit) {}
	//Fruit(const Fruit& fruit) {}
	//Fruit(Fruit& fruit) {}

	//virtual ~Fruit();
	virtual ~Fruit() {};

	//std::string Get_name() { return _name; }
	auto Get_name() -> std::string { return _name; }
	auto Get_weight() { return _weight; }
	auto Get_weight() const { return _weight; }
	auto Get_color() { return _color; }

	virtual void Info()
	{
		std::cout << "\n_name   " << _name;
		std::cout << "\n_weight " << _weight;
		std::cout << "\n_color  " << int(_color);
	}

};