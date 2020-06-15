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

int n, m, k;
vector<pii> s;
vector<pair<int, char> > q;
vector<int> t;

inline void rmv(int i, int j){
    vector<pii> ans; 
    for(pii p: s){
        if(p.snd < i || p.fst > j){
            ans.pb(p);
            continue;
        }
        if(p.fst < i)
            ans.pb({p.fst, i-1});
        if(p.snd > j)
            ans.pb({j+1, p.snd});
    }
    s = ans;
}

inline int sz(){
    int ans = 0;
    for(pii p: s)
        ans += p.snd - p.fst + 1; 
    return ans;
}

inline int at(int m){
    int ans = 0;
    for(pii p: s){
        if(p.snd - p.fst >= m){
            return p.fst + m;
        }
        m -= p.snd - p.fst + 1; 
    }
    assert(false);
}

inline char qry(int x){
    printf("%d\n", x);
    fflush(stdout);
    char c;
    scanf(" %c", &c);
    if(c == 'E')
        exit(0);
    q.pb({x, c});
    t.pb(-1);
    return c;
}

void test(){
    for(pii p: s){
        for(int x=p.fst;x<=p.snd;x++){
            qry(x);
        }
    }
}

void faz(int i){
    if(i < 0 || i >= q.size()) return ;
    t[i] = 1;
    if(q[i].snd == 'L')
        rmv(q[i].fst, q.back().snd);
    else
        rmv(q[0].fst, q[i].snd);
}

void check(){
    // usa a informacao das que com certeza sao verdadeiras
    int l = s[0].fst;
    int r = s.back().snd;

    for(int i=0;i<q.size();i++){
        if(t[i] != -1) continue;
        if((q[i].fst < l && q[i].snd == 'L') || (q[i].fst > r && q[i].snd == 'R')){
            t[i] = 0;
            faz(i-1);
            faz(i+1);
        }
    }
}

int main (){
	scanf("%d", &n);
    s.pb({1, n});
    while(1){
        int tam = sz()-1;
        if(tam < 4)
            break;
        int m = tam/3;
        int im = at(m);
        char c = qry(im);
        int mm = (2*tam)/3;
        int imm = at(mm);
        char cc = qry(imm);
        if(c == 'L'){
            if(cc == 'L'){ //LL
                //printf("im %d (%d) L imm %d (%d) L\n", im, m, imm, m+mm);
                rmv(im, im);
                rmv(imm, s.back().snd);
            }
            else{ //LR 
                //printf("im %d (%d) L imm %d (%d) R\n", im, m, imm, m+mm);
                rmv(im, imm);
            }
        }
        else{
            if(cc == 'L'){ // RL - nao tem o que fazer
                //printf("im %d (%d) R imm %d (%d) R\n", im, m, imm, m+mm);
                rmv(im, im);
                rmv(imm, imm);
            }
            else{ // RR
                rmv(s[0].fst, im);
                rmv(imm, imm);
            }
        }
        check();
    }
    test();
}
