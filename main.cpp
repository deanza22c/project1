#include<iostream>
#include<string>
#include"Globals.h"

using namespace std;

int main()
{
	// before any choices are give, load the data file and build the hash table and binary search tree
	// none of this is set in stone, but for now gives us something to work on
	// if you need to work on some file, just tag it with a "-A" or "-L" or "-H" and upload the file

	int choice = 0;
	while (choice != 9)
	{
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
			cout << "this is the add data choice\n";
			choice = 9;
			break;
		}
		case 2:
		{
			// call to remove data function
			// both the hash table and binary search tree need remove functions
			// use this case to call those remove functions
			// leo and alex will make the remove functions in the their class files
			cout << "this is the remove data choice\n";
			choice = 9;
			break;
		}
		case 3:
		{
			// call to find and display data function
			// this function will use the binary search tree to find and display the creature based on the number entered
			// clifford will write this function
			cout << "this is the find and display data choice\n";
			choice = 9;
			break;
		}
		case 4:
		{
			// call to list data in hash table
			// list all the data stored in the hashed table based on the order in the array
			// leo will write this function
			cout << "this is the list data in hash table choice\n";
			choice = 9;
			break;
		}
		case 5:
		{
			// call to list data in key sequence (sorted)
			// list all data using the creature number as the sort method
			// I think you can use either the hashed table or the binary search tree for the data
			// but lets go with the hashed table for now
			// leo will work on this
			cout << "this is the list data in key sequence (sorted) choice\n";
			choice = 9;
			break;
		}
		case 6:
		{
			// call to print indented tree function
			// cout the binary tree horizontally, alex and hammud will collaborate as needed on this
			cout << "this is the printed indented tree choice\n";
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
			choice = 9;
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