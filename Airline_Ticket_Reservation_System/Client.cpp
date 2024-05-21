#include <iostream>
#include <string>
#include "Client.h"
#include "Manager.h"
using namespace std;

Client::Client() {}

Client::Client(bool takeData) {

    if (takeData) {
        std::cout << "================================ PHOENIX CLIENT ================================\n\n";

        int seatsNum = chooseSeatsNum();
        std::cout << "We will collect your data for the flight\n";
        for (int i = 0; i < seatsNum; i++)
        {
            if (seatsNum > 1) {
                std::cout << "Taking data from #" << i + 1 << " Client\n";
            }
            setName();
            setID();
            setPhoneNum();
            std::cout << "\n==================================== PHOENIX ====================================\n";
            setFromCountry();
            setToCountry();
            setFlightType();
            setPlan();
            chooseSeatPosition();
            printTicket();
        }
    }

    Client::homePage();

}

int Client::chooseSeatsNum()
{
    int numOfSeats;
    do
    {
        std::cout << "How many seats will you take or (-1) to back: ";
        std::cin >> numOfSeats;
        std::cout << '\n';
        if (numOfSeats == -1) {
            Client::homePage();
        }
        else if (numOfSeats < 1 || numOfSeats > 16) {
            std::cout << "You just can take from 1 to 16 seat\n";
        }
        else {
            this->seatsNum += numOfSeats;
        }
    } while (numOfSeats != -1 && (numOfSeats < 1 || numOfSeats > 16));

    return numOfSeats;

}

void Client::setName()
{
    std::cout << "Enter your name : ";
    std::string name;
    std::cin >> name;
    this->name.push_back(name);
}

void Client::setID()
{
    std::cout << "Enter your ID : ";
    std::string id;
    std::cin >> id;
    this->id.push_back(id);
}

void Client::setPhoneNum()
{
    std::cout << "Enter your phone number : ";
    std::string phoneNum;
    std::cin >> phoneNum;
    this->phoneNum.push_back(phoneNum);
}

void Client::setFromCountry()
{
    std::cout << "\nWhich country will you start from?\n\n";
    for (int i = 0; i <= 8; i+=2)
    {
        std::cout << i + 1 << '.' << availableCountries[i];
        
        // Optimizing number of spaces between countries
        for (int j = 0; j < 14 - availableCountries[i].length(); j++) {
            std::cout << ' ';
        }
        std::cout << i + 2 << '.' << availableCountries[i + 1];
        
        std::cout << '\n';
    }
    std::cout << std::endl;
    std::cout << "Choose a country : ";
    short fromCountryNum;
    std::cin >> fromCountryNum;
    while (fromCountryNum < 1 || fromCountryNum > 10) {
        std::cout << "\nInvalid number!\n";
        std::cout << "Choose a country between (1,10) : ";
        std::cin >> fromCountryNum;
    }
    this->fromCountry.push_back(availableCountries[fromCountryNum - 1]);

    std::cout << fromCountry.back() << '\n';
}

void Client::setToCountry()
{

    // Getting from country 
    short fromCountryIndex{};
    for (int i = 0; i < 10; i++)
    {
        if (availableCountries[i] == fromCountry.back()) {
            fromCountryIndex = i;
            break;
        }
    }


    std::cout << "\nWhich country will you go to?\n\n";
    // Reserved country
    short isReserved = 0; // x is bool to indicate if from country reserved
    for (int i = 0; i <= 9; i += 2)
    {

        // Check if the from country reserved
        if(fromCountryIndex == i){
            i++;
            isReserved++;
        }
        std::cout << i + 1 - isReserved << '.' << availableCountries[i];

        // Optimizing number of spaces between countries
        for (int j = 0; j < 14 - availableCountries[i].length(); j++) {
            std::cout << ' ';
        }

        // Check if the from country reserved
        if (fromCountryIndex == i + 1) {
            i++;
            isReserved++;
        }

        if (i != 9) {
            std::cout << i + 2 - isReserved << '.' << availableCountries[i + 1];
        }

        std::cout << '\n';
    }
    std::cout << std::endl;
    std::cout << "Choose a country : ";
    short toCountryNum;
    std::cin >> toCountryNum;

    while (toCountryNum < 1 || toCountryNum > 9) {
        std::cout << "\nInvalid number!\n";
        std::cout << "Choose a country between (1,9) : ";
        std::cin >> toCountryNum;
    }

    // Optimizing toCountry number after adding reserved fromCountry
    if (toCountryNum >= fromCountryIndex + 1) {
        this->toCountry.push_back(availableCountries[toCountryNum]);
    }
    else {
        this->toCountry.push_back(availableCountries[toCountryNum - 1]);
    }
    std::cout << toCountry.back() << std::endl << std::endl;
}

