#pragma once
#include <iostream>
#include <vector>
class Manager : public Client
{

public:
	Manager();
	Manager(bool showData);


private:
	void showManagerPage();
	void printClientsData();
	void printIncome();
	void printReservedSeats();
	void searchForClient();

};