#ifndef SITESYSTEM_H_INCLUDED
#define SITESYSTEM_H_INCLUDED
#include <bits/stdc++.h>
#include "Ticket.h"
#include "Tourist.h"
#include "Flight.h"
#include "DataBase.h"

using namespace std;
//void OpenSite();

class SiteSystem {
private:
	DataBase data;
	Ticket ticket();
	Tourist client;
public:
	SiteSystem();
	~SiteSystem();
	void ReadWayInfo();
	void ReadPersonsInfo();
	void ReadCardsInfo();
	void ChooseServices();
	vector< vector<Flight> > AvailableFlights(string start, string finish);
	void PrintFlights();
	void ChooseFlights(string st, string fn);
	void ReadInfoForTicket(); // ?
	void ChooseSeat();        // ?
};


#endif // SITESYSTEM_H_INCLUDED
