
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<ll, ll> pii;

const int MAXN = 255345;

struct arv{
	int tot;
	long double x;
} tree[MAXN*4];

long double pot[MAXN];

char t[MAXN];

ll s[MAXN];
int ind[MAXN];

map<pii, int> pos;

bool cmp(int a, int b){
	return (s[a] < s[b] || (s[a] == s[b] && a < b));
}

void upd(int idx, int i, int j, int l, long double v){
	if(i > l || j < l) return ;	
	if(i == j){
		if(v == -1){
			tree[idx].tot = 0;
			tree[idx].x = 0;
		}
		else{
			tree[idx].tot = 1;
			tree[idx].x = v;
		}
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2, i, m, l, v);
	upd(idx*2+1, m+1, j, l, v);

	tree[idx].x = tree[idx*2].x + tree[idx*2+1].x*pot[tree[idx*2].tot];
	tree[idx].tot = tree[idx*2].tot + tree[idx*2+1].tot;
}

map<ll, int> ult;

int main(){
	int n;
	scanf("%d", &n);
	pot[0] = 1;
	for(int a=1;a<n;a++){
		pot[a] = pot[a-1]/2.;
	}
	for(int a=0;a<n;a++){
		ind[a] = a;
		scanf(" %c %lld", &t[a], &s[a]);
	}	
	sort(ind, ind+n, cmp);
	for(int a=0;a<n;a++){
		int p = ind[a];
		if(t[ind[a]] == '-')
			p = ult[s[ind[a]]];
		else
			ult[s[ind[a]]] = ind[a];
		pos[pii(s[ind[a]], p)] = a;
	}
	for(int a=0;a<n;a++){
		int p = pos[pii(s[a], a)];
		if(t[a] == '-')
			p = ult[s[a]];
		else
			ult[s[a]] = pos[pii(s[a], a)];
		printf("upd %lld na pos %d\n", s[a], p);
		if(t[a] == '+')
			upd(1, 0, n-1, p, s[a]);
		else
			upd(1, 0, n-1, p, -1);
		long double res = tree[1].x/2.;
		int tam = tree[1].tot;
		if(tam < 64){
			res *= ((long double)(1ll<<tam)/((long double)(1ll<<tam)-1.));
		}
		printf("%.20Lf\n", res);
	}
}

