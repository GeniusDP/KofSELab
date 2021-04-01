#include "Ticket.h"
#include "Flight.h"
#include "Services.h"
        //puts info about just getted seats in flights into file <ID>.txt
        //And creates ticket
        Ticket::Ticket(vector<Flight> flights = vector<Flight>(0), vector<string> reservedSeats = vector<string>(0) )
        {
            for(int i=0; i<reservedSeats.size(); i++){
                ofstream out("DataBase\\" + flights[i].GetFlightID() + ".txt", ios_base::app);
                out << reservedSeats[i] << endl;
            }

            //cout << "Ticket is done!";
            Way = flights;
            SeatsInPlane = reservedSeats;
            TicketPrice = 0;
            for(Flight flight: Way)
            {
                TicketPrice += flight.GetPrice();
            }
        }
        //printing info about ticket onto console and writing into file Ticket.txt
        void Ticket::PrintTicket()
        {
            ofstream out("DataBase\\Tickets.txt", ios_base::app);
            cout << "-----------------------------------------------------\n";
                out << "-----------------------------------------------------\n";
            cout << "Way:\n";
                out << "Way:\n";
            for (int i = 0; i < Way.size(); i++)
            {
                cout << Way[i].GetStartPoint() << " -> ";
                    out << Way[i].GetStartPoint() << " -> ";
            }
            cout << Way[Way.size()-1].GetEndPoint() << endl;
            cout << "Start Time: " << Way[0].GetStartDate() << endl;
            cout << "Arrival Time: " << Way[Way.size()-1].GetEndDate() << endl;
            //cout << "Price: " << TicketPrice << " USD." << endl;
            cout << "-----------------------------------------------------\n";

                out << Way[Way.size()-1].GetEndPoint() << endl;
                out << "Start Time: " << Way[0].GetStartDate() << endl;
                out << "Arrival Time: " << Way[Way.size()-1].GetEndDate() << endl;
                //out << "Price: " << TicketPrice << " USD." << endl;
                out << "-----------------------------------------------------\n";
            out.close();
            PrintServices();
        }
        //used in PrintTicket(). Also writes info into file Ticket.txt
        void Ticket::PrintServices()
        {
            ofstream out("DataBase\\Tickets.txt", ios_base::app);
            cout << "Ticket Price: " << TicketPrice << " USD." << endl;
            cout << "Included Services:" << endl;
                    out << "Ticket Price: " << TicketPrice << " USD." << endl;
                    out << "Included Services:" << endl;
            for(Service service: IncludedServices)
            {
                cout << "- " << service.PrintService() << endl;
                    out << "- " << service.PrintService() << endl;
            }
            cout << "-----------------------------------------------------\n";
                out << "*****************************************************************************************\n";

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
