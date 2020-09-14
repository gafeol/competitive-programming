#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define INF LLONG_MAX
#define MOD 1000000007
#define MAXN 1123
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(s) s.begin(),s.end()
#define double long double
#define int long long
 
typedef double num;
typedef double ll;
 const int N = 112;
const int M = 1123 * 2; const num eps = 1e-8;
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>eps){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF)>eps)result+=delta;
		}
		return result;
	}
};

int n,m;
vector<pii> edges;
int dg[1123];

vector<int> are[1123];

void dfs(int u,set<int> &ans){
	if(ans.find(u)!=ans.end())return;
	ans.insert(u);
	for(auto x:are[u])dfs(x,ans);
}

set<int> top(double g){
	Dinic d(n+2);
	for(auto x:edges){d.add_edge(x.f,x.s,1);}
	for(auto x:edges){d.add_edge(x.s,x.f,1);}
	for(int i=0;i<n;i++)d.add_edge(n,i,m);
	for(int i=0;i<n;i++){
		d.add_edge(i,n+1,(double)m+2*g-dg[i]);
	}
	d.max_flow(n,n+1);
    set<int> ans;
    for(int i=0;i<n+2;i++){
    	for(auto x:d.g[i]){
    		if(x.cap > eps && x.cap > x.f+eps){
    			are[i].pb(x.to);
    		}
    	}
    }

    dfs(n,ans);
    for(int i=0;i<n+2;i++)are[i].clear();
    ans.erase(n);
	return ans;
}

clock_t clk;

set<int> solve(){
	double l=0,u=m;
	set<int> ans={0};
	//double ga=0;
	while(((double)clock() - clk)/CLOCKS_PER_SEC < 1.2){
		double g=(u+l)/2;
		cout<<l<<" "<<u<<" "<<u-l<<" "<<eps<<" "<<g<<endl;
		set<int> sla=top(g);
		if(sla.size()==0)u=g;
		else{
			l=g;
			ans=sla;
		}
	}
	//cout<<l<<endl;
	return ans;
}


int32_t main(){
    clk = clock();
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout<<setprecision(11)<<fixed;

	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		edges.pb(mp(a,b));
		dg[a]++;
		dg[b]++;
	}


	/*while(true){
		double x;
		cin>>x;
		set<int> sla=top(x);
		for(auto y:sla)cout<<y+1<<" ";
		cout<<endl;
	}*/

	set<int> ans=solve();

	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x+1<<endl;



    return 0;
} 
