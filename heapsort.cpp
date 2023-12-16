#include <iostream>
using namespace std;


void heapify(int arr[],int n,int root){
    int largest = root;                                   // root is root element index.
    int left = 2*root +1;
    int right = 2*root+2;

    if(arr[left]>arr[largest] && left<n){
        largest = left;
    }
    if(arr[right]>arr[largest] && right < n){
        largest = right;
    }
    if(largest!=root){
        swap(arr[root],arr[largest]);
        heapify(arr,n,largest);                     //Recursively heapify the sub-tree.
    }

}

void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){              //Divide array into left & right subtree.
        heapify(arr,n,i);                   //Call function to maintain heap property.
    }
    for(int i = n-1;i>=0;i--){              //One by one extract an element from heap
        swap(arr[0],arr[i]);                //move current largest to end.
        heapify(arr,i,0);                   //Call max heapify on reduced heap.
    }
    
}

void printarray(int arr[],int n){

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[20];
    int n;
    cout<<"\nEnter no . of elements to store : ";
    cin>>n;
    cout<<"\nEnter elements to Store : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"\nEntered array is : ";
    printarray(arr,n);
    for(int i = n/2 -1;i>=0;i--){                  //Starting Comparison from leaf to largest.
        heapify(arr,n,i);                          //Calling heap property to maintain.
    }

    cout<<"\nBefore Heapifying array is : ";
    printarray(arr,n);                              //Unsorted.
    heapSort(arr,n);                                //heapsort for sorting.
    cout<<"\nAfter Heapifying array is : ";
    printarray(arr,n);                              //Sorted Array.
    return 0;                             
}
