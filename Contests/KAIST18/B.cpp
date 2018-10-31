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

const int MAXN = 10034;

int n, m, k;
vector<char> st;
char s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int mrk[MAXN][MAXN];

int main (){
	scanf("%d", &n);
	scanf(" %s", s);
	int res = 0;
	memset(mrk, 1, sizeof(mrk));
	for(int a=0;a<=n;a++){
		for(int b=0;b<a;b++){
			mrk[b][a] = 0;
		}
	}
	for(int a=0;a<n;a++){
		if(s[a] == '-'){
			res--;
			for(int a=0;a<st.size()-1;a++){
				if(mrk[a][st.size()-1])
					res--;
				mrk[a][st.size()-1] = 0;
			}
			st.pop_back();
		}
		else{
			st.pb(s[a]);
			for(int i=0;i<st.size();i++){
				if(s[a] == st[i] && mrk[i+1][st.size()-2]){
					res++;
					mrk[i][st.size()-1] = 1;
				}
			}
		}
		printf("%d ", res);
	}
	puts("");
}

