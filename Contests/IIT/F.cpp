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
const int MAXK = 1123;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> X, Y;

pii s[MAXN];

ll res[MAXK*3][MAXK*3];

ll fat[MAXN*3], ifat[3*MAXN];

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll aux = expo(base, e/2);
	aux = mod(aux*aux);
	if(e&1){
		aux = mod(aux*base);
	}
	return aux;
}

ll aux(ll dx, ll dy){
	return mod(fat[dx+dy]*mod(ifat[dx]*ifat[dy]));	
}

int main (){
	fat[0] = 1;
	for(int a=1;a<3*MAXN;a++){
		fat[a] = mod((ll)a*fat[a-1]);
		ifat[a] = mod(expo(fat[a], modn-2));
	}
	for_tests(t, tt){
		scanf("%d%d%d", &n, &m, &k);
		X.clear();
		Y.clear();
		X.pb(1);
		Y.pb(1);
		X.pb(m);
		Y.pb(n);
		for(int a=0;a<k;a++){
			int x, y;
			scanf("%d %d", &x, &y); 
			s[a] = pii(x, y);
			X.pb(x);
			if(x > 1)
				X.pb(x-1);
			if(x < m)
				X.pb(x+1);
			Y.pb(y);
			if(y > 1)
				Y.pb(y-1);
			if(y < n)
				Y.pb(y+1);
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		sort(s, s+k);
		X.erase(unique(X.begin(), X.end()), X.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());
		
		for(int i=Y.size()-1;i>=0;i--){
			for(int j=X.size()-1;j>=0;j--){
	 			int x = X[j];
				int y = Y[i];
				res[i][j] = 0;
				if(i == Y.size()-1 && j == X.size()-1){
					res[i][j] = 1;
					continue;
				}
				if(i < Y.size()-1){
					ll ny = Y[i+1] - Y[i];
					res[i][j] = mod(res[i][j] + res[i+1][j]);
				}
				if(j < X.size()-1){
					ll nx = X[j+1] - X[j];
					res[i][j] = mod(res[i][j] + res[i][j+1]);
				}
				if(binary_search(s, s+k, pii(x, y)))
					res[i][j] = 0;
			}
		}
		printf("%lld\n", res[0][0]);
	}
