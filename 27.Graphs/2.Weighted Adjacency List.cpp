#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int> > > l; 
    public:
        void addEdge(string x,string y,bool bidir,int weight){
            l[x].push_back(make_pair(y,weight));
            if(bidir){
                l[y].push_back(make_pair(x,weight));
            }
        }

        void printAjdList(){
            for(auto i: l){
                string city = i.first;
                list<pair<string,int>> neighbours = i.second;
                cout<<city<<"->";
                for(auto j: neighbours){
                    string destination = j.first;
                    int distance = j.second;
                    cout<<"("<<destination<<","<<distance<<") ";
                }
                cout<<endl;
            }
        }

};

int main(){
    Graph g;
	g.addEdge("A","B",true,20);
	g.addEdge("B","D",true,40);
	g.addEdge("A","C",true,10);
	g.addEdge("C","D",true,40);
	g.addEdge("A","D",false,50);
	
	g.printAjdList();
    return 0;
}

