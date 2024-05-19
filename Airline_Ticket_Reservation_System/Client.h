#pragma once
#include<iostream>
#include<vector>

class Client
{

public:

	struct FlightData
	{
		std::string name;
		std::string id;
		std::string phoneNum;
		std::string fromCountry;
		std::string toCountry;
		std::string flightType; // Round-trip or One-way ticket
		std::string planEconomy;
		int planPrice;
		int seatPosition;
	};


protected:

	static int seatsNum;
	static std::vector <std::string> name;
	static std::vector <std::string> id;
	static std::vector <std::string> phoneNum; // string -> regex -> 11 number

	std::string availableCountries[10] = {
		"Emirates", "America", "England", "Brazil", "China",
		"France", "Egypt", "Saudi Arabia", "Germany", "Russia"
	};

	static std::vector <std::string> fromCountry;
	static std::vector <std::string> toCountry;
	static std::vector <std::string> flightType; // Round-trip or One-way ticket
	static std::vector <std::string> planEconomy;
	static std::vector <int> planPrice;
	static std::vector <int> seatsPosition;
	
	

	static std::vector <FlightData> clientsData;

public:
	
	// Constructors
	Client();
	Client(bool takeData);

	// Home Page
	static void homePage();

	// Setters
	int chooseSeatsNum();
	void setName();
	void setID();
	void setPhoneNum();
	void setFromCountry();
	void setToCountry();
	void setFlightType();
	void setPlan();
	void chooseSeatPosition();

	void printTicket();




	// Functions
	



};








