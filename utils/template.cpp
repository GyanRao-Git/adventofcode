#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<string>

/* SOME OBSERVATIONS

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

     while (std::getline(fin, input, ',')){

          
          
     }


     std::cout << ans << '\n';
     fout << ans << '\n';
     fin.close();
     fout.close();
     return 0;
}
