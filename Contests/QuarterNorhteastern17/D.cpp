#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;
const int MAXH = 1e9;

int n, m, k;
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

const int INF = INT_MAX;
struct arv{
    int gc;
    int cnt;
    arv *L, *R;
    arv() : gc(0), cnt(0), L(NULL), R(NULL) {}
    arv* left() { // create if unexistent
        if(L == NULL){
            L = new arv();
        }
        return L;
    }
    arv* right() { // create if unexistent
        if(R == NULL)
            R = new arv();
        return R;
    }
};

int val(arv* u){
    if(u == NULL || u->cnt == 0)
        return 0;
    return u->gc;
}

int tot(arv *u){
    if(u == NULL)
        return 0;
    return u->cnt;
}

arv* root;

void rmv(arv* u, int i, int j, int l){
    if(i == j){
        u->cnt--;
        if(!u->cnt)
            u->gc = 0;
        return ;
    }
    int m = (i+j)/2;
    if(l <= m)
        rmv(u->left(), i, m, l);
    else
        rmv(u->right(), m+1, j, l);
    u->gc = gcd(val(u->L), val(u->R));
    u->cnt = tot(u->L) + tot(u->R);
}

void add(arv* u, int i, int j, int l){
    if(i == j){
        u->gc = l;
        u->cnt++;
        return ;
    }
    int m = (i+j)/2;
    if(l <= m)
        add(u->left(), i, m, l);
    else
        add(u->right(), m+1, j, l);
    u->gc = gcd(val(u->L), val(u->R));
    u->cnt = tot(u->L) + tot(u->R);
}

void clean(arv* u){
    if(u == NULL) return;
    clean(u->L);
    clean(u->R);
    free(u);
}

int main (){
	scanf("%d", &n);
    root = new arv();
    queue<int> q;
    multiset<int> mnVal;
	for(int a=0;a<n;a++){
        char t;
        scanf(" %c", &t);
        if(t == '+'){
            int x;
            scanf("%d", &x);
            add(root, 1, MAXH, x);
            q.push(x);
            mnVal.insert(x);
        }
        else if(t == '-'){
            int x = q.front(); 
            q.pop();
            mnVal.erase(mnVal.find(x));
            rmv(root, 1, MAXH, x);
        }
        else{
            int mn = *mnVal.begin();
            int gc = root->gc;
            if(gc%mn == 0){
                printf("Y%d\n", mn);
            }
            else
                puts("N");
        }
	}
    return 0;
}

