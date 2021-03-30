#include "Ticket.h"
#include "Flight.h"
#include "Services.h"

        Ticket::Ticket(vector<Flight> flights = vector<Flight>(0))
        {
            //cout << "Ticket is done!";
            Way = flights;
            TicketPrice = 0;
            for(Flight flight: Way)
            {
                TicketPrice += flight.GetPrice();
            }
        }
        void Ticket::PrintTicket()
        {
            cout << "Шлях:\n";
            for (int i = 0; i < Way.size()-1; i++)
            {
                cout << Way[i].GetStartPoint()+" -> ";
            }
            cout << Way[Way.size()-1].GetStartPoint() << endl;
            cout << "Початкова дата: " + Way[0].GetStartDate() << endl;
            cout << "Кінцева дата: " + Way[0].GetEndDate() << endl;
            cout << "Цінa: " << TicketPrice << " грн." << endl;
        }

        void Ticket::PrintServices()
        {
            cout << "Цінa квитка: " << TicketPrice << " грн." << endl;
            cout << "Включені послуги:" << endl;
            for(Service service: IncludedServices)
            {
                cout << "- " << service.PrintService() << endl;
            }

            cout << "Додаткові послуги:" << endl;
            for(Service service: IncludedServices)
            {
                cout << "- " << service.PrintService()+" : " << service.PrintService() << " грн." << endl;
            }

        }

        void Ticket::ChooseService(int numberOfService)
        {
            IncludedServices.push_back(AdditionalServices[numberOfService]);
            TicketPrice += AdditionalServices[numberOfService].GetPrice();
            AdditionalServices.erase(AdditionalServices.begin() + numberOfService);
        }


        void Ticket::AddFlight(){};

        double Ticket::GetPrice()
        {
            return TicketPrice;
        }
