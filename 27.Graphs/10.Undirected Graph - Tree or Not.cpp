#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int V){
            this->V = V;
            l = new list<int>[V];
        }
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        bool isTree(){
            bool *visited = new bool[V];
            int *parent = new int[V];

            for(int i=0;i<V;i++){
                visited[i] = false;
                parent[i] = i;
            }

            queue<int> q;
            q.push(0);
            visited[0] = true;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto neighbour : l[node]){
                    if(visited[neighbour]==true && parent[neighbour]!=node){
                        return false;
                    }else if(!visited[neighbour]){
                        visited[neighbour] = true;
                        parent[neighbour] = node;
                        q.push(neighbour);
                    }
                }
            }
            return true;
        }
};  
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(0,3);
    if(g.isTree()){
    	cout<<"Tree";
	}else{
		cout<<"Not a Tree";
	}
	return 0;
}
