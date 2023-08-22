#include <iostream>
using namespace std;
struct Phanso
{
	int tu;
	int mau;
};
int uocchungmax(int a, int b)
{
	if(b==0)
		return a;
	return uocchungmax(b,a%b);
}
void chuanhoa(Phanso &a)
{
	int uoc = uocchungmax(a.tu, a.mau);
	a.tu /= uoc;
	a.mau /= uoc;
	if(a.tu>0 && a.mau < 0)
	{
		a.tu*=-1;
		a.mau*=-1;
	}
}
Phanso timhieu(Phanso a, Phanso b)
{
	Phanso hieu;
	hieu.tu = a.tu*b.mau - a.mau*b.tu;
	hieu.mau = a.mau*b.mau;
	chuanhoa(hieu);
	return hieu;
}
int main()
{
	Phanso a,b;
	cout << "Phan so a:" << endl << "Tu: ";
	cin >> a.tu;
	cout << "Mau: ";
	cin >> a.mau;
	cout << "Phan so b:" << endl << "Tu: ";
	cin >> b.tu;
	cout << "Mau: ";
	cin >> b.mau;
	if(a.mau == 0 || b.mau == 0)
		cout << "Co phan so khong hop le!";
	else
	{
		chuanhoa(a);
		chuanhoa(b);
		Phanso hieu = timhieu(a,b);
		cout << "Hieu a - b = " << hieu.tu << "/" << hieu.mau;
	}
	return 0;
}

