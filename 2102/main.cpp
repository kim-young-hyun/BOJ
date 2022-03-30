#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long arr[100001];
long long sum[100001];

int main()
{
	int n, m, left, right, mid, ans;
	long long a, b;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		arr[i] *= 1000;
		sum[i] = sum[i - 1] + arr[i];
	}
	left = ans = 0;
	right = 2000000;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		a = -1e18;
		b = 1e18;
		for (int i = m; i <= n; i++)
		{
			a = sum[i] - (long long)mid * (long long)i;
			b = min(b, sum[i - m] - (long long)mid * (long long)(i - m));
			if (a >= b)
				break;
		}
		if (a >= b)
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}