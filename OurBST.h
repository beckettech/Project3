#pragma once
#include "City.h"
#include "Animal.h"


using namespace std;


class OurBST{
public:
	City* head;
	City* FindCity(string name);
	void insert(City* newCity);
	OurBST(City* head);
	OurBST();
};

OurBST::OurBST() {
	this->head = nullptr;
}

OurBST::OurBST(City* head) {
	this->head = head;
}

City* OurBST::FindCity(string name) {
	City* temp = this->head;

	while (temp->name != name) {
		int a = name.compare(temp->name);
		if (a == 1) {
			if (temp->right) {
				temp = temp->right;
			}
			else {
				return nullptr;
			}
		}
		if (a == -1) {
			if (temp->left) {
				temp = temp->left;
			}
			else {
				return nullptr;
			}
		}
	}

	return temp;

	
}

void OurBST::insert(City* newCity) {
	City* temp;
	string name = newCity->name;
	if (this->head) {
		temp = this->head;
	}
	else {
		temp = newCity;
		this->head = temp;
		return;
	}
	

	while (temp->name != name) {
		int a = name.compare(temp->name);
		if (a == 1) {
			if (temp->right) {
				temp = temp->right;
			}
			else {
				temp->right = newCity;
				break;
			}
		}
		if (a == -1) {
			if (temp->left) {
				temp = temp->left;
			}
			else {
				temp->left = newCity;
				break;
			}
		}
	}

	if (temp->name == name) {
		cout << "Name already entered" << endl;
	}
}
