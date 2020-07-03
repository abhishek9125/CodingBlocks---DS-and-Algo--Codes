#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
    public:
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void dfs_helper(T src,map<T,bool>& visited){
            visited[src] = true;
            cout<<src<<" ";
            for(T neighbour : l[src]){
                if(!visited[neighbour]){
                    dfs_helper(neighbour,visited);
                }
            }
            return;
        }

        void dfs(T src){
            map<T,bool> visited;
            for(auto node : l){
                visited[node.first] = false;
            }
            dfs_helper(src,visited);
            return;
        }
};

int main(){
    Graph<int> g;
	g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,0);
    g.dfs(0);
    return 0;
}

