#include<iostream>
using namespace std;

class ThiSinh
{
	public:
		string name;
		int sbd;
		float d1,d2,d3;
		
		float TongDiem(float d1,float d2,float d3)
		{
			return d1+d2+d3;
		}
		void nhapts()
		{
			cin >> name >> sbd >> d1 >> d2 >> d3;
		}
		void xuatts()
		{
			cout << name << " " << sbd << " " << d1 << " " << d2 << " " << d3 << endl;
		}
};

void nhap(ThiSinh a[], int n)
{
	for(int i = 0; i<n; i++)
	{
		a[i].nhapts();
	}
}

void xuat(ThiSinh a[], int n)
{
	cout<<"Danh sach thi sinh do:"<<endl;
	int d = 0;
	for(int i = 0; i<n; i++)
	{
		if(a[i].TongDiem(a[i].d1,a[i].d2,a[i].d3) >= 15 && a[i].d1 >= 1 && a[i].d2 >= 1 && a[i].d3 >= 1)
		{
			a[i].xuatts();
			d++;
		}	
	}
	cout<< "So thi sinh do: "<< d;
}

int main()
{
	int n;
	ThiSinh a[100];
	cin>>n;
	nhap(a,n);
	xuat(a,n);
	return 0;
}








