#include "DataBase.h"


DataBase::DataBase() {
	ifstream FlightFile("DataBase\\Flights.txt"), ServicesFile("DataBase\\Services.txt");
	int cnt=0;
	while (FlightFile) {
        cnt++;
		string st, fn;
		double cst;
		Date startTime, endTime;
		string ID;
		FlightFile >> st >> fn >> cst >> startTime.seconds >> endTime.seconds >> ID;
		flights.push_back(Flight(st, fn, cst, startTime, endTime, ID));

	}
	double cst;
	string serv;
	while (ServicesFile >> cst && getline(ServicesFile, serv)) {
		services.push_back(Service(serv, cst));
	}
	//tourists.push_back(Tourist());
}

DataBase::~DataBase() {
    //ofstream outFile(tour);
}


vector<Service> DataBase::GetServices() {
	return services;
}

vector<Flight> DataBase::GetAllFlights() {
	return flights;
}



void DataBase::FindFlights(vector< vector<Flight> >& ways, string curVertox, string finish, vector<Flight> curWayParm,  vector<bool> usedParm){
    vector<bool> used = usedParm;//�������� ����� ����������
    vector<Flight> curWay = curWayParm;

    if(curVertox == finish){//������ � ways ������ ��������
        ways.push_back(curWay);
    }else{
        for(int i=0; i<flights.size(); i++){
            if( curWay.empty() || (!used[i] && curWay[curWay.size()-1].GetEndDate() <= flights[i].GetStartDate() && flights[i].GetStartPoint() == curVertox) ){
                if( curWay.empty() ){
                    if( flights[i].GetStartPoint() == curVertox ){//���� �������� ������� ����, �� ������ ������ ������ �� ��������� �������
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

    }//else ��������
}
