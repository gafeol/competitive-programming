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

const int MAXN = 21234;

int n, m, k;
char s[3][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool valid(int x){
    return x >= 0 && x < n;
}

bool ok(int i, int j){
    if(!valid(i) || !valid(j)) return false;
    if(abs(s[0][i] - s[1][j]) <= 1) return true;
    return false;
}

int test(int i, int j, int d){
    if(!ok(i, j)) return 0;
    return 1 + test(i+d, j+d, d); 
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        scanf(" %s", s[0]);
        scanf(" %s", s[1]);
        int ans = 0;
        for(int i=0;i<n;i++){
            int j = (n-1)/2;
            if(ok(i, j)){
                ans = max(ans, test(i-1, j-1, -1) + test(i+1, j+1, 1) + 1);
            }
            j++;
            if(ok(i, j)){
                ans = max(ans, test(i-1, j-1, -1) + test(i+1, j+1, 1) + 1);
            }
        }
        if(ans >= (n+1)/2)
            puts("POSITIVE");
        else
            puts("NEGATIVE");
    }
}

