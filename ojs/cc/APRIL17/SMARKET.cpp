#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int LR = 0, RL = 1;

int n, m, k;
int s[MAXN], L[MAXN], R[MAXN], K[MAXN], ind[MAXN];
int bef[MAXN], aft[MAXN];
int bit[MAXN], res[MAXN];
int sq;

void upd(int i, int val){
	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}

int qry(int i){
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void add(int i, int dir, int j){
	if(!dir){
		if(max(j, bef[i]) != i){
			upd(i - max(j,bef[i]), -1);
		}
		upd(i - max(bef[i], j) + 1, 1);
	}
	else{
		if(min(j, aft[i]) != i)
			upd(min(j, aft[i]) - i, -1);
		upd(min(aft[i], j) - i + 1, 1);
	}
}

void rmv(int i, int dir, int j){
	if(!dir){
		upd(min(aft[i], j) - i + 1, -1);
		if(min(aft[i], j) != i)
			upd(min(aft[i], j) - i, 1);
	}
	else{
		upd(i - max(bef[i], j) + 1, -1);
		if(max(bef[i], j) != i)
			upd(i - max(bef[i], j), 1);
	}
}

bool cmp(int i, int j){
	if(L[i]/sq != L[j]/sq)
		return L[i] < L[j];
	return R[i] < R[j];
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		sq = sqrt(m) + 1;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			bef[a] = a;
			if(a != 0){
				if(s[a] == s[a-1])
					bef[a] = bef[a-1];
			}
		}
		for(int a=n-1;a>=0;a--){
			aft[a] = a;
			if(a != n-1){
				if(s[a] == s[a+1])
					aft[a] = aft[a+1];
			}
		}
		for(int a=0;a<m;a++){
			scanf("%d %d %d", L+a, R+a, K+a); 
			L[a]--;
			R[a]--;
			ind[a] = a;
		}
		sort(ind, ind+m, cmp);
		int i = 0, j = -1;
		for(int a=0;a<m;a++){
			int l = L[ind[a]], r = R[ind[a]], k = K[ind[a]];
			while(j < r){
				j++;
				add(j, LR, i);
			}
			while(j > r){
				rmv(j, RL, i);
				j--;
			}
			while(i < l){
				rmv(i, LR, j);
				i++;
			}
			while(i > l){
				i--;
				add(i, RL, j);
			}
			res[ind[a]] = qry(MAXN-10) - qry(k-1);
		}
		while(i <= j){
			rmv(i, LR, j);
			i++;
		}
		for(int a=0;a<m;a++){
			printf("%d\n", res[a]);
		}
	}
}
