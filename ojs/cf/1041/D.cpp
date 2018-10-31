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
pii s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
        scanf("%d%d", &s[a].fst, &s[a].snd);
	}
    int i = 0, j = 0;
    int res = 0;
    int cus = 0;
    while(i < n){
        while(j+1 < n && cus + s[j+1].fst - s[j].snd < k){
            cus += s[j+1].fst - s[j].snd;
            j++;
        }
        res = max(res, s[j].snd + k - cus - s[i].fst);
        if(j > i && i+1 < n)
            cus -= s[i+1].fst - s[i].snd;
        else
            j++;
        i++;
    }
    printf("%d\n", res);
}

