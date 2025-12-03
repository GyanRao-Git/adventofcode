#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

/* SOME OBSERVATIONS
     instead of two spots we need to fill 12 spots 
     
     can we recurse through the input and find?
     12^n

     take/skip logic

     can we memoise later?


*/

long long fn(int i, int len, const std::string& s, std::vector<std::vector<long long>>& dp) {

    if (len == 12) return 0;

    if (i == s.size()) return LLONG_MIN;

    if (dp[i][len] != -1) return dp[i][len];

    int digit = s[i] - '0';

    long long skip = fn(i + 1, len, s, dp);

    long long take = (long long)digit * (long long)pow(10, 11 - len) + fn(i + 1, len + 1, s, dp);

    return dp[i][len] = std::max(take, skip);
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

          ans+=fn(0,0,input,dp);
          
     }


     std::cout << ans << '\n';
     fout << ans << '\n';
     fin.close();
     fout.close();
     return 0;
}
