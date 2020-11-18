/*

Roll No - 101803318
Name - Yashwant
Batch - COE 15
Ques - 2

Complexity - 

Suppose the job scanning through a shelf of books is to be split between k workers. 
Toavoid the need to rearrange the books or separate them into piles, we can divide the shelf into k regions and assign each region to one worker. 
What is the fairest way to divide the shelf up? 
If each book is the same length, partition the books into equal-sized regions, 100 100 100 | 100 100 100 | 100 100 100
But what if the books are not the same length? This partition would yield 100 200 300 | 400 500 600 | 700 800 900
Which part of the job would you volunteer to do? 
How can we find the fairest possiblepartition, i.e. 100 200 300 400 500 | 600 700 | 800 900

Input: A given arrangement S of non-negative numbers and an integer k.

Output: Partition S into k ranges, so as to minimize the maximum sum over all the ranges. This so-called linear partition problem arises often in parallel processing, since we seek to balance the work done across processors so as to minimize the total elapsed run time. We'll find a botched solution to this problem.

INPUT 1
9
100 200 300 400 500 600 700 800 900
3
OUTPUT 1


INPUT 2
OUTPUT 2

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 20
#define maxk 20

void print_books(int *s,int start,int end){
    int i;
    for(i=start;i<=end;i++){
        cout<<s[i]<<" ";
    }
    cout<<"\n";
}

void reconstruct_partitions(int *s,int d[maxn+1][maxk+1],int n,int k){
    if(k==1){
        print_books(s,1,n);
    }else{
        reconstruct_partitions(s,d,d[n][k],k-1);
        print_books(s,d[n][k]+1,n);
    }
}

void partitions(int *s,int n,int k){
    // dp for values
    int m[maxn+1][maxk+1]{};
    // dp for tables 
    int d[maxn+1][maxk+1]{};
    // prefix sums array
    int p[maxn+1];
    // test split cost
    int cost;
    // counters
    int i,j,x;

    // construct prefixes sums
    p[0]=0;
    for(i=1;i<=n;i++){
        p[i]=p[i-1]+s[i];
    }
    // initialize boundaries
    for(i=1;i<=n;i++){
        m[i][1]=p[i];
    }
    for(j=1;j<=k;j++){
        m[1][j]=s[1];
    }

    // evaluate main recurrence
    for(i=2;i<=n;i++){
        for(j=2;j<=k;j++){
            m[i][j]=INT_MAX;
            for(x=1;x<=(i-1);x++){
                cost=max(m[x][j-1],p[i]-p[x]);
                if(m[i][j]>cost){
                    m[i][j]=cost;
                    d[i][j]=x;
                }
            }
        }
    }
    
    // print book partition
    reconstruct_partitions(s,d,n,k);
}



int main(){
    // number of books
    int n;
    cin>>n;
    int *s=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int k;
    cin>>k;
    partitions(s,n,k);
    return 0;
}
