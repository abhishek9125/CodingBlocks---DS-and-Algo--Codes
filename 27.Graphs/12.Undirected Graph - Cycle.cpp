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

        bool cycleHelper(int node,bool* visited,int parent){
            visited[node] = true;
            for(auto neighbour: l[node]){
                if(!visited[neighbour]){
                    bool cycle_found = cycleHelper(neighbour,visited,node);
                    if(cycle_found){
                        return true;
                    }
                }else if(neighbour!=parent){
                    return true;
                }
            }
            return false;
        }

        bool containCycle(){
            bool *visited = new bool[V];
            for(int i=0;i<V;i++){
                visited[i] = false;
            }
            return cycleHelper(0,visited,-1);
        }
};  
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
   
    
    if(g.containCycle()){
        cout<<"Contains a Cycle";
    }else{
        cout<<"Does not contain a Cycle";
    }

	return 0;
}
