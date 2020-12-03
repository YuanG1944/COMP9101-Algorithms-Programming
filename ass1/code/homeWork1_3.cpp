#include<iostream>

using namespace std;

//This is the cpp code
//*Swap two value**/
void swap(int * a, int * b){
    int tmp;
    *a = tmp;
    *a = *b;
    *b = tmp;
}

void Search(int *a, int &FMax, int &secMax, int left, int right){
	if(left == right){
		FMax = left;
        secMax = left;
	}else if(left == right - 1){
		if(a[left] > a[right]){
			FMax = left;
			secMax = right;
		}else{
			FMax = right;
			secMax = left;
		}
	}else{
        /*Step1: Divide the apples into two piles. 
            Use Fmax to store the index of the heaviest apple 
            and use secMax to store the index of the second heaviest apple.*/
		int m = (right - left + 1) / 2;	
		for(int i = left; i < left + m; i++){ 
			if(a[i] > a[i + m])
            /*Step2: Compare the weight of two apples. 
                Heavy on the left and light on the right.*/
                swap(a[i], a[i + m]);
		}	
        /*Step3: Recursion into the heavier side*/
		Search(a, FMax, secMax, left + m, right);
        /*Step4: Compare the small one and last round small apple, choose the heavy one.*/
        if(a[FMax - m] > a[secMax]) 
			secMax = FMax - m;
}

// 对后半部分再次一分为二进行锦标赛算法,
            // 这样最终得到的a[FMax]就是最大值, 
            // 但是a[secMax]不一定
	        // 在每次求出最大值之后,
            // 此时的次大值仅仅是最后一次和最大值相比的数,
            // a[FMax - m]则是倒数第二个和最大值相比的数，
            // 因此要在这两个数之间进行选择

int main(int argc, char const *argv[]){
    int FMax, smax;
    int arr[] = {2, 12, 7, 11, 5, 3, 6, 0, 4, 13, 8, 15, 1, 9, 10, 18, 14, 17, 19, 16};
    // search(arr, FMax, smax, 0, 19);
    Search(arr, FMax, smax, 0, 19);
    putchar(10);
    //cout << FMax << " " << smax << endl;
    cout << arr[FMax] << " " << arr[smax] << endl;
    return 0;
}

/*
当n是2的幂时(n=2k),有，
T(n)=T(n/2) + n/2+1  n>2
    = 1        n= 2

    = 0        n= 1
上式展开：
 T(n)=T(n/2) +n/2+1
      =T(n/4) + n/4 + n/2+2
      =T(n/8) + n/8  +n/4 + n/2+3    
=…
= T(2)+2+ 22 +…+22 + 2k-1+k-1

      =1+2+ 22 +…+22 + 2k-1+k-1

      =2k-1+k-1 =n+logn-2


**/