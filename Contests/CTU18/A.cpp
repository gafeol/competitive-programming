#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) { out << t << "\n"; } template <typename T, typename... Args> void write(ostream& out, T t, Args... args) {
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

int n, m, k;

char s[4][4];

struct dd{
	int v;
	char d[3][3];
};

vector<dd> dados;

int main (){
	dados.pb({1, {{':', ':', ':'}, 
			   	  {':', 'o', ':'}, 
				  {':', ':', ':'}}});

	dados.pb({2, {{'o', ':', ':'}, 
			   	  {':', ':', ':'}, 
				  {':', ':', 'o'}}});

	dados.pb({2, {{':', ':', 'o'}, 
			   	  {':', ':', ':'}, 
				  {'o', ':', ':'}}});

	dados.pb({3, {{':', ':', 'o'}, 
			   	  {':', 'o', ':'}, 
				  {'o', ':', ':'}}});

	dados.pb({3, {{'o', ':', ':'}, 
			   	  {':', 'o', ':'}, 
				  {':', ':', 'o'}}});

	dados.pb({4, {{'o', ':', 'o'}, 
			   	  {':', ':', ':'}, 
				  {'o', ':', 'o'}}});

	dados.pb({5, {{'o', ':', 'o'}, 
			   	  {':', 'o', ':'}, 
				  {'o', ':', 'o'}}});


	dados.pb({6, {{'o', ':', 'o'}, 
			   	  {'o', ':', 'o'}, 
				  {'o', ':', 'o'}}});

	dados.pb({6, {{'o', 'o', 'o'}, 
			   	  {':', ':', ':'}, 
				  {'o', 'o', 'o'}}});


	char d[4][4];
	for(int a=0;a<3;a++){
		scanf(" %s", d[a]);
	}
	for(dd op: dados){
		bool eq = true;
		for(int a=0;a<3 && eq;a++){
			for(int b=0;b<3 && eq;b++){
				if(d[a][b] != op.d[a][b]){
					eq = false;
					break;
				}
			}
		}
		if(eq){
			printf("%d\n", op.v);
			return 0;
		}
	}
	puts("unknown");
}

