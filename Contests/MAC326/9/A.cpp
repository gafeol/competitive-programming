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

multiset<int> val;

set<int> has[MAXN];

map<int, int> cnt;
int mx;

int main (){
    freopen("homo.in", "r", stdin);
    freopen("homo.out", "w", stdout);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        char s[MAXN];
        int x;
        scanf(" %s %d", s, &x);
        if(s[0] == 'i'){
            val.insert(x);
            if(cnt[x] != 0){
                has[cnt[x]].erase(x);
            }
            has[++cnt[x]].insert(x);
            mx = max(mx, cnt[x]);
        }
        else{
            if(cnt[x] != 0) {
                val.erase(val.find(x));
                int tam = cnt[x]--;
                has[tam].erase(x);
                if(has[tam].size() == 0 && mx == tam)
                    mx = tam-1;

                if(tam-1 > 0)
                    has[tam-1].insert(x);
            }
        }
        bool het = (!val.empty() && (*val.begin() != *val.rbegin()));
        bool hom = (mx > 1);
        if(het && hom)
            puts("both");
        else if(het && !hom)
            puts("hetero");
        else if(!het && hom)
            puts("homo");
        else
            puts("neither");
	}
}

