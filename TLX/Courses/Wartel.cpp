#include <iostream>
using namespace std;

int main ()
{
	long int n,q;
	cin>>n>>q;
	string name[n];
	string nameraw;
	string num[n];
	string search;
	int letter[n];
	for (long int temp=0; temp<n; temp++)
	{
		cin>>nameraw>>num[temp];
		letter[temp] =  int(nameraw[0]);
		name[temp] = nameraw;
	}
	for (long int temp2=0; temp2<q; temp2++)
	{
		cin>>search;
		int letters= int(search[0]);
		bool found = false;
		long int left=0;
		long int right=n;
		long int middle;
		while ((!found)&&(left<=right))
		{
			middle = (left+right)/2;
			if (letter[middle]>letters) //too high
			{
				right = middle-1;
			}
			else if (letter[middle]<letters) //too low
			{
				left = middle+1;
			}
			else
			{
				found=true;
			}
		}
		if (!found)
		{
			cout<<"NIHIL"<<endl;
		}
		else
		{
			if (name[middle]==search)
			{
				cout<<num[middle]<<endl;
			}
			else
			{
				long int middlelow=middle-1;;
				long int middlehigh=middle+1;
				bool found=false;
				while ((!found)&&(letter[middlelow]==letters))
				{
					if (name[middlelow]==search)
					{
						found=true;
						cout<<num[middlelow]<<endl;
					}
					middlelow--;
				}
				while ((!found)&&(letter[middlehigh]==letters))
				{
					if (name[middlehigh]==search)
					{
						found=true;
						cout<<num[middlehigh]<<endl;
					}
					middlehigh++;
				}
				if (!found)
				{
					cout<<"NIHIL"<<endl;
 				}
			}
		}
	}
	return 0;
}
