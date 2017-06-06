#ifndef GLOBALS_H
#define GLOBALS_H
#include<string>
#include<iostream>

int getMenuInput(int size)
{
	int userInput = 0;
	std::string tempString;
	getline(std::cin, tempString);
	while ((tempString[0] < 49 || tempString[0] > (48 + size)) || tempString[1] != '\0')
	{
		std::cout << "1 - " << size << " are the only valid choices, try again: ";
		getline(std::cin, tempString);
	}
	userInput = stoi(tempString);
	return userInput;
}

#endif