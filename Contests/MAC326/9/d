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


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int MAXT = MAXN*163;

int n, m, k;
int s[MAXN];
int L[MAXT], R[MAXT];

void prep_cin(){
	cin.tie(0);
}

vector<ll> tree;

ll v(int x){
    // Retorna o valor de tree[x] se x ja existe na arv, senao retorna 0
    if(x == -1) return 0;
    return tree[x];
}

void ex(int u, int dir){
    // Se dir[u] nao existir, cria o no
    if(!dir){
        if(L[u] != -1) return ;
        L[u] = tree.size();
    }
    else{
        if(R[u] != -1) return ;
        R[u] = tree.size();
    }
    tree.pb(0ll);
}

int lcp(int ra, int rb, int i = 0, int j = n-1){
    if(i == j){
        return i-(v(ra) != v(rb));
    }
    int m = (i + j)/2;
    if(v(L[ra]) == v(L[rb])){
        ex(ra, 1);
        ex(rb, 1);
        return lcp(R[ra], R[rb], m+1, j);
    }
    else{
        ex(ra, 0);
        ex(rb, 0);
        return lcp(L[ra], L[rb], i, m);
    }
}

ll qry(int idx, int i, int j, int l){
    if(idx == -1) return 0;
    if(i > l || j < l) return 0;
    if(i == j) 
        return tree[idx];
    int m = ((i+j)>>1);
    return qry(L[idx], i, m, l) + 
            qry(R[idx], m+1, j, l);
}

ll pot[MAXN];

// antes de dar o upd, tree.size() eh a raiz da nova arvore
void upd(int idx, int i, int j, int l, ll x){
    int nidx = tree.size();
    //printf("upd %d -> %d\n", idx, nidx);
    tree.pb(0);
    if(i > l || j < l) return ;
    if(i == j){
        tree[nidx] = x;
        //printf("tree[%d] = %lld\n", nidx, x);
        return ;
    }
    int m = (i + j)/2;
    if(l <= m){
       R[nidx] = R[idx];
       //printf("idx L %d R %d\n", L[idx], R[idx]);
       //printf("nidx L %d  R %d\n", L[nidx], R[nidx]);
       ex(idx, 0);
       L[nidx] = tree.size();
       //printf("GO LEFT\n");
       upd(L[idx], i, m, l, x);
    }
    else{
        L[nidx] = L[idx];
        ex(idx, 1);
        R[nidx] = tree.size();
       //printf("GO RIGHT\n");
        upd(R[idx], m+1, j, l, x);

    }
    tree[nidx] = mod(mod(v(L[nidx])*pot[j - m]) + v(R[nidx]));
    //printf("tree[%d] = %lld\n", nidx, tree[nidx]);
}

void printt(int idx, int i, int j){
    if(idx == -1){
        //printf("idx -1\n");
        return ;
    }
    //printf("idx %d i %d j %d x %lld\n", idx, i, j, tree[idx]);
    if(i == j) return;
    int m = (i+j)/2;
    printt(L[idx], i, m);
    printt(R[idx], m+1, j);
}

struct tree_cmp {
    bool operator() (const int &a, const int &b) const {
        int l = lcp(a, b);
        if(l == n-1) return 0;
        //printf("l %d a %d b %d\n", l, a, b);
        int la = qry(a, 0, n-1, l+1);
        int lb = qry(b, 0, n-1, l+1); //PODE APAGAR
        assert(la != lb);
        return (la == 0);
    }
};

multiset<int, tree_cmp> ord;

void print(){
    puts("Print:");
    for(auto it: ord){
        printf("%d ", it);
    }
    puts("");
}

int main (){
    pot[0] = 1;
    for(int a=1;a<MAXN;a++)
        pot[a] = mod(pot[a-1]*7ll);
    for_tests(t, tt){
        ll res = 1;
        int r = 0;
        tree.clear();
        tree.pb(0);
        ord.clear();
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        scanf("%d%d", &n, &m);
        for(int a=0;a<m;a++){
            char c;
            scanf(" %c", &c); 
            if(c == '!'){
                int x;
                scanf("%d", &x);
                int i = n-1-x; 
                int nr; 
               /// puts("VELHA ARV");
                //printt(r, 0, n-1);
                while(i >= 0 && qry(r, 0, n-1, i) == 1){
                    nr = tree.size();
                    upd(r, 0, n-1, i, 0);
                    //printf("upd %d 0\n", i);
                    r = nr;
                    i--;
                }
                if(i >= 0){
                    nr = tree.size();
                    //printf("upd %d 1\n", i);
                    upd(r, 0, n-1, i, 1);
                    r = nr;
                }
                //puts("NOVA ARV");
                //printt(r, 0, n-1);
                //printf("insere %d\n", r);
                ord.insert(r);

                //print();
                // fazer conta com os dois ais proximos pra ver quanto adiciona na resposta
                auto it = ord.find(r); 
                int mx = -1;
                if(it != ord.begin()){
                    auto beg = --ord.find(r);
                    mx = max(mx, lcp(r,*beg));  
                }
                it++;
                if(it != ord.end()){
                    mx = max(mx, lcp(r, *it));
                }

                //printf("mx %d res += %d\n", mx, n-1-mx);
                res = res + (ll)n-1ll-mx;
            }
            else{
                printf("%lld\n", res);
            }
        }
    }
}

