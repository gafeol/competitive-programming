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

const int MAXN = 212;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> M[MAXN][MAXN];

int res[MAXN];

void upd(int x, int y){
    for(int p: M[x][y]){
        res[p] = 1;
    }

}

int main (){
    int d;
    scanf("%d%d", &n, &d);
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int x, y;
        scanf("%d%d", &x, &y);
        M[x][y].pb(a);
    }
    int lim = d;
    for(int y=0;y<d;y++){
        for(int x=0;x<lim;x++){
            //printf("1 check %d %d\n", x, y);
            upd(x, y);
        }
        lim--;
    }
    lim = 0;
    for(int y=d;y<=n;y++){
        for(int x=0;x<lim;x++){
            //printf("2 check %d %d\n", x, y);
            upd(x, y); 
        }
        lim++;
    }
    int ini = n-d+1;
    for(int y=n;y>n-d;y--){
        for(int x=ini;x <= n;x++){
            //printf("3 check %d %d\n", x, y);
            upd(x, y);
        }
        ini++;
    }
    ini = n;
    for(int y=n-d-1;y>=0;y--){
        for(int x=ini;x<=n;x++){
            //printf("4 check %d %d\n", x, y);
            upd(x, y);
        }
        ini--;
    }
    for(int a=0;a<m;a++){
        if(res[a])
            puts("NO");
        else
            puts("YES");
    }
}

