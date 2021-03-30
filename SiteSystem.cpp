#include "SiteSystem.h"

SiteSystem::SiteSystem() {
	cout << "Hello, friend, on our air company website!\n";
}

SiteSystem::~SiteSystem() {
	cout << "Goodbye! Have a great day! :)";
}


void SiteSystem::ReadWayInfo() {
	string start_point, end_point;
	cout << "Enter start point please: ";
	getline(cin, start_point);
	cout << "Enter end point please: ";
	getline(cin, end_point);
	vector<vector<Flight>> available = AvailableFlights(start_point, end_point);

	if ( !available.size()) {
		cout << "There are no ways! Type in other start and end points( and time)" << endl;
		ReadWayInfo();
		//exit(0);//����� ���������� ����������� �����������
	}else{
        ChooseFlights(available, start_point, end_point);
	}
}

void SiteSystem::ReadPersonsInfo() {
	Tourist t;
	string name, surname, passport;
	int age = 0;
	cout << "Enter name please: ";
	cin >> name;
	cout << "Enter surname please: ";
	cin >> surname;
	cout << "Enter age please: ";
	cin >> age;
	while (age < 18) {
		cout << "Illegal age! Re-enter it, please: ";
		cin >> age;
	}
	cout << "Enter passport number please: ";
	cin >> passport;
  	while (passport.size() != 10) {
    	cout << "CVV must have size 10! \n";
    	cin >> passport;
  	}
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
        for(int j=1; j<available[i].size(); j++){
            cout << "\\" << available[i][j].GetFlightID();
        }
        cout << "\n*********************************************************************************" << endl;
    }
    int type=0;
    cout << "Type in number of way which you need: ";
    cin >> type;
    ticket = Ticket(available[type]);
}


void SiteSystem::PrintFlights() {
	vector<Flight> TicketFlights;
	//TicketFlights = ticket.GetAllFlights();
	int i = 1;
	for (const auto& flight : TicketFlights) {
		cout << i++ << ". ";
		//flight.PrintFlight();
	}
}

void SiteSystem::ChooseServices() {
	//potom
}
