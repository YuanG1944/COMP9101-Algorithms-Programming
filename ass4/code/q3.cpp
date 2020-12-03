#include<iostream>
#include<vector>

using namespace std;

//蠢!!!
int letsHappy(vector<vector<int>> activities){
    if(activities.size() == 0) return 0;
    if(activities.size() == 1) return max(activities[0][0], max(activities[0][1], activities[0][2]));
    int n = activities.size();
    for(int i = 1; i < n; ++i){
        activities[i][0] += max(activities[i - 1][1], activities[i - 1][2]);
        activities[i][1] += max(activities[i - 1][0], activities[i - 1][2]);
        activities[i][2] += max(activities[i - 1][1], activities[i - 1][0]);
    }
    return max(activities[n - 1][0], max(activities[n - 1][1], activities[2][0]));
}

//   {4, 2, 3}
int main(){
    vector<vector<int>> activities{
        {1, 2, 4},
        {1, 3, 2},
        {2, 5, 1},
        {3, 1, 2} 
    };
    
    for(int i = 0; i < activities.size(); ++i){
        for(int j = 0; j < activities[0].size(); ++j){
            cout << activities[i][j] << " ";
        }
        putchar(10);
    }
    cout << "=======================" << endl;
    // cout << max(5, max(0, 3)) << endl;
    int res = letsHappy(activities);
    cout << "res = " << res << endl;
    return 0;
}