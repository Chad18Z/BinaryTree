#include "Trophycase.h"
#include <iostream>

using namespace std;

// Initialize Default constructor to safe values
Trophycase::Trophycase()
{	
	m_count = 0;

	Trophies = new BinaryTree();
}
// return the total number of trophies in the case
int Trophycase::GetNumberOfTrophies()
{
	return m_count;
}
// returns the size of the trophycase
int Trophycase::GetSizeOfTrophycase()
{
	return m_count;
}
// Adds a new trophy to the trophycase
void Trophycase::AddTrophy(Trophy& trophy)
{
	Trophies->Insert(trophy);
	// increment the counter
	m_count++;
}
void Trophycase::PrintInOrder()
{
	Trophies->InOrderPrint(cout);
}
// return the trophy at this index
//Trophy& Trophycase::GetTrophy(string name)
//{
//	return Trophies->Search(name);
//}

// destructor
Trophycase::~Trophycase()
{
	delete [] Trophies;
	Trophies = NULL;
}
// delete the trophy at this index
void Trophycase::DeleteTrophy(int index)
{
	// decrement the number of trophies in the case
	m_count--;

	// assign last trophy in array to the deleted trophy's position
	Trophies[index] = Trophies[m_count];
}





