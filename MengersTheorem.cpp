#include <iostream>
#include <bits/stdc++.h>
#include <time.h> 
using namespace std;
//https://www.youtube.com/watch?v=dUAeleBMRCQ
//Menger's Theorem
unordered_map<int,vector<int>> graph;

int ans=INT_MAX,cnt=0;
vector<bool> visited;
void DFS(vector<bool>& visited,int src,int dest,vector<int> vis){
	if(src == dest){
		cnt++;
		for(int i : vis)visited[i]=1;
		return;
	}
	vis.push_back(src);
	for(int i:graph[src])
		if(!visited[i] && find(vis.begin(),vis.end(),i)==vis.end())
			DFS(visited,i,dest,vis);
}

int main(){
	ifstream in("input");
	streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	cin.rdbuf(in.rdbuf());
	int V,a,b,E ;
	cin >> V >> E;
	while(E--){
		cin >> a >>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//for(int i:graph[3])cout << i << 'a';
	//vector<bool> visited(V,0);
	visited.resize(V,0);
	for(int i=0;i<V;i++){
		for(int j=i+1;j<V;j++)
		{
			for(int i=0;i<V;i++)visited[i]=0;
		//	for (bool i : visited)cout <<i << ' ';
		//	cout<<endl;
			
			cnt=0;

				DFS(visited,i,j,{});
			//cout<< i<< ' ' <<j<<' '<<cnt <<endl;
			ans=min(ans,cnt);
		}
	}
	cout << ans;
}
