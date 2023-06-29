#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
float a[1000][1000];
void y2(float a[1000][1000])
{
	cout << "Mang da nhap la: " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

void y3(float a[1000][1000])
{
	float sum=0;
	for(int i=0; i<n ; i++)
	{
		for(int j=0; j<m ; j++)
			sum+=a[i][j];
	}
	cout << "Tong cua mang la: " << sum;
}

void y4(float a[1000][1000])
{
	int k;
	cout << "Nhap hang k: "; cin >> k;
	float max=a[k-1][0];
	for(int j=0 ; j<m ; j++)
	{
		if(a[k-1][j]>max)
			max=a[k-1][j];
	}
	cout << "So lon nhat trong hang " << k << " la: " << max;
}
void y5(float a[1000][1000])
{
	int dem=0,k;
	cout << "Nhap cot k: "; cin >> k;
	for(int i=0 ; i<n ; i++)
	{
		if(a[i][k-1]<0)
			dem++;
	}
	if(dem)
		cout << "Cot " << k << " co " << dem << " so am";

	else 
		cout << "Cot " << k << " khong co so am nao";
}

void y6(float a[1000][1000])
{
	int dem=0;
	for(int i=0 ; i<n ; i++)
	{	//a[i][i]
		if(dem!=0 && (int)sqrt(a[i][i]) * (int)sqrt(a[i][i]) == a[i][i] )
		{
			cout << " " << a[i][i];
			continue;
		}
		if( (int)sqrt(a[i][i]) * (int)sqrt(a[i][i]) == a[i][i])
		{	
			dem++;
			cout << "Cac so chinh phuong tren duong cheo chinh la: " << a[i][i]; 
		}
	}
	if(dem == 0)
		cout << "Tren duong cheo chinh khong co so chinh phuong nao";
}
void y7(float a[1000][1000])
{
	float sum=0;
	int dem=0;
	for(int i=0 ; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(j==i)
				continue;
			else
			{
				if(dem!= 0 && 150 % (int)a[i][j] == 0)
				{
					dem++;
					sum+=a[i][j];
					cout << " " << a[i][j];
					continue;
				}
				if(150 % (int)a[i][j] == 0)
				{
					dem++;
					sum=a[i][j];
					cout << "Cac so la uoc cua 150 tren duong cheo phu la: " << a[i][j];
				}
			}
		}
	}
	if(dem)
		cout << "\nTrung binh cong cac so la uoc cua 150 tren duong cheo phu la: " << sum/dem;
	else
		cout << "Tren cac duong cheo phu khong co nao la uoc cua 150";
}

/*void y8(float a[1000][1000])
{	
	for(int i = 0; i<n ; i++)
		sort(a[i], a[i] + m, greater<float>() );

	cout << "Cac hang sau khi sap xep theo chieu giam dan la: \n";
		for(int i=0;i<n;i++)
    		{
        		for(int j=0;j<m;j++)
            			cout << a[i][j] << "\t";
        		cout << endl;
    		}
}*/
 
void y8(float a[1000][1000])
{
	float tmp;
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<m-1; k++)
		{
			for(int j = k+1; j<m ; j++)
			{
				if( a[i][k] < a[i][j])
				{
					tmp=a[i][k];
					a[i][k]=a[i][j];
					a[i][j]=tmp;
				}
			}
					
		}
	}
	cout << "Cac hang sau khi sap xep theo chieu giam dan la: \n";
		for(int i=0;i<n;i++)
    		{
        		for(int j=0;j<m;j++)
            			cout << a[i][j] << "\t";
        		cout << endl;
    		}
}

int main()
{
    cout << "Nhap so hang: "; cin >> n;
    cout << "Nhap so cot: "; cin >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    int y;
    cout << "Chon y (2-8): "; cin >> y;
    switch(y)
    {
	case 2: y2(a); break;
	case 3: y3(a); break;
	case 4: y2(a) ; y4(a) ; break;
	case 5: y2(a) ; y5(a) ;break;
	case 6: y2(a) ; y6(a) ; break;
	case 7: y2(a) ; y7(a) ; break;
	case 8: y2(a); y8(a);break;
	default: cout << "bai nay chi co 8 y";
    }
    return 0;
}
