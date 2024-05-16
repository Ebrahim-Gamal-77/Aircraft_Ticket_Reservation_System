#pragma once
#include <iostream>
#include <vector>
class Manager : public Client
{

public:
	Manager();
	Manager(bool showData);


private:
	void printClientsData();
	void printIncome();
	void printReservedSeats();
	void searchForClient();



};