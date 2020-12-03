#include<iostream>
#include<vector>

using namespace std;

int findBestPath(vector<vector<int>> grid){
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> dp(R, vector<int>(C, 0));
    for(int i = 1; i < R; ++i){
        if(grid[i - 1][0] < grid[i][0]){
            dp[i][0] += dp[i - 1][0] + 1;
        }
    }
    for(int j = 1; j < C; ++j){
        if(grid[0][j - 1] < grid[0][j]){
            dp[0][j] += dp[0][j - 1] + 1;
        }
    }
    for(int i = 1; i < R; ++i){
        for(int j = 1; j < C; ++j){
            int top = 0;
            int left = 0;
            if(grid[i - 1][j] < grid[i][j]){
                ++left;
            }
            if(grid[i][j - 1] < grid[i][j]){
                ++top;
            }
            dp[i][j] = min(dp[i - 1][j] + left, dp[i][j - 1] + top);
        }
    }

    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            cout << dp[i][j] << " ";
        }
        putchar(10);
    }
    return dp[R - 1][C - 1];
}

int main(){
    vector<vector<int>> grid{
        {1, 2, 3},
        {1, 3, 2},
        {2, 5, 1}
    };
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            cout << grid[i][j] << " ";
        }
        putchar(10);
    }
    cout << "=========================" << endl;
    int res = findBestPath(grid);
    cout << "res = " << res << endl;
}