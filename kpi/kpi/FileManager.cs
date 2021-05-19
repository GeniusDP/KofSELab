using System;
using System.IO;

namespace kpi
{
    public class FileManager
    {
        private string path;

        public FileManager(string path)
        {
            this.path = path;
        }

        public void Register(User newUser)
        {
            using (StreamWriter sw = new StreamWriter(path+@"\users.txt", true))
            {
                sw.WriteLine(newUser.access+" "+newUser.login+" "+newUser.password);
            }
        }

        public bool Avtorization(User user)
        {
            string usersInfo = user.access + " " + user.login + " " + user.password;
            using (StreamReader sr = new StreamReader(path+@"\users.txt"))
            {
                while (!sr.EndOfStream)
                {
                    if (sr.ReadLine() == usersInfo)
                    {
                        return true;
                    }
                }
            }

            return false;
        }
        
        public void CreateTest(int numberOfTest, string nameOfCourse, int countOfQuestions){
            using (StreamWriter sw = new StreamWriter(path+@"\"+nameOfCourse+@"\Test"+numberOfTest+".txt"))
            {
                for (int i = 0; i < countOfQuestions; i++)
                {
                    sw.WriteLine(Console.ReadLine());// запитання
                    sw.WriteLine(Console.ReadLine());// варіант відповіді 1
                    sw.WriteLine(Console.ReadLine());// варіант відповіді 2
                    sw.WriteLine(Console.ReadLine());// варіант відповіді 3
                    sw.WriteLine(Console.ReadLine());// варіант відповіді 4
                    sw.WriteLine(Console.ReadLine());// відповідь
                }
            }

            using (StreamWriter sw = new StreamWriter(path + @"\" + nameOfCourse + @"\StatisticTest" + numberOfTest + ".txt"))
            {
            }
        }

        public void AppendToLecture(int numberOfLecture, string nameOfCourse)
        {
            using (StreamWriter sw = new StreamWriter(path+@"\"+nameOfCourse+@"\Lecture"+numberOfLecture+".txt", true))
            {
                while (true)
                {
                    string str = Console.ReadLine();
                    if(str=="0") break;
                    sw.WriteLine();
                }
            }
        }
    }
}