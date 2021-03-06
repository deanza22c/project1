#include<iostream>
#include<string>
#include<fstream>
#include"Globals.h"
#include"Scanner.h"
#include"Pokemon.h"
#include"LinkedList.h"
#include"BinarySearchTree.h"

using namespace std;
//Pokemon *getDataMemoryAddress(ifstream);
int getIntegerInput();

Pokemon *getDataMemoryAddress(ifstream &file)
{
	Pokemon *newPokemon = nullptr;
	newPokemon = new Pokemon;
	file >> *newPokemon;
	//cout << newPokemon->getPokemonName() << endl;
	return newPokemon;
}

void buildDynamicDataStructures(ifstream &file, BinarySearchTree<SortablePokemon> &pokemonBST, LinkedList<Pokemon*> &pokemonLinkedList){
	while (!file.eof()){
		Pokemon *newPokemon = nullptr;
		newPokemon = new Pokemon;
		file >> *newPokemon;
		cout << newPokemon << endl;
		pokemonLinkedList.push_end(newPokemon);
		pokemonBST.addValue(newPokemon);
	}
}

int main()
{
	// before any choices are give, load the data file and build the hash table and binary search tree
	// none of this is set in stone, but for now gives us something to work on
	// if you need to work on some file, just tag it with a "-A" or "-L" or "-H" and upload the file
	ifstream dataRecordsFile;
	dataRecordsFile.open("PokeStats.txt");

	BinarySearchTree<SortablePokemon> pokemonBST;
	LinkedList<Pokemon*> pokemonLinkedList;

	buildDynamicDataStructures(dataRecordsFile, pokemonBST, pokemonLinkedList);


	dataRecordsFile.close();

	//pokemonBST.printBreadthFirstTraverse();
	cout << endl << endl;
	pokemonBST.coutPostOrderTraverse();
	cout << endl << endl;
	pokemonBST.coutPreOrderTraverse();
	cout << endl << endl;
	pokemonBST.coutInOrderTraverse();
	cout << endl << endl;
	/*
	dataRecordsFile.open("PokeStats.txt");
	BinarySearchTree<Pokemon*> AlexPokemonBST;
	Pokemon *tempPokemon = nullptr;
	while (!dataRecordsFile){
		tempPokemon = new Pokemon;
		dataRecordsFile >> *tempPokemon;
		pokemonBST.addValue(tempPokemon);
	}
	*/



	//dataRecordsFile.open("PokeStats.txt");
	//Pokemon pokemonArray[ARRAY_SIZE];
	//for (int count = 0; count < ARRAY_SIZE; count++)
	//{
	//	dataRecordsFile >> pokemonArray[count];
	//}

	int creatureIndexNumber;
	string name;
	string elements;
	int offense;
	int defense;

	int choice = 0;
	while (choice != 9)
	{
		//system("cls");
		cout << "1: add new data\n";
		cout << "2: remove data\n";
		cout << "3: find and display data\n";
		cout << "4: list data in hash table sequence\n";
		cout << "5: list data in key sequence (sorted)\n";
		cout << "6: print indented tree\n";
		cout << "7: effiency\n"; 
		cout << "8: team choice (scanner)\n";
		cout << "9: exit program\n";
		cout << "Enter the choice: ";
		choice = getMenuInput(9);




		switch (choice)
		{
		case 1:
		{
				  // call to add data function
				  // both the hash table and binary search tree need add functions
				  // use this case to call those add functions
				  // leo and alex will make the add functions in the their class files
				  system("cls");
				  cout << "this is the add data choice\n";
				  cout << "enter in creature number: ";
				  creatureIndexNumber = getIntegerInput();
				  cout << "enter in creature name: ";
				  getline(cin, name);
				  cout << "enter in creature elements: ";
				  getline(cin, elements);
				  cout << "enter in creature offense: ";
				  offense = getIntegerInput();
				  cout << "enter in creature defense: ";
				  defense = getIntegerInput();
				  Pokemon *newPokemon = nullptr;
				  newPokemon = new Pokemon(name, creatureIndexNumber, elements, offense, defense);
				  //newPokemon->setAll(creatureIndex, name, elements, offense, defense);
				  pokemonLinkedList.push_end(newPokemon);
				  pokemonBST.addValue(SortablePokemon(newPokemon));
				  //choice = 9;
				  cout << "\npress <Enter> to return to main menu...";
				  cin.get();
				  break;
		}
		case 2:
		{
				  // call to remove data function
				  // both the hash table and binary search tree need remove functions
				  // use this case to call those remove functions
				  // leo and alex will make the remove functions in the their class files
				  system("cls");
				  cout << "this is the remove data choice\n";
				  //choice = 9;
				  cout << "\npress <Enter> to return to main menu...";
				  cin.get();
				  break;
		}
		case 3:
		{
				  // call to find and display data function
				  // this function will use the binary search tree to find and display the creature based on the number entered
				  // clifford will write this function
				  cout << "this is the find and display data choice\n";

				  cout << "enter in creature number to search for: ";
				  creatureIndexNumber = getIntegerInput();
				  // send the number to the binary search tree module and print out the results of the search
				  cout << "\npress <Enter> to return to main menu...";
				  cin.get();

				  break;
		}
		case 4:
		{
				  // call to list data in hash table
				  // list all the data stored in the hashed table based on the order in the array
				  // leo will write this function
				  system("cls");
				  cout << "this is the list data in hash table choice\n";


				  pokemonLinkedList.displayList();
				  cout << "\npress <Enter> to return to main menu...";
				  cin.get();


				  break;
		}
		case 5:
		{
				  // call to list data in key sequence (sorted)
				  // list all data using the creature number as the sort method
				  // I think you can use either the hashed table or the binary search tree for the data
				  // but lets go with the hashed table for now
				  // leo will work on this
				  system("cls");
				  cout << "this is the list data in key sequence (sorted) choice\n";
				  //clif/team -  it looks like you placed the inorder traversal into the breadthfirst functions. I restored the breadth traversal, and create an inorder function.
				  pokemonBST.coutInOrderTraverse();
				  cout << "\npress <Enter> to return to main menu...";
				  cin.get();
				  break;
		}
		case 6:
		{
				  // call to print indented tree function
				  // cout the binary tree horizontally, alex and hammud will collaborate as needed on this
				  //system("cls");
				  cout << "this is the printed indented tree choice\n";
				  cout << pokemonBST.findDepth();
				  choice = 9;
				  break;
		}
		case 7:
		{
				  // call to effiency
				  // display the effiency of our hashed table and binary search tree
				  // clifford will work on this
				  cout << "this is the effiency choice\n";
				  choice = 9;
				  break;
		}
		case 8:
		{
				  // call to scanner function
				  // this is our team choice and for now the idea is to display a message that a wild pokemon has appeared
				  // display an out line of the creature, flash the words scanning on the the screen
				  // then after the 3 seconds display the full picture and some stats about the creature
				  // it will only display one creature for now, and in the future it may display a random pokemon
				  cout << "this is the scanner choice\n";
				  startScanner();
				  //choice = 9;
				  break;
		}
		case 9:
		{
				  // exit program 
				  break;
		}
		default:
		{
				   // this is here for safety
				   break;
		}

		}
	}

	cout << "\npress <Enter> to exit the program...";
	cin.get();
	return 0;
}