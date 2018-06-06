#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345, MAXV = 1000010*2;

int n, m, k;
int s[MAXN];

pii qr[MAXN];

int cnt[MAXV];

int bit[MAXN], ind[MAXN];

bool cmp(int a, int b){
	return qr[a].snd < qr[b].snd;
}

int qry(int i){
	i += 2;
	int ans =0;
	while(i < MAXN){
		ans = max(ans, bit[i]);
		i += (i&-i);
	}
	return ans;
}

void upd(int i, int val){
	i += 2;
	while(i > 0){
		bit[i] = max(bit[i], val);
		i -= (i&-i);
	}
}

int res[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] += 1000000;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		qr[a] = pii(i, j);
		ind[a] = a;
	}
	sort(ind, ind+m, cmp);
	int i = 0, j = -1;
	for(int aa = 0;aa < m;aa++){
		int a = ind[aa];
		while(j < qr[a].snd){
			j++;
			cnt[s[j]]++;
			while(cnt[s[j]] > 1){
				cnt[s[i]]--;
				upd(i, j-i);
				i++;
			}
		}
		debug("i %d j %d qr %d\nmin(%d %d)\n", i, j, a, j-i+1, j-qr[a].fst+1);
		int ans = min(j - i + 1, j - qr[a].fst + 1);
		debug("mx %d %d\n", ans, qry(qr[a].fst));
		ans = max(ans, qry(qr[a].fst));
		res[a] = ans;
	}
	for(int a=0;a<m;a++)
		printf("%d\n", res[a]);
}

