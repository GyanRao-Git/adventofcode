#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
// #include<string>

/* SOME OBSERVATIONS

     we can merge the intervals to reduce duplicate checking
     run loop and check 
          if number start with zero then invalid
          if repeated numbers then invalid


*/

// constants

bool check(long long x){
     std::string s= std::to_string(x);
     int n = s.size();
     if (n % 2 != 0) return false;

     std::string left  = s.substr(0, n/2);
     std::string right = s.substr(n/2);

     return left == right;
}

int main()
{

     std::ifstream fin("../input.txt");
     // std::ifstream fin("../test_input.txt");
     if (!fin)
     {
          std::cerr << "Cannot open input file";
          return 1;
     }

     std::ofstream fout("../output.txt");
     if (!fout)
     {
          std::cerr << "Cannot open output.txt file";
          return 1;
     }

     long long ans=0;
     std::string input;
     std::vector<std::pair<long long,long long>> intervals;
     while (std::getline(fin, input, ',')){

          int dash;
          for(int i=0;i<input.size();i++){
               if(input[i]=='-'){
                    dash=i;
                    break;
               }
          }
          long long start=std::stoll(input.substr(0,dash));
          long long end=std::stoll(input.substr(dash+1));
          intervals.push_back(std::make_pair(start,end));
          
     }

     std::sort(intervals.begin(),intervals.end());
     std::vector<std::pair<long long,long long>> merged_intervals;
     for(auto it:intervals){
          if (merged_intervals.empty() || it.first > merged_intervals.back().second) merged_intervals.push_back(it);
          else  merged_intervals.back().second = std::max(merged_intervals.back().second, it.second);
     }


     for(auto&[start,end]:merged_intervals){
          for(long long i=start;i<=end;i++){
               if(check(i)) ans+= i;
          }
     }

     std::cout << ans << '\n';
     fout << ans << '\n';
     fin.close();
     fout.close();
     return 0;
}
