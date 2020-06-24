#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(){

    }

    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
};

class personCompare{
    public:
        bool operator()(Person a,Person b){
            return a.age<b.age;
        }
};  

int main(){

    int n;
    cin>>n;

    priority_queue<Person,vector<Person>,personCompare> q;

    for(int i=0;i<n;i++){
        string name;
        int age;
        cin>>name>>age;
        Person p(name,age);
        q.push(p);
    }

    int k=3;
    for(int i=0;i<k;i++){
        Person p = q.top();
        cout<<p.name<<" "<<p.age<<endl;
        q.pop();
    }
    return 0;
}

