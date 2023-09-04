//Sqaure Root using Bianry Search

#include<iostream>
using namespace std;

// we are creating here "long long int" because when we sqaure a large integer that might go out of range of "int",
// which may give error, so its better to use "long long int".

// for integer part
long long int integerPart(int n){
    int s = 0, e = n;
    long long int mid = s + (e - s)/2;   
    long long int answer = 0;

    while(s <= e){
        if(mid*mid > n){
            e = mid - 1;   // neglecting the range from mid to last number
        }
        if(mid*mid < n){
            answer = mid;   // storing the answer as it could be possible answer and updating the start
            s = mid + 1;
        }
        if(mid*mid == n){
            return mid;     // perfect sqaure condition
        }

        mid = s + (e - s)/2;
    }

    return answer;
}

// for fractional part
double fractionalPart(int n, int precision, int intPart){
    
    double factor = 1;
    double ans = intPart;

    for(int i=0; i<precision; i++){
        factor = factor / 10;  // it will get 0.1, 0.001, 0.0001, .....

        for(double j=ans; j*j<n; j=j+factor){
            ans = j;
        }

    }

    return ans;

}

int main(){
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int intPart = integerPart(n);

    cout << "Sqaure Root of the number " << n << " is " << fractionalPart(n, 3, intPart) << endl;
}