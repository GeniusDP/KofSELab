#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "Date.h"
#include "Flight.h"
#include "Services.h"
#include "Ticket.h"
#include "Tourist.h"
#include "Services.h"
#include <bits/stdc++.h>
using namespace std;


class DataBase {
private:
	vector<Flight> flights;
	vector<Service> services;
	vector<Tourist> tourists;
	vector<Ticket> tickets;
public:
	DataBase();
	~DataBase();
	vector<Service> GetServices();
	void FindFlights(vector< vector<Flight> >& ways, string curVertox, string finish, vector<Flight> curWayParm = vector<Flight>(0),  vector<bool> usedParm = vector<bool>(100, false));
	vector<Flight> GetAllFlights(); //new, needed it af
};


#endif // DATABASE_H_INCLUDED
