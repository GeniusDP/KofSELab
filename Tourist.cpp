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


        void Tourist::GetPersonsInfo() //������?
        {
            cout << "��'�: "+Name << endl;
            cout << "�������: "+Surname << endl;
            cout << "���� ����������: "+DateOfBirth.seconds << endl;
            cout << "����� ��������: "+PassportNumber << endl;
        }


        void Tourist::GetCardsInfo() //������?
        {
            cout << "����� ������: "+CardNumber << endl;
            cout << "�vv ���: "+CvvCode << endl;
            cout << "������: "+PIN << endl;
        }
