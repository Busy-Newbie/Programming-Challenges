//Busy Newbie got AC somehow :)
#include <cstdio>
using namespace std;

int main()
{
	int test, numg, numm, maxg, maxm, g, m;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d", &numg, &numm);
		maxg = maxm = -1;
		while(numg--)
		{
			scanf("%d", &g);
			if(g > maxg) maxg = g;
		}
		while(numm--)
		{
			scanf("%d", &m);
			if(m > maxm) maxm = m;
		}
		if(maxg >= maxm) printf("Godzilla\n");
		else printf("MechaGodzilla\n");
	}
	return 0;
}