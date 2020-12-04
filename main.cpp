#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include "OurBST.h"
#include "Animal.h"
#include "City.h"

using namespace std;

void BSTRead(OurBST& bst)
{
	ifstream myfile ("Project3Data.csv");
	string line;
	string name;
	string state;
	string strpop;

	if (myfile.is_open()) {
		int counter = 0;
		getline(myfile,line);
		while (getline(myfile, name, ',') ) {
			getline(myfile, state, ',');
			getline(myfile, strpop);
			if (strpop != "A") {
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				bst.insert(city);
				
				
			}

			counter++;
		}
		cout << "done" << endl;
		myfile.close();
		
	}
}

void AVLRead()
{

}

void printAnimalList()
{
	cout << "Please note that these numbers were created with no weapons use by any party.\n" << endl;

	cout << "Duck:" << endl;
	cout << "\t\t 15 ducks to 1 person" << endl;
	cout << "\t\t 0.067 people to 1 duck" << endl;
	
	cout << "Lion:" << endl;
	cout << "\t\t .08 lions to 1 person" << endl;
	cout << "\t\t 12.5 people to 1 lion" << endl;
	
	cout << "T-Rex:" << endl;
	cout << "\t\t .0025 T-Rexes to 1 person" << endl;
	cout << "\t\t 400 people to 1 T-Rex" << endl;
	
	cout << "Fire Ant:" << endl;
	cout << "\t\t 750 fire ants to 1 person" << endl;
	cout << "\t\t .0013 people to 1 fire ant" << endl;
	
	cout << "Grizzly Bear:" << endl;
	cout << "\t\t .0625 grizzly bears to 1 person" << endl;
	cout << "\t\t 16 people to 1 grizzly bear" << endl;
	
	cout << "Emu:" << endl;
	cout << "\t\t 1 emu to 1 person" << endl;
	cout << "\t\t 1 person to 1 emu" << endl;
	
	cout << "Squirrel:" << endl;
	cout << "\t\t 22 squirrels to 1 person" << endl;
	cout << "\t\t .046 people to 1 squirrel" << endl;
	
	cout << "Chimpanzee:" << endl;
	cout << "\t\t 2 chimpanzees to 1 person" << endl;
	cout << "\t\t .5 people to 1 chimpanzee" << endl;
	
	cout << "Gator:" << endl;
	cout << "\t\t .1 gators to 1 person" << endl;
	cout << "\t\t 10 people to 1 gator" << endl;
	
	cout << "Gorilla:" << endl;
	cout << "\t\t .05 gorillas to 1 person" << endl;
	cout << "\t\t 20 people to 1 gorilla" << endl;
}

void createAnimals(vector<pair<string, float>>& animals)
{
	animals.push_back(make_pair("duck", 15));
	animals.push_back(make_pair("lion", .08));
	animals.push_back(make_pair("t-rex", .0025));
	animals.push_back(make_pair("fire ant", 750));
	animals.push_back(make_pair("grizzly bear", .0625));
	animals.push_back(make_pair("emu", 1));
	animals.push_back(make_pair("squirrel", 22));
	animals.push_back(make_pair("chimpanzee", 2));
	animals.push_back(make_pair("gator", .1));
	animals.push_back(make_pair("gorilla", .05));
}

bool validateAnimalAddition(string userAnimal)
{
	if(userAnimal != "duck" || userAnimal != "lion" || userAnimal != "fire ant" || userAnimal != "grizzly bear" || userAnimal != "emu" || userAnimal != "squirrel" || userAnimal != "chimpanzee" || userAnimal != "gator" || userAnimal != "gorilla") {
		return false;
	}else{
		return true;
	}
}

float getAnimalWeight(string animal, vector<pair<string, float>> animals)
{
	for(auto it = animals.begin(); it != animals.end(); ++it){
		if(it->first == animal){
			return it->second;
		}
	}
}

