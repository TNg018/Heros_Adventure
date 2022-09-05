//Based on Heros_Inventory from Beginning C++ Through Game Programming Third Edition Michael Dawson, Chapter 4 Introducing the Hero’s Inventory 3.0 Program page 123

#include <iostream>
#include <string>
#include <unistd.h> 	// sleep(int) for Linux - use Windows.h for Windows - update in header file 
#include <vector>
#include <cstdlib>     /* srand, rand */
#include <random>

int TIME = 1;

class Hero {												// class
	public:						 							//access specifier
		Hero();												// constructor declaration
		void play();										
		void Introduction();								
		void GetInventory();
		void PrintInventory();
		//to do: make inventory private
		std::vector<std::string> inventory;					//attribute
		std::vector<std::string> Trade();
		void Battle();
		void Robbery();
};

/*
Constructor definition outside of the class
*/
Hero::Hero()
{}

int main(){
	// create hero object
	Hero game;
	game.play();
	return 0;
}

/*
Introduction
*/
void Hero::Introduction(){
	std::cout << "Welcome Hero!" << std::endl;
}

/*
Add items to inventory to start game
*/
void Hero::GetInventory(){
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
}

/*
Output current inventory size and inventory items
*/
void Hero::PrintInventory(){
	std::cout << "\nYou have " << inventory.size() << " items in your inventory." << std::endl;
	sleep(TIME);
	std::cout << "Your items are: " << std::endl;
	for (unsigned int i=0; i < inventory.size(); i++){
		sleep(TIME);
		// sleep will not flush as desired if no std::endl in cout
		std::cout << inventory[i] << std::endl;
	}	
}

/*
Option to trade first item in inventory for other weapon
*/
std::vector<std::string> Hero::Trade() {
	sleep(TIME);
    std::cout << "\nPress 1 to trade your sword to a battle axe\n or \nPress 2 to trade your sword to a mace\n or \nPress 0 to keep your sword:";
    int input;
    std::cin >> input;
    
    if (input == 1) {
        std::cout << "\nYou trade your sword for a battle axe." << std::endl;
        inventory[0] = "battle axe";
       	PrintInventory();
    } else if (input == 2) {
        std::cout << "\nYou trade your sword for a mace." << std::endl;
        inventory[0] = "mace";
       	PrintInventory();
    } else if (input == 0) {
        std::cout << "\nYou kept your sword." << std::endl;
    } else {
        std::cout << "Invalid input, please enter 0 or 1" << std::endl;
    }
    /*
    for (unsigned int i=0; i<inventory.size(); i++) {
        sleep(TIME);
        std::cout << inventory[i] << std::endl;
    }
    */
	return inventory;
}

/*
Get random int to determine outcome of battle
*/
void Hero::Battle(){
	srand(time(NULL));
	sleep(TIME);
	std::cout << "\nYou encounter an enemy and must battle." << std::endl;
	int r = rand() % 4;
	if (r == 0) {
		sleep(TIME);
		std::cout << "You lost your shield." << std::endl;
    	// remove the top item from the stack
    	inventory.pop_back();
		PrintInventory();    	
	} else if (r == 1) {
		sleep(TIME);
		std::cout << "Your enemy was no match against you. " << std::endl;
    	sleep(TIME);
		std::cout << "You gain a weapon. " << std::endl;
    	inventory.push_back("bow and arrows");
    	PrintInventory();
	} else if (r == 2) {
		sleep(TIME);
		std::cout << "You nearly are defeated." << std::endl;
		sleep(TIME);
		std::cout << "Choose a number between 0 - 3." << std::endl;
		sleep(TIME);
		std::cout << "Choose correctly and you will make a stunning recovery." << std::endl;

		int chance;
		std::cin >> chance;
		if (chance == r) {
			std::cout << "Against all odds you survive!" << std::endl;
		} else {
			std::cout << "You have lost." << std::endl;
			//end game
		}
	} else {
		sleep(TIME);
		std::cout << "The battle ends in a stalemate. " << std::endl;
		std::cout << "Both parties continue on their way. " << std::endl;
	}
	
}

/*
Clear inventory
*/
void Hero::Robbery(){
	//choose a path - compare to random number 
	std::cout << "\nYou were robbed of all of your possessions by a thief.";
	inventory.clear();
	if (inventory.empty())
	{
		std::cout << "\nYou have nothing.\n";
	}
	else
	{
		std::cout << "\nYou have at least one item.\n";
	}
}

/*
Run game in a loop until game is over
*/
void Hero::play(){
	Introduction();
	GetInventory();
	PrintInventory();
	Trade();
	Battle();
	Robbery();
}
