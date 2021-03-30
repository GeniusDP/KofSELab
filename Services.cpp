#include "Services.h"

Service::Service(string new_name, double new_cost) {
    name = new_name;
    cost = new_cost;
}

string Service::PrintService() {
    return name;
}

double Service:: GetPrice(){
    return cost;
}
