#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void chuanhoaxau(string &s)
{
    while (s[0] == ' ')
        strcpy(&s[0],&s[1]);
    for (int i=0; i<s.size() -1; i++)
    {
        if (s[i] == ' ' && s[i+1] == ' ')
        {
            strcpy(&s[i],&s[i+1]);
            i--;
        }
    }
    if (s[s.size()-1] == ' ')
        s[s.size() - 1] = '\0';
}

void xuatcactu(string &s) 
{
    string a[s.size()];
    int j = 0;
    for (int i=0 ; i<s.size(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
        {
            a[j] += s[i];
        }        
        else if (a[j] == ""  )
            continue; 
        else
        {   
            j++;
           // cout << "vi tri cua i:" << i << j << endl;
        }
    }
        cout << "Cac tu co trong xau la: \n";

    for(int i=0 ; i<j+1; i++ )
    {
        if(a[i] != "")
        {
            cout << "Tu thu " << i+1 << ": ";
            cout << a[i]<< endl;
        }

    }   
}
int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    chuanhoaxau(s);
    xuatcactu(s);
}

//['bo', 'an', 'co']