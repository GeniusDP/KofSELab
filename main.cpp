#include <bits/stdc++.h>
using namespace std;
#include "Tourist.h"//works
#include "Date.h"//works
#include "Ticket.h"//works
#include "SiteSystem.h"//works
#include "DataBase.h"//works
#include "Services.h"//works
#include "Flight.h"//works



int main()
{
    SiteSystem site;
    site.ReadWayInfo();
    site.ReadPersonsInfo();
    site.ChooseServices();
    site.ReadCardsInfo();
    return 0;
}
