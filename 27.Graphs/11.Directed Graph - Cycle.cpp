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
        }

        bool cycleHelper(int node,bool* visited,bool* stack){
            visited[node] = true;
            stack[node] = true;

            for(auto neighbour : l[node]){
                if(stack[neighbour]==true){
                    return true;
                }else if(visited[neighbour]==false){
                    bool cycle_found = cycleHelper(neighbour,visited,stack);
                    if(cycle_found){
                        return true;
                    }
                }
            }

            stack[node] = false;
            return false;
        }

        bool containCycle(){
            bool *visited = new bool[V];
            bool *stack = new bool[V];

            for(int i=0;i<V;i++){
                visited[i] = stack[i] = false;
            }

            return cycleHelper(0,visited,stack);
        }
};  
int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2);
    
    if(g.containCycle()){
        cout<<"Contains a Cycle";
    }else{
        cout<<"Does not contain a Cycle";
    }

	return 0;
}
