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

pair<int, int> f(pair<int, int> p, int dir) {
    if (p.first == 0)
        dir *= -1;
    p.first *= dir;
    p.second *= dir;
    swap(p.first, p.second);
    return p;
}

int main (){
	scanf("%d", &n);
    pair<int, int> st = make_pair(0, 0);
    pair<int, int> dir = make_pair(1, 0);
	for(int i=0;i<n;i++){
        int p = (i + 2) / 2;
	    int l, t; scanf("%d %d", &l, &t);
        if (dir.first == 0) {
            int d = dir.second * p;
            printf("%d ", abs(d - st.second));
            st.second = d;
        } else {
            int d = dir.first * p;
            printf("%d ", abs(d - st.first));
            st.first = d;
        }
        dir = f(dir, t);
    }
    printf("\n");
}

