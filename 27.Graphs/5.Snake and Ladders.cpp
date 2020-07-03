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
        void addEdge(T x,T y,bool bidir = true){
            l[x].push_back(y);
        }

        int shortestPath(T src,T dest){
            map<T,int> dist;
            map<T,T> parent;
            queue<T> q;

            for(auto x : l){
                dist[x.first] = INT_MAX;
            }
            q.push(src);
            dist[src] = 0;
            parent[src] = src;

            while(!q.empty()){
                T node = q.front();
                q.pop();
                for(auto neighbour : l[node]){
                    if(dist[neighbour]==INT_MAX){
                        q.push(neighbour);
                        dist[neighbour] = dist[node] + 1;
                        parent[neighbour] = node;
                    }
                }
            }

            T temp = dest;
            while(temp!=src){
                cout<<temp<<"<--";
                temp = parent[temp];
            }
            cout<<src<<endl;
            return dist[dest];
        }
};
int main()
{
	Graph<int> g;
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;
	
	for(int u=0;u<=36;u++)
	{
		for(int dice = 1;dice<=6;dice++)
		{
			int v = u + dice + board[u + dice];
			g.addEdge(u,v,false); 
		}
	}
	
	cout<<"Shortest Distance is "<<g.shortestPath(0,36)<<endl;
	
	return 0;
}
