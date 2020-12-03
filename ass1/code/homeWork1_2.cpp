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

void machBN(int *bolts, int *nuts, int left, int right){
    if (left < right){
        /*Step1: pick one nut from nuts[n]*/
        int tmp = nuts[right];
        int i = left;
        int j = right;
        /*Step2: use this nut to compare with bolts. */
        while(i < j){
            while(i < j && bolts[i] < tmp)
                i += 1;
            while(i < j && bolts[j] > tmp)
                j -= 1;
            if(i < j){
                swap(bolts[i], bolts[j]);
            }
                
        }
        /*Step3: move bolts to right*/
        swap(bolts[right], bolts[i]);

        i = left;
        j = right;
        /*Step4: use this bolt (has matched) to compare with nuts:*/
        tmp = bolts[right];
        while(i < j){
            while(i < j && nuts[i] < tmp)
                i += 1;
            while(i < j && nuts[j] > tmp)
                j -= 1;
            if(i < j){
                swap(nuts[i], nuts[j]);
            }
        }
        /*Step5: move nut to right*/
        swap(nuts[right], nuts[i]);
        /*Step6: repeat step1-5(recursion)*/
        machBN(bolts, nuts, i, right - 1);
        machBN(bolts, nuts, left, i - 1);
    }
}
    
        
int main(int argc, char const *argv[]){
    int bolts[] = {17, 16, 3, 10, 2, 6, 7, 12, 8, 14, 11, 1, 18, 4, 5, 0, 13, 15, 9, 19};
    int nuts[] = {15, 10, 7, 4, 17, 6, 9, 1, 0, 16, 13, 12, 19, 5, 8, 18, 2, 3, 14, 11};
    int numSize = sizeof(bolts) / sizeof(int);
    for(int i = 0; i < numSize; i++){
        cout << bolts[i] << " ";
    }
    putchar(10);
    for(int i = 0; i < numSize; i++){
        cout << nuts[i] << " ";
    }

    putchar(10);
    machBN(bolts, nuts, 0, numSize - 1);
    for(int i = 0; i < numSize; i++){
        cout << bolts[i] << " ";
    }
    putchar(10);
    for(int i = 0; i < numSize; i++){
        cout << nuts[i] << " ";
    }
    putchar(10);
    return 0;
}
