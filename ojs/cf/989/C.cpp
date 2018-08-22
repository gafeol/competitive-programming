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

int n[4];

char m[51][51];

void put(int i, int j, int c){
	char cor;
	cor = 'A' + c;
	m[i][j] = cor;
	n[c]--;
	assert(n[c] >= 0);
}

int main (){
	int x = 0;
	for(int a=0;a<4;a++)
		scanf("%d", n+a);
	
	put(0, 49, 3);
	int col = 0;
	int lin = 0;
	n[2]--; // save one for later
	for(int c=0;c<3;c++){
		while(n[c]){
			put(lin, col, c);
			m[lin+1][col] = 'D';
			m[lin+1][col+1] = 'D';
			m[lin][col+1] = 'D';
			col+=2;
			if(col >= 50){
				col = 0;
				lin += 2;
			}
		}
		while(col != 0){
			m[lin][col] = 'D';
			m[lin+1][col+1] = 'D';
			m[lin+1][col] = 'D';
			col++;
			if(col >= 50){
				col = 0;
				lin += 2;
			}
		}
	}
	for(int a=0;a<50;a++){
		m[lin][col] = 'C';
		col++;
		if(col >= 50){
			col = 0;
			lin++;
		}
	}
	while(n[3]){
		put(lin, col, 3);
		m[lin+1][col] = 'C';
		m[lin+1][col+1] = 'C';
		m[lin][col+1] = 'C';
		col+=2;
		if(col >= 50){
			col = 0;
			lin += 2;
		}
	}
	while(col != 0){
		m[lin][col] = 'C';
		m[lin+1][col] = 'C';
		col++;
		if(col >= 50){
			col = 0;
			lin += 2;
		}
	}
	printf("%d 50\n", lin); 
	for(int a=0;a<lin;a++){
		for(int b=0;b<50;b++){
			printf("%c", m[a][b]); 
		}
		puts("");
	}
}

