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

const int MAXN = 1123456;

int n, m, k;
char s[2][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf("%d", &n);
    scanf(" %s %s", s[0], s[1]);
    for(int a=0;a<n;a++){
        s[0][a] -= '0';
        s[1][a] -= '0';
    }
    int res = 0;
    for(int a=0;a<n;a++){
        if(s[0][a] == s[1][a]) continue;  
        res++;
        if(s[0][a] && s[1][a+1])
            s[0][a+1] = 1;
        if(s[1][a] && (s[0][a+1] && !s[1][a+1]))
            s[0][a+1] = 0;
    }
    printf("%d\n", res);
}

