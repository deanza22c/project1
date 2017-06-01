#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <fstream>

class pokemon
{
private:
	std::string name;
	int dexNum;
	std::string type1;
	std::string type2;
	int bst;
	pokemon *prev;
	pokemon *next;
	pokemon *left;
	pokemon *right;
public:
	//Constructors
	pokemon()
	{
		name = "";
		dexNum = 999;
		type1 = "";
		type2 = "";
		bst = 0;
		prev = nullptr;
		next = nullptr;
		left = nullptr;
		right = nullptr;
	}
	pokemon(std::string v, int w, std::string x, std::string y,int z)
	{
		name = v;
		dexNum = w;
		type1 = x;
		type2 = y;
		bst = z;
		prev = nullptr;
		next = nullptr;
		left = nullptr;
		right = nullptr;
	}	
	pokemon(std::string v, int w, std::string x, std::string y, int z, pokemon* P, pokemon* L, pokemon* R)
	{
		name = v;
		dexNum = w;
		type1 = x;
		type2 = y;
		bst = z;
		prev = P;
		next = nullptr;
		left = L;
		right = R;
	}
	pokemon(std::string v, int w, std::string x, std::string y, int z, pokemon* P, pokemon* N)
	{
		name = v;
		dexNum = w;
		type1 = x;
		type2 = y;
		bst = z;
		prev = P;
		next = N;
		left = nullptr;
		right = nullptr;
	}

	//getters
	std:: string getName()
	{
		return name;
	}
	int getdexNum()
	{
		return dexNum;
	}
	std::string getType1()
	{
		return type1;
	}
	std::string getType2()
	{
		return type2;
	}
	int getBST()
	{
		return bst;
	}
	pokemon* getPrev()
	{
		return prev;
	}
	pokemon* getNext()
	{
		return next;
	}
	pokemon* getLeft()
	{
		return left;
	}
	pokemon *getRight()
	{
		return right;
	}

	//setters
	void setName(std::string x)
	{
		name = x;
	}
	void setdexNum(int x)
	{
		dexNum = x;
	}
	void setType1(std::string x)
	{
		type1 = x;
	}
	void setType2(std::string x)
	{
		type2 = x;
	}
	void setBST(int x)
	{
		bst = x;
	}
	void setPrev(pokemon* p)
	{
		prev = p;
	}
	void setNext(pokemon* n)
	{
		next = n;
	}
	void setLeft(pokemon* l)
	{
		left = l;
	}
	void setRight(pokemon* r)
	{
		right = r;
	}
	
	//Overloading >> operator to read in data from file
	friend std::ifstream& operator >>(std::ifstream& file, pokemon p)
	{
		std::string tempStr;
		getline(file, tempStr, '|');
		p.setdexNum(std::stoi(tempStr));
		getline(file, tempStr, '|');
		p.setName(tempStr);
		getline(file, tempStr, '|');
		p.setType1(tempStr);
		getline(file, tempStr, '|');
		p.setType2(tempStr);
		getline(file, tempStr, '\n');
		p.setBST(std::stoi(tempStr));
		return file;
	}
};
#endif