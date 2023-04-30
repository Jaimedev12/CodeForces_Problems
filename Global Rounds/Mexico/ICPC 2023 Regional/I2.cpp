#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=110;
int p[MAXN*MAXN];
int find(int x){return p[x]=p[x]==x?x:find(p[x]);}
void join(int x, int y){p[find(x)]=find(y);}

vector<ii> mov={{1,0},{0,1},{-1,0},{0,-1}};
int a[MAXN][MAXN],pingo[MAXN],vis[MAXN*MAXN];
ii pos[MAXN*MAXN];

int main(){FIN;
	int n,m; cin>>n>>m;
	vector<pair<int,ii>> v;
	fore(i,0,n) fore(j,0,m) cin>>a[i][j],a[i][j]--,pos[a[i][j]]={i,j};
	fore(i,0,n*m) p[i]=i;
	
	int ans=0;
	vector<int> asd(n*m);
	fore(i,0,n*m) if(!asd[i]){
		fore(j,0,n*m) vis[j]=0;
		priority_queue<int,vector<int>,greater<int>> q;
		q.push(i);
		vis[i]=1;
		int res=0;
		
		while(SZ(q)){
			int now=q.top(); q.pop();
			asd[now]=1;
			int x=pos[now].fst, y=pos[now].snd;
			res++;
			
			for(auto dir:mov){
				int nx=x+dir.fst, ny=y+dir.snd;
				if(nx<0||ny<0||nx==n||ny==m||a[nx][ny]<a[x][y]||vis[a[nx][ny]])continue;
				vis[a[nx][ny]]=1;
				q.push(a[nx][ny]);
			}
		}
		
		ans=max(ans,res);
	}
	
	cout<<ans<<"\n";
}