#pragma once
#include <iostream>
#include <vector>
class Manager : public Client
{

private:
	void printOverall();
	void printIncome();
	void printReservedChairs();
	void search(std::string name);

public:
	Manager();

};

