#include<iostream>
#include<string>

using namespace std;

/*match substring of dna O(N)*/
bool isVenom(string dna, string venom){
    int i = 0, j = 0;
    int m = dna.size(), n = venom.size();
    while(i < m && j < n){
        if(dna[i] == venom[j]){
            ++i;
            ++j;
        }else{
            ++i;
        }
    }
    return j == n;
}

/*create level of venomSequence O(5*x) = O(1)*/
string venomLevel(int level){
    string sequence = "SNAKE";
    string venom;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < level; ++j){
            venom += sequence[i];
        }
    }
    return venom;
}

/*get Maximum venomLevel O(n/5logn)*/
int getvenomLevel(string dna){
    int maxLevel = dna.size() / 5;
    int l = 0, r = maxLevel;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        //create venom sequence
        string venom = venomLevel(mid);
        //check whether dna sequence satisfy venom sequence
        if(isVenom(dna, venom)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}

int main(){
    string dna = "SSSFFDHGFHFNNNGHCVBNFHAAAGFDTFGHKKKFGFDGFGEEE";
    int res = getvenomLevel(dna);
    cout << res << endl;
}