#include <iostream>
using namespace std;
struct Phanso
{
    int tu;
    int mau;
};

int uocChungMax(int a, int b)
{
	if(b == 0 )
		return a;
	return uocChungMax(b,a%b);
}
//int boiChungMin(int a, int b)
//{
//	return (a*b) / uocChungMax(a,b);
//}
Phanso rutgon(Phanso x)
{
	int uocchung = uocChungMax(x.tu,x.mau);
	x.tu /= uocchung;
	x.mau /= uocchung;
	if(x.mau < 0 && x.tu>0)
	{
		x.tu*=-1;
		x.mau*=-1;
	}
	return x;
}
Phanso tinhTong(Phanso a, Phanso b)
{
	Phanso tmp;
	tmp.tu = a.tu*b.mau + a.mau*b.tu;
	tmp.mau = a.mau*b.mau;
	tmp = rutgon(tmp);
	return tmp;
}

int main()
{
	Phanso a,b;
	cout << "Phan so a:" << endl <<  "Tu: ";
	cin >> a.tu;
	cout << "Mau: ";
	cin >> a.mau;
	cout << "Phan so b:" << endl << "Tu: ";
	cin >> b.tu;
	cout << "Mau: ";
	cin >> b.mau;
	if(a.mau==0 || b.mau == 0)
		cout << "Co phan so khong hop le!";
	else
	{
		a = rutgon(a);
		b = rutgon(b);
		Phanso ans = tinhTong(a,b);
		cout << "Tong a + b = " << ans.tu << "/" << ans.mau;	
	}
	return 0;
}
