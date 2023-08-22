#include <iostream>
#include <string>
using namespace std;
int demtu(string s, int i, int tmp)
{
    if(s[i] == '\0')\
        return 0;
    if(tmp == 0 && s[i] != ' ')
        return 1+demtu(s,i+1,1);
    if(tmp == 0 && s[i] == ' ')
        return demtu(s,i+1,0);
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
        cout << "Xau rong!";
    else
    {
        string tmp="";
        int dem = 0;
        cout << "So tu cua S: " << demtu(s,0,0) << endl;
        cout << "So ky tu khong la chu cai/chu so: ";
        for(int i=0 ; i<s.size() ; i++)
        {
            if(isdigit(s[i]) == 0 && isalpha(s[i]) == 0)
            {
                dem++;
                continue;
            }
                tmp+=s[i];
        }
        cout << dem << endl;
        cout << "Xau S sau khi xoa:" << tmp << endl ;
    }
    
}