#include <iostream>
using namespace std;
struct Phanso
{
	int tu;
	int mau;	
};
int uocchungmax(int a, int b)
{
	if(b == 0)
		return a;
	return uocchungmax(b,a%b);
}
void chuanhoa(Phanso &a)
{
	int uoc = uocchungmax(a.tu, a.mau);
	a.tu /= uoc;
	a.mau /= uoc;
	if(a.mau < 0 && a.tu > 0)
	{
		a.mau*=-1;
		a.tu*=-1;
	}
}
int main()
{
	Phanso a;
	cout << "Cho phan so a:" << endl << "Tu: ";
	cin >> a.tu;
	cout << "Mau: ";
	cin >> a.mau;
	if(a.mau == 0)
		cout << "Phan so khong hop le!";
	else
	{
		chuanhoa(a);
		cout << "Chuan hoa phan so: " << a.tu << '/' << a.mau;
	}
}
