#include "SiteSystem.h"
#include <windows.h>
SiteSystem::SiteSystem() {
	cout << "Hello, friend, on our air company website!\n";
}

//Ends work of the program
//Starts puting info into file Ticket.txt
SiteSystem::~SiteSystem() {
    cout << "Show your ticket:\n";
    ticket.PrintTicket();
	cout << "Goodbye! Have a great day! :)";
}


void SiteSystem::ReadWayInfo() {//reads info about way from console
	string start_point, end_point;
	cout << "Enter start point please: ";
	getline(cin, start_point);
	cout << "Enter end point please: ";
	getline(cin, end_point);
	//gets from Database all ways which are available
	vector<vector<Flight>> available = AvailableFlights(start_point, end_point);

	if ( !available.size()) {
		cout << "There are no ways! Type in other start and end points" << endl;
		ReadWayInfo();
	}else{
        ChooseFlights(available, start_point, end_point);
	}
}

void SiteSystem::ReadPersonsInfo() {//read from console and writes into file
	ofstream out("DataBase\\Tickets.txt", ios_base::app);
	Tourist t;
	string name, surname, passport;
	int age = 0;
	cout << "Enter name please: ";
	cin >> name;
	cout << "Enter surname please: ";
	cin >> surname;
	cout << "Enter age please: ";
	cin >> age;
	cout << "Enter passport number please: ";
	cin >> passport;
	client = Tourist(name, surname, {age}, passport);
  	while ( !client.CheckPersonsInfo() ) {
        cout << "Enter name please: ";
        cin >> name;
        cout << "Enter surname please: ";
        cin >> surname;
        cout << "Enter age please: ";
        cin >> age;
        cout << "Enter passport number please: ";
    	cin >> passport;
    	client = Tourist(name, surname, {age}, passport);
  	}
  	out << "Name: " << name << endl;
  	out << "Surname: " << surname << endl;
  	out << "Age: " << age << endl;
  	out << "Passport: " << passport << endl;
  	cout << "Done!\n";
}

void SiteSystem::ReadCardsInfo() {
	string card, cvv, pin;
	cout << "Enter card please: ";
	cin >> card;
	cout << "Enter CVV please: ";
	cin >> cvv;
	cout << "Enter PIN please: ";
	cin >> pin;
	client.SetCardInfo(card, cvv, pin);
	while (!client.CheckCardsInfo()) {
		cout << "Card is not in right format! Rewrite! \n";
		cout << "Enter card please: ";
        cin >> card;
        cout << "Enter CVV please: ";
        cin >> cvv;
        cout << "Enter PIN please: ";
        cin >> pin;
        client.SetCardInfo(card, cvv, pin);
	}
	cout << "Checking data!...\n";
	//Sleep(2000);
	cout << "Done!\n";
	client.GetPersonsInfo();
}

vector< vector<Flight> > SiteSystem::AvailableFlights(string start, string finish) {
	vector< vector<Flight> > v;
	data.FindFlights(v, start, finish);
	return v;
}

//interface of choosing way
//suggests all flights and client has to choose one of them
void SiteSystem::ChooseFlights(vector< vector<Flight> > available, string st, string fn) {
    for(int i=0; i<available.size(); i++){
        int summaryPrice = 0;
        cout << i << ".)"<< available[i][0].GetStartPoint();
        for(int j=0; j<available[i].size(); j++){
            cout << " -> " << available[i][j].GetEndPoint();
            summaryPrice += available[i][j].GetPrice();
        }
        cout << "| Take-off time = " << available[i][0].GetStartDate() << "| Arrival time = " << available[i][available[i].size()-1].GetEndDate();
        cout << "\n| price = " << summaryPrice << "\n| ID:";
        cout << available[i][0].GetFlightID();
        for(int j=1; j<available[i].size(); j++){//prints IDs of all flights
            cout << "\\" << available[i][j].GetFlightID();
        }
        cout << "\n*********************************************************************************" << endl;
    }
    int type=0;
    cout << "Type in number of way which you need: ";
    cin >> type;//choosing the way


    ticket = Ticket(available[type], ChooseSeat(available[type]));
}


void SiteSystem::PrintFlights() {
	vector<Flight> TicketFlights;
	int i = 1;
	for (const auto& flight : TicketFlights) {
		cout << i++ << ". ";
	}
}

