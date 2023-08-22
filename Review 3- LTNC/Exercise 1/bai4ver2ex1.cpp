#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "Nhap xau S:";
    getline(cin,s);
    if(s=="")
        cout << "So tu cua S:0" << endl << "Xau S sau khi xoa:";
    else
    {
        int dem=0;
        if(s[0]==' ')
            dem=0;
        if(s[0] != ' ')
            dem=1;
        if(s[s.size()-1] == ' ')
            s[s.size()-1] = '\0';
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i]==' ' &&  s[i+1] != ' ')
                dem++;
            if(isdigit(s[i]))   
            {
                    s.erase(s.begin()+i);
                    i--;
            }
        }
        cout << "So tu cua S:" << dem << endl;
        cout << "Xau S sau khi xoa:" << s;
    }
}