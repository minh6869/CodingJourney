#include <iostream>
#include <string>
using namespace std;
int demtu(string s, int i, int tmp)
{
    if(s[i] == '\0')
        return 0;
    if(tmp == 0 && s[i] != ' ')
        return 1+demtu(s,i,1);
    if(tmp == 0 && s[i] == ' ')
        return demtu(s,i,0);
    if(tmp == 1 && s[i] != ' ')
        return demtu(s,i+1,1);
    if(tmp == 1 && s[i] == ' ')
        return demtu(s,i+1,0);
}
int main()
{
    string s;
    cout << "Nhap xau S:";
    getline(cin,s);
    if(s=="")
    {
        cout << "So tu cua S:0" << endl << "Xau S sau khi xoa:";
    }
    else
    {
        cout << "So tu cua S:" << demtu(s,0,0) << endl;
        cout << "Xau S sau khi xoa:";
        for(int i=0 ; i<s.size() ; i++)
        {
            if(isdigit(s[i]))
                continue;
            cout << s[i];
        }
    }
}