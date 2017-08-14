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

const int MAXN = 212345, MAXS = 5000056;

int n, m, k;
int s[MAXS];
char S[MAXS];
vector<char> st[MAXN];
int maxi[MAXS];
int mid[MAXS];

bool cmp(pii a, pii b){
	return (a.fst > b.fst);
}

int main (){
	scanf("%d", &n);
	int mx = 0;
	memset(mid, -1, sizeof(mid));
	memset(maxi, -1, sizeof(maxi));
	for(int a=0;a<n;a++){
		int tam;
		scanf(" %s %d", S, &tam);
		int len = strlen(S);
		for(int i=0;i<len;i++){
			st[a].pb(S[i]);
		}
		while(tam--){
			int i;
			scanf("%d", &i);
			mx = max(mx, i+len-1);
			if(i + len-1 > maxi[i]){
				maxi[i] = i+len-1;
				mid[i] = a;
			}
		}
	}
	int ate = -1, i = 0,  id = -1;
	for(int a=1;a<=mx;a++){
		if(mid[a] == -1 && id == -1){
			printf("a");
		}
		else{
			if(ate <= maxi[a]){
				ate = maxi[a];
				i = 0;
				id = mid[a];
			}
			printf("%c", st[id][i]);
			i++;
		}
		if(a == ate || i == st[id].size())
			id = -1;
	}
	puts("");
}
