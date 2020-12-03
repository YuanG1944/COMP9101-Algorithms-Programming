#include<iostream>

using namespace std;

long long myPow(int M, int n){
    /*set result */
    long long res = 1;
    while(n > 0){
        /*Bit operation, if the last bit is 1
        do the res *= M*/
        if((n & 1)){
            res *= M;
        }
        M *= M;
        /*right shifted one time*/
        n = n >> 1;
    }
    return res;
}

int main(){
    long long res = myPow(2, 3);
    cout << res << endl;
    return 0;
}