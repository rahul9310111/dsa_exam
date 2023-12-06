#include<iostream>
using namespace std;

void heapify(int arr[] , int size , int i ){
    //if it is max_heap
    int largest = i ;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= size && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= size && arr[largest] < arr[right]){
        largest = right ;
    }

    if( largest != i ){
        swap(arr[largest], arr[i]);
        heapify(arr,size , largest);
    }
}

void heap_sort(int arr[] , int size){

    while(1< size){

        //swap krna 
        swap(arr[1] , arr[size]);
        size--;

        //make again left over data's into heap
        heapify(arr,size , 1);
    }

}

int main() {
    int arr[] = {-1, 23,56,34,78,45};
    int n = 5;
    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr,n,i);
    }

    for(int i = 1 ; i <= n ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heap_sort(arr,5);
    for(int i = 1 ; i <= n ; i++ ){
        cout<<arr[i]<<" ";
    }
    return 0;
}