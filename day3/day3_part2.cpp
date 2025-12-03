#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<string>

/* SOME OBSERVATIONS
     instead of two spots we need to fill 12 spots 
     
     can we recurse through the input and find?
     12^n

     take/skip logic

     can we memoise later?


*/

long long fn(int idx, const std::string &input, int len,
             std::vector<std::vector<long long>> &dp, long long curr) {
    
    if (len == 12) return curr;
    if (idx >= (int)input.size()) return 0;

    bool canMemo = (curr == 0);

    if (canMemo && dp[idx][len] != -1) return dp[idx][len];

    int digit = input[idx] - '0';
    
    long long takeCurr = curr * 10 + digit;
    long long take = fn(idx + 1, input, len + 1, dp, takeCurr);
    long long skip = fn(idx + 1, input, len, dp, curr);

    long long res = std::max(take, skip);

    if (canMemo) dp[idx][len] = res;

    return res;
}



int main(){

     std::ifstream fin("../input.txt");
     // std::ifstream fin("../test_input.txt");
     if (!fin){
          std::cerr << "Cannot open input file";
          return 1;
     }

     std::ofstream fout("../output.txt");
     if (!fout){
          std::cerr << "Cannot open output.txt file";
          return 1;
     }

     long long ans=0;
     std::string input;

     while (std::getline(fin, input)){

          long long maxi=0;

          char null='\0';

          int n=input.size();

          std::vector<std::vector<long long>> dp(n,std::vector<long long>(12,-1));
          
          std::string temp="";

          ans+=fn(0,input,0,dp,0);
          
     }


     std::cout << ans << '\n';
     fout << ans << '\n';
     fin.close();
     fout.close();
     return 0;
}
