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
int s[MAXN];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds

namespace GNU { typedef tree<pii, null_type, less<pii>, rb_tree_tag,
    tree_order_statstics_node_update> ordered_set; }
    using GNU::ordered_set;
    // null_type pode mudar pra virar map
    // multiset e multimap nao tem suporte aqui, tem que sair usando pair pelo jeito
    // less eh o comparador

    ordered_set q;

    // s.insert(int) s.erase(iterator ou int)
    // end(s) == s.find_by_order(int) -> s nao contem int
    // find_by_order retorna o iterator pro kth maior elemento (comecando do 0)
    // 	(int) *s.find_by_order(int)
    // order_of_key retorna o numero de elementos no set estritamente menor que int
    // 	(int) s.order_of_key(int)
    //

    int ind[MAXN];

    bool cmp(int a, int b){
        return (s[a] > s[b] || (s[a] == s[b] && a < b));
    }

int main (){
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        scanf("%d", s+a);
        ind[a] = a;
    }
    sort(ind, ind+n, cmp);
    scanf("%d", &m); 
    vector<tuple<int, int, int> > qry;
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        qry.pb({i, j, a});
    }
    sort(qry.begin(), qry.end());
    int i = 0;
    int ans[MAXN];
    for(int a=0;a<m;a++){
        int k, pos, id;
        tie(k, pos, id) = qry[a];
        while(i < k){
            q.insert({ind[i], s[ind[i]]});
            i++;
        }
        ans[id] = q.find_by_order(pos-1)->snd;
    }
    for(int a=0;a<m;a++)
        printf("%d\n", ans[a]);
}
