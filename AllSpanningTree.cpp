#include<bits/stdc++.h>
using namespace std;
typedef struct {
int from ,to,dist;
}edge;
inline bool operator<(const edge& lhs, const edge& rhs)
{
  return lhs.dist < rhs.dist;
}

vector<edge> graph;
vector<int> parent;
int find(int i){
	//int temp=i;
	while(i!=parent[i])
		i=parent[i];
	return i;	
}
void dunion(int a,int b){
	parent[find(a)]=find(b);
}
void printGraph(set<set<edge>>& g){
	int i=1;
	for(auto st: g){
		cout << "Tree : " <<i<<endl;
		for(auto it = st.begin();it!=st.end();it++){
			cout << it->from << " <-> " << it->to << endl;
		}
		i++;
		cout << endl <<endl;
	}
}
void PermuteAll(int V,int E){
set<set<edge>> ans;
sort(graph.begin(),graph.end(),[](edge a,edge b){return a.dist < b.dist;});	
do{
		set<edge> temp;
		for(int i=0;i<V;i++)parent[i]=i;		
		for(int i=0,j=0;i<V-1 && j<E;j++){
			//cout << "Find " << find(graph[j].from)  << ' ' << find(graph[j].to) << endl;
			if(find(graph[j].from) != find(graph[j].to))
				temp.insert(graph[j]),i++,dunion(graph[j].from,graph[j].to);
		}
		ans.insert(temp);
	}while(next_permutation(graph.begin(),graph.end(),[](edge a,edge b){return a.dist < b.dist;}));
	printGraph(ans);
}
int main(){
	ifstream in("input");
	streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	cin.rdbuf(in.rdbuf());

	int V,E,a,b,c;
	cin >> V >> E;
	
	parent.resize(V);
	while(E--){
		cin >> a>>b;
		graph.push_back({a,b,E});
	}
	PermuteAll(V,graph.size());
	return 0;
}
//E!*vlogv
