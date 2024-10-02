#include <iostream>
#include <string>
using namespace std;

int dem_chu_cai(string & str,int i)
{
    if(i == str.size())
        return 0;
    if (isalpha(str[i]))
        return 1 + dem_chu_cai(str,i+1);
    return dem_chu_cai(str,i+1);

}
int dem_chu_so(string & str,int i)
{
    if(i == str.size())
        return 0;
    if (isdigit(str[i]))
        return 1 + dem_chu_so(str,i+1);
    return dem_chu_so(str,i+1);

}
int main()
{   
    string str;
    cout << "Nhap vao mot xau ki tu: ";
    getline(cin,str);
    cout << "Trong xau co " << dem_chu_cai(str,0) << " chu cai" << endl;
    cout << "Trong xau co " << dem_chu_so(str,0) << " chu so" << endl;
}
