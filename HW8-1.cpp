#include<string>
using namespace std;

struct User
{
string login;
string password;

User()
{
login = "DUC_ANH";
password = "1234";
}
};

bool request(string login)
{
User us;
string password;
int counter = 0;
cout << "Введите пароль" << endl;
cin >> password;

while (true)
{
if (login == us.login && password == us.password)
{
return true;
}
if ((login != us.login || password != us.password) && counter == 3)
{
throw password;
}
else {
cout << "Не верно , давайте попробуем снова" << endl;
cout << endl;
cout << "Введите пароль" << endl;
cin >> password;
counter++;
}
}

}

int main()
{
try
{
bool result;
setlocale(LC_ALL, "ru");
string login;
cout << "Введите логин" << endl;
cin >> login;
result = request(login);
if (result == true)
{
cout << "Поздравляю вы вошли" << endl;
}
}
catch (const string str)
{
cout << "Не верно попыток больше нет, до свидания :)" << endl;
return false;
}

return 0;
}