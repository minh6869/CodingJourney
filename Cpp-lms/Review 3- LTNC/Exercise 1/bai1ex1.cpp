#include <iostream>
#include <string>
using namespace std;
int n;
string find(string s, int i )
{
    if(i==n+1)
        return s;
    cout << "Ho ten thu " << i << ": ";
    string temp;
    getline(cin,temp);
    if(temp.size() < s.size())
        return find(temp,i+1);
    return find(s,i+1);
}
int main()
{
    
    string s;
    while(1)
    {
        cout << "N = ";
        cin >> n;
        cin.ignore();
        if(0<n && n<10)
            break;
    }
    cout << "Ho ten thu 1: ";
    getline(cin,s);
    string tmp = find(s,2);
    cout << "Ho ten ngan nhat (dau tien): " << tmp;
}