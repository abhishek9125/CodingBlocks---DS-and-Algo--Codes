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

        void dfs(){
            map<T,bool> visited;
            for(auto node : l){
                visited[node.first] = false;
            }
            int id = 1;
            for(auto p : l){
                T node = p.first;
                if(!visited[node]){
                    cout<<"Component "<<id<<" : "<<node<<" -> ";
                    dfs_helper(node,visited);
                    cout<<endl;
                    id++;
                }
            }

            return;
        }
};

int main(){
    Graph<int> g;
	g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);
    g.dfs();
    return 0;
}

