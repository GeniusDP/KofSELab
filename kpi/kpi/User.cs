namespace kpi
{
    public class User
    {
        public readonly string login;
        public readonly string password;
        public readonly string access;

        public User(string n, string p, string a)
        {
            login = n;
            password = p;
            access = a;
        }
    }
}