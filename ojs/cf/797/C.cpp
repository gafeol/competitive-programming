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
char s[MAXN];

multiset<char> q;

stack<char> st;

vector<char> res;

int main (){
	scanf(" %s", s);
	int n = strlen(s);
	for(int a=0;a<n;a++){
		q.insert(s[a]);
	}
	st.push('z'+1);	
	int i = 0;
	while(i < n){
		char top = *q.begin();
		while(top >= st.top()){
			res.pb(st.top());
			st.pop();
		}
		while(s[i] != top){
			q.erase(q.find(s[i]));
			st.push(s[i]);
			i++;
		}
		res.pb(top);
		q.erase(q.find(top));
		i++;
	}
	while(!st.empty()){
		res.pb(st.top());
		st.pop();
	}
	for(char c: res){
		if(c != 'z'+1)
			printf("%c", c);
	}
}
