#include<iostream>
#include<vector>
using namespace std;



void SelectionSort(vector<int> &arr, int n){
    for(int i = 0 ; i< n-1 ; i++){
        int minIndex = i;

        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]);
    }   
}


int main(){

    vector<int> v;
    int n;
    cout << "Enter the number of elements of Vector/Array: " ;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for(int i=0; i<n; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    cout << "The elements are : " ;
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    SelectionSort(v, n);

    cout << "Elements after sorting : " ;
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}