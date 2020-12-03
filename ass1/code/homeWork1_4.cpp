#include<iostream>
#include<vector>

using namespace std;

/*the Two-dimensional vector reprsent orchard, 
  n as the length of purchased square
  ii as the maximum i index
  jj as the maxinum j index */
int getMaxApple(vector<vector<int>> & orchard, int n, int & ii, int & jj){
    int max = -1;
    int tmpMax = 0;
    for(int i = 1; i < 4 * n; ++i){
        orchard[i][0] += orchard[i - 1][0];
        orchard[0][i] += orchard[0][i - 1];
    }
    for(int i = 1; i < 4 * n; ++i){
        for(int j = 1; j < 4 * n; ++j){
            /*The value of the element in the lower right corner*/
            orchard[i][j] += (orchard[i - 1][j] + orchard[i][j - 1] 
                            - orchard[i - 1][j - 1]);
            if(i >= n && j >= n){
                /*get the sum of square*/
                int tmpMax = orchard[i][j] - orchard[i - n][j] 
                            - orchard[i][j - n] + orchard[i - n][j - n];
                if(tmpMax > max){
                    max = tmpMax;
                    ii = i;
                    jj = j;
                }
            }
        }
    }
    return max;
}

int main(int argc, char const *argv[]){
    vector<vector<int>> matrix = {{1, 3, 2, 1, 5, 1, 2, 3},
                                  {2, 3, 4, 3, 5, 6, 1, 3},
                                  {3, 4, 5, 7, 8, 2, 3, 1},
                                  {2, 3, 4, 3, 5, 6, 1, 3},
                                  {0, 4, 5, 7, 8, 2, 3, 1},
                                  {2, 3, 4, 9, 9, 6, 1, 3},
                                  {3, 4, 5, 7, 9, 2, 3, 1},
                                  {2, 3, 4, 3, 5, 6, 1, 3},};
                                  
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            cout << matrix[i][j] << " ";
        }
        putchar(10);
    }
    int ii = 1, jj = 1;
    int max = getMaxApple(matrix, 2, ii, jj);
    putchar(10);
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            cout << matrix[i][j] << " ";
        }
        putchar(10);
    }
    cout << "ii: " << ii << " " << "jj: " << jj << endl;
    cout << "max = " << max << endl;

    return 0;
}

