//Busy Newbie got AC somehow :)
#include <iostream.h>
int DivSum(int);
int main()
{
    int *a,n;
    long *b;
    cin>>n;
    a=new int[n];
    b=new long[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==1 or a[i]==0) b[i]=0;
        else b[i]=DivSum(a[i]);
    }
    for (int i=0; i<n; i++) printf("%d\n",b[i]);
    return 0;
}
int DivSum(int n)
{
    int a=2,b,S=1;
    while (true)
    {
          b=n/a;
          if (a>b) break;
          if (n%a==0)
          { 
             S+=a;
             if (b!=a) S+=b;
          }
          a++;     
    }
    return S;
}