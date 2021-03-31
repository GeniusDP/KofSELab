#include "Ticket.h"
#include "Flight.h"
#include "Services.h"

        Ticket::Ticket(vector<Flight> flights = vector<Flight>(0), vector<string> avaliableSeats = vector<string>(0) )
        {
            for(int i=0; i<avaliableSeats.size(); i++){
                ofstream out("DataBase\\" + flights[i].GetFlightID() + ".txt", ios_base::app);
                out << avaliableSeats[i] << endl;
            }

            //cout << "Ticket is done!";
            Way = flights;
            SeatsInPlane = avaliableSeats;
            TicketPrice = 0;
            for(Flight flight: Way)
            {
                TicketPrice += flight.GetPrice();
            }
        }
        void Ticket::PrintTicket()
        {
            cout << "Way:\n";
            for (int i = 0; i < Way.size(); i++)
            {
                cout << Way[i].GetStartPoint() << " -> ";
            }
            cout << Way[Way.size()-1].GetEndPoint() << endl;
            cout << "Start Time: " << Way[0].GetStartDate() << endl;
            cout << "Arrival Time: " << Way[Way.size()-1].GetEndDate() << endl;
            cout << "Price: " << TicketPrice << " USD." << endl;
        }

        void Ticket::PrintServices()
        {
            cout << "ֳTicket Price: " << TicketPrice << " USD." << endl;
            cout << "Included Services:" << endl;
            for(Service service: IncludedServices)
            {
                cout << "- " << service.PrintService() << endl;
            }

            cout << "Additional Services:" << endl;
            for(Service service: AdditionalServices)
            {
                cout << "- " << service.PrintService()+" : " << service.PrintService() << " USD." << endl;
            }

        }

        void Ticket::ChooseService(int numberOfService)
        {
            IncludedServices.push_back(AdditionalServices[numberOfService]);
            TicketPrice += AdditionalServices[numberOfService].GetPrice();
            AdditionalServices.erase(AdditionalServices.begin() + numberOfService);
        }

        void Ticket::SetServices(vector<Service> ServicesToAdd) {
            IncludedServices = ServicesToAdd;
            for (Service& x : ServicesToAdd) {
                TicketPrice += x.GetPrice();
            }
        }

        void Ticket::AddFlight(){};

        double Ticket::GetPrice()
        {
            return TicketPrice;
        }
