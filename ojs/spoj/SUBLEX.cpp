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

const int MAXN = 212345;

int n, m, k;
vector<int> p;
vector<int> lcp;
char s[MAXN];
// Suffix array Nlog2 + Kazai
vector<int> sa(string s){
    int n = s.size();
    if(n == 1) // Tratar caso n = 1
        exit(0);

    p.resize(n);
    vector<int> r(n+1), aux(n);
    for(int a=0;a<n;a++){
        r[a] = s[a];
        p[a] = a;
    }
    r[n] = -1;

    for(int d=1;d < n;d*=2ll){
        sort(p.begin(), p.end(), [&](int a, int b){
            return make_pair(r[a], r[min(n, a+d)]) < make_pair(r[b], r[min(n, b+d)]);
                }); 
        int val = 0;
        for(int a=0;a<n;a++){
            if(a > 0)
                val += (make_pair(r[p[a]], r[min(n, p[a]+d)]) != make_pair(r[p[a-1]], r[min(n, p[a-1]+d)]));
            aux[p[a]] = val;
        }
        for(int a=0;a<n;a++)
            r[a] = aux[a];
        if(r[p[n-1]] == n-1) break;
    }

    //Kazai 
    int sz = 0;
    lcp.resize(n);
    for(int i=0;i<n;i++){
        if(r[i] == n-1){
            lcp[i] = sz = 0;
            continue;
        }
        int o = p[r[i]+1];
        while(i + sz < n && o + sz < n && s[i + sz] == s[o + sz])
            sz++;
        lcp[i] = sz;
        sz = max(0, sz-1);
    }
    return lcp;
}

void qry(int k){
    int tam = strlen(s);
    for(int a=0;a<tam;a++){
        int prvlcp = (a > 0 ? lcp[p[a-1]] : 0);
        //printf("a %d k %d  tam %d -%d -%d\n", a, k, tam, p[a], prvlcp);
        if(k <= tam - p[a] - prvlcp){
            int i = p[a];
            
            while(i < p[a] + prvlcp)
                printf("%c", s[i++]);
            //puts("\n foi lcp \n");
            for(int cnt=0;cnt<k;cnt++){
                printf("%c", s[i++]); 
            }
            puts("");
            return ;
        }
        k -= tam - p[a] - prvlcp;
    }
}

int main (){
    scanf(" %s", s);
    sa(s);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", &k);
        qry(k);
	}
}

