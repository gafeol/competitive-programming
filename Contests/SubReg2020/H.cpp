#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112
#define MAXN2 4123456
#define MOD 1000000007
#define f first
#define s second
#define pii pair<long long, long long>
#define INF INT_MAX
#define int long long

int n;
int c[MAXN];
int sumac[MAXN];
string s1,s2;
int memo[MAXN][MAXN][2];

string s;

int go(int i, int k, int lo){
    if(k < 0) return 0;
    int &r = memo[i][k][lo];
    if(i == n)
        return r = (k == 0);
    if(r != -1)
        return r;
    
    if(lo){
        r = go(i+1, k-1, 1) + go(i+1, k, 1);
    }
    else{
        if(s[i] == '0')
            r = go(i+1, k, lo);
        else
            r = go(i+1, k-1, lo) + go(i+1, k, 1);
    }
    return r;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(8)<<fixed;
	int k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	int com,fim;
	cin>>com>>fim;
	sumac[0]=0;
	for(int i=1;i<n;i++){
		sumac[i]=sumac[i-1]+c[i-1];
	}
	if(sumac[n-1]+c[n-1]<com){
		cout<<0<<endl;
		return 0;
	}
	for(int i=n-1;i>=0;i--){
		if(c[i] < com){
            s1.pb('1');
            com -= c[i];
        }
		else
			s1.pb('0');
	}
	for(int i=n-1;i>=0;i--){
		if(c[i]<=fim){
			s2.pb('1');
			fim-=c[i];
		}
		else s2.pb('0');
	}
    s = s2;
    memset(memo, -1, sizeof(memo));
    int ans = go(0, k, 0);
    s = s1;
    memset(memo, -1, sizeof(memo));
    ans -= go(0, k, 0);
	cout<< max(0ll, ans) <<endl;
	return 0;
}
 
