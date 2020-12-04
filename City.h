#pragma once
#include <string>
#include <iostream>

using namespace std;

struct City {
	string name;
	int pop;
	City* right;
	City* left;
	City* parent;
	City(string name, string state, int pop);
};

City::City(string city, string state, int pop) {
	this->name = city + ", " + state;
	this->pop = pop;
	right = nullptr;
	left = nullptr;
	parent = nullptr;

}
