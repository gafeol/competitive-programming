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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

using pt = complex<int>;

pt solve(int n, int k) {
    //fprintf(stderr, "solve %d %d\n", n, k);
    if (k == 1) {
        if (n == 0) return {0, 0};
        if (n == 1) return {0, 1};
        if (n == 2) return {1, 1};
        if (n == 3) return {1, 0};
    }
    assert(k);
    const int p = (1 << (2 * (k-1)));
    const int m = n%p;
    //fprintf(stderr, "p = %d, m = %d\n", p, m);
    switch(n/p) {
        case 0:
        return pt{0, (1 << (k - 1)) - 1} + solve(p - 1 - m, k - 1) * pt{0, -1};
        case 1:
        return pt{0, 1 << (k - 1)} + solve(m, k - 1);
        case 2:
        return pt{1 << (k - 1), 1 << (k - 1)} + solve(m, k - 1);
        case 3:
        return pt{(1 << k) - 1, 0} + solve(p-1-m, k - 1) * pt{0, 1};
    }
}

int main (){
    int n, m, k = 0;
	scanf("%d%d", &n, &m);
    while ((1 << k) < n) k++;
    auto ans = solve(--m, k);
    printf("%d %d\n", 1 + real(ans), 1 + imag(ans));
}

