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

set<int> tim; 
int res[MAXN];
map<int, int> d;

bool cmp(int a, int b){
    return s[a] < s[b];
}
int ind[MAXN];

int main (){
	scanf("%d%d%d", &n, &m, &k);
    int nd = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        ind[a] = a;
	}
    sort(ind, ind+n, cmp);
    for(int aa=0;aa<n;aa++){
        int a = ind[aa];

        if(tim.empty() || *tim.begin() >= s[a] - k){
            res[a] = ++nd;
            d[s[a]] = nd;
            tim.insert(s[a]);
        }
        else{
            int bf = *tim.begin(); 
            tim.erase(tim.begin());
            tim.insert(s[a]);
            d[s[a]] = d[bf];
            res[a] = d[s[a]];
        }

    }
    printf("%d\n", nd);
    for(int a=0;a<n;a++)
        printf("%d%c", res[a], " \n"[a == n-1]);
}

