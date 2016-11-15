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

int main (){
	scanf("%d", &n);
	scanf(" %s", s);
	int cnt = 0;
	int mx = 0;
	int in = 0;
	int tam = 0;
	for(int a=0;a<n;a++){
		if(s[a] == '_'){
			if(in){
				if(tam)
					cnt++;
			}
			else
				mx = max(mx, tam);
			tam = 0;
		}
		else if(s[a] == '('){
			if(in){
				if(tam)
					cnt++;
			}
			else
				mx = max(mx, tam);
			in++;
			tam = 0;
		}
		else if(s[a] == ')'){
			if(in){
				if(tam)
					cnt++;
			}
			else
				mx = max(mx, tam);
			in--;
			tam = 0;
		}
		else{
			tam++;
			if(!in)
				mx  = max(mx, tam);
		}
	}
	printf("%d %d\n", mx, cnt);

	
}
