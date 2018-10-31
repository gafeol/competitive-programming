#include <bits/stdc++.h>

 

using namespace std;

#define pb push_back

#define mp make_pair

#define f first

#define s second

#define int long long

typedef long long ll;

typedef pair<int,int>pii;

#define MAXN 21234

#define INF numeric_limits<ll>::max()

#define MOD 998244353

#define eps 1e-15

#define eeps

#define cood long double



int n,m,s;



int solve(int i){

    //cout<<i<<endl;

    if(i==1 || i==2)return i*s+m;

    return (i/2)*m+s+solve(i/2);

}





int32_t main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.precision(5);

    cout.setf(ios::fixed);



    cin>>n>>m>>s;



    cout<<m+solve(n-1)<<endl;





    return 0;

}
