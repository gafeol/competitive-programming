#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2123456;

int n, m;
ll k;

ll s[MAXN];

ll c[MAXN];

multiset<ll> q;

ll mx(){
	return -(*q.begin());
}

void add(ll x){
	q.insert(-x);
}
void rmv(ll x){
	q.erase(q.find(-x));
}

int main(){
	int p;
	scanf("%d%lld%d", &n, &k, &p);
	ll sum = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		sum += s[a];
		if(a >= p)
			sum -= s[a-p];
		c[a] = sum;
	}
	int i = 0, j = p-1;
	if(p != 0)
		add(c[j]);
	sum = 0;
	for(int a=0;a<=j;a++)
		sum += s[a];
	int res = 0;
	while(i < n){
//		printf("i %d j %d\n", i, j);
		while(j+1 < n && (j < i+p-1 || sum + s[j+1] - max(c[j+1], mx()) <= k)){
//			printf("	j %d\n", j);
			j++;
			sum += s[j];
			if(j >= i+p-1 && p != 0)
				add(c[j]);
		}
		if(sum - mx() > k) break;
//		printf("anda\n");
//		printf("i %d j %d\n", i, j);
//		printf("som %lld mx %lld\n", sum, mx());

		res = max(res, j - i + 1);
		if(j >= i)
			sum -= s[i];
		if(p != 0 && i+p-1 <= j)
			rmv(c[i+p-1]);
		i++;
	}
	printf("%d\n", res);
}
