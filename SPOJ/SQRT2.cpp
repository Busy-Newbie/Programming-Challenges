//Busy Newbie got AC somehow :)
#include <stdio.h>
#include <malloc.h>
long B=10000;
long LB=4;
void SetToInteger(long n,long *x,long Integer) 
{
	for (long i=1; i<n; i++) x[i]=0;
	x[0]=Integer;
}
long IsZero(long n, long *x) 
{
	for (long i=0; i<n; i++) if (x[i]) return 0;
	return 1;
}
void Add(long n,long *x,long *y) 
{
	long carry=0,i;
	for (i=n-1; i>=0; i--) 
	{
		x[i]+=y[i]+carry;
		if (x[i]<B) carry=0;
		else { carry=1; x[i]-=B; }
	}
}
void Mul(long n,long *x,long q)
{
	long carry=0,xi,i;
	for (i=n-1; i>=0; i--) 
	{
		xi=x[i]*q;		
		xi+=carry;		
		if (xi>=B) { carry = xi/B; xi-=(carry*B); }
		else carry=0;
		x[i]=xi;
	}  
}
void Div(long n,long *x,long d) 
{
	long carry=0,xi,q,i;
	for (i=0; i<n; i++) 
	{
		xi=x[i]+carry*B;
		q=xi/d;
		carry=xi-q*d;   
		x[i]=q;        
	}
}

void Print(long n,long *x) 
{
	long i;
	printf ("%d.", x[0]);
	for (i=1; i<n; i++) 
	{
		printf ("%.4d", x[i]);
	}
	printf ("\n");
}
int main () 
{
	long NbDigits=40000,size=1+NbDigits/LB,k=1;
	long *r2=(long *)malloc(size*sizeof(long));
	long *uk=(long *)malloc(size*sizeof(long));
	SetToInteger(size,r2,1);
	SetToInteger (size,uk,1);
	while(!IsZero(size,uk))
	{
		Div(size,uk,57122);
		Div(size,uk,2*k);  
		Mul(size,uk,2*k-1);  
		Add(size,r2,uk);
		k++;
	}
	Mul(size,r2,239);  
	Div(size,r2,169);
	Print(size,r2);
	free(r2);
 	free(uk);
 	return 0;
}





