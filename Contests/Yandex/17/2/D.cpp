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

int n, m, k;
int s[MAXN];
map<pii, int> ind;
queue<pii> q;

int vi[] = {0, 0, 1, -1};
int vj[] = {1, -1, 0, 0};

int main (){
	scanf("%d", &n);
	int res = 0;
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		q.push(pii(i, j));
		while(!q.empty()){
			i = q.front().fst;
			j = q.front().snd;
			q.pop();
			if(ind[pii(i, j)] == 0)
				res++;
			ind[pii(i, j)]++;
			if(ind[pii(i, j)] == 5){
				ind[pii(i, j)] = 0;
				res--;
				for(int a=0;a<4;a++){
					q.push(pii(i + vi[a], j + vj[a]));
				}
			}
		}
		printf("%d\n", res);
	}
}
