#include <iostream>
#include <string>
using namespace std;
int demtu(string s, int i, int tmp)
{
    if(s[i] == '\0')
        return 0;
    if(tmp == 0 && s[i] != ' ')
        return 1+demtu(s,i+1,1);
    if(tmp == 0 && s[i] == ' ')
        return demtu(s,i+1,0);
    if(tmp == 1 && s[i] != ' ')
        return demtu(s,i+1,1);
    if(tmp == 1 & s[i] == ' ')
        return demtu(s,i+1,0);
}
int main()
{
    string s;
    cout << "Nhap xau S:";
    getline(cin,s);
    if(s=="")
    {
        cout << "Xau S sau khi xoa:" << endl << "So tu cua S:0";
    }
    else
    {
        string tmp="";
        for(int i=0 ; i<s.size() ; i++)
        {
            if(isdigit(s[i]) == 0 && isalpha(s[i]) == 0 && s[i] != ' ')
                continue;
            tmp+=s[i];
        }
        cout << "Xau S sau khi xoa:" << tmp << endl;
        cout << "So tu cua S:" << demtu(tmp,0,0);
    }
}