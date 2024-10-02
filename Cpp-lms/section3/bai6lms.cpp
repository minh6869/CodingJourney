#include <iostream>
#include <string>
using namespace std;

void thaythecumtu(string &s)
{
    string s1 = "gmail.com";
    string s2 = "e.tlu.edu.vn";
    size_t a = s.find(s1);
    if ( a == string::npos)
        cout << "Trong xau s khong chua cum tu 'gmail.com'\n";
    while (a != string::npos)
    {
        s = s.replace(a , s2.size(), s2);
        //a++;
        a = s.find(s1,a+1);
    }
    cout << "Xau s sau khi thay the la: " << s;
}
int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    thaythecumtu(s);
    return 0;
}