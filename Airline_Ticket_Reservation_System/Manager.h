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
	void printClientData(int clientIndex);
	void PrintAllData();
	void printIncome();
	void printReservedSeats();
	void searchForClient();

};