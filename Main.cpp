#include <string>
#include <iostream>
#include <fstream>
#include "OurBST.h"
#include "Animal.h"
#include "City.h"

using namespace std;

int main() {
	
	ifstream myfile ("Project3Data.csv");
	string line;
	string name;
	string state;
	string strpop;
	OurBST bst;

	if (myfile.is_open()) {
		int counter = 0;
		getline(myfile,line);
		while (getline(myfile, name, ',') ) {
			getline(myfile, state, ',');
			getline(myfile, strpop, ',');
			if (strpop != "A") {
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				bst.insert(city);
				
				counter++;
			}
			getline(myfile, line);

		}
		//cout << (bst.head)->name <<endl;
		cout << "done" << endl;
		myfile.close();
		
	}
	return 0;
}