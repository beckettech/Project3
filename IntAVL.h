#pragma once
#include <algorithm>
#include "City.h"
#include "Animal.h"
using namespace std;

class IntAVL
{
public:

	City* head;
	City* FindCity(int pop);
	void insert(City* newCity);
	int findHeight(City* head);
	int bfactor(City* head);
	struct City* balance(City* head);
	struct City* rotateL(City* head);
	struct City* rotateR(City* head);
	struct City* rotateLR(City* head);
	struct City* rotateRL(City* head);

	IntAVL()
	{
		head = NULL;
	}
};


City* IntAVL::FindCity(int pop)
{
	City* temp = this->head;
	City* highestBelow = nullptr;

	while (temp->pop != pop && (temp->right || temp->left)) {
		if (pop > temp->pop) {
			highestBelow = temp;
			if (temp->right) {
				temp = temp->right;
			}
			else {
				return highestBelow;
			}
		}
		else if (pop < temp->pop) {
			if (temp->left) {
				temp = temp->left;
			}
			else {
				return highestBelow;
			}
		}
	}
	if (!(temp->right || temp->left)) {
		if (pop < temp->pop) {
			return highestBelow;
		}

	}

	return temp;


}

int IntAVL::findHeight(City* root)
{
	//base case, empty
	if (root == nullptr)
		return 0;

	//h(1 head)=1
	else
		return 1 + max(findHeight(root->left), findHeight(root->right));
}

int IntAVL::bfactor(City* root)
{
	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);
	return leftHeight = rightHeight;
}

struct City* IntAVL::balance(City* root)
{
	int bf = bfactor(root);
	if (bf > 1)
	{
		if (bfactor(root->left) > 0)
			root = rotateL(root);
		else
			root = rotateLR(root);
	}
	else if (bf < -1)
	{
		if (bfactor(root->right) > 0)
			root = rotateRL(root);
		else
			root = rotateR(root);
	}
	return root;
}

struct City* IntAVL::rotateR(City* head)
{
	if (head->right == nullptr)
	{
		cout << "unsuccessful" << endl;
	}
	City* temp;
	temp = head->right;
	head->right = temp->left;
	temp->left = head;

	return temp;
}

struct City* IntAVL::rotateL(City* head)
{
	if (head->left == nullptr)
	{
		cout << "unsuccessful" << endl;
	}
	City* temp;
	temp = head->left;
	head->left = temp->right;
	temp->right = head;

	return temp;
}

struct City* IntAVL::rotateLR(City* head)
{
	City* temp;
	head->left = rotateR(head->left);
	temp = rotateL(head);

	return temp;
}

struct City* IntAVL::rotateRL(City* head)
{
	City* temp;
	head->right = rotateL(head->right);
	temp = rotateR(head);

	return temp;
}

void IntAVL::insert(City* newCity)
{
	City* temp;
	int population = newCity->pop;
	if (this->head)
		temp = this->head;

	else
	{
		temp = newCity;
		this->head = temp;
		return;
	}


	while (temp->pop != population)
	{
		if (population > temp->pop)
		{
			if (temp->right)
			{
				temp = temp->right;
			}
			else
			{
				temp->right = newCity;
				break;
			}
		}
		if (population < temp->pop)
		{
			if (temp->left)
			{
				temp = temp->left;
			}
			else
			{
				temp->left = newCity;
				break;
			}
		}
	}
}
