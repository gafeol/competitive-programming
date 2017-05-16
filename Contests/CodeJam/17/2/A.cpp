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
#define debug(args...)// fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212;

int n, m, k;
int s[MAXN];
int cnt[10];

int main (){
	for_tests(t, tt){
		memset(s, 0, sizeof(s));
		memset(cnt, 0, sizeof(cnt));
		int res = 0;
		scanf("%d %d", &n, &k);
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			s[a] = s[a]%k;
			cnt[s[a]]++;
		}
		res = 0;
		int soma = 1;
		res += cnt[0];
		cnt[0] = 0;
		for(int a=1;a<k;a++){
			if(a != k-a){
				int mn = min(cnt[a], cnt[k-a]);
				if(mn != 0){
					res += soma;
					soma = 0;
				}
				else
					continue;
				cnt[a] -= mn;
				cnt[k-a] -= mn;
				res += mn-1;	
				soma += 1;
			}
			else{
				int mn = cnt[a]/2;
				if(mn != 0){
					res += soma;
					soma = 0;
				}
				else continue;
				res += mn-1; 
				soma += 1;
				cnt[a] -= 2*mn;
			}
		}
		for(int a=1;a<k;a++){
			if(cnt[a] != 0){
				int aux = cnt[a]/k;
				cnt[a] = cnt[a]%k;
				if(aux != 0){
					res += soma;
					soma = 0;
				}
				else
					continue;
				debug("res += %d res %d\n", aux-1, res);
				res += aux-1;
				soma += 1;
			}
		}
		if(soma != 0 && cnt[0] + cnt[1] + cnt[2] + cnt[3] != 0){
			res += soma;
			soma = 0;
		}
		if(k == 4){
			int S  = 4;
			if(cnt[2] != 0){
				res += soma;
				soma = 0;
				S = (S + 2)%k;
			}
			while(cnt[1] != 0){
				res += soma;
				soma = 0;
				if(S == 0) res++;
				S = (S + 1)%k;
				cnt[1]--;
			}

			while(cnt[3] != 0){
				res += soma;
				soma = 0;
				if(S == 0) res++;
				S = (S + 3)%k;
				cnt[3]--;
			}
		}
		printf("Case #%d: %d\n", tt, res);
	}
}
