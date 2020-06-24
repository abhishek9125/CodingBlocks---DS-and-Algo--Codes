#include<iostream>
#include<set>
#include<map>
using namespace std;

class compare{
    public:
        bool operator()(pair<string,int> p1,pair<string,int> p2){
            return p1.second<p2.second;
        }
};

int main() 
{
    int n,friends;
    cin>>n>>friends;
    map<string,int> net;
    while(n--)
    {
        string x,y;
        int amount;
        cin>>x>>y>>amount;

        if(net.count(x)==0){
            net[x] = 0;
        }
        if(net.count(y)==0){
            net[y] = 0;
        }

        net[x] -= amount;
        net[y] += amount;
    }

    multiset<pair<string,int>, compare> m; // We can declare pair<int,string> as multiset sorts according to first element but implemented compare for learning purpose

    for(auto p: net){
        string person = p.first;
        int amount = p.second;

        if(net[person]!=0){
            m.insert(make_pair(person,amount));
        }
    }

    int count = 0;
    while(!m.empty()){
        auto low = m.begin();
        auto high = prev(m.end());

        int debit = low->second;
        string debit_person = low->first;

        int credit = high->second;
        string credit_person = high->first;

        m.erase(low);
        m.erase(high);

        int settlement_amount = min(-debit,credit);
        debit += settlement_amount;
        credit -= settlement_amount;

        cout<<debit_person<<" will Pay "<<settlement_amount<<" to "<<credit_person<<endl;

        if(debit!=0){
            m.insert(make_pair(debit_person,debit));
        }
        if(credit!=0){
            m.insert(make_pair(credit_person,credit));
        }

        count++;
    }

    cout<<count<<endl;

    return 0;
}

