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

const int MAXN = 12;

int n, k;
int m[MAXN][MAXN];

bool mrk[1123456];


void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int sc(int x){
    stack<int> v;
    int cnt = 4;
    while(cnt--){
        v.push(x%10);
        x/=10;
    }
    int u = 0;
    while(!v.empty()){
        int nxt = v.top();
        v.pop();
        u = m[u][nxt];
    }
    return u;
}
int scc(int x){
    stack<int> v;
    int cnt = 5;
    while(cnt--){
        v.push(x%10);
        x/=10;
    }
    int u = 0;
    while(!v.empty()){
        int nxt = v.top();
        v.pop();
        u = m[u][nxt];
    }
    return u;
}

int test(int x){
    int pot[10];
    pot[0] = 1;
    for(int a=1;a<=6;a++)
        pot[a] = pot[a-1]*10;
    for(int a=0;a<5;a++){
        for(int b=0;b<5;b++){
            if(a == b) continue;
            if(abs(b-a) > 1) continue;
            int olddx = x;
            int da = (x/pot[a])%10;
            int db = (x/pot[b])%10;
            if(da == db) continue;
            x -= da*pot[a];
            x += da*pot[b];
            x -= db*pot[b];
            x += db*pot[a];
            
            if(mrk[x]) return 1; 
            x = olddx;
        }
    }
    for(int d=0;d<=9;d++){
        for(int i=0;i<5;i++){
            int oldx = x;
            int od = (x/pot[i])%10;
            if(od == d) continue;
            x -= od*pot[i];
            x += d*pot[i];
            if(mrk[x]) return 1;
            x = oldx;
        }
    }
    return 0;
}

int main (){
	for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            scanf("%d", &m[a][b]);
        }
	}
    vector<int> v;
    for(int a=0;a<10000;a++){
        int b = sc(a);
        v.pb(a*10 + b);
    }
    for(int a=0;a<100000;a++){
        int b = scc(a);
        if(!b)
            mrk[a] = 1;
    }
    int res = 0;
    for(int a: v){
       res += test(a);
    }
    printf("%d\n", res);
}

