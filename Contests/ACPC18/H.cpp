#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pii pair<long long,long long>
#define MAXN 21234
#define INF INT_MAX
#define double long double
#define pi acos(-1)
#define int long long
 
int32_t ciclo[112345678];
 
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
 
 
int32_t main () {
    ios_base::sync_with_stdio(false);
    cout<<setprecision(5)<<fixed;
 
    freopen("hawawshi.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n,x,A,B,a,b,p;
        cin>>n>>x>>A>>B>>a>>b>>p;
        int at=0;
        int nxt=x;
        do{
            //cout<<nxt<<endl;
            ciclo[at]=nxt;
            nxt=(a*nxt+b)%p;
            at++;
        }while(nxt!=x);
        int resp=0;
        for(int i=0;i<at;i++){
            if(ciclo[i]>=A&&ciclo[i]<=B&&
                (i==0||at-i<n))resp++;
        }
        //cout<<resp<<" "<<B-A+1<<endl;
        if(resp==0)cout<<"0/1"<<endl;
        else cout<<resp/gcd(resp,B-A+1)<<"/"<<
                (B-A+1)/gcd(resp,B-A+1)<<endl;
 
 
 
    }
 
    return 0;
}
 
 
 
