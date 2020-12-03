#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
动态规划
    首先将字符串中的数字和操作符分别存储下来
    第i个操作符对应的数字是i和i+1，同理第i个数的前面的操作符是i-1，后面的一个是i（i表示在数组中的序号）
    dp[i][j]表示从第i个数字到第j个数字的所有情况
        （1）i==j
            等于数字本身的值
        （2）i != j(j肯定是大于i的) 
            将i-j分成两个式子来看，[i,i]op[i+1,j],[i,i+1]op[i+2,j]...[[i,j-1]]op[j,j]
            将上面的所有情况全部组合起来
            现在需要考虑一个问题是[i,i+k]op[i+k+1,j]的op应该是ops数组里面的哪一个，应该是ops[i+k]
    有了以上，我们就可以写出动态规划了，还有一个需要注意的地方是，（2）情况也就是一个遍历，但是遍历的顺序需要注意，不应该是[0,j]->[j-1,j]而应该是[j-1,j]->[0->j]。如果是从[0,j]开始，你会发现[1,j]..[j-1,j]这些你需要的都还没算
*/

bool isOp(string& c){
    return c == "AND" || c == "OR" || c == "NAND" || c == "NOR";
}

int calculate(const int& num1, const string& op, const int& num2){
    if(op == "AND")
        return num1 && num2;
    else if(op == "OR")
        return num1 || num2;
    else if(op == "NAND")
        return !(num1 && num2);
    else
        return !(num1 || num2);
}

int diffWaysToCompute(vector<string> formula) {
    vector<int> nums;
    vector<string> ops;
    //把数字和计算公式放到两个数组
    for(int i = 0; i < formula.size(); i++){
        if(isOp(formula[i])){
            ops.push_back(formula[i]);
        }else{
            if(formula[i] == "1"){
                nums.push_back(1);
            }else{
                nums.push_back(0);
            }
        }
    }
    cout << "num:" << endl;
    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
    putchar(10);
    cout << "op:" << endl;
    for(int i = 0; i < ops.size(); ++i){
        cout << ops[i] << " ";
    }
    putchar(10);

    int res = 0;
    int n = nums.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
    for(int i = 0; i < n; i++)
        dp[i][i].push_back(nums[i]);
    
    for(int j = 1; j < n; j++){
        for(int i = j-1; i >= 0; i--){
            for(int k = i; k < j; k++){
                for(int r1 : dp[i][k]){
                    for(int r2 : dp[k+1][j]){
                        dp[i][j].push_back(calculate(r1,ops[k],r2));
                    }
                }
            }
        }
    }

    for(int i = 0; i < dp[0][n - 1].size(); ++i){
        if(dp[0][n - 1][i] == 1){
            res++;
        } 
        cout << dp[0][n - 1][i] << " ";
    }
    putchar(10);

    cout << res << endl;
    return res;
}

int main(){
    vector<string> formula{"1", "AND", "0", "OR", "1", "NAND", "0", "NOR", "1"};
    int res = diffWaysToCompute(formula);
    cout << "res = " << res << endl;
    return 0;
}