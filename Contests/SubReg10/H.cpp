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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

string notas[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

int f(string s){
	if(s == "Db") s = "C#";
	if(s == "Eb") s = "D#";
	if(s == "Gb") s = "F#";
	if(s == "Ab") s = "G#";
	if(s == "Bb") s = "A#";
	if(s == "Cb") s = "B";
	if(s == "B#") s = "C";
	if(s == "Fb") s = "E";
	if(s == "E#") s = "F";
	for(int a=0;a<12;a++)
		if(s == notas[a])
			return a;
}

int ms[MAXN];
int t[MAXN];

int main (){
	while(scanf("%d%d", &n, &m) && n+m){
		for(int a=0;a<n;a++){
			char nota[5];
			scanf(" %s", nota);
			ms[a+1] = f(nota);
		}
		for(int a=0;a<m;a++){
			char nota[5];
			scanf(" %s", nota);
			t[a+1] = f(nota);
		}

		int ff[MAXN];
		memset(ff, 0, sizeof(ff));
		ff[0] = 0; ff[1] = 0;
		for(int i=2;i<=m;i++){
			int ii = ff[i-1];	
			while(ii != 0 && t[ii+1] != t[i])
				ii = ff[ii];
			if(t[ii+1] == t[i])
				ff[i] = ii+1;
		}
		int res = 0;
		for(int a=0;a<12 && res == 0;a++){
			for(int b=1;b<=m;b++){
				t[b] = (t[b]+1)%12;
			}
			int deg = 0;
			for(int i=1;i<=n;i++){
				if(ms[i] == t[deg+1])
					deg++;
				else{
					while(deg != 0 && t[deg+1] != ms[i])
						deg = ff[deg];
					if(t[deg+1] == ms[i])
						deg++;
				}
				if(deg == m){
					res = 1;
					break;
				}
			}
		}
		if(res)
			puts("S");
		else
			puts("N");
	}
}

