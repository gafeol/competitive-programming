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

set<int> pos;
multiset<int> dif;

void add(int x){
    auto aft = pos.lower_bound(x);
    if(aft != pos.begin()){
        auto bef = aft;
        bef--;
        if(aft != pos.end())
            dif.erase(dif.find(*aft - *bef));
        dif.insert(x - *bef);
    }

    if(aft != pos.end())
        dif.insert(*aft - x);
    pos.insert(x);
}

void rmv(int x){
    pos.erase(x);
    auto aft = pos.lower_bound(x);
    if(aft != pos.begin()){
        auto bef = aft;
        bef--;
        if(aft != pos.end())
            dif.insert(*aft - *bef);
        dif.erase(dif.find(x - *bef));
    }

    if(aft != pos.end())
        dif.erase(dif.find(*aft - x));
}

int qry(){
    if(pos.size() <= 2)
        return 0;
    else
        return *pos.rbegin() - *pos.begin() - *dif.rbegin();
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d",s+a);
        add(s[a]);
	}
    printf("%d\n", qry());
    for(int a=0;a<m;a++){
        int t, x;
        scanf("%d%d", &t, &x);
        if(t == 1)
            add(x);
        else
            rmv(x);
        printf("%d\n", qry());
    }
}

