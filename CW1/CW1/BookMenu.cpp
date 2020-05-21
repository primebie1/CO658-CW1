#include "BookMenu.h"
#include <iostream>
#include <stdio.h>
namespace DataStruc
{

	/* AIRFRAME TEMPLATE
				..		\
			  .'  '.	 \
			 /      \	  > NOSE
			/        \   /
		   |		  | /
		   | UUU  UUU |
		   | UUU  UUU | > SEAT
		   | UUU  UUU |
		   | UUU  UUU |
		   | UUU  UUU |
		  /| UUU  UUU |\		\
	    .' | UUU  UUU | '.		 \
	   /   | UUU  UUU |   \		  > WING
	       | UUU  UUU |     	 /
		 ,.| UUU  UUU |., 		/
		'  | UUU  UUU |  '
		   | UUU  UUU |
		   | UUU  UUU |
		   | UUU  UUU |
		   | UUU  UUU |
		   | UUU  UUU |
		   | UUU  UUU |
		   \          / \
			'.      .'   > TAIL
			  '.__.'    /
	*/
	BookMenu::BookMenu(std::string craftName, std::string flightName, int custnum, HashTable* hashTab)
	{
		this->craftName = craftName;
		this->flightName = flightName;
		customerID = custnum;
		this->hashTab = hashTab;
	}
	//Rendering Components
	void BookMenu::RenderNose()
	{
		printf("                ..\n");
		printf("              .'  '.\n");
		printf("             /      \\\n");
		printf("            /        \\\n");
		printf("           |          |\n");
	}
	void BookMenu::Render3x2()
	{
		printf("           | UUU  UUU |\n");
	}
	void BookMenu::RenderWingSeats()
	{
		printf("          /| UUU  UUU |\\\n");
		printf("        .' | UUU  UUU | '.\n");
		printf("       /   | UUU  UUU |   \\\n");
		printf("           | UUU  UUU |    \n");
		printf("         ,.| UUU  UUU |.,\n");
		printf("        '  | UUU  UUU |  '\n");
	}
	void BookMenu::RenderTail()
	{
		printf("           \\          /\n");
		printf("            '.      .'\n");
		printf("              '.__.'\n");
	}

	void BookMenu::Display()
	{
		std::cout << "Aircraft Name: " << craftName << std::endl
				  << "Flight Number: " << flightName << std::endl;
		//Row Calculation
		int size = hashTab->GetSize();
		//take into account seats in WingSeats
		size -= 36;
		size /= 6;
		std::div_t divResult = std::div(size, 2);
		int front = divResult.quot;
		int back = divResult.quot + divResult.rem;


		//render aircraft
		RenderNose();
		for (int i = 0; i < front; i++)
		{
			Render3x2();
		}
		RenderWingSeats();
		for (int i = 0; i < back; i++)
		{
			Render3x2();
		}
		RenderTail();
	}
	void BookMenu::Select(std::string ID)
	{
		selectedID = HashTable::ProcessString(ID);
		std::cout << "Selected " << hashTab->Find(selectedID)->GetName() << "!" << std::endl;
	}
	void BookMenu::DisplayInfo(std::string ID)
	{
		Seat* selectedSeat = hashTab->Find(HashTable::ProcessString(ID));
		std::cout << std::boolalpha;
		std::cout << "Seat: " << selectedSeat->GetName() << std::endl;
		std::cout << "Booked: " << selectedSeat->CheckBooked() << std::endl;
		std::cout << "Special Dietary Requirements: " << selectedSeat->GetDietReq() << std::endl;

	}
	void BookMenu::BookSelected()
	{
		char type;
		do
		{
			std::cout << "Do you have any Dietary Requirements? [y/n]" << std::endl;
			std::cin >> type;
		}
		while (!std::cin.fail() && type != 'y' && type != 'n');

		hashTab->Find(selectedID)->BookSeat(customerID,(type=='y'));
	}
	void BookMenu::DisplayMenu()
	{
		//loop menu until deactivated
		bool menuActive = true;
		while (menuActive)
		{
			system("CLS");
			std::cout 
				<< "Please input your selection:" << std::endl
				<< "1. Display Craft Information" << std::endl
				<< "2. Get Seat Information" << std::endl
				<< "3. Select A Seat" << std::endl
				<< "4. Book Selected Seat" << std::endl
				<< "5. Exit" << std::endl;
			//hold on menu until a valid choice is made
			char choice;
			do
			{
				std::cin >> choice;
			}
			while (!std::cin.fail() && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5');
			//run command according to menu choice
			if (choice == '1')			//display craft
			{
				system("CLS");
				Display();
				system("PAUSE");
			}
			else if (choice == '2')		//display seat information
			{
				std::cout << "Please input seat number:" << std::endl;
				std::string strChoice;
				std::cin >> strChoice;
				system("CLS");
				DisplayInfo(strChoice);
				system("PAUSE");
			}
			else if (choice == '3')		//select seat
			{
				system("CLS");
				std::cout << "Please input seat number:" << std::endl;
				std::string strChoice;
				std::cin >> strChoice;
				Select(strChoice);
				system("PAUSE");
			}
			else if (choice == '4')		//book selected seat
			{
				system("CLS");
				BookSelected();
				system("PAUSE");
			}
			else if (choice == '5')		//exit program
			{
				menuActive = false;
			}

		}
	}
}

