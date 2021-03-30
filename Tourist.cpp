#include "Tourist.h"



        Tourist::Tourist(string name, string surname, Date date, string passport)
        {
            Name = name;
            Surname = surname;
            DateOfBirth = date;
            PassportNumber = passport;
        }



        bool Tourist::CheckPersonsInfo()
        {
            //if(DateOfBirth >= Date.seconds) return false;
            for(char c: Name)
            {
                if( !isalpha(c) ) return false;
            }
            for(char c: Surname)
            {
                if( !isalpha(c) ) return false;
            }
            if (PassportNumber.size() != 9) return false;
            return true;
        }


        void  Tourist::SetCardInfo(string number, string cvv, string pin)
        {
            CardNumber = number;
            CvvCode = cvv;
            PIN = pin;
        }

        bool Tourist::CheckCardsInfo()
        {
            if (CvvCode.size()!=3) return false;
            if (PIN.size() != 4) return false;
            if (CardNumber.size() != 16) return false;
            return true;
        }


        void Tourist::GetPersonsInfo() //нафіга?
        {
            cout << "Ім'я: "+Name << endl;
            cout << "Прізвище: "+Surname << endl;
            cout << "Дата народження: "+DateOfBirth.seconds << endl;
            cout << "Номер паспорту: "+PassportNumber << endl;
        }


        void Tourist::GetCardsInfo() //нафіга?
        {
            cout << "Номер картки: "+CardNumber << endl;
            cout << "Сvv код: "+CvvCode << endl;
            cout << "Пароль: "+PIN << endl;
        }
