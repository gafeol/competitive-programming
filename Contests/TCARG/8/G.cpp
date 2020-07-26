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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

struct trie {
    int cnt;
    trie* nxt[2];

    trie() {
        cnt = 0;
        nxt[0] = nxt[1] = NULL;
    }
};

trie* add(trie* u, int x, int h=29){
    if(u == NULL)
        u = new trie();
    u->cnt++;
    if(h == -1) return u;
    int b = ((x&(1<<h)) > 0);
    //printf("u add h %d b %d\n", h, b);
    u->nxt[b] = add(u->nxt[b], x, h-1);
    return u;
}

trie* rmv(trie* u, int x, int h=29){
    assert(u != NULL);
    u->cnt--;
    assert(u->cnt >= 0);
    if(u->cnt == 0)
        return NULL;
    if(h == -1) return u;
    int b = ((x&(1<<h)) > 0);
    u->nxt[b] = rmv(u->nxt[b], x, h-1);
    return u;
}

int qry(trie* u, int x, int h=29){
    if(h == -1) return 0;
    int b = ((x&(1<<h)) > 0);
    if(u->nxt[1-b] != NULL && u->nxt[1-b]->cnt > 0)
        return (1<<h) + qry(u->nxt[1-b], x, h-1);
    else
        return qry(u->nxt[b], x, h-1);
}

int main (){
    trie* root = new trie();
    root = add(root, 0);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        char t;
        int x;
        scanf(" %c %d", &t, &x);
        if(t == '+')
            root = add(root, x);
        else if(t == '-')
            root = rmv(root, x);
        else
            printf("%d\n", qry(root, x));
	}
}

