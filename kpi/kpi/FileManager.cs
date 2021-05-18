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
        
        
    }
}