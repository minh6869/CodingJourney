#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void chuanhoa(string &s)
{
    while (s[0] == ' ')
        strcpy(&s[0],&s[1]);
    for( int i=0 ; i<s.size() ; i++)
    {
        if( s[i] == ' ' && s[i+1] == ' ')
        {
            strcpy(&s[i],&s[i+1]);
            i--;
        }
    }
    if (s[s.size() -1] == ' ')
        s[s.size() -1] == '\0';
}
void xuatcactu(string &s, string a[])
{
    int j = 0;
    for (int i=0 ; i<s.size() ; i++)
    {
            a[j] += s[i];
        if (s[i] != ' ')
            continue;
        j++;
    }
}
string find_word_length_max(string &s , string a[])
{
    int max = a[0].size();
    int index = 0;
    for(int i=0 ; i<s.size() ; i++)
    {
        if(a[i] != "")
        {
            if (a[i].size() > max)
            {
                max = a[i].size();
                index = i;
            }
        }
        
    }
    return a[index];

}

int main() 
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    chuanhoa(s);
    string a[s.size()];
    xuatcactu(s,a);
    cout << "Tu co chieu dai lon nhat trong xau la: " << find_word_length_max(s,a);
    

    
}