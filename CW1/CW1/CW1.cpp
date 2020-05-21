// CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "BookMenu.h"
#include "HashTable.h"

using namespace DataStruc;



int main()
{	

	//setup and aircraft config
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char* craftName = "G-ERTI";
	const char* flightName = "MJN1";
	int seatPerRow = 6;
	int rowsOnCraft = 32;
	//size matches Boeing 737-800
	HashTable* b7378 = new HashTable(seatPerRow * rowsOnCraft);
	//adding all seats to aircraft
	for (int i = 0; i < rowsOnCraft; i++)
	{
		for (int j = 0; j < seatPerRow; j++)
		{
			std::string seatString = std::to_string(i + 1);
			seatString += alphabet.at(j);
			Seat* insertedSeat = new Seat(seatString, SeatClass::Economy);
			b7378->Insert(insertedSeat);
		}
	}
	//create menu
	BookMenu bookMenu(std::string(craftName), std::string(flightName), 1, b7378);
	//start menu loop
	bookMenu.DisplayMenu();

	/*	Testing Commands
	bookMenu.Display();
	bookMenu.DisplayInfo("1A");
	bookMenu.Select("1A");
	bookMenu.BookSelected();
	bookMenu.DisplayInfo("1A");
	*/

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
