#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include "Flight.h"
#include "Services.h"
#include "Tourist.h"
#include <bits/stdc++.h>
using namespace std;

    class Ticket
    {
        vector<Flight> Way;
        vector<string> SeatsInPlane;
        double TicketPrice;

        vector<Service> AdditionalServices;
        Tourist Client;
    public:
        vector<Service> IncludedServices;
        Ticket(){}

        //puts info about just getted seats in flights into file <ID>.txt and creates ticket
        Ticket(vector<Flight> flights, vector<string> avaliableSeats);

        void PrintTicket();//printing info about ticket onto console and writing into file Ticket.txt

        void PrintServices();//used in PrintTicket(). Also writes info into file Ticket.txt

        void ChooseService(int numberOfService);
        void SetServices(vector<Service> ServicesToAdd);

        void AddFlight();
        double GetPrice();
    };



#endif // TICKET_H_INCLUDED
