#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define inf INT_MAX
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define mod 1000000009
#define ld long double
#define eps 1e-8
 
int n,m;
 
char mm[1123][1123];
 
bool na[1123][1123];
 
char resp[1123][1123];
 
void marca(int i,int j,int ai,int aj){
    int ri=0,rj=0,bi=n-1,bj=m-1;
    if(i<ai)bi=i;
    if(i>ai)ri=i;
    if(j<aj)bj=j;
    if(j>aj)rj=j;
    for(int ii=ri;ii<=bi;ii++){
        for(int jj=rj;jj<=bj;jj++){
            na[ii][jj]=1;
        }
    }
}
 
void solve(int ri,int rj,int bi,int bj){
    //cout<<ri<<" "<<rj<<" "<<bi<<" "<<bj<<endl;
    ri=max(ri,0);
    bi=min(bi,n-1);
    rj=max(rj,0);
    bj=min(bj,m-1);
    //cout<<ri<<" "<<rj<<" "<<bi<<" "<<bj<<endl;
    if(bj<rj || bi<ri)return;
    //cout<<ri<<" "<<rj<<" "<<bi<<" "<<bj<<endl;
    //cout<<endl;
    int last=ri;
    for(int i=ri;i<=bi;i++){
        for(int j=rj;j<=bj;j++){
            if(j>rj && resp[i][j-1]>='a')resp[i][j]=resp[i][j-1];
            if(mm[i][j]!='.')
                resp[i][j]=mm[i][j]-'A'+'a';
        }
        for(int j=bj;j>=rj;j--){
            if(j<bj && resp[i][j+1]>='a')resp[i][j]=resp[i][j+1];
            if(mm[i][j]!='.')
                resp[i][j]=mm[i][j]-'A'+'a';
        }
    }
    for(int j=rj;j<=bj;j++){
        for(int i=ri+1;i<=bi;i++){
            if(resp[i][j]<'a')resp[i][j]=resp[i-1][j];
        }
        for(int i=bi-1;i>=ri;i--){
            if(resp[i][j]<'a')resp[i][j]=resp[i+1][j];
        }
    }
}
 
int32_t main (){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<setprecision(2)<<fixed;
 
    cin>>n>>m;
    int ai,aj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mm[i][j];
            if(mm[i][j]=='A'){
                ai=i;aj=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mm[i][j]!='.'&&mm[i][j]!='A'){
                marca(i,j,ai,aj);
            }
        }
    }
 
    vector<pii> sla(n);
    for(int i=0;i<n;i++){
        pair<int,int> coisa=mp(1500,0);
        for(int j=0;j<m;j++){
            if(na[i][j]==0){
                coisa.f=min(coisa.f,j);
                coisa.s=max(coisa.s,j);
            }
        }
        sla[i]=coisa;
        //cout<<i<<" "<<coisa.f<<" "<<coisa.s<<endl;
    }
 
    int ans=-1;
    pair<int,int> genans;
    pair<int,int> genans2;
    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            int respar=(min(sla[i].s,sla[k].s)-max(sla[i].f,sla[k].f))*(k-i+1);
            if(respar>ans){
                ans=respar;
                genans=mp(i,k);
                //cout<<genans.f<<" "<<genans.s<<endl;
                genans2=mp(max(sla[i].f,sla[k].f),min(sla[i].s,sla[k].s));
            }
        }
    }
    //cout<<ans<<endl;
    //cout<<genans.f<<" "<<genans.s<<endl;
    //cout<<genans2.f<<" "<<genans2.s<<endl;
    for(int i=genans.f;i<=genans.s;i++){
        for(int j=genans2.f;j<=genans2.s;j++){
            resp[i][j]='a';
        }
    }
 
    solve(0,0,n-1,genans2.f-1);
    solve(0,genans2.f,genans.f-1,genans2.s);
    solve(genans.s+1,genans2.f,n-1,genans2.s);
    solve(0,genans2.s+1,n-1,m-1);
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mm[i][j]!='.'){
                resp[i][j]=mm[i][j];
                //cout<<mm[i][j]<<" "<<resp[i][j]<<endl;
            }
        }
    }
 
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(resp[i][j]>='A')cout<<resp[i][j];
            else cout<<'.';
        }
        cout<<endl;
    }
 
 
 
    return 0;
}
