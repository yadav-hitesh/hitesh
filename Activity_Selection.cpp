//maximum activities can take place at an event

#include<iostream>
#include<limits.h>
#define max 20
using namespace std;

typedef struct act{
    int start;
    int finish;
}act;

int ans_set[30],count=0;

int act_set_rec(act arr[],int i,int j){
    //initially i=0,j=n+1 (dummy activities)
 
    int selected=i,next=i+1;
    while(next<j&&arr[next].start<arr[selected].finish){
        next++;
        if(next<j){
            ans_set[count++]=next;
            return(1+act_set_rec(arr,next,j));
        }
        else
            return 0;
    }
}

int act_set_iter(act A[],int i,int j){
    //call comes with initial value as A=arr,i=1,j=n
    int m,count=0,k,selected=i;
    ans_set[count++]=i;
    for(k=i+1;k<=j;k++){
        if(A[k].start>=A[selected].finish){
            ans_set[count++]=k;
            selected=k;
        }
    }
    return count;
}

int main(){
    act arr[max];
    int n,i,j,noofact;
    cout<<"Enter number of activities: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Enter starting time of activity "<<i;
        cin>>arr[i].start;
        cout<<"Enter finishing time of activity "<<i;
        cin>>arr[i].finish;
    }
    
    arr[0].finish=-1;
    arr[n+1].start=INT_MAX;
    sort(arr,j-1);
    for(i=1;i<=n;i++){
        cout<<arr[i].start<<"  "<<arr[i].finish<<endl;
    }
    noofact=act_set_rec(arr,0,n+1);
    cout<<"Maximum number of activities that can take place(recursive): "<<noofact;
    print(arr,noofact);
    noofact=act_set_iter(arr,1,n);
    cout<<"Maximum number of activities that can take place(iterative): "<<noofact;
    print(arr,noofact);

    return 0;
}