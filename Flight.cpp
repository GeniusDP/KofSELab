#include "Flight.h"

double Flight::GetPrice(){
    return m_FlightPrice;
}

string Flight::GetEndPoint(){
    return m_EndPoint;
}

string Flight::GetStartPoint(){
    return m_StartPoint;
}

int Flight::GetStartDate(){
    return m_StartDate.seconds;
}

vector<bool> Flight::GetSeats(){
    return m_Seats;
}

int Flight::GetEndDate(){
    return m_EndDate.seconds;
}

Flight::Flight(string StartPoint, string EndPoint, double FlightPrice, Date StartDate, Date EndDate, string FlightID){
    m_FlightID = FlightID;
    m_StartPoint = StartPoint;
    m_EndPoint = EndPoint;
    m_FlightPrice = FlightPrice;
    m_StartDate = {StartDate};
    m_EndDate = {EndDate};
    m_Seats.resize( ( ('F'-'A') + 1)*( (5-1) + 1) );
}

void Flight::SetSeats(string position){
    int row;
    int positionInRow;
    row = position[0]-'A';//[0..5]
    positionInRow = position[1]-'1';//[0..4]
    if( row>=0 && row<=5 && positionInRow>=0 && positionInRow<=4 ){
        m_Seats[row*6 + positionInRow] = true;//have reserved a place
    }else{
        cout << "!!!!!!!!!!| ~ Cannot set a seat: wrong position! ~ |!!!!!!!!!!";
    }
}

