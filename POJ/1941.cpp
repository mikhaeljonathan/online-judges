 #include <stdio.h>
#include <cstring>
using namespace std;
bool arr[2100][2100];
int isi[2100][2100];
int pangkat[11];


void rekursi (int a, int x, int y)
{

     for (int b = x+1-pangkat[a]; b<=x-1; b++)
    {
        for (int k = y; k<=y+pangkat[a]-1; k++)
        {
            if (arr[b][k] == false && b+k == x+y){
            	isi[b][k] = 57;
			}
                
        }
    }
    
    int count = x+y+1;
    for (int b = x+1-pangkat[a]; b<=x-1; b++)
    {	
        for (int k = y+pangkat[a]; k<=y+(2*pangkat[a])-2; k++)
        {
//        	printf("b : %d k : %d count : %d\n", b, k, count);
            if (arr[b][k] == false && b+k == count)
                isi[b][k] = 92;
            count = count+2;
        }
    }
	
    for (int f = y;f<= y+pangkat[a+1]-1; f++)
    {
        if (f == y)
            isi[x][f] = 57;
        else if (f == y+pangkat[a+1]-1)
            isi[x][f] = 92;
        else
            isi[x][f] = 95;

	
    }
//    for (int i = 0; i < 4; i++){
//		for (int j = 0; j < 8; j++){
//			printf("%c", isi[i][j]);
//		}
//		puts("");
//	}
//	puts("");
    if (a>1)
    {
        //kiri bawah
        rekursi(a-1, x,y);

        //atas
        rekursi(a-1, x-pangkat[a-1], y+pangkat[a-1]);

        //bawah kanan
        rekursi(a-1, x, y+pangkat[a]);
    }

}




int main()
{
	while (1){
		
		memset(arr, false , sizeof (arr));
	    memset (isi, 0, sizeof (isi));
	    memset (pangkat, 0, sizeof(pangkat));
	    pangkat[0] = 1;
	    for (int f = 1; f<=11; f++)
	        pangkat[f] = pangkat[f-1]*2;
	    int N;
	    scanf ("%d", &N);
	    if (N == 0) break;
	    rekursi (N, pangkat[N]-1,0);
	
	    for (int b = 0; b<pangkat[N]; b++ )
	    {
	        for (int k = 0; k <= (2*pangkat[N])-1; k++)
	         {
	            if (isi[b][k] == 57)
	                printf("/");
	            else if (isi[b][k] == 92)
	            {
	                int d = 92;
	                char u = d;
	                printf("%c", u);
	            }
	
	            else if (isi[b][k] == 95)
	                printf("_");
	            else
	                printf (" ");
	
	        }
	        printf ("\n");
	    }
	    puts("");
	}
    
}

