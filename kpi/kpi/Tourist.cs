using System;

namespace kpi
{
    public class Tourist
    {
        //поля
        private string Name;
        private string Surname;
        private DateTime DateOfBirth;
        private string PassportNumber;
        private string CardNumber;
        private string CvvCode;
        private string PIN;

        //конструктор
        public Tourist(string name, string surname, DateTime date, string passport)
        {
            Name = name;
            Surname = surname;
            DateOfBirth = date;
            PassportNumber = passport;
        }
        
        //методи
        public bool CheckPersonsInfo()
        {
            if (DateOfBirth >= DateTime.Today) return false;
            foreach (var letter in Name)
            {
                if (!Char.IsLetter(letter)) return false;
            }
            foreach (var letter in Surname)
            {
                if (!Char.IsLetter(letter)) return false;
            }
            if (PassportNumber.Length != 9) return false;
            return true;
        }
        
        public void  SetCardsInfo(string number, string cvv, string pin)
        {
            CardNumber = number;
            CvvCode = cvv;
            PIN = pin;
        }

        public bool CheckCardsInfo()
        {
            if (CvvCode.Length!=3) return false;
            if (PIN.Length != 4) return false;
            if (CardNumber.Length != 16) return false;
            return true;
        }

        public void GetPersonsInfo() //нафіга?
        {
            Console.WriteLine("Ім'я: "+Name);
            Console.WriteLine("Прізвище: "+Surname);
            Console.WriteLine("Дата народження: "+DateOfBirth);
            Console.WriteLine("Номер паспорту: "+PassportNumber);
        }
        
        public void GetCardsInfo() //нафіга?
        {
            Console.WriteLine("Номер картки: "+CardNumber);
            Console.WriteLine("Сvv код: "+CvvCode);
            Console.WriteLine("Пароль: "+PIN);
        }
    }
}