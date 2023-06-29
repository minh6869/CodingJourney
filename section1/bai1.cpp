#include <iostream>
#include <cmath>
using namespace std;
int giaithua(int i)
{
	if(i==1)
		return 1;
	return i*giaithua(i-1);
}
float y1(int n)
{
	
	float sum=0.0;
	for(int i =1 ; i<=n ; i++)
		sum+=1.0/i;
	return sum;
	//cout << sum << endl;
}

float y2(int n)
{
	float sum = 0.0;
	for (int i = 1 ; i <= n ; i++)
		sum+=1.0/(2*i);
	return sum;
}

int y3(int n)
{
	int sum=1;
	for(int i = 1; i<=n; i++)
		sum+=3*i;
	return sum;
}
int y4(int n)
{
	int sum=1;
	for(int i=1; i<=n; i++)
		sum+=2*i+1;
	return sum;
}
float y5(int n)
{
	float x,sum=0;
	cout << "Nhap x = "; cin >> x;
	for (int i = 0;i<=n;i++)
		sum+=pow(x,i);
	return sum;
}
float y6(int n)
{
	float x,sum=1.0;
	int gt;
	cout << "Nhap x = "; cin >> x;
	for(int i = 1; i <= n; i++)
	{
		gt=giaithua(2*i);
		sum+=pow(-1.0,i)*pow(x,2*i)/gt;
	}
	return sum;
}

float y7(int n)
{
	float x,sum=1,giaithua=1;
	cout << "Nhap x = "; cin >> x;
	for (int i = 1;i <= n; i++)
	{
		giaithua*=i;
		sum+=pow(x,i)/giaithua;
	}
	return sum;
}
int main()
{
	int n,i;
	cout << "Nhap n = "; cin >> n;
	cout << "Chon y (1-7): "; cin >> i;
	switch(i)
	{
		case 1: cout <<  y1(n);break;
		case 2: cout <<  y2(n);break;
		case 3: cout <<  y3(n);break;
		case 4: cout <<  y4(n);break;
		case 5: cout <<  y5(n);break;
		case 6: cout <<  y6(n);break;
		case 7: cout <<  y7(n);break;
		default: cout << "Bai 1 chi co 7 cau\n";
	}
	return 0;
}
