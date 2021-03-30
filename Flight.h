#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include "Date.h"
#include <bits/stdc++.h>
using namespace std;

class Flight{
    string m_StartPoint;
    string m_EndPoint;
    double m_FlightPrice;
    Date m_StartDate;
    Date m_EndDate;
    vector<bool> m_Seats;
    string m_FlightID;
public:
    Flight(string StartPoint="", string EndPoint="", double FlightPrice=0., Date StartDate = {0}, Date EndDate = {0}, string FlightID="");
    void SetSeats(string position);

    double GetPrice();

    string GetStartPoint();

    string GetEndPoint();

    int GetStartDate();

    int GetEndDate();

    string GetFlightID();
    vector<bool> GetSeats();
};


#endif // FLIGHT_H_INCLUDED
