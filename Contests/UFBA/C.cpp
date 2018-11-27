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

const int MAXN = 212345;

ll n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll M[3][3];
ll base[3][3], aux[3][3];

void expo(ll e){
	if(e == 1) return ;

	expo(e/2ll);

	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			aux[a][b] = 0;
			for(int c=0;c<3;c++){
				aux[a][b] = mod(aux[a][b] + M[a][c]*M[c][b]);
			}
		}
	}
	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			M[a][b] = aux[a][b];
		}
	}
	
	if((e&1)){
		for(int a=0;a<3;a++){
			for(int b=0;b<3;b++){
				aux[a][b] = 0;
				for(int c=0;c<3;c++){
					aux[a][b] = mod(aux[a][b] + M[a][c]*base[c][b]);
				}
			}
		}
		for(int a=0;a<3;a++){
			for(int b=0;b<3;b++){
				M[a][b] = aux[a][b];
			}
		}
	}
}

void print(){
	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			printf(" %lld", M[a][b]);
		}
		puts("");
	}
	puts("");
}

int main (){
	M[0][0] = 2; M[0][1] = 1; M[0][2] = 0;
	M[1][0] = 0; M[1][1] = 1; M[1][2] = -1;
	M[2][0] = 0; M[2][1] = 0; M[2][2] = 1;

	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			base[a][b] = M[a][b];
		}
	}

	for_tests(t, tt){
		for(int a=0;a<3;a++){
			for(int b=0;b<3;b++){
				M[a][b] = base[a][b];
			}
		}
		base[1][2] = M[1][2] = -1;

		scanf("%lld", &n);
		expo(n);
		ll sum = mod(M[0][1]*(mod(n)) + M[0][2]);
		//printf("sum %lld\n", sum);
		//print();
		for(int a=0;a<3;a++){
			for(int b=0;b<3;b++){
				M[a][b] = base[a][b];
			}
		}
		base[1][2] = M[1][2] = 1;
		expo(n);
		//print();
		sum = mod(modn + mod(sum - (M[0][1] + M[0][2])));
		printf("%lld\n", sum);
	}
}

