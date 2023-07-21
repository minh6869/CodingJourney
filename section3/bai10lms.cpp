#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void chuanhoa(string &s)
{
    while (s[0] == ' ')
        strcpy(&s[0],&s[1]);
    for (int i=0 ; i<s.size() -1 ; i++)
    {
        if(s[i] == ' ' && s[i+1] == ' ')
        {
            strcpy(&s[i],&s[i+1]);
            i--;
        }
    }
    if(s[s.size() -1] == ' ')
        s[s.size() -1] == '\0';

}
string xuatcactu(string &s, string a[])
{
    
    int j = 0;
    for(int i = 0; i<s.size() ; i++)
    {
        if(isalpha(s[i]) || isdigit(s[i]))
                a[j] += s[i];
        else if (a[j] == "")
            continue;
        else
            j++;  
    }
    for(int i=0 ; i<j+1; i++)
    {
        if(a[i] != "")
        {
            if(islower(a[i][0]))
                a[i][0] = toupper(a[i][0]);
        }
    }   
}
int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    chuanhoa(s);
    string a[s.size()];
    xuatcactu(s,a);
    cout << "Xau sau khi chuan hoa la:"; 
    for (int i=0 ; i<s.size()-1 ; i++)
    {
        if(a[i] != "")
            cout << " " << a[i] ;
    }

    return 0;
}
