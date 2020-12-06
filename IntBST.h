#pragma once
#include "City.h"
#include "Animal.h"


using namespace std;


class IntBST {

public:
	City* head;
	City* FindCity(int pop);
	void insert(City* newCity);
	IntBST(City* head);
	IntBST();
};

IntBST::IntBST(City* head) {
	this->head = head;
}

IntBST::IntBST() {
	this->head = nullptr;
}

City* IntBST::FindCity(int pop) {
	City* temp = this->head;

	while (temp->pop != pop) {
		if (pop > temp->pop) {
			if (temp->right) {
				temp = temp->right;
			}
			else {
				return nullptr;
			}
		}
		if (pop < temp->pop) {
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

void IntBST::insert(City* newCity) {
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


	while (temp->pop != newCity->pop) {
		if (newCity->pop > temp->pop) {
			if (temp->right) {
				temp = temp->right;
			}
			else {
				temp->right = newCity;
				newCity->parent = temp;
				break;
			}
		}
		if (newCity->pop < temp->pop) {
			if (temp->left) {
				temp = temp->left;
			}
			else {
				temp->left = newCity;
				newCity->parent = temp;
				break;
			}
		}
	}

	
}
