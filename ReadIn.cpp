#include <string>
#include <iostream>
#include <fstream>
#include "OurBST.h"
#include "Animal.h"
#include "City.h"
#include "AVL.h"
#include "chrono"
using namespace std;

int main() {

	ifstream myfile("Project3Data.csv");
	string line;
	string name;
	string state;
	string strpop;
	OurBST bst;
	AVL AVLtree;

	auto BST_Start_Time = chrono::high_resolution_clock::now();
	auto AVL_Start_Time = chrono::high_resolution_clock::now();


	while (myfile.is_open())
	{
		//start BST timer
		auto BST_Start = chrono::high_resolution_clock::now();
		BST_Start_Time = BST_Start;
		//insert file in a BST
		int BSTcounter = 0;
		getline(myfile, line);
		while (getline(myfile, name, ','))
		{
			getline(myfile, state, ',');
			getline(myfile, strpop);
			if (strpop != "A")
			{
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				bst.insert(city);
			}
			BSTcounter++;
		}
		myfile.close();
	}
	//end BST timer
	auto BST_End = chrono::high_resolution_clock::now();
	//calculate BST time elapsed
	auto BST_Time = chrono::duration_cast<chrono::nanoseconds>(BST_End - BST_Start_Time).count();
	cout << "BST - Time Elapsed: " << BST_Time << endl;

	//reopen file for AVL tree
	ifstream myfile2("Project3Data.csv");
	while (myfile2.is_open())
	{
		//start AVL timer
		auto AVL_Start = chrono::high_resolution_clock::now();
		AVL_Start_Time = AVL_Start;
		//insert file in a AVL tree
		int AVLcounter = 0;
		getline(myfile, line);
		while (getline(myfile, name, ','))
		{
			getline(myfile, state, ',');
			getline(myfile, strpop);
			if (strpop != "A")
			{
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				AVLtree.insert(city);
			}
			AVLcounter++;
		}
		myfile2.close();
	}

	//end BST timer
	auto AVL_End = chrono::high_resolution_clock::now();
	//calculate BST time elapsed
	auto AVL_Time = chrono::duration_cast<chrono::nanoseconds>(AVL_End - AVL_Start_Time).count();
	cout << "AVL - Time Elapsed: " << AVL_Time << endl;
}
