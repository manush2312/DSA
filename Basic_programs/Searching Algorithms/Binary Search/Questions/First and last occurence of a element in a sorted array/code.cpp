// first and last occurence of a element in a sorted array
// given a sorted array of size "N" and also given an integer "K". Our task is to find the first and last position of integer "K"
// in sorted array.

# include<iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key){

    int s = 0, e = n-1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while(s <= e){

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;   // as to find the first occurence
        }
        else if(arr[mid] > key){  // left part
            e = mid -1;
        }
        else if(arr[mid] < key){  // right part
            s = mid + 1;
        }
        mid = s + (e - s) / 2;

    }

    return ans;
}

int lastOccurence(int arr[], int n, int key){

    int s = 0, e = n-1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while(s <= e){

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;   // as to find the first occurence
        }
        else if(arr[mid] > key){  // left part
            e = mid -1;
        }
        else if(arr[mid] < key){  // right part
            s = mid + 1;
        }
        mid = s + (e - s) / 2;

    }

    return ans;
}

int main(){

    int even[] = {1,2,3,3,5};

    cout << "First occurence of key is at Index: " << firstOccurence(even, 5,3) << endl;
    cout << "Last occurence of key is at Index: " << lastOccurence(even, 5,3) << endl;
}