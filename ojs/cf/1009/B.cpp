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
vector<int> ns;
char p[MAXN];

int cnt[10];

int main (){
	scanf(" %s", p);
	n = strlen(p);
	for(int a=0;a<n;a++){
		char c = p[a];
		if(c == '0')
			s[a] = 0;
		else if(c == '1')
			s[a] = 1;
		else
			s[a] = 2;
		cnt[s[a]]++;
	}
	int um = 0;
	for(int a=0;a<n;a++){
		cnt[s[a]]--;
		if(s[a] == 0)
			ns.pb(0);
		else if(s[a] == 1){
			if(um)
				continue;
			ns.pb(1);
		}
		else{
			um = 1;
			while(cnt[1] > 0){
				ns.pb(1);
				cnt[1]--;
			}
			ns.pb(2);
		}
	}
	assert(ns.size() == n);
	for(int a=0;a<n;a++){
		s[a] = ns[a];
	}
	ns.clear();
	memset(cnt, 0, sizeof(cnt));
	for(int a=0;a<n;a++){
		cnt[s[a]]++;
		if(s[a] == 2){
			while(cnt[0] > 0){
				ns.pb(0);
				cnt[0]--;
			}
			while(cnt[1] > 0){
				ns.pb(1);
				cnt[1]--;
			}
			while(cnt[2] > 0){
				ns.pb(2);
				cnt[2]--;
			}
		}
	}
	while(cnt[0] > 0){
		ns.pb(0);
		cnt[0]--;
	}
	while(cnt[1] > 0){
		ns.pb(1);
		cnt[1]--;
	}
	while(cnt[2] > 0){
		ns.pb(2);
		cnt[2]--;
	}
	for(int a=0;a<n;a++)
		printf("%d", ns[a]);
}

