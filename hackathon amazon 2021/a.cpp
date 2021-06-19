#include<bits/stdc++.h>

using namespace std;

class Order{
    public:
    int id,prepTime,recieveTime;
    Order(int id, int prepTime, int recieveTime){
        this->id=id;
        this->prepTime=prepTime;
        this->recieveTime=recieveTime;
    }
    
    void operator=(const Order &operand){
        id=operand.id;
        prepTime=operand.prepTime;
        recieveTime=operand.recieveTime;
    }
    void print(){
        cout<<id<<"-"<<recieveTime<<" "<<prepTime<<"\n";
    }
};

bool operator<(const Order &operand1, const Order operand2){
    return !(operand1.prepTime<operand2.prepTime);
}

void sol(int N, int K, int W, pair<int,int> *orders){
    priority_queue<Order>orderQueue;
    int ans[N], curTime=orders[0].first, i=1;
    Order temp(0, orders[0].second, orders[0].first);
    orderQueue.push(temp);
    // ans[0]=temp.prepTime*K- (curTime-temp.recieveTime)*W;
    // curTime+=temp.prepTime;
    while(!orderQueue.empty() || i<N){
        // cout<<"\n\n"<<curTime<<"->\n";
        while(i<N && curTime>=orders[i].first){
            Order temp(i, orders[i].second, orders[i].first);
            orderQueue.push(temp);
            // cout<<temp.id<<", ";
            ++i;
        }
        Order curOrder=orderQueue.top();
        // cout<<curOrder.id<<"* ";
        orderQueue.pop();
        // cout<<orderQueue.top().id<<"| ";
        // for(auto iq:orderQueue)
            // cout<<iq.id<<", ";
        // cout<<"\n";
        ans[curOrder.id] = curOrder.prepTime*K- (curTime-curOrder.recieveTime)*W;
        // cout<<curOrder.id<<"-"<<ans[curOrder.id]<<"\n";
        // ans[i] = ( ans[i]>0?ans[i]:0 );
        curTime+=curOrder.prepTime;
        
    }
    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";
}

int main(){
	int t;
    cin>>t;
    while(t--){
        int N,K,W;
        cin>>N>>K>>W;
        pair<int,int> orders[N];
        for(int i=0;i<N;i++){
            int order_time, order_duration;
            cin>>order_time>>order_duration;
            orders[i]={order_time,order_duration};
        }

        sol(N, K, W, orders);
        cout<<"\n";
    }
}