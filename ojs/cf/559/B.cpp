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

string s1, s2;

	string go(string s){
	if(s.size()&1) return s;
	
	int m = (s.size()/2);
	string a = go(s.substr(0, m));
	string b = go(s.substr(m, m));

	if(a > b)
		return b+a;
	return a+b;
}

int main (){
	cin >> s1;
	cin >> s2;
	s1 = go(s1);
	s2 = go(s2);
	if(s1 == s2)
		puts("YES");
	else
		puts("NO");
}
