using System;
using System.Collections.Generic;

namespace kpi
{
    public class Ticket
    {
        //поля
        private List<Flight> Way;
        private double TicketPrice;
        private List<Service> IncludedServices;
        private List<Service> AdditionalServices;
        private Tourist Client;

        //конструктор
        public Ticket(List<Flight> flights)
        {
            Way = flights;
            TicketPrice = 0;
            foreach (var flight in Way)
            {
                TicketPrice += flight.FlightPrice;
            }
        }

        //методи
        public void PrintTicket()
        {
            Console.Write("Шлях:");
            for (int i = 0; i < Way.Count-1; i++)
            {
                Console.Write(Way[i].StartPoint+" -> ");
            }
            Console.WriteLine(Way[Way.Count-1].EndPoint);
            Console.WriteLine("Початкова дата: "+Way[0].startDate);
            Console.WriteLine("Кінцева дата: "+Way[0].endDate);
            Console.WriteLine("Цінa: "+TicketPrice+" грн.");
        }

        public void PrintServices()
        {
            Console.WriteLine("Цінa квитка: "+TicketPrice+" грн.");
            Console.WriteLine("Включені послуги:");
            foreach (var service in IncludedServices)
            {
                Console.WriteLine("- "+service.NameOfService);
            }
            
            Console.WriteLine("Додаткові послуги:");
            foreach (var service in AdditionalServices)
            {
                Console.WriteLine("- "+service.NameOfService+" : "+service.ServicePrice+" грн.");
            }
            
        }
        public void ChooseService(int numberOfService)
        {
            IncludedServices.Add(AdditionalServices[numberOfService]);
            TicketPrice += AdditionalServices[numberOfService].ServicePrice;
            AdditionalServices.Remove(AdditionalServices[numberOfService]);
        }
        
        public void AddFlight(){}

        public double GetPrice()
        {
            return TicketPrice;
        }
    }
}