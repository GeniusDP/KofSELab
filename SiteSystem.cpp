#include "SiteSystem.h"

SiteSystem::SiteSystem() {
	cout << "Hello, friend, on our air company website!\n";
}

SiteSystem::~SiteSystem() {
	cout << "Goodbye! Have a great day! :)";
}


void SiteSystem::ReadWayInfo() {
	string start_point, end_point;
	cout << "Enter start point please: ";
	getline(cin, start_point);
	cout << "Enter end point please: ";
	getline(cin, end_point);
	vector<vector<Flight>> available = AvailableFlights(start_point, end_point);
	if (available.size() > 0) {
		cout << "choose";
	}
}

void SiteSystem::ReadPersonsInfo() {
	Tourist t;
	string name, surname;
	int age = 0;
	cout << "Enter name please: ";
	cin >> name;
	cout << "Enter surname please: ";
	cin >> surname;
	cout << "Enter age please: ";
	cin >> age;
	while (age < 18) {
		cout << "Illegal age! Re-enter it, please: ";
		cin >> age;
	}
	cout << "Done!\n";
	//client.SetPersonalInfo(name, surname, age);
	client = Tourist(name, surname, {age}, "");
}

void SiteSystem::ReadCardsInfo() {
	string card, cvv, pin;
	cout << "Enter card please: ";
	cin >> card;
	while (card.size() != 16) {
		cout << "Card must have size 16! \n";
		getline(cin, card);
	}
	cout << "Enter cvv please: ";
	cin >> cvv;
	while (cvv.size() != 3) {
		cout << "CVV must have size 3! \n";
		cin >> cvv;
	}
	cout << "Enter cvv please: ";
	cin >> pin;
	while (cvv.size() != 3) {
		cout << "CVV must have size 3! \n";
		cin >> cvv;
	}
	cout << "Checking data!...\n";
	//Sleep(2000);
	cout << "Done!\n";
	client.SetCardInfo(card, cvv, pin);
}

vector< vector<Flight> > SiteSystem::AvailableFlights(string start, string finish) {
	vector<vector<Flight>> v;
	data.FindFlights(v, start, finish);
	return v;
}

void SiteSystem::ChooseFlights(string st, string fn) {
	vector< vector<Flight> > available = AvailableFlights(st, fn);
}


void SiteSystem::PrintFlights() {
	vector<Flight> TicketFlights;
	//TicketFlights = ticket.GetAllFlights();
	int i = 1;
	for (const auto& flight : TicketFlights) {
		cout << i++ << ". ";
		//flight.PrintFlight();
	}
}

void SiteSystem::ChooseServices() {
	//potom
}
