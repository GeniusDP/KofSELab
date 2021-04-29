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
            for(char c: Name)
            {
                if( !isalpha(c) ){
                    cout << "Illegal name! \n";
                    return false;
                }
            }
            for(char c: Surname)
            {
                if( !isalpha(c) ){
                    cout << "Illegal surname! \n";
                    return false;
                }
            }
            if (PassportNumber.size() != 9){
                cout << "Passport must have size 9! \n";
                return false;
            }

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
            if (CvvCode.size()!=3){
                cout << "CVV is not in right format!\n";
                return false;
            }
            if (PIN.size() != 4){
                cout << "CVV is not in right format!\n";
                return false;
            }
            if (CardNumber.size() != 16){
                cout << "CVV is not in right format!\n";
                return false;
            }
            return true;
        }


        void Tourist::GetPersonsInfo()
        {
            cout << "Name: " << Name << endl;
            cout << "Surname: " << Surname << endl;
            cout << "Age: " << DateOfBirth.seconds << endl;
            cout << "Passport number: " << PassportNumber << endl;
        }


        void Tourist::GetCardsInfo()
        {
            cout << "Card number: " << CardNumber << endl;
            cout << "Ñvv-code: " << CvvCode << endl;
            cout << "Password: " << PIN << endl;
        }
