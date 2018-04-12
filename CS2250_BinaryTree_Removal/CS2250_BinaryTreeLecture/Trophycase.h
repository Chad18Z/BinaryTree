#ifndef TROPHYCASE_H
#define TROPHYCASE_H

#include <iostream>
#include <string>
#include "Trophy.h"
#include "BinaryTree.h"

using namespace std;

class Trophycase
{
public:
	Trophycase();
	~Trophycase();
	void AddTrophy(Trophy& trophy);
	int GetNumberOfTrophies();
	int GetSizeOfTrophycase();
	//Trophy& GetTrophy(string name); //search for trophy
	void DeleteTrophy(int index);
	
private:
	BinaryTree* Trophies;
	int m_size; 
	int m_count; 
};

#endif


