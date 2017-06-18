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

void print(int bola, int lin){
	puts("YES");
	for(int a=2;a<bola+2;a++){
		printf("1 %d\n", a); 
	}
	int u = 1;
	for(int v = 0;v<lin;v++){
		printf("%d %d\n", u, v+bola+2);
		u = v+bola+2;
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &k);
		if(n == 2){
			if(k != 1)
				puts("NO");
			else{
				puts("YES");
				printf("1 2\n");
			}
			continue;
		}
		int bola = n-2;
		int dist = 3;
		int res = 0;
		while(bola > 1){
			int lin = dist-2;
			int center = dist/2 - 1;
			int coid = 0;
			int cnt = lin;
			while(cnt > n/2){
				coid++;
				cnt--;
			}
			int beauty = abs(center - coid);
			if(beauty == k){
				print(bola, lin);
				res = 1;
				break;
			}

			bola--;
			dist++;
		}
		if(!res){
			int lin = dist-2;
			int center = dist/2 - 1;
			int coid = 0;
			int cnt = lin;
			while(cnt > n/2){
				coid++;
				cnt--;
			}
			int beauty = abs(center - coid);
			if(beauty == k){
				print(bola, lin);
				res = 1;
			}
		}
		if(!res)
			puts("NO");
	}
}
