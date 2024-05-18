#include "Client.h"
#include "Manager.h"
#include <vector>
using namespace std;


Manager::Manager() {}

// Ebrahim work
Manager::Manager(bool showData) {

	int password;
	do
	{
		std::cout << "Enter Manager Password or (-1) to back: ";
		std::cin >> password;

		switch (password)
		{
		case 1234:
			std::cout << '\n';
			showManagerPage();
			break;
		case -1:
			std::cout << '\n';
			Client::homePage();
			break;
		default:
			std::cout << "Wrong Password! Try again.\n\n";
			break;
		}
	} while (password != -1 && password != 1234);

}

void Manager::showManagerPage() {

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
			PrintAllData();
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

void Manager::searchForClient()
{

	std::string searchedName;
	bool isNameFound = false;

	do
	{
		std::cout << "Who do you want to search for or (-1) to back: ";
		std::cin >> searchedName;
		if (searchedName == "-1") {
			std::cout << endl;
			showManagerPage();
		}
		else
		{
			for (int i = 0; i < name.size(); i++)
			{
				if (searchedName == name.at(i))
				{
					isNameFound = true;
					cout << "\n\n==================================== " << searchedName << " Data ====================================\n\n";
					printClientData(i);
					std::cout << endl;
					showManagerPage();
					break;
				}
			}
			if (!isNameFound) {
				std::cout << "\nSry this name doesn't exist, Try again\n";
			}

		}
	} while (searchedName != "-1" && !isNameFound);





}

void Manager::printClientData(int clientIndex) {
	
cout << "Name: " << name.at(clientIndex)
<< "\t" << "ID: " << id.at(clientIndex)
<< "\t" << "Phone Number: " << phoneNum.at(clientIndex) << endl;

cout << "From: " << fromCountry.at(clientIndex)
<< "\t" << "To: " << toCountry.at(clientIndex) 
<< "\t" << "Seat Number: " << reservedSeats.at(clientIndex) << endl;

cout << "Flight Type: " << flightType.at(clientIndex)
<< "\t" << "Plan Type: " << planType.at(clientIndex)
<< "\t" << "Plan Price: " << planPrice.at(clientIndex) << endl;

}

// Ahmed work
void Manager::PrintAllData()
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
	int totalPrice = 0;

	cout << "|          Name               |          Price               |" << endl << endl;
	for (int j = 0; j < name.size(); j++)
	{
	    cout << "|   " << name.at(j) << "               " << "|   " << planPrice.at(j) << "               " << endl;
	
	    totalPrice += planPrice.at(j);
	}

	cout << endl << "The total income today is : " << totalPrice << " LE" << endl << endl;
	cout << "==================================== PHOENIX ====================================";

}

void Manager::printReservedSeats()
{
	int totalSeats = reservedSeats.size();
	cout << endl << "The Number Of Reserved Chairs Is: " << endl << endl;
	for (int i = 0; i < reservedSeats.size(); i++)
	{
		cout << "seat number : " << reservedSeats.at(i) << endl;
	}
	cout << endl << "The Number Of Reserved Chairs For Today Is :  " << totalSeats << "  Seats" << endl;
	cout << "\n==================================== PHOENIX ====================================\n\n";

	// cout << "The Number Of Reserved Chairs For Today Is :\t" << seatsNum << "\n";
	// cout << "\n==================================== PHOENIX ====================================\n\n";


}


