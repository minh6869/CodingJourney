#include <iostream>
using namespace std;

unsigned long long dem(unsigned long long n)
{
	if(n==0)
		return 0;
	else 
		return 1 + dem(n/10);
}
int main()
{
	unsigned long long n;
	cout << "Nhap n = "; cin >> n;
//	if(n<0)
//		n*=-1;
	cout << dem(n);
	return 0;
}
