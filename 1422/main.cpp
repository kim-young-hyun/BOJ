#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ull unsigned long long

ull arr[50];
int dp[50];
int p[50];
vector<pair<ull, ull> > v;

bool compare(pair<ull, ull> a, pair<ull, ull> b)
{
	return a.first * b.second + b.first > b.first * a.second + a.first;
}

int main()
{
	int n, k, m, temp;
	ull a, b;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%llu", &a);
		b = 1;
		while (b <= a)
			b *= 10;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end(), compare);
	v.push_back({ -1, -1 });
	m = 1;
	n = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] != v[i - 1])
		{
			arr[n] = v[i - 1].first;
			dp[n] = m;
			k -= m;
			m = 1;
			n++;
		}
		else
			m++;

	temp = 0;
	for (int i = 1; i < n; i++)
		if (arr[temp] < arr[i])
			temp = i;
	dp[temp] += k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < dp[i]; j++)
			printf("%llu", arr[i]);
	}
	return 0;
}