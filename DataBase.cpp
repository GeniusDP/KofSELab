#include "DataBase.h"


DataBase::DataBase() {
	ifstream FlightFile("DataBase\\Flights.txt"), ServicesFile("DataBase\\Services.txt");
	while (FlightFile) {
		string st, fn;
		double cst;
		Date startTime, endTime;
		string ID;
		FlightFile >> st >> fn >> cst >> startTime.seconds >> endTime.seconds >> ID;
		flights.push_back(Flight(st, fn, cst, startTime, endTime, ID));
	}
	while (ServicesFile) {
		double cst;
		string serv;
		ServicesFile >> cst;
		getline(ServicesFile, serv);
		services.push_back({ serv, cst });
	}
}

DataBase::~DataBase() {
//	ofstream TouristsFile("DataBase\\Tourists.txt", ios::app), TicketsFile("DataBase\\Tickets.txt", ios::app);
//	for (auto& t : tourists) {
//		TouristsFile << t.Get() << '\n';
//	}
//	for (auto& t : tickets) {
//		TicketsFile << t.Get() << '\n';
//	}
}


vector<Service> DataBase::GetServices() {
	return services;
}

vector<Flight> DataBase::GetAllFlights() {
	return flights;
}



void DataBase::FindFlights(vector< vector<Flight> >& ways, string curVertox, string finish, vector<Flight> curWayParm,  vector<bool> usedParm){
    vector<bool> used = usedParm;//создание копий параметров
    vector<Flight> curWay = curWayParm;

    if(curVertox == finish){//запись в ways нового маршрута
        ways.push_back(curWay);
    }else{
        for(int i=0; i<flights.size(); i++){
            if( curWay.empty() || (!used[i] && curWay[curWay.size()-1].GetEndDate() <= flights[i].GetStartDate() && flights[i].GetStartPoint() == curVertox) ){
                if( curWay.empty() ){
                    if( flights[i].GetStartPoint() == curVertox ){//если начинаем строить путь, то должны начать именно со стартовой вершины
                        used[i] = true;
                        curWay.push_back(flights[i]);

                        FindFlights(ways, flights[i].GetEndPoint(), finish, curWay, used);

                        curWay.erase(curWay.end()-1);
                        used[i] = false;
                    }
                }else{
                    used[i] = true;
                    curWay.push_back(flights[i]);

                    FindFlights(ways, flights[i].GetEndPoint(), finish, curWay, used);

                    curWay.erase(curWay.end()-1);
                    used[i] = false;
                }
            }
        }

    }//else заглушки
}
