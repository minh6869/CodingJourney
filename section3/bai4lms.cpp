#include <iostream>
#include <string>
using namespace std;
void chenphantu(string &s)
{
    string s1 = "gmail.com";
    size_t a = s.find(s1);
    if (a == string::npos)
        cout << "Xau s khong chua tu 'gmail.com' nen khong chen duoc";
    else
    {
    while (a != string::npos)
    {
        s.insert(a,"@");
        //a+=2;
        a = s.find(s1,a+2);
    }
    cout << s;
    }
        
}
int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    chenphantu(s);
    return 0;
}