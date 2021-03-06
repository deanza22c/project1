#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <fstream>

class Pokemon
{
private:
	std::string pokemonName;
	int serialNumber;
	std::string elementalType;
	//std::string type2;
	int offense;
	int defense;
public:
	//Constructors
	Pokemon()
	{
		pokemonName = "unknown name";
		serialNumber = 999;
		elementalType = "unknown";
		//type2 = "";
		offense = 0;
		defense = 0;
	}
	Pokemon(std::string name, int idNumber, std::string emelents, int offenseNumber, int defenseNumber)
	{
		pokemonName = name;
		serialNumber = idNumber;
		elementalType = emelents;
		//type2 = "";
		offense = offenseNumber;
		defense = defenseNumber;
	}

	//getters
	std::string getPokemonName()
	{
		return pokemonName;
	}
	int getSerialNumber()
	{
		return serialNumber;
	}
	std::string getElementalType()
	{
		return elementalType;
	}
	//std::string getType2()
	//{
	//	return type2;
	//}
	int getOffenseStat()
	{
		return offense;
	}
	int getDefenseStat()
	{
		return defense;
	}

	//setters
	void setPokemonName(std::string name)
	{
		pokemonName = name;
	}
	void setSerialNumber(int idNumber)
	{
		serialNumber = idNumber;
	}
	void setElementType(std::string element)
	{
		elementalType = element;
	}
	//void setType2(std::string x)
	//{
	//	type2 = x;
	//}
	void setOffenseStat(int offenseNumber)
	{
		offense = offenseNumber;
	}
	void setDefenseStat(int defenseNumber)
	{
		defense = defenseNumber;
	}
	void setAll(std::string name, int number, std::string element, int attack, int defend)
	{
		pokemonName = name;
		serialNumber = number;
		elementalType = element;
		offense = attack;
		defense = defend;
	}
	//Overloading >> operator to read in data from file
	friend std::ifstream& operator >> (std::ifstream &file, Pokemon &creature)
	{
		std::string tempString;
		int tempNumber;
		getline(file, tempString, '|');
		tempNumber = std::stoi(tempString);
		creature.setSerialNumber(tempNumber);
		getline(file, tempString, '|');
		creature.setPokemonName(tempString);
		getline(file, tempString, '|');
		creature.setElementType(tempString);
		//getline(file, tempStr, '|');
		//p.setType2(tempStr);
		getline(file, tempString, '|');
		creature.setOffenseStat(std::stoi(tempString));
		getline(file, tempString, '\n');
		creature.setDefenseStat(std::stoi(tempString));
		return file;
	}


	//  Overload the instream pointer operator
	friend std::ifstream& operator >> (std::ifstream &file, Pokemon *&creature)
	{
		std::string tempString;
		int tempNumber;
		getline(file, tempString, '|');
		tempNumber = std::stoi(tempString);
		creature->setSerialNumber(tempNumber);
		getline(file, tempString, '|');
		creature->setPokemonName(tempString);
		getline(file, tempString, '|');
		creature->setElementType(tempString);
		//getline(file, tempStr, '|');
		//p.setType2(tempStr);
		getline(file, tempString, '|');
		tempNumber = std::stoi(tempString);
		creature->setOffenseStat(tempNumber);
		getline(file, tempString, '\n');
		tempNumber = std::stoi(tempString);
		creature->setDefenseStat(tempNumber);
		return file;
	}


	// overloaded out stream operator 
	friend std::ostream &operator << (std::ostream &outStream, Pokemon &creature)
	{
		std::cout << creature.serialNumber << " " << creature.pokemonName << " " << creature.elementalType;
		return outStream;
	}

	//  Overload the outstream pointer operator
	friend std::ostream &operator << (std::ostream &outStream, Pokemon *&creature)
	{
		std::cout << creature->serialNumber << " " << creature->pokemonName << " " << creature->elementalType;
		return outStream;
	}

	// Overloaded <= pointer operation
	bool operator<=(const Pokemon *&rightSide)
	{
		bool status;
		if (this->serialNumber == rightSide->serialNumber)
		{
			status = true;
		}
		else if (this->serialNumber < rightSide->serialNumber)
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}

};

struct SortablePokemon {
	Pokemon* p;

	SortablePokemon() : p(nullptr) {}

	SortablePokemon(Pokemon* p) : p(p) {}

	SortablePokemon(const SortablePokemon& other) : p(other.p) {}

	bool operator<=(SortablePokemon other) {
		return p->getSerialNumber() <= other.p->getSerialNumber();
	}

	friend std::ostream &operator << (std::ostream &outStream, SortablePokemon creature)
	{
		std::cout << creature.p->getSerialNumber() << " " << creature.p->getPokemonName() << " " << creature.p->getElementalType();
		return outStream;
	}
};


#endif