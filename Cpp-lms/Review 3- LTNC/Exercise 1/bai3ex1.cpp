#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int demtu(string s, int index, int tmp)
{
    if(s[index] == '\0')
        return 0;
    if(tmp == 0 && s[index] != ' ')
        return 1+demtu(s,index+1,1);
    if(tmp == 0 && s[index] == ' ')
        return demtu(s,index+1,0);
    if(tmp == 1 && s[index] != ' ')
        return demtu(s,index+1,1);
    if(tmp == 1 && s[index] == ' ')
        return demtu(s, index+1, 0);
    
}
int main()
{
    string s,w;
    cout << "Nhap xau S:";
    getline(cin,s);
    if(s=="")
        cout << "So tu cua S: 0" << endl;
    else
        cout << "So tu cua S: " << demtu(s,0,0) << endl;
    cout << "Nhap xau W:";
    getline(cin,w);
    size_t a = s.find(w);
    if(a == string::npos)
        cout << "Xau W khong xuat hien trong S!";
    else
        cout << "Xau W xuat hien trong S tai vi tri: " << a;
}