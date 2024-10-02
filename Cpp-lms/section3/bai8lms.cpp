#include <iostream>
#include <string>
using namespace std;

string convert(string &s)
{
    for (int i=0; i<s.size() ; i++)
    {
            if(isupper(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = toupper(s[i]);
    }
    return s;
}
int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    cout << "Xau sau khi chuyen hoa la: " << convert(s) << endl;
}