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
    site.ReadWayInfo();system("cls");
    site.ReadPersonsInfo();system("cls");
    site.ChooseServices();system("cls");
    site.ReadCardsInfo();system("cls");
    return 0;
}
