#include<iostream> 
#include<string> 
using namespace std;

bool request(string login)
{
    string user_login = "Vu_An";
    string user_password = "1506";
    string password;
    int counter = 1;
    cout << "Enter password" << endl;
    cin >> password;
    while (true)
    {
        if (login == user_login && password == user_password)
        {
            return true;
        }
        else
        {
            cout << "Wrong, let's try again" << endl;
            cout << endl;
            cout << "Enter password" << endl;
            cin >> password;
            counter++;
        }
        if (counter == 3)
        {
            throw password;
        }
    }
}
int main()
{
    try
    {
        bool result;
        string login;
        cout << "Enter login information" << endl;
        cin >> login;
        result = request(login);
        if (result == true)
        {
            cout << "Congratulations, you've entered" << endl;
        }
    }
    catch (const string str)
    {
        cout << "Wrong attempts no more, goodbye" << endl;
        return false;
    }
    return 0;
}