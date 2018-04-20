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

int M[20][20];
int aux[20][20];


int has(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < n && M[i][j] == 1);
}

int vi[] = {0, -1, 1, 0};
int vj[] = {1, 0, 0, -1};

int go(){
	int ch = 0;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			aux[a][b] = 0;
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			int cnt = 0;
			for(int d=0;d<4;d++){
				cnt += has(a+vi[d], b+vj[d]);
			}
			aux[a][b] = ((cnt > 1) || (M[a][b] == 1));
			if(M[a][b] != aux[a][b]) ch = 1;
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			M[a][b] = aux[a][b];
		}
	}
	return ch;
}

int main (){
	scanf(" %s", s);
	n = strlen(s);
	for(int a=0;a<n;a++){
		M[0][a] = (s[a]-'0');	
	}
	for(int a=1;a<n;a++){
		for(int b=0;b<n;b++){
			char c;
			scanf(" %c", &c);
			M[a][b] = (c-'0');
		}
	}
	while(go());
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			printf("%d", M[a][b]);
		}
		printf("\n");
	}
}

