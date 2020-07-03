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
        void topologicalSort(){
            int indegree[V] = {0};
            for(int i=0;i<V;i++){
                for(auto y : l[i]){
                    indegree[y]++;
                }
            }

            queue<int> q;

            for(int i=0;i<V;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int node = q.front();
                cout<<node<<"->";
                q.pop();

                for(auto neighbour : l[node]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                    }
                }
            }
        }    
};  
int main()
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.topologicalSort();
	return 0;
}
