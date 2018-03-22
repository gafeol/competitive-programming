#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

//tl 7*10^8

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		string a,b;
		cin>>a>>b;
		int state;

		if(a=="rock"){
			if(b=="moon"||b=="scissors")state=1;
			else if(b=="sun"||b=="paper")state=2;
			else state=3;
		}
		else if(a=="paper"){
			if(b=="sun"||b=="rock")state=1;
			else if(b=="scissors"||b=="moon")state=2;
			else state=3;
		}
		else if(a=="scissors"){
			if(b=="moon"||b=="paper")state=1;
			else if(b=="rock"||b=="sun")state=2;
			else state=3;
		}
		else if(a=="moon"){
			if(b=="sun"||b=="paper")state=1;
			else if(b=="rock"||b=="scissors")state=2;
			else state=3;
		}
		else{
			if(b=="rock"||b=="scissors")state=1;
			else if(b=="paper"||b=="moon")state=2;
			else state=3;
		}

		if(state==1){
			cout<<"akira"<<endl;
		}
		else if(state==2){
			cout<<"hideki"<<endl;
		}
		else cout<<"drew"<<endl;

	}	


	return 0;
}
