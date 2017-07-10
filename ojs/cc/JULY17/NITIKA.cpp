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
stack<char> res;

int main (){
	for_tests(t, tt){
		scanf(" %[^\n]", s);
		int tam = strlen(s);
		int cnt = 0;
		for(int a=tam-1;a>=0;a--){
			if(cnt == 0){
				if(a == 0 || s[a-1] == ' ')
					res.push(toupper(s[a]));
				else
					res.push(tolower(s[a]));
			}
			else{
				if(a == 0 || s[a-1] == ' '){
					res.push('.');
					res.push(toupper(s[a]));
					if(a != 0)
						res.push(' ');
				}
			}

			if(s[a] == ' ')
				cnt++;
		}
		while(!res.empty()){
			printf("%c", res.top());
			res.pop();
		}
		printf("\n");
	}
}
