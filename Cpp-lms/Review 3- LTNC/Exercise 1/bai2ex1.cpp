#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char s[100];
    cout << "Nhap xau:";
    gets(s);
    if(s[0]=='\0')
        cout << "Xau rong!";
    else
    {
        while(s[0] == ' ')
            strcpy(&s[0],&s[1]);
        for (int i=0 ; i<strlen(s); i++)
        {
            if(s[i] == ' ' && s[i+1] == ' ')
            {
                strcpy(&s[i],&s[i+1]);
                i--;
            }
        }
        if(s[strlen(s) -1 ] == ' ')
            s[strlen(s)-1] = '\0';
        if( strlen(s) == 0)
        {
            cout << "Chuan hoa:" << endl;
            cout << "So tu:0";
        }
        else
        {
            int dem = 0;
            for(int i=0 ; i<strlen(s) ; i++)
            {
                if(s[i] == ' ')
                    dem++;
            }
            cout << "Chuan hoa:" << s << endl;
            cout << "So tu:" << dem+1;
        }
    }
    return 0;
}