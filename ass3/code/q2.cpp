#include<iostream>
#include<vector>
#include<string>

using namespace std;
/*offset the number of RPS*/
void after_terget(int & opponent, int & player){
    if(opponent > player){
        opponent = opponent - player;
        player = 0;
    }else{
        player = player - opponent;
        opponent = 0;
    }
}

/*conut the max get point*/
int RPS_game(vector<int> opponent, vector<int> player){
    int res;
    //opponent[0] = Ra, opponent[1] = Pa, opponent[2] = Sa
    //player[0] = Rb, player[1] = Pb, player[2] = Sb

    //win
    //win = min(Ra, Pb) + min(Pa, Sb) + min(Sa, Rb)
    int win = min(opponent[0], player[1]) + min(opponent[1], player[2]) + min(opponent[2], player[0]);

    after_terget(opponent[0], player[1]);
    after_terget(opponent[1], player[2]);
    after_terget(opponent[2], player[0]);

    //draw
    int draw = 0;
    after_terget(opponent[0], player[0]);
    after_terget(opponent[1], player[1]);
    after_terget(opponent[2], player[2]);

    //lose: remaind opponent is player lose point 
    int lose = opponent[0] + opponent[1] + opponent[2];

    //get result
    res = win + draw - lose;

    return res;
}

int main(){
    vector<int> opponent{3, 5, 6};
    vector<int> player{2, 7, 5};
    int res = RPS_game(opponent, player);
    cout << res << endl;

    return 0;
}