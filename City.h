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
	City(string name, int pop);
};

City::City(string name, int pop) {
	this->name = name;
	this->pop = pop;
	right = nullptr;
	left = nullptr;
	parent = nullptr;

}
