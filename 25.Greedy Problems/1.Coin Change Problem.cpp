#include<iostream>
#include<algorithm>
using namespace std;

void coinChange(int n,int *coins,int money)
{
    int ans = 0;
    cout<<"Coins: ";
    while(money>0)
    {
        int index = upper_bound(coins,coins+n,money) - 1 - coins;
        money = money - coins[index];
        ans++;
        cout<<coins[index]<<",";
    }
    cout<<endl;
    cout<<"Total Coins"<<" "<<ans;
    return;
}

int main() 
{
    int money;
    cin>>money;

    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(coins)/sizeof(int);
    coinChange(n,coins,money);
    return 0;
}

