#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//SOLUTION
int secondSmallest(int arr[],int n)
{
    int small = INT_MAX, second_small = INT_MAX;
    for(int i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }
    }
   return second_small;     
}
int secondLargest(int arr[],int n)
{
    int large=INT_MIN,second_large=INT_MIN;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}

int main() {
    //INPUT
    int arr[]={0,2,15,9,10,4,0,13,13,18,18};  
    //int n = 6;
    int n=sizeof(arr)/sizeof(arr[0]);
        int sS=secondSmallest(arr,n);
        int sL=secondLargest(arr,n);
    cout<<"Second smallest: "<<sS<<endl;
    cout<<"Second largest: "<<sL<<endl;
    return 0;
}