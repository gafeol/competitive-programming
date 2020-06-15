#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
const int MAXN = 212345;

int A, B, n;
ll T, ta, tb;

vector<pll> s;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds

namespace GNU { typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set; }
using GNU::ordered_set;
ordered_set q;

//        123456789
ll DEZ = 1000000000LL;

int main (){
	scanf("%d%d%lld%lld%lld", &A, &B, &T, &ta, &tb);
    scanf("%d", &n);
    vector<ll> Y;
	for(int a=0;a<n;a++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        s.push_back({x, y});
	}
    int res = 0;
    sort(s.begin(), s.end());
    ll timeSpent = 0;
    for(int i=0;i<s.size();i++){
        if(A < s[i].fst){
            timeSpent += (s[i].fst - A)*ta;
            A = s[i].fst;
        }
        q.insert(make_pair(s[i].snd, i));
        if(timeSpent > T) break;
        ll nB = ((ll)B) + (T - timeSpent)/tb;
        nB = min(nB, DEZ);
        int key = nB + 1;
        res = max(res, (int)q.order_of_key(make_pair(key, -1)));
        //printf("menor que %lld tem %d caras\n", nB, (int)q.order_of_key(key));
    }
    printf("%d\n", res);
}

