#include <iostream>
using namespace std;
void fullbaris(int c2);
void hasil(int l, int c, int s);
void backslash(int s, int temp2);
void slash(int s, int temp2);
void barisganjil(int s, int c);
void barisgenap(int s, int c);


int main()
{
	int t;
	cin>>t;
	for (int tcase=1;tcase<=t;tcase++)
	{
		int l,c,s;
		cin>>l>>c>>s;
		hasil(l,c,s);
		cout<<endl;
	}
	return 0;
}

void hasil(int l, int c, int s)
{
	int c2 = (s+1)*c+1;
	for (int temp=1;temp<=l;temp++) //jumlah baris
	{
		fullbaris(c2); //baris pembatas
        if	(temp%2==1) //baris ganjil
		{
			barisganjil(s,c);
		}	
		else // baris genap
		{
			barisgenap(s,c);
		}
	}
	fullbaris(c2);
}

void fullbaris(int c2)
{
	for (int temp=1;temp<=c2;temp++) 
	{
		cout<<"*";
	}
	cout<<endl;
}

void backslash(int s, int temp2)
{
	for (int temp=1;temp<=s;temp++) //jumlah kolom kotak kecil
	{
		if (temp==temp2)
		{
			cout<<"\\";
		}
		else
		{
			cout<<".";
		}
	}
}

void slash(int s, int temp2)
{
	for (int temp=1;temp<=s;temp++) //jumlah kolom kotak kecil
	{
		if (temp+temp2==s+1)
		{
			cout<<"/";
		}
		else
		{
			cout<<".";
		}
	}
}

void barisganjil(int s, int c)
{
	for (int temp2=1;temp2<=s;temp2++) //jumlah baris kotak kecil
	{
			
		for (int temp3=1;temp3<=c;temp3++) //jumlah kotak kecil diulang
		{
			cout<<"*";
			if (temp3%2==1)
			{
				backslash(s,temp2);
			}
			else
			{
				slash(s,temp2);
			}
		}	
		cout<<"*"<<endl;	
	}
}

void barisgenap(int s, int c)
{
	for (int temp2=1;temp2<=s;temp2++) //jumlah baris kotak kecil
	{
			
		for (int temp3=1;temp3<=c;temp3++) //jumlah kotak kecil diulang
		{
			cout<<"*";
			if (temp3%2==1)
			{
				slash(s,temp2);
			}
			else
			{
				backslash(s,temp2);
			}
		}
		cout<<"*"<<endl;		
	}
}
