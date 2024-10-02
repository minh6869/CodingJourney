#include <iostream>
#include <string>
using namespace std;
string daonguoc(string &s)
{
    for (int i = 0 ; i < s.size() / 2 ; i++)
    {
        char tmp = s[i];
        s[i] = s[s.size() -1 -i];
        s[s.size() -1-i] = tmp;
    }
    return s;
}
int main() 
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    cout << "Xau sau khi dao nguoc la: " << daonguoc(s);
}