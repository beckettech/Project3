#pragma once
#include <algorithm>
#include "City.h"
#include "Animal.h"
using namespace std;

class AVL
{
public:

	City* head;
	City* FindCity(string name);
	void insert(City* newCity);
	int findHeight(City* head);
	int bfactor(City* head);
	struct City* balance(City* head);
	struct City* rotateL(City* head);
	struct City* rotateR(City* head);
	struct City* rotateLR(City* head);
	struct City* rotateRL(City* head);

	AVL()
	{
		head = NULL;
	}
};


City* AVL::FindCity(string name)
{
	City* temp = this->head;

	while (temp->name != name)
	{
		int a = name.compare(temp->name);
		if (a >= 1)
		{
			if (temp->right)
			{
				temp = temp->right;
			}
			else
				return nullptr;
		}
		if (a <= -1)
		{
			if (temp->left)
			{
				temp = temp->left;
			}
			else
				return nullptr;
		}
	}

	return temp;


}

int AVL::findHeight(City* root)
{
	//base case, empty
	if (root == nullptr)
		return 0;

	//h(1 head)=1
	else
		return 1 + max(findHeight(root->left), findHeight(root->right));
}

int AVL::bfactor(City* root)
{
    if(root == NULL)
        return 0;
	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);
	return leftHeight = rightHeight;
}

struct City* AVL::balance(City* root)
{
    int bf = 0;
    if(root != NULL)
        bf = bfactor(root);
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

struct City* AVL::rotateR(City* head)
{
	if (head == nullptr)
	{
        return nullptr;
	}
    if(head->right == nullptr)
    {
        return nullptr;
    }
	City* temp;
	temp = head->right;
	head->right = temp->left;
	temp->left = head;

	return temp;
}

struct City* AVL::rotateL(City* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
	if (head->left == nullptr)
	{
        return nullptr;
	}
	City* temp;
	temp = head->left;
	head->left = temp->right;
	temp->right = head;

	return temp;
}

struct City* AVL::rotateLR(City* head)
{
	City* temp;
	head->left = rotateR(head->left);
	temp = rotateL(head);

	return temp;
}

struct City* AVL::rotateRL(City* head)
{
	City* temp;
	head->right = rotateL(head->right);
	temp = rotateR(head);

	return temp;
}

void AVL::insert(City* newCity)
{
	City* temp;
	string name = newCity->name;
	if (this->head)
		temp = this->head;

	else
	{
		temp = newCity;
		this->head = temp;
		return;
	}


	while (temp->name != name)
	{
		int a = name.compare(temp->name);
		if (a >= 1)
		{
			if (temp->right)
			{
				temp = temp->right;
			}
			else
			{
				temp->right = newCity;
                balance(head);
				break;
			}
		}
		if (a <= -1)
		{
			if (temp->left)
			{
				temp = temp->left;
			}
			else
			{
				temp->left = newCity;
                balance(head);
				break;
			}
		}
	}
}
