#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include "Flight.h"
#include "Services.h"
#include "Tourist.h"
#include <bits/stdc++.h>
using namespace std;

class Ticket
    {

        //����
        vector<Flight> Way;
        double TicketPrice;
        vector<Service> IncludedServices;
        vector<Service> AdditionalServices;
        Tourist Client;
    public:
        //�����������
        Ticket(vector<Flight> flights);

        //������
        void PrintTicket();

        void PrintServices();

        void ChooseService(int numberOfService);


        void AddFlight();
        double GetPrice();
    };



#endif // TICKET_H_INCLUDED
