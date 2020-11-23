/*

Roll No - 101803318
Name - Yashwant
Batch - COE 15
Ques - 2

Complexity - O(k*(n^2))

Suppose the job scanning through a shelf of books is to be split between k workers. 
To avoid the need to rearrange the books or separate them into piles, we can divide the shelf into k regions and assign each region to one worker. 
What is the fairest way to divide the shelf up? 
If each book is the same length, partition the books into equal-sized regions, 100 100 100 | 100 100 100 | 100 100 100
But what if the books are not the same length? This partition would yield 100 200 300 | 400 500 600 | 700 800 900
Which part of the job would you volunteer to do? 
How can we find the fairest possiblepartition, i.e. 100 200 300 400 500 | 600 700 | 800 900

Input: First line contains N = no of books, Second line contains lengths of N books, Third line has K = no of partaition to make
Output: Partition N into k partitions, so as to minimize the maximum sum over all the partitions.

INPUT 1
9
100 100 100 100 100 100 100 100 100
3
OUTPUT 1
100 100 100
100 100 100
100 100 100

INPUT 2
9
100 200 300 400 500 600 700 800 900
3
OUTPUT 2
100 200 300 400 500
600 700 
800 900

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void reconstruct_partitions(int *s,int **dtables,int n,int k){
    if(k==1){
        // reached endpoint printing result
        for(int i=1;i<=n;i++){
            cout<<s[i]<<" ";
        }
        cout<<"\n";
    }else{
        // print result for smaller problem first
        reconstruct_partitions(s,dtables,dtables[n][k],k-1);
        // printing result for current partition while backtracking
        for(int i=dtables[n][k]+1;i<=n;i++){
            cout<<s[i]<<" ";
        }
        cout<<"\n";
    }
}

void partitions(int *s,int n,int k){
    // dp for values - initially all 0
    int **values=new int*[n+1];
    for(int i=0;i<n+1;i++){
        values[i]=new int[k+1]{};
    }
    // dp for tables - initially all 0
    int **dtables=new int*[n+1];
    for(int i=0;i<n+1;i++){
        dtables[i]=new int[k+1]{};
    }
    // prefix sums array
    int *psums=new int[n+1];
    // cost variable will contain the splitting cost
    int cost;

    // construct prefixes sums
    psums[0]=0;
    for(int i=1;i<=n;i++){
        psums[i]=psums[i-1]+s[i];
    }
    // initialize boundaries
    // as we already know the answers for n=1 & k=1 values
    for(int i=1;i<=n;i++){
        values[i][1]=psums[i];
    }
    for(int j=1;j<=k;j++){
        values[1][j]=s[1];
    }

    // evaluating other recurrences
    // for each n & k , values DP contains the sum of max values partition
    // for each n & k , dtables DP contains the index of where to put the divider to achive the recorded max sum partition 
    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            values[i][j]=INT_MAX;
            for(int x=1;x<=(i-1);x++){
                cost=max(values[x][j-1],psums[i]-psums[x]);
                if(values[i][j]>cost){
                    // saving max cost in values DP
                    values[i][j]=cost;
                    // saving the index of the divider in dtables DP 
                    dtables[i][j]=x;
                }
            }
        }
    }
    
    // the dtables array is used to find the required dividers for the partitions and printing the results
    reconstruct_partitions(s,dtables,n,k);

    // deleting dynamically allocated storages
    for(int i=0;i<n+1;i++){
        delete values[i];
        delete dtables[i];
    }
    delete values;
    delete dtables;
    delete psums;
}



int main(){
    // number of books
    int n;
    cin>>n;
    int *s=new int[n+1];
    // lengths of n books
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    // no of partitions required
    int k;
    cin>>k;
    partitions(s,n,k);
    return 0;
}
