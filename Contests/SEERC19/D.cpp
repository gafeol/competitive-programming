#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
const ll modn2 = 1000000009;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % modn2; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)


const int MAXN = 2000006;

ll pri = 104729;
int n, m, k;
ll s[MAXN];

bool check(){
    ll h, h2;
    h = h2 = 0;
    ll pot, pot2;
    pot = pot2 = 1;
    int sz = n/2;
    for(int a=0;a<n;a++)
        s[a+n] = s[a];
    for(int a=0;a<sz;a++){
        pot = mod(pot*pri);
        pot2 = mod2(pot2*pri);
        h  = mod(h*pri + s[a]);
        h2 = mod2(h2*pri + s[a]);
    }
    map<pll, int> mrk;    
    mrk[{h, h2}] = 0;
    for(int i = sz;i-sz+1<n;i++){
        h = mod(h*pri + s[i]);
        h2 = mod2(h2*pri + s[i]);

        h = mod(modn + h - mod(pot*s[i-sz]));
        h2 = mod2(modn2 + h2 - mod2(pot2*s[i-sz]));

        if(mrk.find({h, h2}) != mrk.end()){
            //printf("i %d h %lld h2 %lld\n", i, h, h2);
            //printf("ta batendo com %d\n", mrk[{h, h2}]);
            return false;
        }
        mrk[{h, h2}] = i;
    }

    return true;
}

char pal[MAXN];
vector<ll> val;

int main (){
    srand(time(NULL));
    clock_t clk = clock();
    map<char, int> freq;
    vector<char> chs;
    scanf(" %s", pal);
    n = strlen(pal);
    sort(pal, pal+n);
    for(int a=0;a<26;a++)
        val.pb(rand()%pri);
    for(int a=0;a<n;a++){
       s[a] = val[pal[a]-'a']; 
       chs.pb(pal[a]);
       freq[pal[a]]++;
    }
    if(check()){
        puts("YES");
        printf("%s\n",pal);
        return 0;
    }
    sort(chs.begin(), chs.end());
    chs.erase(unique(chs.begin(), chs.end()), chs.end());
    sort(chs.begin(), chs.end(), [&](char a, char b) { return freq[a] >= freq[b]; });
    assert(freq[chs[0]] > n/2);
    
    int pos = 0;
    for(int x=0;x<n/2;x++){
        pal[pos++] = chs[0];
        freq[chs[0]]--;
    }
    if(chs.size() > 1){
        pal[pos++] = chs[1];
        freq[chs[1]]--;
    }
    for(int i=0;i<chs.size();i++){
        while(freq[chs[i]]--){
            pal[pos++] = chs[i];
            //printf("pos %d bota %c\n", pos, chs[i]);
        }
    }
    for(int a=0;a<n;a++)
        s[a] = val[pal[a]-'a'];
    bool ok = false;
    while(((double)clock() - clk)/CLOCKS_PER_SEC < 0.75){
        if(check()){
            ok = true;
            break;
        }
        random_shuffle(pal, pal+n);
        for(int a=0;a<n;a++)
            s[a] = val[pal[a]-'a'];
    }
    if(ok){
        puts("YES");
        printf("%s\n", pal);
    }
    else
        puts("NO");
}

