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
        void addEdge(T x,T y,bool bidir=true){
            l[x].push_back(y);
            if(bidir){
                l[y].push_back(x);
            }
        }

        void bfs(T src){
            map<T,int> distance;
            queue<T> q;
            q.push(src);

            for(auto x : l){
                T node = x.first;
                distance[node] = INT_MAX;
            }
            distance[src] = 0;
            while(!q.empty()){
                T node = q.front();
                q.pop();

                for(auto neighbour : l[node]){
                    if(distance[neighbour] == INT_MAX){
                        q.push(neighbour);
                        distance[neighbour] = distance[node] + 1;
                    }
                }
            }
            for(auto x : l){
                T node = x.first;
                int dist = distance[node];
                cout<<"Node: "<<node<<" Distance from Source: "<<dist<<endl;
            }
        }
};

int main(){
    Graph<int> g;
	g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    return 0;
}

