#include <iostream>
using namespace std;

int main ()
{
	typedef struct {
		long int x;
		long int y;
	} titik;
	titik t,t2;
	long int jarakx,jaraky,jarak;
	
	cin>>t.x>>t.y>>t2.x>>t2.y;
	if (t.x-t2.x<0)
	{
		jarakx=-(t.x-t2.x);
	}
	else
	{
		jarakx=t.x-t2.x;
	}
	
	if (t.y-t2.y<0)
	{
		jaraky=-(t.y-t2.y);
	}
	else
	{
		jaraky=t.y-t2.y;
	}
	
	jarak=jarakx+jaraky;
	cout<<jarak<<endl;
}
