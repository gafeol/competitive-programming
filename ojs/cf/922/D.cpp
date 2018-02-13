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
string s[MAXN];

ll cnt(string x){
	int tam = x.size();
	ll ns;
	ns = 0;
	ll res = 0;
	for(int a=0;a<tam;a++){
		if(x[a] == 's')
			ns++;
		else
			res += ns;
	}
	return res;
}

bool cmp(string a, string b){
	return (cnt(a+b) > cnt(b+a));
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		cin >> s[a];
	}
	sort(s, s+n, cmp);
	string ans = "";
	for(int a=0;a<n;a++)
		ans.append(s[a]);
	printf("%lld\n", cnt(ans));
}

