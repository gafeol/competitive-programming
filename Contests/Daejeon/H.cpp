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

template<typename Field> struct dft {
    using F = typename Field::F;
    template <typename It> dft(It a, int n, bool inv = false) {
        assert((n & (n - 1)) == 0);
        {
            vector<size_t> p(n);
            for (int i = 0; i < n; i++)
                p[i] = (p[i >> 1] >> 1) | ((i & 1) * (n / 2));
            for (auto i : p)
                if (i < p[i]) swap(a[i], a[p[i]]);
        }
        F r = Field::nth_root(n);
        if (inv) r = Field::inv(r);
        rec(a, n, r);
    }

    template <typename It> void rec(It a, int n, F r) {
        if (n == 1) return;
        n >>= 1;
        rec(a, n, r * r);
        rec(a + n, n, r * r);
        F w = static_cast<F>(1);
        for (int i = 0; i < n; i++, w = w * r) {
            F tmp = w * a[n + i];
            a[n + i] = a[i] - tmp;
            a[i] = a[i] + tmp;
        }
    }
};

constexpr int P = 7 * 17 * (1 << 23) + 1;
constexpr int g = 3;

struct mod {
    int x;
    mod() : x(0) {}
    mod(int a) : x(a) {}
    mod operator+(const mod& b) {
        int sum = x + b.x;
        return sum < P ? sum : sum - P;
    }
    mod operator-(const mod& b) {
        int sum = x - b.x;
        return sum < 0 ? sum + P : sum;
    }
    mod operator*(const mod& b) {
        return (ll(x)* ll(b.x)) %P;
    }
};

inline mod fexp(mod x, size_t e) {
    mod t(1);
    for(; e; e >>= 1, x = x*x)
        if (e & 1) t = t * x;
    return t;
}

struct M {
    using F = mod;
    static F nth_root(size_t n) { return fexp(g, (P - 1)/n); }
    static F inv(F x) { return fexp(x, P - 2); }
};


int main (){

    int n, m;
    cin >> n >> m;
    string S(n, 0), T(m, 0);
    for (int i = 0; i < n; i++) 
        cin >> ws >> S[i];
    for (int i = 0; i < m; i++) 
        cin >> ws >> T[i];
    //cout << S << endl;
    //cout << T << endl;

    int K = 0;
    while ((1 << K) <= n + m)
        K++;
    const int N = (1 << K);

    const char* TT = "RSP";
    vector<M::F> P[3], Q[3], A[3];

    for (int a = 0; a < 3; a++) {
        P[a] = vector<M::F>(N);
        Q[a] = vector<M::F>(N);
        A[a] = vector<M::F>(N);

        for (int i = 0; i < n; i++)
            P[a][i] = (S[i] == TT[a]);

        for (int i = 0; i < m; i++)
            Q[a][m - 1 - i] = (T[i] == TT[a]);
    }

    for (int b = 0; b < 3; b++) {
        int c = (b + 2)%3;
        dft<M>(P[b].begin(), N);
        dft<M>(Q[c].begin(), N);
        for (int i = 0; i < N; i++)
            A[b][i] = P[b][i] * Q[c][i];
        dft<M>(A[b].begin(), N, true);
        for (int i = 0; i < N; i++)
            A[b][i] = A[b][i] * M::inv(N);
    }

    int bst = 0;
    for (int i = m-1; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += A[j][i].x;
        bst = max(bst, sum);
    }
    /*
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            fprintf(stderr, "%d%c", A[i][j].x, " \n"[j + 1 == N]);
    */
    printf("%d\n", bst);

}

