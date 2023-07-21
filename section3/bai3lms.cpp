#include <iostream>
#include <string>
using namespace std;
void timkiem_thaythe(string &s)
{
    string s1;
    cout << "Nhap xau con s1: ";
    getline(cin,s1);
    size_t a = s.find(s1);
    if (a == string::npos)
        cout << "Xau s1 khong co trong xau s\n";
    else
    {
        cout << "Vi tri xau s1 xuat hien trong xau s la: " << a;
        while (a != string::npos)
        {
            a++;
            a = s.find(s1,a);
            if(a != string::npos)
                cout << " " << a;
        }
    }  
}

int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    timkiem_thaythe(s);
    return 0;
}