#include<iostream>
#include<vector>

using namespace std;

/*This is the binary search fuction*/
int binSearch(vector<int> num, int left, int right, int key){
    if(left > right) return -1;
    int mid = left + (right - left) / 2;
    if(num[mid] == key){
        return mid;
    }
    if(num[mid] > key){
        return binSearch(num, left, mid - 1, key);
    }else{
        return binSearch(num, mid + 1, left, key);
    }
}

/*This is the judgement function to check that 
whether there are two equal numbers in squareSum[] array*/
bool judgeSquareSum(vector<int> num){
    /*Set a vextor to contain squares of two distinct numbers*/
    vector<int> squareSum; 
    /*Step1: append sqSum in squareSum array*/
    for(int i = 0; i < num.size() - 1; i++){
        for(int j = i + 1; j < num.size(); j++){
            int sqSum = num[i] * num[i] + num[j] * num[j];
            squareSum.push_back(sqSum);
        }
    }
    /*Step2: Sort squareSum[] array*/
    sort(squareSum.begin(),squareSum.end());
    /*Step3: Use binary search to find whether 
    there are two equal numbers in squareSum[] array*/
    for(int i = 0; i < squareSum.size() - 1; i++){
        if(binSearch(squareSum, i + 1, squareSum.size(), squareSum[i]) != -1){
            return true;
        }
    }
    return false;
}

int main(int argc, const char** argv) {
    vector<int> num{3, 4, 2, 0, 1, 5};
    bool juge = judgeSquareSum(num);
    cout << juge << endl;
    return 0;
}