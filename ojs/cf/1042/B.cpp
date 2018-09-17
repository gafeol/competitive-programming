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

map<string, int> pr;

int main (){
	scanf("%d", &n);
    const int inf = 400000;
    pr["A"] = inf;
    pr["B"] = inf;
    pr["C"] = inf;
    pr["AB"] = inf;
    pr["AC"] = inf;
    pr["BC"] = inf;
    pr["ABC"] = inf;
    for(int a=0;a<n;a++){
        char s[10];
        int p;
        scanf("%d %s", &p, s);
        int tam = strlen(s);
        sort(s, s+tam);
        pr[s] = min(pr[s], p);
    }

    pr["A"] = min(pr["A"], min(pr["AB"], min(pr["AC"], pr["ABC"])));
    pr["B"] = min(pr["B"], min(pr["AB"], min(pr["BC"], pr["ABC"])));
    pr["C"] = min(pr["C"], min(pr["BC"], min(pr["AC"], pr["ABC"])));
    pr["AB"] = min(pr["AB"], pr["ABC"]);
    pr["AC"] = min(pr["AC"], pr["ABC"]);
    pr["BC"] = min(pr["BC"], pr["ABC"]);
    int ans = min(pr["A"] + pr["B"] + pr["C"], pr["A"] + pr["BC"]);
    ans = min(ans, pr["B"] + pr["AC"]);
    ans = min(ans, pr["C"] + pr["AB"]);
    ans = min(ans, pr["ABC"]);

    if(ans < inf)
        printf("%d\n", ans);
    else
        puts("-1");
}
