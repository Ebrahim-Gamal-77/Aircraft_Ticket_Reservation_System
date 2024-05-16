#include "Client.h"
#include "Manager.h"
#include <vector>
using namespace std;


Manager::Manager() {}

// Ebrahim work
Manager::Manager(bool showData) {

	std::cout << "================================ PHOENIX MANAGER ================================\n\n";
	std::cout << "1.Print all Clients data              2.Print all income\n";
	std::cout << "3.Print reserved seats number         4.Search for a Client\n";
	std::cout << "5.Back to Home page\n\n";
	std::cout << "Your Choice: ";
	short choice;
	do {
		std::cin >> choice;
		std::cout << std::endl;
		switch (choice)
		{
		case 1:
			printClientsData();
			break;
		case 2:
			printIncome();
			break;
		case 3:
			printReservedSeats();
			break;
		case 4:
			searchForClient();
			break;
		case 5:
			Client::homePage();
			break;
		default:
			std::cout << "Invalid number!\n";
			std::cout << "Choose a number between (1-5) : ";
		}
	} while (choice < 1 || choice > 5);

}

void Manager::showManagerPage() {

}

void Manager::searchForClient()
{
}

// Ahmed work
void Manager::printClientsData()
{
	/*
	cout << "FullName* : " << name << "             |" << " ID* : " << id << "             |" << " Phone Number* :  " << phoneNum << " |" << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";
	cout << "From " << fromCountry << "\t\t\t\t\t\t\t\t\t" << " To " << toCountry << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";
	cout << "Chosen Flight Type Is : " << flightType << "\t\t\t\t" << "Chosen Plan Is : " << plan << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";
	*/
}


// Yosef work
void Manager::printIncome()
{


}

void Manager::printReservedSeats()
{
	cout << "The Number Of Reserved Chairs For Today Is :\t" << seatsNum << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";

}


