#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v.size())
#define prin(a) cout << #a << " = " << a << endl
#define prinv(v) cout << #v << " = "; for(auto it : v) cout << it << ", "; cout << endl
#define all(v) (v).begin(),(v).end()

typedef long long ll;

#define rmin(a,b) a = min<ll>(a,b)
#define rmax(a,b) a = max<ll>(a,b)

#define fi first
#define se second

const int MAXN = 112345;
vector<int> adj[MAXN];
ll n;

bool isStar(){
    int cnt = 0;
    for(int a=0;a<n;a++){
        cnt += (adj[a].size() == 1);
    }
    return (cnt == n-1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	 cin >> n;
	
    for(int a=1;a<n;a++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(a);
    }
	ll ans = 0;
	
    if(isStar()){
        ans = n-1;

    }
    else{
        ll cur = n-1;
        for(ll delt = 1; delt<=n; delt++){
            ans += cur*delt*delt;
            cur--;
        }

        cout << ans << endl;
    }
}
