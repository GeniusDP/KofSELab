#ifndef SERVICES_H_INCLUDED
#define SERVICES_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class Service {
private:
    string name;
    double cost;
public:
    Service(string new_name, double new_cost);
    string PrintService();
    double GetPrice();
};

#endif // SERVICES_H_INCLUDED
