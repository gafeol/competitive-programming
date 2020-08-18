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

int root;

struct no {
    int nxt[30];
    int f[30];
    
    int next(char c){
        if(nxt[c-'a'] == -1)
            return -1;
        return nxt[c-'a'];
    }

    no() {
        for(int a=0;a<30;a++){
            nxt[a] = -1;
            f[a] = 0;
        }
    }
};

vector<no> trie;

inline int create(int u, char c){
    if(trie[u].next(c) == -1){
        trie[u].nxt[c-'a'] = trie.size();
        trie.push_back(no()); 
    }
    return trie[u].next(c);
}

inline void add(string s){ // adds string s to trie
     int u = root; 
     int freq[30];
     memset(freq, 0, sizeof(freq));
     for(char c: s)
         freq[c-'a']++;
     for(int a=0;a<30;a++)
        trie[u].f[a] += (freq[a] > 0);
     for(char c: s){
        u = create(u, c);
        freq[c-'a']--;
        for(int a=0;a<30;a++){
            trie[u].f[a] += (freq[a] > 0);
        }
     }
}

inline void init(){
    trie.clear();
    trie.push_back(no());
    root = 0;
}


void print() { // prints the whole trie
    for(int i=0;i<trie.size();i++){
        printf("i %d nxt: ", i); 
        for(int a=0;a<30;a++){
            if(trie[i].nxt[a] == -1) continue;
            printf("(%c %d) ", 'a'+a, trie[i].nxt[a]); 
        }
        puts("");
    }
}


inline int query(string s){
    int u = root; 
    for(int a=0;a+1<s.size();a++){
        u = trie[u].next(s[a]);
        if(u == -1)
            return 0;
    }
    return trie[u].f[s.back()-'a'];
}

char pal[1000006];

int main (){
    init();
	scanf("%d", &n);
    vector<int> ind;
    vector<string> s;
	for(int a=0;a<n;a++){
        scanf(" %s", pal);
        int sz= strlen(pal);
        reverse(pal, pal+sz);
        s.pb(pal);
        ind.pb(a);
	}
    sort(ind.begin(), ind.end(), [&](int a, int b) -> bool { return (s[a].size() > s[b].size()); });
    ll ans = 0;
    for(int aa=0;aa<n;aa++){
        int i = ind[aa];
        ans += query(s[i]);
        add(s[i]);
//print();
    }
    printf("%lld\n", ans);
}

