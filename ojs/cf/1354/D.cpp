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

const int MAXN = 1000006;
int n, m;
int bit[MAXN];


void upd(int i, int val){
    while(i < MAXN){
        bit[i] += val;
        i += (i&-i);
    }
}

int qry(int i){
    int ans =0;
    while(i > 0){
        ans += bit[i]; 
        i -= (i&-i);
    }
    return ans;
}

void rmvk(int k){ 
    int pot = 19; 
    int pos = 0;
    //printf("o %d-esimo eh ", k);
    while(pot >= 0){
        int up = pos + (1<<pot);
        if(up < MAXN && bit[up] < k){
            pos = up;
            k -= bit[up];
        }
        pot--;
    }
    pos++;
    upd(pos, -1);
}

int get(){
    int pot = 19; 
    int pos = 0;
    while(pot >= 0){
        int up = pos + (1<<pot);
        if(up < MAXN && bit[up] < 1)
            pos = up;
        pot--;
    }
    pos++;
    return pos;
}

int main (){
    int cnt = 0;
	scanf("%d%d", &n, &m);
    for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        upd(x, 1);
	}
    for(int a=0;a<m;a++){
        int x;
        scanf("%d", &x);
        if(x < 0){
            x = -x;
            rmvk(x);
        }
        else
            upd(x, 1);
    }
    if(qry(MAXN-5) >= 1)
        printf("%d\n", get());
    else
        puts("0");
}

