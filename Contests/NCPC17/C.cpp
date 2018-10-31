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

int n, m, k, ind[MAXN];
int s[MAXN][3];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

multiset<int> q[3];
map<int, set<int> > has[3];

int res[3][MAXN];
int nr[3][MAXN];

int sum (int u){
    int ans = 0;
    for(int a=0;a<3;a++)
        ans += res[a][u];
    return ans;
}

int up(int c, int x){
    auto nxt = q[c].upper_bound(x);
    if(nxt == q[c].end())
        nxt = q[c].begin();
    return *nxt;
}

int dw(int c, int x){
    auto beg = q[c].lower_bound(x); 
    if(beg == q[c].begin())
        return *q[c].rbegin();
    else
        --beg;
    return *beg;
}

int cus(int c, int x){
    if(has[c][x].size() > 1)
        return 0;
    if(q[c].size() == 1) return 0;

    int nxt = up(c, x);
    int beg = dw(c, x);
    
    int ans = 0;
    ans += nxt - x;
    if(nxt < x)
        ans += 360;
    ans += x - beg;
    if(beg > x)
        ans += 360;
    return ans;
}

multiset<pii> bst;
set<int> at;

void atu(int c, int x){
    int u = *has[c][x].begin();
    at.insert(u);
    //printf("nr[%d][%d] = %d\n", c, u, cus(c, x));
    nr[c][u] = cus(c, x);
}

void upd(int c, int u){
    //printf("upd %d u %d\n", c, u);
    if(q[c].size() <= 1) return ;
    int x = s[u][c];
    //printf("x %d\n", x);
    //printf("has %d %d erase %d\n", c, x, u);
    has[c][x].erase(u);
    //printf("q[%d] erase find %d\n", c,x);
    q[c].erase(q[c].find(x));

    if(has[c][x].size() == 0){
       int nxt = up(c, x); 
       int bef = dw(c, x);
       //printf("nxt %d bef %d\n", nxt, bef);
       atu(c, nxt);
       atu(c, bef);
    }
    else if(has[c][x].size() == 1){
        //printf("so atu %d\n", x);
        atu(c, x);
    }
}
//
map<int, int> inv;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d %d %d %d", &s[a][0], &s[a][1], &s[a][2], &ind[a]);
        inv[ind[a]] = a;
        for(int t=0;t<3;t++){
            q[t].insert(s[a][t]);
            has[t][s[a][t]].insert(a); 
        }
	}
    for(int a=0;a<n;a++){
        for(int t=0;t<3;t++){
            res[t][a] = cus(t, s[a][t]);
            nr[t][a] = res[t][a];
            //printf("%d %d = %d\n", t, a, res[t][a]);
        }
        bst.insert(pii(sum(a), -ind[a]));
    }

    while(!bst.empty()){
        pii top = *bst.begin();
        bst.erase(top);
        int u = inv[-top.snd];
        for(int t=0;t<3;t++)
            upd(t, u);
        for(auto a: at){
            bst.erase(pii(sum(a), -ind[a]));
            for(int t=0;t<3;t++)
                res[t][a] = nr[t][a];
            bst.insert(pii(sum(a), -ind[a]));
        }
        at.clear();
        printf("%d\n", ind[u]);
    }
}

