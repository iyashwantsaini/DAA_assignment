/*

Roll No - 101803318
Name - Yashwant
Batch - COE 15
Ques - 3

Complexity - O(n*logn)

Implement Greedy Fractional Knapsack for the following problems:
1.N =3, M =  20, (P1, P2, P3) = (25, 24, 15), (W1, W2, W3) =  (18, 15, 10)
2.N =7, M = 15 , (P1, P2, P3, P4, P5, P6, P7) = (10, 5, 15, 7, 6, 18, 3); (W1, W2, W3, W4, W5, W6, W7) = (2, 3, 5, 7, 1, 4, 1)

Input: First line conatains N= no of items, W= max weight allowed. Second line has profits of N items. Third line has weights of N items
Output: Max profit we can generate from selecting items that has a total weight : W.

INPUT 1
3 20
25 24 15
18 15 10
OUTPUT 1
31.5

INPUT 2
7 15
10 5 15 7 6 18 3
2 3 5 7 1 4 1
OUTPUT 2
55.3333

SAMPLE INPUT 3
3 50
60 100 120
10 20 30
SAMPLE OUTPUT 3
240

SAMPLE INPUT 4
4 60
280	100	120	120
40	10	20	24
SAMPLE OUTPUT 4
440


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// sorts on basis of profit/weight value
bool compare(pair<int,int> item1,pair<int,int> item2){
    double frac1=(double)item1.first/(double)item1.second;
    double frac2=(double)item2.first/(double)item2.second;
    if(frac1==frac2){
        return item1.first>item2.first;
    }
    return frac1>frac2;
}

double frac_knap(int n,int m,pair<int,int> *items){
    // sort on basis of profit/weight value
    // item must have high profits and less weight to get max total profit
    sort(items,items+n,compare);
    // for(int i=0;i<n;i++){
    //     cout<<items[i].first<<" "<<items[i].second<<endl;
    // }
    int W=0;
    double profit=0;
    for(int i=0;i<n;i++){
        if((W+items[i].second)<=m){
            // complete items can be included
            // add directly
            W+=items[i].second;
            profit+=items[i].first;
        }else{
            // complete item can't be included, so fractional is included
            // add partial
            profit+=(
                ((double)(m-W)/(double)items[i].second)*items[i].first
            );
            break;
        }
    }
    return profit;
}

int main(){
    // n=number of workers, m=total weight required 
    int n,m;
    cin>>n>>m;
    // contains profits and weights for 'n' items
    pair<int,int> *items=new pair<int,int>[n+1];
    // get profits for items
    for(int i=0;i<n;i++){
        cin>>items[i].first;
    }
    // get weights for items
    for(int i=0;i<n;i++){
        cin>>items[i].second;
    }
    double profitmax=frac_knap(n,m,items);
    cout<<profitmax<<endl;
    return 0;
}
