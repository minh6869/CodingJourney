#include <iostream>
#include <vector>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000 



const int x_max = 10;
const int y_max = 8;
const int x_min = 4;
const int y_min = 4;



int computerCode(int x, int y){
    int code = INSIDE;

    if(x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if(y < y_min)
        code |= BOTTOM;
    else if(y > y_max)
        code |= TOP;

    return code;
    
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2){
    int code1 = computerCode(x1, y1);
    int code2 = computerCode(x2, y2);
    int accept = 0;
    while(true) { 
        if((code1 == 0) && (code2 == 0) ){
            
            accept = 1;
            break; // cả hai điểm nằm trong vùng nhìn thấy 
        }
        if (code1 & code2 == 0)
            break; // cả hai điểm nằm ngoài vùng nhìn thấy
        else {
            int code_out = 0;
            int x, y;
            if(code1 != 0)
                code_out = code1;
            else 
                code_out = code2;

        //sử dụng công thức y = a(x-x1) + y1
        //    y = ax - ax1 + y1
        //   ax = y + ax1 - y1
        //    x = x1 + (y-y1) / a
        //với a = (y2-y1) / (x2 - x1);
            if(code_out & TOP){

                y = y_max;
                x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
            }
            else if(code_out & BOTTOM){
                y = y_min;
                x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
            }
            else if(code_out & RIGHT){
                x = x_max;
                y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
            }
            else if(code_out & LEFT){
                x = x_min;
                y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
            }

            if(code_out == code1){
                x1 = x;
                y1 = y;
                code1 = computerCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computerCode(x2, y2);
            }
        }
    }
    if(accept){ 
        cout << "Line accept from " << x1 << ", " << y1 << " to " << x2 << ", " << y2;
    }
    else{
        cout << "Duong thang khong cat";
    }
    
}



int main()
{
    vector<int> A = {-2, -3};
    vector<int> B = {1, 1};
    cout << computerCode(7, 9);
    cohenSutherlandClip(7, 9, 7, 3);
}
