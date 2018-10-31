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

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


int ind[MAXN];

int win[MAXN];

bool cmp(int a, int b){
	return s[a] > s[b];
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		ind[a] = a;
	}
	sort(ind, ind+n, cmp);
	for(int a=0;a<n;a++){
		int i = ind[a];
		int mx = 0;
		for(int d=i-s[i];d>=0;d -= s[i])
			mx = max(mx, win[d]);	
		for(int d=i+s[i];d<n;d+=s[i])
			mx = max(mx, win[d]);
		if(mx == 0)	
			win[i] = 1;
		else
			win[i] = 0;
	}
	for(int a=0;a<n;a++){
		if(win[a])
			printf("B");
		else
			printf("A");
	}
}

