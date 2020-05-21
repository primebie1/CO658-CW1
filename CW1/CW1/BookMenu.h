#pragma once
#include <string>
#include "HashTable.h"
namespace DataStruc
{
	class BookMenu
	{
	public:
		BookMenu(std::string craftName, std::string flightName, int custnum, HashTable* hashTab);
		void Display();
		void Select(std::string ID);
		void DisplayInfo(std::string ID);
		void BookSelected();
		void DisplayMenu();
	private:
		HashTable* hashTab;
		std::string craftName;
		std::string flightName;
		int selectedID;
		int customerID;

		//PLANE RENDERING
		void RenderNose();
		void RenderWingSeats();
		void Render3x2();
		void RenderTail();
	};
}


