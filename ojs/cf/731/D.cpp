#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define hash asdasda

const int MAXN = 512345;

int n, m, k, tam[2];
int s[MAXN][2], leap[MAXN], queb, tleapi, pri[MAXN], tpri;
int dif[MAXN], base[MAXN];

vector<int> w[MAXN];

vector<pii> ans;

ll hash[MAXN][2];

int bb(int i, int j){
	while(i < j){
		int m = (i+j+1)/2;
		if(hash[m][0] == hash[m][1])
			i = m;
		else
			j = m-1;
	}
	if(hash[i][0] != hash[i][1])
		i--;
	return i;
}

void cmp(int i, int j){
	int t = min(tam[i], tam[j]);
	int d = bb(0, t-1) + 1; 
//	printf("primeira diferença em %d t = %d\n", d, t);
	if(d == t){
		if(tam[i] <= tam[j]){
			ans.pb(pii(0,0));
			ans.pb(pii(m-1, 1));
			//printf("ADD (t[%d] <= t[%d]):\n %d %d\n\n", tam[i], tam[j], 0, m-1); 
			return;
		}
	}
	if(s[d][i] < s[d][j]){
//		printf("ADD (%d < %d):\n %d %d\n %d %d\n\n", s[d][i], s[d][j], 0, m-s[d][j]-1, m-s[d][i], m-1);
		ans.pb(pii(0,0));
		ans.pb(pii(m-s[d][j]-1, 1));
		ans.pb(pii(m-s[d][i], 0));
		ans.pb(pii(m-1, 1));
	}
	else{
//		printf("ADD (%d > %d):\n %d %d\n\n", s[d][i], s[d][j], m-s[d][i], m-s[d][j]-1);
		ans.pb(pii(m-s[d][i], 0));
		ans.pb(pii(m-s[d][j]-1, 1));
	}
}

int main (){
	scanf("%d%d", &n, &m);
	memset(dif, 0, sizeof(dif));
	queb = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &tam[a%2]);
		if(a == 0)
			tpri = tam[a%2];
		for(int i=0;i<tam[a%2];i++){
			scanf("%d", &s[i][a%2]);
			s[i][a%2]--;
			w[a].pb(s[i][a%2]);
			if(a == 0)
				pri[i] = s[i][a%2];
			else{
				if(i >= tpri || pri[i] != s[i][a%2])
					dif[i] = 1;
			}
			if(i != 0)
				hash[i][a%2] = hash[i-1][a%2];
			else
				hash[i][a%2] = 0;
			hash[i][a%2] = mod(hash[i][a%2]*m + s[i][a%2]);
		}
		if(a != 0){
//			printf("comparando %d e %d\n", a-1, a);
			cmp(1-(a%2), a%2);
		}
	}
	sort(ans.begin(), ans.end());
	int cnt = 0;
	for(pii ev: ans){
		if(ev.snd == 0)
			cnt++;
		else
			cnt--;
		if(cnt == n-1){
			printf("%d\n", ev.fst);
			return 0;
		}
	}
	puts("-1");
}
