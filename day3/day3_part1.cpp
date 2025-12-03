#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<string>

/* SOME OBSERVATIONS
     greedily fill two spots

          _ and _

          if we find a greater number than first then 
               first greedily secure the second number by replacing/filling the second place

          then replace the first place and empty the second
*/

// constants


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

          int maxi=0;

          char null='\0';

          int n=input.size();
          char tens = null, ones =null;
          for(char ch:input){
               if(tens==null){
                    tens=ch;
                    continue;
               }
               if(ones==null || ch-'0'>ones-'0') ones=ch;
               maxi=std::max(maxi, (tens-'0')*10 + (ones-'0'));

               if(ch - '0' > tens - '0'){
                    tens=ch;
                    ones=null;
               }
          }

          ans+=maxi;
          
     }


     std::cout << ans << '\n';
     fout << ans << '\n';
     fin.close();
     fout.close();
     return 0;
}
