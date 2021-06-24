#include<iostream>
using namespace std;

void merge( int a[], int start, int end){

    int temp[10000];     
    int mid= ( start + end ) / 2; 

    int i= start, j= mid+1, k= start;
     while( i<= mid && j<= end ){

        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<= end){
        temp[k++]=a[j++];
    }

    for(int i= start; i<= end; i++){
        a[i]= temp[i];
    }

    return; 
} 

void mergeSort( int a[], int start, int end){
    if( start >= end ){
        return;
    }
    int mid= ( start + end ) / 2;
    mergeSort( a, start, mid);
    mergeSort( a, mid + 1, end);
    merge( a, start, end);

    return;

}


int main(){

    int n;                  
    cout<<"Enter the number of elements of the array to be sorted: ";
    cin>>n;

    int a[n];
    cout<<"Enter the elements of the array: ";
    
    for(int i= 0; i<n; i++){
        cin>>a[i];
    }
    mergeSort( a, 0, n-1 );
    for(int i= 0; i< n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}