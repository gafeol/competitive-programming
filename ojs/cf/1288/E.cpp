#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds

namespace GNU { typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set; }
using GNU::ordered_set;
// null_type pode mudar pra virar map
// multiset e multimap nao tem suporte aqui, tem que sair usando pair pelo jeito
// less eh o comparador

ordered_set s;

// s.insert(int) s.erase(iterator ou int)
// end(s) == s.find_by_order(int) -> s nao contem int
// find_by_order retorna o iterator pro kth maior elemento (comecando do 0)
// 	(int) *s.find_by_order(int)
// order_of_key retorna o numero de elementos no set estritamente menor que int
// 	(int) s.order_of_key(int)

const int MAXN = 312345;

int n, m, k;
int L[MAXN], R[MAXN];
int ind[MAXN];

int main (){
	scanf("%d%d", &n, &m);
    for(int a=1;a<=n;a++){
        L[a] = R[a] = a;
        s.insert(a);
        ind[a] = a;
    }
    int deg = 0;
	for(int a=0;a<m;a++){
        int x;
        scanf("%d", &x);
        L[x] = 1;
        int mx = 1 + s.order_of_key(ind[x]);
        R[x] = max(R[x], mx);
        s.erase(ind[x]);
        ind[x] = --deg;
        s.insert(ind[x]);
	}
    for(int v=1;v<=n;v++){
        if(L[v] == 0)
            L[v] = v;
        int mx = 1 + s.order_of_key(ind[v]);
        R[v] = max(R[v], mx);
        printf("%d %d\n", L[v], R[v]);
    }
}

