/* 
Book Allocation Problem
Given an array of integers, where "arr[i]" represents the number of pages in the "i-th" book. There are "m" number of students 
and the task is to allocate all the books to their students. Allocate books in such a way:-

1. Each student gets atleast one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a continous manner.

You have to allocate the book to "m" students such that maximum number of pages assigned to a student in minimum.
 */

#include<iostream>
using namespace std;


bool isPossibleSolution(int arr[], int n, int m, int mid){
    
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum = pageSum + arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }

            
            pageSum = arr[i];
        }
    }

    return true;

}


int allocateBooks(int arr[], int n, int m){

    // m --> number of students, n --> number of books
    int s = 0, sum = 0, ans = -1;
    for (int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    int e = sum;
    int mid = s + (e - s)/2;

    while(s <= e){

        if(isPossibleSolution(arr, n, m, mid)){

            ans = mid;
            e = mid - 1;

        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }

    return ans;

}

int main(){

    int arr[] = {10, 20, 30, 40};
    int students = 2;

    int answer = allocateBooks(arr, 4, 2);
    cout << "The answer is: " << answer << endl;



    return 0;
}