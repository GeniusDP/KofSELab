#include "SiteSystem.h"

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
	cin >> name; out << "Name: " << name << endl;
	cout << "Enter surname please: ";
	cin >> surname; out << "Surname: " << surname << endl;
	cout << "Enter age please: ";
	cin >> age;
	while (age < 18) {
		cout << "Illegal age! Re-enter it, please: ";
		cin >> age;
	}
    out << "Age: " << age << endl;
	cout << "Enter passport number please: ";
	cin >> passport;
  	while (passport.size() != 10) {
    	cout << "Passport must have size 10! \n";
    	cin >> passport;
  	}
  	out << "Passport: " << passport << endl;
  	//out << "----------------------------------------------------------\n";
  	cout << "Done!\n";
  	client = Tourist(name, surname, {age}, passport);
	//client.GetPersonsInfo();
}

void SiteSystem::ReadCardsInfo() {
	string card, cvv, pin;
	cout << "Enter card please: ";
	cin >> card;
	while (card.size() != 16) {
		cout << "Card must have size 16! \n";
		getline(cin, card);
	}
	cout << "Enter CVV please: ";
	cin >> cvv;
	while (cvv.size() != 3) {
		cout << "CVV must have size 3! \n";
		cin >> cvv;
	}
	cout << "Enter PIN please: ";
	cin >> pin;
	while (pin.size() != 4) {
		cout << "PIN must have size 3! \n";
		cin >> pin;
	}
	cout << "Checking data!...\n";
	//Sleep(2000);
	cout << "Done!\n";
	client.SetCardInfo(card, cvv, pin);
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

    //choosing seats(from available) to
    vector<string> seats(available[type].size());
    cout << "Choose the seat for each flight:\n";
    for(int i=0; i<available[type].size(); i++){
        cout << "******Flight " << i << ": from " << available[type][i].GetStartPoint() << " to " << available[type][i].GetEndPoint() << endl;
        vector<bool> avalSeats = available[type][i].GetSeats();
        for(int j=0; j<('F'-'A'+1)*5; j++){
            if( avalSeats[j] )cout << char(j/6+'A') << char(j%6+'1') << " | ";
        }
        cout << endl;
        string myseat; cin >> myseat;
        while( myseat.size()!=2 || !avalSeats[(myseat[0]-'A')*6 + myseat[1]-'1'] ){
            cout << "This seat is not avaliable!";
            cin >> myseat;
        }
        seats[i] = myseat;
    }
    ticket = Ticket(available[type], seats);
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


void ChooseSeat(){



}