void SiteSystem::ChooseServices() {
	//potom
	vector<Service> services = data.GetServices();
	for (int i=0; i<services.size(); i++) {
		cout << i + 1 << ". " << services[i].PrintService() << " | " << services[i].GetPrice() << '\n';
	}
	vector<Service> choosen;
	cout << "Enter position of service or 0 if you want to exit \n";
	int num = 1;
	while (num) {
		cin >> num;
		if (num != 0) {
			if (num <= services.size() && num >= 1) choosen.push_back(services[num - 1]);
			else cout << "Enter correct number please!\n";
		}
	}
	ticket.SetServices(choosen);
	cout << "Done!\n";
}


vector<string> SiteSystem::ChooseSeat(vector< Flight > available){
    vector<string> seats(available.size());
    cout << "Choose the seat for each flight:\n";
    for(int i=0; i<available.size(); i++){
        cout << "******Flight " << i << ": from " << available[i].GetStartPoint() << " to " << available[i].GetEndPoint() << endl;
        vector<bool> avalSeats = available[i].GetSeats();
        for(int j=0; j<('F'-'A'+1)*5; j++){
            if( avalSeats[j] )cout << char(j/6+'A') << char(j%6+'1') << " | ";
        }
        cout << endl;
        string myseat; cin >> myseat;
        while( myseat.size()!=2 || !avalSeats[(myseat[0]-'A')*6 + myseat[1]-'1'] ){
            cout << "This seat is not available!\n";
            cin >> myseat;
        }
        seats[i] = myseat;
    }
    return seats;
}


//������� README
void SiteSystem::StartInfo() {
    //setlocale(LC_ALL, "russian");
    setlocale (LC_ALL, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Do you want to see instructions for use? (y/n) \n";
    char ch;
    cin >> ch;
    while (ch != 'y' && ch != 'n') {
        cout << "Enter y or n please!\n";
        cin >> ch;
    }
    if (ch == 'y') {
        cout << "³���� �� ������ ����, ������������ ��� ���������� ���������. ��� �������� ���������� ������� ��������� �����������: \n \
1.  ��� ���� �� ���� ��� ���������� ��������� �������, �� ��� ��������� ������ ����� ������ ��������� ����� �� ��������� ������ Enter �� ��������. ���� ��������� ������ ����� ������ ������ ����� �� ����� �������� Enter �� ��������. \n \
2.  ϳ��� ���������� ������������ ����� ������� ����� ������ ��� �� ������ ���������, �� ����� ����������� �� �� �������� ��� �������� ���� ����� �� ������������ ����� (����� ��������� � ������ ����� ���������). ���� � ����� ������ �� ����,  �� ���� ��������� ��� �������� ��������� ���� �� ���. ������� �����, �� ���� ���� ������ ����� ����� ������. �� ������� ������ ������������ ( ����� ��� ������� ������ ������ �����, ������� ���������� � 0). ��� ������ ������ ������ ���� ����� �� �������� Enter �� ��������. \n \
3.  ��� ������� ������ ������� ���� �� ������ ���� (���� �������� ���� ��� ������). ��� ������ ���� ������ ������ ���� �����, ���������, ��5� (��� �����). �������� Enter. �������� �� 䳿 ��� ��� �����, �� ������� � ���� ������ ������. \n \
4.  ϳ��� ���������� ������������ ����� ���������� ������� ��������� ��� ������ ������� ��� � ������ �������: ���, �������, �� (�� ���� ����� 18 ����) �� ����� �������� (������� ������, ������� ���� �� ���������� 9). ϳ��� ������� �������� ������ ���������� Enter. \n \
5.  ��� ��� �� ���� ������ ����������� �������� ������� � �� �������. ������ ������ ���������� ��� ���������� ������ ����� ����� (����� ������� �������� ����� �� ������). ���� �� �������� �� �������� �������, �� ������ ������ 0, ��� ��������� ��� ����. \n \
6.  ����� ��� ��������� �������� ������. ��������� �� ����� 4 ������� ��������� � ��� ��� ������ � ������ �������: ����� ������(16 ����), �VV-��� (3 �����) �� PIN-��� (4 �����). ϳ��� ������� �������� ������ ���������� Enter. \n \
7.  ���� ������� ������ ��� ��� ���������� ������. ��� ����� � ����� �������� ���� ������. \n \
�����, �� ������� ��� ����. ��������� �������! \n";
    }
    else {
        cout << "Ok!";
    }
    cout << "\nPress enter please:";
    string enter;
    cin.ignore(1);
    getline(cin, enter);
    system("cls");
}
