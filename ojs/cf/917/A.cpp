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

const int MAXN = 5123;

int n, m, k;
char s[MAXN];

int op(char c){
	return (c == '?' || c == '(');
}

int cl(char c){
	return (c == '?' || c == ')');
}

int main (){
	scanf(" %s", s);
	n = strlen(s);
	int res = 0;
	for(int i=0;i<n;i++){
		int cnt = 0;
		int clos = 0;
		for(int j = i;j < n;j++){
			if(s[j] == '(')
				cnt++;
			else if(s[j] == ')'){
				cnt--;
				if(cnt < 0){
					if(!clos) break;
					clos--;
					cnt+=2;
				}
			}
			else{
				if(cnt > 0){
					clos++;
					cnt--;
				}
				else
					cnt++;
			}
			if(cnt == 0)
				res++;
		}
	}
	printf("%d\n", res);
}

