#include "Client.h"
#include "Manager.h"
#include <vector>
using namespace std;

void Manager::printOverall()
{
	cout << "FullName* : " << name << "             |" << " ID* : " << id << "             |" << " Phone Number* :  " << phoneNum << " |" << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";
	cout << "From " << fromCountry << "\t\t\t\t\t\t\t\t\t" << " To " << toCountry << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";
	cout << "Chosen Flight Type Is : " << flightType << "\t\t\t\t" << "Chosen Plan Is : " << plan << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";
}

void Manager::printIncome()
{	

	
}

void Manager::printReservedChairs()
{
	cout << "The Number Of Reserved Chairs For Today Is :\t" << seatsNum << "\n";
	cout << "\n==================================== PHOENIX ====================================\n\n";

}

void Manager::search(std::string name)
{
}

static void ExitPhoenix() {
	std::cout << "Good Luck!\n";
	std::cout << "============ PHOENIX ============\n\n";
	exit(0);
}

Manager::Manager()
{



}
