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

const int MAXN = 412345;

int n, m, k;
char s[MAXN];

int cnt[MAXN];

vector<char> odd, ev;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c", &s[a]);
		cnt[s[a]]++;
	}
	for(char a=32;a<=126;a++){
		if(cnt[a]&1){
			odd.pb(a);
			cnt[a]--;
		}
		if(cnt[a] > 0)
			ev.pb(a);
	}
	int j = 0, od = 0;
	if(odd.size() == 0){
		puts("1");
		stack <char> st;
		for(char a=32;a<=126;a++){
			while(cnt[a] != 0){
				printf("%c", a);
				st.push(a);
				cnt[a] -= 2;
			}
		}
		while(!st.empty()){
			printf("%c", st.top());
			st.pop();
		}
		return 0;
	}

	while((n - odd.size())%(2*odd.size()) != 0){
		if(cnt[ev[j]] == 0) j++;
		cnt[ev[j]]-=2;
		odd.pb(ev[j]);
		odd.pb(ev[j]);
	}
	printf("%d\n", (int)odd.size());
	int len = (n - odd.size())/odd.size();
	debug("len %d\n", len);
	while(odd.size() > od){
		stack <char> st;
		for(int i=0;i<len;i+=2){
			if(cnt[ev[j]] == 0)
				j++;
			cnt[ev[j]]-=2;
			printf("%c", ev[j]);
			st.push(ev[j]);
		}
		printf("%c", odd[od]);
		od++;
		while(!st.empty()){
			printf("%c", st.top());
			st.pop();
		}
		printf(" ");
	}
}