void Client::setFlightType()
{
    int chooseType;
    string flightType;
    std::cout << "Which flight type do you want? \n";
    std::cout << "1) One-way          2) Round-trip\n\n";
    std::cout << "Your flight type : ";
    std::cin >> chooseType;
    if (chooseType == 1)
    {
        flightType = "One-way";
        std::cout << "One-way" << std::endl;
        std::cout << "\n==================================== PHOENIX ====================================\n";
    }
    else if (chooseType == 2)
    {
        flightType = "Round-trip";
        std::cout << "Round-trip" << std::endl;
        std::cout << "\n==================================== PHOENIX ====================================\n\n";
    }
    this->flightType.push_back(flightType);
}

void Client::setPlan()
{
	int PLAN;
	int plan1 = 7500;
	int plan2 = 10000;
	int plan3 = 15000;
	int plan4 = 25000;

	if (flightType.back() == "One-way")
	{
		cout << endl;
		cout << "                 --> CHOOSE THE PLAN YOU WANT FOR ONE-WAY <--                 " << endl << endl << endl;

		cout << "   *********************************     *********************************   " << endl;
		cout << "   *                               *     *                               *   " << endl;
		cout << "   *           PLAN ( 1 )          *     *           PLAN ( 2 )          *   " << endl;
		cout << "   *       { ECONOMY CLASS }       *     *   { PREMIUM ECONOMY CLASS }   *   " << endl;
		cout << "   *                               *     *                               *   " << endl;
		cout << "   *    7,500 LE   --->   150 $    *     *    10,000 LE   --->   200 $   *   " << endl;
		cout << "   *                               *     *                               *   " << endl;
		cout << "   *********************************     *********************************   " << endl << endl << endl;

		cout << "   *********************************     *********************************   " << endl;
		cout << "   *                               *     *                               *   " << endl;
		cout << "   *           PLAN ( 3 )          *     *           PLAN ( 4 )          *   " << endl;
		cout << "   *      { BUSINESS CLASS }       *     *        { FIRST CLASS }        *   " << endl;
		cout << "   *                               *     *                               *   " << endl;
		cout << "   *    15,000 LE   --->   300 $   *     *    25,000 LE  --->   500 $    *   " << endl;
		cout << "   *                               *     *                               *   " << endl;
		cout << "   *********************************     *********************************   " << endl << endl << endl;

		cout << "Enter your Plan number : ";
		cin >> PLAN;
		while (PLAN < 0 || PLAN > 4)
		{
			cout << "Invalid number, Enter your plan number again : ";
			cin >> PLAN;
		}

		switch (PLAN)
		{
		case 1:
			this->planEconomy.push_back("ECONOMY CLASS");
			this->planPrice.push_back(7500);
			cout << endl << "{ ECONOMY CLASS } The price is : " << plan1 << " LE" << endl;
			break;
		case 2:
			this->planEconomy.push_back("PREMIUM ECONOMY CLASS");
			this->planPrice.push_back(10000);
			cout << endl << "{ PREMIUM ECONOMY CLASS } The price is : " << plan2 << " LE" << endl;
			break;
		case 3:
			this->planEconomy.push_back("BUSINESS CLASS");
			this->planPrice.push_back(15000);
			cout << endl << "{ BUSINESS CLASS } The price is : " << plan3 << " LE" << endl;
			break;
		case 4:
			this->planEconomy.push_back("FIRST CLASS");
			this->planPrice.push_back(25000);
			cout << endl << "{ FIRST CLASS } The price is : " << plan4 << " LE" << endl;
			break;
		}
	}
	else if (flightType.back() == "Round-trip")
	{
		cout << endl;
	    cout << "                 --> CHOOSE THE PLAN YOU WANT FOR ROUND-TRIP <--                 " << endl << endl << endl;
	    
	    cout << "   *********************************     *********************************   " << endl;
	    cout << "   *                               *     *                               *   " << endl;
	    cout << "   *           PLAN ( 1 )          *     *           PLAN ( 2 )          *   " << endl;
	    cout << "   *       { ECONOMY CLASS }       *     *   { PREMIUM ECONOMY CLASS }   *   " << endl;
	    cout << "   *                               *     *                               *   " << endl;
	    cout << "   *    15,000 LE   --->   300 $   *     *    20,000 LE   --->   400 $   *   " << endl;
	    cout << "   *                               *     *                               *   " << endl;
	    cout << "   *********************************     *********************************   " << endl << endl << endl;
	    
	    cout << "   *********************************     *********************************   " << endl;
	    cout << "   *                               *     *                               *   " << endl;
	    cout << "   *           PLAN ( 3 )          *     *           PLAN ( 4 )          *   " << endl;
	    cout << "   *      { BUSINESS CLASS }       *     *        { FIRST CLASS }        *   " << endl;
	    cout << "   *                               *     *                               *   " << endl;
	    cout << "   *    30,000 LE   --->   600 $   *     *    50,000 LE  --->  1,000 $   *   " << endl;
	    cout << "   *                               *     *                               *   " << endl;
	    cout << "   *********************************     *********************************   " << endl << endl << endl;

        cout << "Enter your Plan Number : ";
        cin >> PLAN;
        while (PLAN < 0 || PLAN > 4)
        {
            cout << "Invalid number, Enter your plan number again : ";
            cin >> PLAN;
        }
        
        switch (PLAN)
        {
        case 1:
            this->planEconomy.push_back("ECONOMY CLASS");
            this->planPrice.push_back(15000);
            cout << endl <<"{ ECONOMY CLASS } The price is : " << plan1 * 2 << " LE" << endl;
            break;
        case 2:
            this->planEconomy.push_back("PREMIUM ECONOMY CLASS");
            this->planPrice.push_back(20000);
            cout << endl << "{ PREMIUM ECONOMY CLASS } The price is : " << plan2 * 2 << " LE" << endl;
            break;
        case 3:
            this->planEconomy.push_back("BUSINESS CLASS");
            this->planPrice.push_back(30000);
            cout << endl << "{ BUSINESS CLASS } The price is : " << plan3 * 2 << " LE" << endl;
            break;
        case 4:
			      this->planEconomy.push_back("FIRST CLASS");
			      this->planPrice.push_back(50000);
			      cout << endl << "{ FIRST CLASS } The price is : " << plan4 * 2 << " LE" << endl;
            break;
        }
    }
}

