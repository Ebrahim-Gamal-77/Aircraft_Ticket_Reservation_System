#include "Client.h"
#include "Manager.h"
#include <vector>
#include <string>
using namespace std;

// Constructors
Manager::Manager() {}

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

// Functions
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
			printAllData();
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
<< "\t\t" << "ID: " << id.at(clientIndex)
<< "\t\t" << "Phone Number: " << phoneNum.at(clientIndex) << endl;

cout << "From: " << fromCountry.at(clientIndex)
<< "\t\t" << "To: " << toCountry.at(clientIndex) 
<< "\t\t" << "Seat Number: " << seatsPosition.at(clientIndex) << endl;

cout << "Flight Type: " << flightType.at(clientIndex)
<< "\t\t" << "Plan Type: " << planEconomy.at(clientIndex)
<< "\t\t" << "Plan Price: " << planPrice.at(clientIndex) << endl;

std::cout << "\nPress any key to back ";
std::string temp;
std::cin >> temp;
showManagerPage();

}

void Manager::printAllData()
{

	// I have a problem here with spaces formatting ... The program gives me a runtime error even my logic is correct
	for (int i = 0; i < name.size(); i++) {
		cout << "Client #" << i + 1 << endl;

		cout << "|Name: " << name.at(i) << '|';
		for (int j = 0; j < 38 - name.at(i).length(); j++)
		{
			cout << " ";
		}
		cout << "|ID: " << id.at(i) << '|';
		for (int j = 0; j < 25 - id.at(i).length(); j++)
		{
			cout << " ";
		}
		cout << "|Phone Number: " << phoneNum.at(i) << '|' << endl;

		cout << "|From: " << fromCountry.at(i) << '|';
		for (int j = 0; j < 38 - fromCountry.at(i).length(); j++)
		{
			cout << " ";
		}
		cout << "|To: " << toCountry.at(i) << '|';
		for (int j = 0; j < 25 - toCountry.at(i).length(); j++)
		{
			cout << " ";
		}
		cout << "|Flight Type: " << flightType.at(i) << '|' << endl;

		cout << "|Plan Economy: " << planEconomy.at(i) << '|';
		for (int j = 0; j < 30 - planEconomy.at(i).length(); j++)
		{
			cout << " ";
		}
		cout << "|Plan Price: " << planPrice.at(i) << '|';
		for (int j = 0; j < 17 - to_string(planPrice.at(i)).length(); j++)
		{
			cout << " ";
		}
		cout << "|Seat Position: " << seatsPosition.at(i) << '|' << endl << endl;


	}

	std::cout << "\nPress any key to back ";
	std::string temp;
	std::cin >> temp;
	showManagerPage();
}

void Manager::printIncome()
{
	int totalPrice = 0;

	cout << "------------------------------------------------------\n"; 
	cout << "|          Name            |          Price          |\n";
	cout << "------------------------------------------------------\n";
	for (int i = 0; i < planPrice.size(); i++)
	{
		cout << "|          " << name.at(i);
		for (int j = 0; j < 16 - name.at(i).length(); j++)
		{
			cout << ' ';
		}
		cout << "|          " << planPrice.at(i);
		for (int j = 0; j < 15 - to_string(planPrice.at(i)).length(); j++)
		{
			cout << ' ';
		}
		cout << '|' << endl;
	
	    totalPrice += planPrice.at(i);
	}
	cout << "------------------------------------------------------\n";
	cout << "|       Total Income       |          " << totalPrice;
	for (int j = 0; j < 15 - to_string(totalPrice).length(); j++)
	{
		cout << ' ';
	}
	cout << "|\n";
	cout << "------------------------------------------------------\n";

	std::cout << "\nPress any key to back ";
	std::string temp;
	std::cin >> temp;
	showManagerPage();

}  

void Manager::printReservedSeats()
{
	int totalSeats = seatsPosition.size();
	cout << endl << "The Number Of Reserved Chairs Is: " << endl << endl;
	for (int i = 0; i < seatsPosition.size(); i++)
	{
		cout << "Name: " << name.at(i) << "\t\tSeat Number: " << seatsPosition.at(i) << endl;
	}
	cout << endl << "Total Reserved Chairs For Today Is :  " << totalSeats << "  Seats" << endl;
	cout << "\n==================================== PHOENIX ====================================\n\n";

	std::cout << "\nPress any key to back ";
	std::string temp;
	std::cin >> temp;
	showManagerPage();

}
