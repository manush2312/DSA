/* Peak Index In a Mountain Array
there is an array named as "Mountain" if :-
--> it has atleast 3 elements
--> there exist some "i" with 0 < i < arr.length() - 1 such that :-
    -> arr[0] < arr[1] < ... arr[i-1] < arr[i]
    -> arr[i] > arr[i+1] > ... > arr[arr.length() - 1]

Example of Mountain array : {0, 1, 0} , {0, 2, 10} , {0, 10, 5, 2} , {3, 4, 5, 1}

We need to return the peak element.
*/

#include<iostream>
using namespace std;

int peakIndexOfMountainArray(int arr[], int n){
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;

    while(s < e){
        if(arr[mid] < arr[mid + 1]){
            s = mid + 1;
        }else{
            e = mid;
        }

        mid = s + (e - s)/2;
    }

    return s;
    
}

int main(){

    int even[] = {0, 10, 5, 2};
    int odd[] = {3,4,5,6,4,3,2};

    int answer = peakIndexOfMountainArray(even, 4);
    cout << "Peak Element of Array is: " << answer << endl;   // this will print the index of peak element

    answer = peakIndexOfMountainArray(odd, 7);
    cout << "Peak Element of Array is: " << answer << endl;

    return 0;
}
