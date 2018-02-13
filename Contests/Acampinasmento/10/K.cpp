#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> vis;

ll n;
int m;

queue<ll> q;

ll s[20];

int main(){
	scanf("%lld %d", &n, &m);
	for(int a=0;a<m;a++)
		scanf("%lld", s+a);
	q.push(n);
	vis[n] = 1;
	int cnt = 0;
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		cnt++;
		for(int a=0;a<m;a++){
			if(vis.find(u/s[a]) == vis.end()){
				vis[u/s[a]] = 1;
				q.push(u/s[a]);
			}
		}
	}
	printf("%d\n", cnt);
}
