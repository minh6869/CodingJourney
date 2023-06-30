#include <stdio.h>
#include <windows.h>
//void SetColor(int backgound_color, int text_color){
//	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//	int color_code = backgound_color * 16 + text_color;
//	SetConsoleTextAttribute(hStdout, color_code);
//}

int main(){
	float x,y,z;
	//SetColor(0,12);
	system("Color 0C");
	for(y=1.5; y > -1.5; y-=0.095){
		for(x=-1.5;x<1.5;x+=0.03){
			
		z=x*x+y*y-1;
			putchar(z*z*z-x*x*y*y*y <= 0.0 ? '*' : ' ');
		}
		Sleep(300);
		printf("\n");//putchar('\n');
	}
	SetConsoleOutputCP(65000);
	printf("                                            Happy New Yeahhh:)                         ");
	return 0;
}
