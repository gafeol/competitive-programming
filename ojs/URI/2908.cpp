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

const int MAXB = 13, MAXZ = 112;

int pos[MAXB];
int nxt[MAXB][MAXZ];
int cnt[MAXZ];

int b, z;
ll res;

void go(int st){
    while(st--){
        for(int a=1;a<=z;a++){
            if(cnt[a] == b){
                printf("%d ", a);
                cout << res << endl;
                exit(0);
            }
            else if(cnt[a] > 0)
                break;
        }
        for(int a=1;a<=b;a++){
            cnt[pos[a]]--;
            pos[a] = nxt[a][pos[a]]; 
            cnt[pos[a]]++;
        }
        res++;
    }
}

int cycsz[MAXB], zno[MAXB][MAXZ];
vector<int> poss_zoo;

void dfs(int b, int u, int ini){
    assert(zno[b][u] == -1);
    zno[b][u] = cycsz[b]++; 
    if(nxt[b][u] != ini)
        dfs(b, nxt[b][u], ini);
}


void recon(){
    // discover cycsz, make inters, fill zno[beast][vert]
    for(int a=1;a<=b;a++){
        dfs(a, pos[a], pos[a]); 
    }
    for(int i=1;i<=z;i++){
        int aux = 0;
        for(int a=1;a<=b;a++)
            aux += (zno[a][i] != -1);
        if(aux == b){
           poss_zoo.pb(i); 
        }
    }
}


void prep(int zoo, vector<ll> &val, vector<ll> &md){
    //debug("prep zoo %d\n", zoo);
    for(int bst=1;bst<=b;bst++){
        // x % cycsz[bst] == zno[bst][zoo]
        val.pb(zno[bst][zoo]);
        md.pb(cycsz[bst]);
        //debug("bst %d val pb %d md pb %d\n", bst, zno[bst][zoo], cycsz[bst]);
    }
}
//begin of algo

ll gcd(ll a, ll b, ll &x, ll &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}


bool join(ll &a, ll &n, ll b, ll m){
    //cerr << "a " << toString(a) << " n " << toString(n) << " b " << toString(b) << " m " << toString(m) << endl;
    ll x, y;
    ll gc = gcd(n, m, x, y);
    //cerr << " gcd " << toString(gc) <<  endl;
    //cerr << "x " << toString(x) << " y " << toString(y) << endl;
    //debug("gc %lld\n", gc);
    if((a - b)%gc != 0 || (n == m && a != b))
        return false; // n tem solucao

    ll lcm = (n/gc)*m;
    //cerr << " lcm " << toString(lcm) << endl;
    ll res = (a + x * (b - a)/gc % (m / gc) * n) % lcm; 
    res = (res + lcm)%lcm; // get a positive solution

    //cerr << "res " << toString(res) << endl;
    //debug("res %lld\n", res);
    assert(res%n == a && res%m == b);

    // preparing for the next step
    a = res;
    n = lcm;
    return true;
}

ll crt(vector<ll> &val, vector<ll> &md){
    assert(val.size() > 0 &&  val.size() == md.size());
    ll lval = val[0], lmd = md[0];

    for(int i=1;i<val.size();i++){
        if(!join(lval, lmd, val[i], md[i]))
            return -1;
    }
    return lval;
}


int main (){
    memset(zno, -1, sizeof(zno));
	scanf("%d%d", &b, &z);
	for(int a=1;a<=b;a++){
        scanf("%d", pos+a);
        cnt[pos[a]]++;
        for(int i=1;i<=z;i++){
            scanf("%d", &nxt[a][i]);
        }
	}
    go(150);
    recon();

    if(!poss_zoo.size()){
        puts("*");
        return 0;
    }


    ll best = LLONG_MAX, zbest;
    for(int zoo: poss_zoo){
        vector<ll> val, md;
        prep(zoo, val, md);

        ll res = crt(val, md);
        if(res == -1) // n tem solucao
            continue;
        ll meetup_time = 150ll + res;
        
        if(best > meetup_time){
            best = meetup_time;
            zbest = zoo;
        }
    }
    if(best == LLONG_MAX)
        puts("*");
    else
        cout << zbest << " " << best << endl;
}


