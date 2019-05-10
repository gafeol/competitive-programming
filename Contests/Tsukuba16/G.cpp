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

const int MAXN = 512345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

map<int, int> nxt;

int qry(int x){
    if(nxt.find(x) == nxt.end()) return x;
    return nxt[x] = qry(nxt[x]);
}

void add(int x){
    if(nxt.find(x) == nxt.end()){
        nxt[x] = x - 1;
        return ;
    }
    nxt.erase(x);
    add(x-1);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        int p = qry(s[a]);
        if((p == 0 && nxt.size() > s[a]) || nxt.find(0) != nxt.end()){
            puts("No");
            continue;
        }
        add(s[a]);
        puts("Yes");
	}

}