void Client::chooseSeatPosition()
{
    int seatPosition;
    cout << endl;
    cout << "                             ----> CHOOSE THE SEAT YOU WANT <----                         " << endl << endl << endl;


    cout << "   /                                                                                  \\  " << endl;
    cout << "  /                                                                                    \\  " << endl;
    cout << "  *                                                                                     *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *   |      1      |   |      2      |      .      |      3      |   |      4      |   *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *    \\___________/     \\___________/       .       \\___________/     \\___________/    *  " << endl;
    cout << "  *                                                                                     *  " << endl;
    cout << "  *                                                                                     *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *   |      5      |   |      6      |      .      |      7      |   |      8      |   *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *    \\___________/     \\___________/       .       \\___________/     \\___________/    *  " << endl;
    cout << "  *                                                                                     *  " << endl;
    cout << "  *                                                                                     *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *   |      9      |   |      10     |      .      |      11     |   |     12      |   *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *    \\___________/     \\___________/       .       \\___________/     \\___________/    *  " << endl;
    cout << "  *                                                                                     *  " << endl;
    cout << "  *                                                                                     *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *   |      13     |   |      14     |      .      |      15     |   |     16      |   *  " << endl;
    cout << "  *   |             |   |             |      .      |             |   |             |   *  " << endl;
    cout << "  *    \\___________/     \\___________/       .       \\___________/     \\___________/    *  " << endl;
    cout << "  *                                                                                     *   " << endl;
    cout << "   \\                                                                                   /  " << endl;
    cout << "    \\                                                                                 /  " << endl << endl;

    cout << "Enter your seat position : ";
    cin >> seatPosition;

    while (seatPosition < 0 || seatPosition > 16)
    {
        cout << "SORRY, INVALID SEAT NUMBER, TRY ENTER THE SEAT NUMBER AGAIN: ";
        cin >> seatPosition;
    }
    this->seatsPosition.push_back(seatPosition);
    cout << "DONE, YOU HAVE BOOKED SEAT " << seatPosition << endl << endl;
    cout << "\n==================================== PHOENIX ====================================\n\n";
}

