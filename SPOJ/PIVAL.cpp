//Busy Newbie got AC somehow :)
#include <stdio.h>
#include <malloc.h>
#include <math.h>
long B=10000; 
long LB=4;
long MaxDiv=450;
void SetToInteger(long n,long *x,long Integer) 
{
	long i;
	for (i=1;i<n;i++) x[i]=0;
	x[0]=Integer;
}
long IsZero(long n,long *x) 
{
	long i;
	for (i=0; i<n; i++)  
    if (x[i]) return 0;
	return 1;
}
void Add(long n,long *x,long *y) 
{
	long carry=0,i;
	for (i=n-1; i>=0; i--) 
	{
		x[i]+=y[i]+carry;
		if (x[i]<B) carry=0;
		else { carry=1; x[i]-=B;
    }
  }  
}
void Sub(long n,long *x,long *y) {
	long i;
	for (i=n-1; i>=0; i--) 
	{
		x[i]-=y[i];
		if (x[i]<0) if (i) { x[i]+=B; x[i-1]--; }
	}
}
void Mul(long n,long *x,long q) 
{
	long carry=0, xi, i;
	for (i=n-1; i>=0; i--) 
	{
		xi=x[i]*q;		
		xi+=carry;		
		if (xi>=B) { carry=xi/B; xi-=(carry*B); }
		else carry=0;
		x[i]=xi;
	}  
}
void Div(long n,long *x,long d,long *y) 
{
	long carry=0,xi,q,i;
	for (i=0; i<n; i++) 
	{
		xi=x[i]+carry*B;
		q=xi/d;
		carry=xi-q*d;   
		y[i]=q;
	}
}
void arccot(long p,long n,long *x,long *buf1,long *buf2) 
{
	long p2=p*p,k=3,sign=0;
	long *uk=buf1,*vk=buf2;
	SetToInteger(n,x,0);
	SetToInteger(n,uk,1);
	Div(n,uk,p,uk);
	Add(n,x,uk);
	while (!IsZero(n,uk)) 
	{
		if (p<MaxDiv) Div (n,uk,p2,uk);  
		else { Div (n,uk,p,uk); Div (n,uk,p,uk); }
		Div (n,uk,k,vk);
		if (sign) Add(n,x,vk);
		else Sub(n,x,vk); 
		k+=2;
		sign=1-sign;
	}
}
void Print(long n, long *x) 
{
	long i; 
	printf ("%d.", x[0]);
	for (i=1; i<n; i++) 
	{
		printf ("%.4d", x[i]);
	}
}
int main () 
{  
	long NbDigits=25000,NbArctan,p[10],m[10];
	long size=1+NbDigits/LB, i;
	long *Pi      = (long *)malloc(size*sizeof(long));
	long *arctan  = (long *)malloc(size*sizeof(long));
	long *buffer1 = (long *)malloc(size*sizeof(long));
	long *buffer2 = (long *)malloc(size*sizeof(long)); 
	NbArctan=3;
	m[0]=12; m[1]=8;  m[2]=-5;
	p[0]=18; p[1]=57; p[2]=239; 
	SetToInteger (size, Pi, 0);
	for (i=0; i<NbArctan; i++) 
	{
		arccot (p[i],size,arctan,buffer1,buffer2);
		Mul(size,arctan,abs(m[i]));
		if (m[i]>0) Add(size,Pi,arctan);  
		else Sub(size,Pi,arctan);  
	}
	Mul(size,Pi,4);
	Print(size,Pi); 
	free(Pi);
	free(arctan);
 	free(buffer1);
 	free(buffer2);
 	return 0;
}