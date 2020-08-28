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

int n; ll k;
ll s[MAXN];
ll ans[MAXN];
int ind[MAXN];

int bit[MAXN];

void upd(int i, int x){
    i+=2;
    while(i < MAXN){
        bit[i] += x;
        i += (i&-i);
    }
}

int qry(int i){
    i+=2;
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= (i&-i);
    }
    return ans;
}

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        ind[a] = a;
	}
    sort(ind, ind+n, [&](int a, int b) { return (s[a] < s[b] || (s[a] == s[b] && a < b)); });
    int i = 0;
    set<int> wait;
    queue<int> q;

    set<tuple<ll, int, int>> ev;
    for(int a=0;a<n;a++){
        ev.insert({s[a], 0, a});
    }
    ll time = 0;
    while(!ev.empty()){
        tuple<ll, int, int> tp = *ev.begin(); 
        ev.erase(ev.begin());
        ll tev; 
        int t, i;
        tie(tev, t, i) = tp;
        //printf("Ev %lld %d %d\n", tev, t, i);
        if(t == 0){
            //printf("add %d\n", i);
            if(qry(i) == 0){
                //printf("ninguem na queue\n");
                // adiciona na queue
                if(q.empty())
                    ev.insert({tev + k, 1, i});
                q.push(i);
                upd(i, 1);
            }
            else
                wait.insert(i);
        }
        else{
            //printf("solve %d at %lld\n", i, tev);
            upd(i, -1); 
            assert(q.front() == i);
            q.pop();
            //printf("queue sz %d front %d\n", q.size(), q.front());
            ans[i] = tev;
            if(!q.empty()){
                int f = q.front();
                ev.insert({tev+k, 1, f});
            }
            else if(!wait.empty()){
                int f = *wait.begin();
                wait.erase(wait.begin());
                upd(f, 1);
                q.push(f);
                ev.insert({tev+k, 1, f});
            }
        }
    }
    for(int a=0;a<n;a++){
        printf("%lld%c", ans[a], " \n"[a==n-1]);
    }
}

