#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAXN 1123
#define INF (int)1.5e12
#define INFF LLONG_MAX/2

int n,m,p,x,y;
//total e meu
vector<pii> are[MAXN][2];
//total a partir do x, total a partir do y, meu
pair<int,pii> dis[MAXN][3];
set<int> ss;

//fee, se sou eu ou oponente
map<pair<int,bool>,pair<int,pii>> memo;

void dij(int s,int fee, int ig, int id){
	for(int i=0;i<MAXN;i++)dis[i][id].f=INFF;
	priority_queue<pii> q;
	dis[s][id]=mp(0,mp(0,0));q.push(mp(0,s));
	int xx;
	while(!q.empty()){
		xx=q.top().s;int c=-q.top().f;q.pop();
		if(dis[xx][id].f!=c)continue;
		for(pii at:are[xx][ig]){
			int y=at.s,c=at.f;
			if(dis[xx][id].f+c+fee<dis[y][id].f){
				dis[y][id]=
				mp(dis[xx][id].f+c+fee,mp(dis[xx][id].s.f+1,dis[xx][id].s.s+c));
				q.push(mp(-dis[y][id].f,y));
			}
		}
	}
}


pair<pair<pii,pii>,pii> top(int fee){
	pair<int,pii> ms;
	if(memo.find(mp(fee,0))!=memo.end())ms=memo[mp(fee,0)];
	else{
		dij(x,fee,1,2);
		ms=dis[y][2];
		memo[mp(fee,0)]=ms;
	}
	pair<int,pii> mt;
	if(memo.find(mp(fee,1))!=memo.end())mt=memo[mp(fee,1)];
	else{
		dij(x,fee,0,0);
		dij(y,fee,0,1);
		mt=mp(INFF,mp(-1,-1));
		for(int i=0;i<n;i++){
			if(ss.find(i)==ss.end()){
				pair<int,pii> potans=mp(min(dis[i][0].f+dis[i][1].f,INFF),
					mp(dis[i][0].s.f+dis[i][1].s.f,dis[i][0].s.s+dis[i][1].s.s));
				mt=min(mt,potans);
			}
		}
		memo[mp(fee,1)]=mt;
	}
	return mp(mp(ms.s,mt.s),mp(ms.f,mt.f));
}

int phiAtual=INF;

pair<pii,pii> nxtEqs(pair<pii,pii> eqs){
    int  i = 0, j = phiAtual;     
    while(i < j){
        int phi = ((i + j)>>1);
        pair<pii,pii> neqs = top(phi).f;
        if(neqs == eqs)
            j = phi-1;
        else
            i = phi;
    }
    pair<pii,pii> neqs = top(i).f;
    phiAtual=i;
    if(neqs == eqs){
        // Equacoes nao mudam mais
        return {{-1,-1},{-1,-1}};
    }
    return neqs;
}

int ans=-1;

void roda(int fee){
	if(fee<=ans)return;
	//cout<<fee<<endl;
	pii sla=top(fee).s;
	if(sla.f<sla.s)ans=max(ans,fee);
}

//meu depois o cara
void add(pair<pii,pii> c){
	//cout<<c.f.f<<" "<<c.f.s<<" "<<c.s.f<<" "<<c.s.s<<endl;
	if(c.f.f==c.s.f)return;
	pii testar;
	int val=(c.s.s-c.f.s)/(c.f.f-c.s.f);
	testar=mp(val,val+1);
	if((c.s.s-c.f.s)%(c.f.f-c.s.f)==0)testar.f=val-1;
	roda(testar.f);
	roda(testar.s);
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n>>p>>x>>y;
	x--;y--;
	for(int i=0;i<p;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		are[a][0].pb(mp(c,b));
		are[b][0].pb(mp(c,a));
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		x--;
		ss.insert(x);
	}
	for(int i=0;i<n;i++){
		if(ss.find(i)==ss.end())continue;
		for(auto x:are[i][0]){
			if(ss.find(x.s)!=ss.end())are[i][1].pb(x);
		}
	}

	if(ss.size()==n){
		cout<<"Infinity"<<endl;
		return 0;
	}
	pair<pair<pii,pii>,pii> ini=top(INF);

	if(ini.s.f<ini.s.s){
		cout<<"Infinity"<<endl;
		return 0;
	}
	pair<pii,pii> curreqs=ini.f;
	add(curreqs);
	while(true){
		pair<pii,pii> nxt=nxtEqs(curreqs);
		cout<<nxt.f.f<<" "<<nxt.f.s<<" "<<nxt.s.f<<" "<<nxt.s.s<<endl;
		if(nxt.f.f==-1 || nxt==curreqs)break;
		add(nxt);
		if(ans!=-1)break;
		curreqs=nxt;
	}
	if(ans<=0)cout<<"Impossible"<<endl;
	else cout<<ans<<endl;



    return 0;
} 





























 
