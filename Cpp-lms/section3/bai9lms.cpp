#include <iostream>
#include <string>
using namespace std;
void tongcacchuso(string s, int so[])
{
    int tong = 0;
    for(int i = 0; i<s.size() ; i++)
    {
        if(isdigit(s[i]))
            tong += so[s[i]];
    }
    cout << "Tong cac chu so co trong xau la: " << tong;
}
int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    int so[60];
    int j = 0;
    for(int i = 48; i<=57 ; i++)
    {
        so[i] = j;
        j++;
    }
    tongcacchuso(s,so);
}