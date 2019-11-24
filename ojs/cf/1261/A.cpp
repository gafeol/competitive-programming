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

const int MAXN = 2123;

int n, m, k;
char s[MAXN];

vector<pii> ans;

void print(int a, int b){
    if(a > b) 
        swap(a, b);
    int aux[MAXN];
    for(int i = a;i <= b;i++)
        aux[b - (i - a)] = s[i];
    for(int i=a;i<=b;i++)
        s[i] = aux[i];
    ans.pb({a, b});
}

int nxt(int t, int i){
    for(int j=i;j<n;j++){
        if(t == (s[j] == ')'))
            return j;
    }
    assert(false);
}

int main (){
    for_tests(t, tt){
        ans.clear();
        queue<int> pos[2];
        scanf("%d%d", &n, &k);
        k--;
        for(int a=0;a<n;a++){
            scanf(" %c", s+a);
            pos[(s[a] == ')')].push(a);
        }
        int i = 0;
        while(k--){
            int j = nxt(0, i);
            pos[0].pop();
            print(i, j);
            i++;
            j = nxt(1, i);
            print(i, j);
            i++;
        }
        while(!pos[0].empty()){
            int j = nxt(0, i); 
            pos[0].pop();
            print(i, j);
            i++;
        }
        printf("%d\n", ans.size());
        for(pii p: ans)
            printf("%d %d\n", p.fst+1, p.snd+1);
    }
}

