#include "bits/stdc++.h"
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

const int MAXN = 100;

int n, m, k;
int s[MAXN];
bool inv;


vector<vector<int>> res;

void make_swp(vector<int> &swp){
    vector<vector<int>> aux;
    int i = 0;
    for(int a=0;a<swp.size();a++){
        int q = swp[a];
        vector<int> ele;
        while(q--){
            ele.pb(s[i]);
            i++;
        }
        aux.pb(ele);
    }
    assert(i == n);
    i = 0; 
    for(int a=aux.size()-1;a>=0;a--){
       for(int x: aux[a]){
           s[i++] = x;
       }
    }
}

void put(int x){
    // se inv false entao seq eh ....... x+1 x+2 x+3 ... n
    //    quero transf em n, n-1, ...., x+1, x, ........
    if(x == 1 && !inv)
        return;
    vector<int> swp;
    if(inv == false){
        int cntEmpty = 0;
        int i = 0;
        while(s[i] != x){
            cntEmpty++;
            i++;
        }
        if(cntEmpty != 0)
            swp.pb(cntEmpty);

        int obj = x-1;
        swp.pb(obj - i + 1);
        for(int a=obj+1;a<n;a++)
            swp.pb(1);
        inv = true;
    }

    else{
        int i = 0;
        for(int a=x+1;a<=n;a++){
            swp.pb(1); 
            i++;
        }
        int cnt = 0;
        for(;i<n;i++){
            cnt++;
            if(s[i] == x)
                break;
        }
        swp.pb(cnt);
        if(i+1 < n)
            swp.pb(n - i - 1);
        inv = false;
    }
    if(swp.size() > 1)
        res.pb(swp);
    make_swp(swp);
    /*
    debug("after swps\n");
    for(int a=0;a<n;a++){
        debug("%d ", s[a]);
    }
    debug("\n\n");
    */
}

int main (){
    inv = true;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}

    for(int v=n;v>=1;v--){
        put(v);
    }

    printf("%d\n", res.size());
    for(vector<int> v: res){
        printf("%d ", v.size());
        for(int x: v)
            printf("%d ", x);
        puts("");
    }

}

