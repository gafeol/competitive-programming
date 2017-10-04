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
int s[MAXN], lst[MAXN], ini;

int pos(int i, int v, int l){
	int ans = 0;
	for(int a=1;a<=n;a++){
		if(a == i) continue;
		if(s[a] > v || (s[a] == v && lst[a] < l)) ans++;
	}
	return ans+1;
}

bool cmp(int a, int b){
	return (s[a] > s[b] || (s[a] == s[b] && lst[a] < lst[b]));
}

int ind[MAXN];

int main (){
	scanf("%d%d%d%d", &n, &k, &m, &ini);
	if(n == 1){
		puts("1");
		return 0;
	}
	for(int a=0;a<ini;a++){
		int x;
		scanf("%d", &x);
		s[x]++;
		lst[x] = a+1;
	}
	for(int a=1;a<=n;a++)
		ind[a-1] = a;
	sort(ind, ind+n, cmp);
	for(int a=1;a<=n;a++){
		int bst = pos(a, s[a] + m - ini, ((m - ini == 0) ? lst[a]:m+1));	
		if(bst > k || s[a] + m - ini == 0){
			printf("3 ");
			continue;
		}
		int soma = (s[a] == 0);
		int cnt = m - ini - (s[a] == 0);
		s[a] += soma;
		int save = lst[a];
		if(soma) lst[a] = m+1;
		int posi = 1;
		for(int jj=0;jj<n;jj++){
			int j = ind[jj];
			if(j == a) continue;
			if(cmp(j, a)) posi++;
			else{
				debug("compara %d com o cara %d\n", a, j);
				cnt -= s[a] - s[j] + 1;
				if(cnt >=0)
					posi++;

			}
		}
		if(soma){
			s[a] -= soma;
			lst[a] = save;
		}
		debug("cara %d posi %d\n", a, posi);
		if(posi <= k && s[a] != 0)
			printf("1 ");
		else
			printf("2 ");
	}
	puts("");
}

