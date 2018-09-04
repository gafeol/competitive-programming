#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1000456;
const int tam = 10;

int n, m, k;
int sq;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


pii q[MAXN];

int ind[MAXN];

bool res[MAXN];

pii ar[MAXN];

ull val[MAXN][tam];
ull hh[tam];


inline void add(int i){
	for(int b=0;b<tam;b++){
		hh[b] ^= val[ar[i].fst][b];
		hh[b] ^= val[ar[i].snd][b];
	}
}

ull h[MAXN][tam];

vector<int> ires[MAXN];

int main (){
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<tam;b++){
			val[a][b] = (((ull)rand()) << 20ll)^((ull)rand());
		}
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;j--;
		ar[a] = pii(i, j);
	}
	int nq;
	scanf("%d", &nq);
	for(int a=0;a<nq;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		q[a] =	pii(i, j);
	}
	for(int a=0;a<m;a++){
		for(int b=0;b<tam;b++)
			h[a][b] = hh[b];
		add(a);		
	}
	for(int b=0;b<tam;b++)
		h[m][b] = hh[b];
	for(int a=0;a<nq;a++){
		int ok = 1;
		for(int b=0;b<tam;b++){
			if((h[q[a].snd][b]^h[q[a].fst-1][b]) != 0ull){
				ok = 0;
				break;
			}
		}
		if(ok)
			puts("Yes");
		else
			puts("No");
	}
}
