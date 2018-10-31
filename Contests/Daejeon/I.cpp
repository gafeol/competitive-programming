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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int Z[MAXN];

inline void z(int tam){
    int L, R;
    L = R = 0;
    for(int i=1;i<tam;i++){
        if(i > R){
            L = R = i;
            while(R < tam && s[R] == s[R-L])
                R++;
            Z[i] = R - L;
            R--;
        }
        else {
            if(Z[i-L] >= R-i+1){
                L = i;
                while(R < tam && s[R] == s[R-L])
                    R++;
                Z[i] = R-L;
                R--;
            }
            else
                Z[i] = Z[i-L];
        }
    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int i; scanf("%d", &i);
        s[n-a-1] = i;
	}
    s[n] = 0;
    z(n);
    Z[0] = n;
    pair<int, int> best = make_pair(n-1, 1);
    for (int i=1;i<n;i++) {
        int k = 0;
        for (int j = i; j < n; j+=i) {
            if (Z[j] < i) {
                k = n - Z[j] - j;
                break;
            }
        }
        if (k + i < best.first + best.second) {
            best = {k, i};
        }
    }
    printf("%d %d\n", best.first, best.second);
}

