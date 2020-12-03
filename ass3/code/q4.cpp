#include<iostream>
#include<vector>

using namespace std;

/*
Two-dimensional array jobs, 
every element contains two numbers which are deadline and profit[deadline,profit].
day means that the worker has total work days
*/
int maxProfit(vector<vector<int >> jobs, int day){
    int res = 0;
    //Create a selected_work array as every time unit has a slot
    //the default value is -1
    vector<int> selected_work(day, -1);

    //Sort all jobs in decreasing order based on profit
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b){
                                            return a[1] > b[1];
    });

    //Iterate jobs array and find slot
    for(auto i: jobs){
        int tmpNum = i[0] - 1;
        //If slot which before the deadline is empty, this job can be choose
        while(tmpNum >= 0){
            //If slot is empty, put the profit in it
            if(selected_work[tmpNum] == -1){
                selected_work[tmpNum] = i[1];
                res += i[1];
                break;
            }else{
                //else find another empty slot
                --tmpNum;
            }
        }
    }

    return res;
}


int main(){
    vector<vector<int >> jobs{{2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15}};
    int res = maxProfit(jobs, 3);
    cout << res << endl;
    return 0;
}