void Client::homePage() {

    std::cout << "================== PHOENIX AIRCRAFT TICKET RESERVATION SYSTEM ==================" << endl << endl;

    // Taking homepage choices
    std::cout << "1.Book a Ticket                       2.Manager\n\n";
    std::cout << "Your Choice: ";
    short choice;
    do {
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            new Client(true);
            break;
        case 2:
            new Manager(true);
            break;

        default:
            std::cout << "Invalid number!\n";
            std::cout << "Choose a number between (1-2) : ";
        }
    } while (choice < 1 || choice > 2);

}

void Client::printTicket() {

    cout << "******************************************************************************************************************" << endl;
    cout << "*                                               << PHOENIX TICKET >>                                             *" << endl;
    cout << "******************************************************************************************************************" << endl << endl;
    cout << "*  Name : " << name.back() << "     " << "ID: " << id.back() << "     " << "Phone Number : " << phoneNum.back();
    for (int i = 0; i < 74 - (name.back().length() + id.back().length() + phoneNum.back().length()); i++)
    {
        cout << ' ';
    }
    cout << '*' << endl << endl;
    cout << "*  From : " << fromCountry.back() << "     " << "To : " << toCountry.back() << "     " << "Seat Number: " << seatsPosition.back();
    for (int i = 0; i < 75 - (fromCountry.back().length() + toCountry.back().length() + to_string(seatsPosition.back()).length()); i++)
    {
        cout << ' ';
    }
    cout << '*' << endl << endl;
    cout << "*  Flight Type : " << flightType.back() << "     " << "Plan Economy: " << planEconomy.back() << "     " << "Plan Price: " << planPrice.back();
    for (int i = 0; i < 60 - (flightType.back().length() + planEconomy.back().length() + to_string(planPrice.back()).length()); i++)
    {
        cout << ' ';
    }
    cout << '*' << endl << endl;
    cout << "******************************************************************************************************************" << endl << endl;

}


// Static members Declaration
int Client::seatsNum = 0;


// These data needs to replace instead of discrete data
std::vector <Client::FlightData> Client::clientsData = {
    {"Ebraim", "30412011100997", "01023970103", "Emirates", "Germany", "One-way", "ECONOMY CLASS", 7500, 3},
    {"Yosef", "30509191203652", "01140772593", "Egypt", "Saudi Arabia", "Round-trip", "PREMIUM ECONOMY CLASS", 10000, 12},
    {"Mahmoud", "30512121500375", "01060063308", "America", "England", "One-way", "BUSINESS CLASS", 15000, 9},
    {"Ahmed", "30501051201918", "01018001401", "China", "Russia", "Round-trip", "FIRST CLASS", 50000, 5}
};

std::vector <std::string> Client::name = {
	"Ebrahim",
	"Yosef",
	"Mahmoud",
	"Ahmed"
};

std::vector <std::string> Client::id = {
	"30412011100997",
	"30509191203652",
	"30512121500375",
	"30501051201918"
};

std::vector <std::string> Client::phoneNum = {
	"01023970103",
	"01140772593",
	"01060063308",
	"01018001401"
};

std::vector <std::string> Client::fromCountry = {
	"Emirates",
	"Egypt",
	"America",
	"China"
};

std::vector <std::string> Client::toCountry = {
	"Germany",
	"Saudi Arabia",
	"England",
	"Russia"
};

std::vector <std::string> Client::flightType = {
	"One-way",
	"Round-trip",
	"One-way",
	"Round-trip"
};

std::vector <std::string> Client::planEconomy = {
	"ECONOMY CLASS",
	"PREMIUM ECONOMY CLASS",
	"BUSINESS CLASS",
	"FIRST CLASS"
};

std::vector <int> Client::planPrice = {
	7500,
	10000,
	15000,
	50000
};

std::vector <int> Client::seatsPosition = {
	3,
	12,
	9,
	5
};

