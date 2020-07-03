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
        void addEdge(T u,T v){
            l[u].push_back(v);
        }

        void dfs_helper(T src,map<T,bool>& visited,list<T>& ordering){
            visited[src] = true;

            for(T neighbour : l[src]){
                if(!visited[neighbour]){
                    dfs_helper(neighbour,visited,ordering);
                }
            }

            ordering.push_front(src);

            return;
        }

        void dfs(){
            map<T,bool> visited;
            list<T> ordering;
            for(auto node : l){
                visited[node.first] = false;
            }
 
            for(auto p : l){
                T node = p.first;
                if(!visited[node]){
                    dfs_helper(node,visited,ordering);
                }
            }

            for(auto node : ordering){
                cout<<node<<"->";
            }

            return;
        }
};

int main(){
    Graph<string> g;
	g.addEdge("Python","Data Processing");
    g.addEdge("Python","PyTorch");
    g.addEdge("Python","ML");
    g.addEdge("Data Processing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","Face Recognition");
    g.addEdge("Dataset","Face Recognition");
    g.dfs();
    return 0;
}

