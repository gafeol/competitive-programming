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

int A;

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &A);
		if(A > 2){
			printf("1 ");
			for(int a=0;a<n;a++){
				printf("%c", 'a' + (a%3));
			}
			puts("");
			continue;
		}
		if(A == 1){
			printf("%d ", n);
			for(int a=0;a<n;a++){
				printf("a");
			}
			puts("");
			continue;
		}
		if(n <= 2){
			printf("1 ");
			for(int a=0;a<n;a++){
				printf("%c", 'a'+(a%2)); 
			}
			puts("");
			continue;
		}
		if(n <= 4){
			printf("2 ");
			for(int a=0;a<n;a++){
				printf("%c", 'a'+((a/2)%2));
			}
			puts("");
			continue;
		}
		if(n <= 8){
			printf("3 ");
			string nxt = "aaababbb";
			for(int a=0;a<n;a++)
				printf("%c", nxt[a]);
			puts("");
			continue;
		}
		string res = "aababb";
		int tam = res.size();
		printf("4 ");
		for(int a=0;a<n;a++){
			printf("%c", res[a%tam]);
		}
		puts("");
	}
}

