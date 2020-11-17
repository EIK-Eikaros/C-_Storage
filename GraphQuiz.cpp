#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#define V 200
using namespace std;
int g[V][V];
int vis[V];
vector<int> m;
int res[V];
int maxx = 0;
void DFS(int s,int v){
	vis[s] = false;
	m.push_back(s);
	while(true){
	int max =0;
	int pre = -1;
	int nex = -1;
		for(int i=0;i<m.size();i++){
			for(int j=0;j<=v;j++){
				if(vis[j] && g[m[i]][j]>max){
					max = g[m[i]][j];
					pre = m[i];
					nex = j;
				}
			}
		}
		if(pre!=-1){
			vis[nex] = false;
			m.push_back(nex);
			if(res[pre]<max && pre!=s){
				res[nex] = res[pre];
			}else{
				res[nex] = max;
			}
		}else{
			break;
		}
	}
}
int main(){
	int v,e;
	cin>>v>>e;
	for(int i=0;i<=v;i++){
		vis[i] = true;
		for(int j=0;j<=v;j++){
			g[i][j] = 0;
		}
	}
	int a,b,s;
	for(int i=0;i<e;i++){
		cin>>a>>b>>s;
		g[a][b] = s;
		g[b][a] = s;
	}
	int st,en,t;
	cin>>st>>en>>t;
	DFS(st,v);
	float p = ceil((double)t/(res[en]-1));
	cout<<p<<endl;
}
//7 10 1 2 30 1 3 15 1 4 10 2 4 25 2 5 60 3 4 40 3 6 20 4 7 35 5 7 20 6 7 30 1 7 99
