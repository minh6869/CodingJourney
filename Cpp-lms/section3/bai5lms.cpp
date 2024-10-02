#include <iostream>
#include <string>
using namespace std;

bool check(char i)
{
    if (isdigit(i) != 0 && int(i) % 2 == 0)
        return true;
    return false;  
}
void chendautru(string &s)
{
    for (int i=0 ; i< s.size() - 1 ; i++)
    {
        if(check(s[i]) == true && check(s[i+1]) == true)
                s.insert(i+1,"-");
    }        
    cout << "Xau s sau khi chen dau tru vao giua hai so chan la: " << s << endl;
}
int main()
{
    string s;
    cout << "Nhap xau s = ";
    getline(cin,s);
    chendautru(s);
    return 0;
}