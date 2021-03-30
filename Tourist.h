#ifndef TOURIST_H_INCLUDED
#define TOURIST_H_INCLUDED
#include "Date.h"
#include <bits/stdc++.h>
using namespace std;

    class Tourist
    {
        //����
        string Name;
        string Surname;
        Date DateOfBirth;
        string PassportNumber;
        string CardNumber;
        string CvvCode;
        string PIN;

        //�����������
    public:
        Tourist(string name="", string surname="", Date date={0}, string passport="");

        //������
        bool CheckPersonsInfo();

        void SetCardInfo(string number, string cvv, string pin);

        bool CheckCardsInfo();

        void GetPersonsInfo();

        void GetCardsInfo();
    };


#endif // TOURIST_H_INCLUDED
