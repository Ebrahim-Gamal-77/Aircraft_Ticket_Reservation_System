#include <iostream>
#include <vector>
#include "Client.h"
class Manager : public Client
{

public:
	Manager();
	Manager(bool showData);


private:
	void showManagerPage();
	void printClientData(int clientIndex);
	void printAllData();
	void printIncome();
	void printReservedSeats();
	void searchForClient();

};
