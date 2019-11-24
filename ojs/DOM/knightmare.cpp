#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

struct arv{
    int sum, lz;
    int L, R;

    arv() {
        sum = lz = 0;
        L = R = -1;
    }
} root;

vector<arv> tree;

int get(int &son){
    if(son == -1){
        son = tree.size();
        tree.pb(arv());
    }
    return son;
}

void unlaze(int idx, int i, int l){
    if(tree[idx].lz == 0) return;
    int aux = tree[idx].lz;
    tree[idx].lz = 0;
    int L = get(tree[idx].L), R = get(tree[idx].R);
    tree[L].sum += aux;
    tree[L].lz += aux;
}

void upd(int idx, int i, int j, int l, int r, int x){
    if(i > r || j < l) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
       tree[idx].sum += x; 
       if(x < 0 && tree[idx] < 
    }
}

int main (){
    for_tests(t, tt){
        tree.clear();
        tree.pb(root);
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            int i, j, l, r;
            sacnf("%d%d%d%d", &i, &j, &l, &r);
        }
    }
}

