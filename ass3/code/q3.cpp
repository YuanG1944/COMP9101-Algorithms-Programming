#include<iostream>
#include<vector>

//写的时候把时刻表换成分钟
//一天有1440分钟(区间:[0, 1440])

using namespace std;

int findMinplatform(vector<vector<int>>& timeTable){
    if(timeTable.size() < 1) return timeTable.size();

    //Separate the schedule which across midnight to the two schedules.
    auto i = timeTable.begin();
    while(i != timeTable.end()){
        if((*i)[0] > (*i)[1]){
            vector<int> b = {0, (*i)[1]};
            (*i)[1] = 1044;
            i = timeTable.insert(i + 1, b);
        }else{
            ++i;
        }
    }

    //Sort timeTable array based on departures time
    sort(timeTable.begin(), timeTable.end(), [](vector<int> &a, vector<int> &b){
                                            return a[0] < b[0];
    });

    //calculate the maximum number of trains stay in platform at same time
    //initialize the first interval
    int left = timeTable[0][0];
    int right = timeTable[0][1];
    //initialize the result and tmp
    //res is the minimum number of platforms
    int res = 1;
    //tmp is count the maximum number of trains stay in platform at same time
    int tmp = 1;

    for(int i = 1; i < timeTable.size(); ++i){
        //if current departures time not in the interval
        //picked max(res, tmp)
        if(right < timeTable[i][0]){
            left = timeTable[i][0];
            right = timeTable[i][1];
            res = max(res, tmp);
            tmp = 1;
        }else{
            //if current departures time in the interval
            //shrink the interval
            if(left < timeTable[i][0]){
                left = timeTable[i][0];
            }
            if(right > timeTable[i][1]){
                right = timeTable[i][1];
            }
            //the number of trains stay in platform at same time +1
            ++tmp;
        }
    }
    return res;
}


int main(){
    vector<vector<int>> time_table = {{10, 16}, {2, 8}, {1, 6}, {5, 12}, {23, 5}};
    int res = findMinplatform(time_table);
    cout << "sort\n";
    for(auto i: time_table){
        cout << i[0] << " " << i[1] << endl;
    }
    cout << "res = " << res << endl;
    return 0;
}