int main()
{
	// introduction
	cout << "Hello and welcome to: Lions and Tigers and Bears, Oh My!" << endl;
	cout << "This program will allow you to approxiate the number of a type of animal needed to overthrow any city" << endl;
	cout << "in the United States based off of population data gathered by the US Census Department." << endl;
	cout << "\n" << endl;	

	// user chooses which option to run
	cout << "Please indicate which process you would like to run:" << endl;
	cout << "\t[1]\tEnter the name of any city in the United States and select an animal from the list that will be provided." << endl;
	cout << "\t\tWe will then tell you the approxiate number of that animal needed to overthrow that city based off population." << endl;
	cout << "\t[2]\tSelect one or more animals from the list that will be provided along with the respective quantities and" << endl;
	cout << "\t\twe will then tell you which US cities could reasonably be overthrown by your assembled animal army." << endl;

	int userOption = 0;
	while(userOption != 1 || userOption != 2){
		cout << "\nPlease make your selection by entering either \"1\" or \"2\": " << endl;
		cin >> userOption;
	}
	cout << "Excellent choice!" << endl;
	
	// read data into BST
	OurBST bst;
	BSTRead(bst);

	// read data into AVL
	//initiate AVL here
	AVLRead();

	// create animal weights
	vector<pair<string, float>> animals;
	createAnimals(animals);

	// animal list
	cout << "Here is the list of supported animals along with the assocaited data relating to defeating the average human:" << endl;
	printAnimalList();
	cout << "\n" << endl;

	// actually do what user wants
	if(userOption == 1){
		string cityChoice, stateChoice;
		cout << "Please enter the city to be overthrown: ";
		cin >> cityChoice;
		cout << "In which US state is " << cityChoice << " located: ";
		cin >> stateChoice;
		string cityState = cityChoice + ", " + stateChoice;
		string userAnimal;
		bool validAnimal = false;
		while(!validAnimal){
			cout << "Please select your animal from the above list: ";
			cin >> userAnimal;
			transform(userAnimal.begin(), userAnimal.end(), userAnimal.begin(), ::tolower);
			validAnimal = validateAnimalAddition(userAnimal);
		}
		
		// calculate number of animals needed
		float animalWeight = getAnimalWeight(userAnimal ,animals);
		// run search in BST for cityState
		double timeBST;
		int popBST;		//serach for cityState within BST and return population
		float animalsNeededBST = popBST * animalWeight;
		
		// run search in AVL for cityState
		double timeAVL;
		int popAVL;		//serach for cityState within AVL and return population
		float animalsNeededAVL = popAVL * animalWeight;

		// print out results
		cout << cityState << " could be overthrown by " << animalsNeededBST << " " << userAnimal << "s.";
		cout << "Storing the data in a BST took " << timeBST << " seconds." << endl;
		cout << "Storing the data in an AVL Tree took " << timeAVL << "seconds." << endl;

	}
	else if(userOption == 2){

		cout << "Please enter the animals you would like to add to your army followed by the number of that animal." << endl;
		cout << "Enter \"-1\" as the animal name when you are done adding." << endl;
		vector<pair<string, int>> userAnimalArmy;
		string userAnimal = "";
		int numOfAnimal;
		while(userAnimal != "-1"){
			cout << "Please enter the animal name: ";
			cin >> userAnimal;
			if(userAnimal == "-1"){
				break;
			}
			transform(userAnimal.begin(), userAnimal.end(), userAnimal.begin(), ::tolower);
			bool validAnimal = validateAnimalAddition(userAnimal);
			if(validAnimal){
				cout << "Please enter the number of " << userAnimal << "s to add: ";
				cin >> numOfAnimal;
				userAnimalArmy.push_back(make_pair(userAnimal, numOfAnimal));
			}
		}

		double maxPop = 0;
		for(auto it = userAnimalArmy.begin(); it != userAnimalArmy.end(); ++it){
			maxPop += (1 / getAnimalWeight(it->first, animals)) * it->second;
		}

		//search thru BST and return the city/cities which a pop less than maxPop
		//search thru AVL and return the city/cities which a pop less than maxPop

		// print results
		

	}
	


	return 0;
}
