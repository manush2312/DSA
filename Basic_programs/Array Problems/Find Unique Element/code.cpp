// size of array is N, where N is equal to "2m+1"(i.e. odd number). Now in the array, "M" numbers are present twice and 
// one number is present only once.
// Example --> N=3 then array size = 7
// array = {3,7,2,2,7,3,4},   here 3 numbers(2,3,7) are occuring twice and 4 is occuring only once. And we need to find 
// number which is occuring only once.

#include<iostream>
using namespace std;

int findUniqueElement(int arr[], int n){

    int ans=0;

    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];    // we are XORing each element 
    } 

    return ans;

}


int main(){
    int n;
    int arr[10];
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    cout << "Enter the elements:" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int answer = findUniqueElement(arr, n);

    cout << "The unique element is: " << answer << endl;

    return 0;
}