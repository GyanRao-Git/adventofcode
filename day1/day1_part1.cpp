#include<iostream>
#include<fstream>

/* SOME OBSERVATIONS

     dial starts with 50 
     password is number of times dial points at 0

     R is add and take MOD
     L is subtract and take MOD

     so its not negative add 99

*/

// constants 
#define MOD 100
#define START 50
int main(){
     
     std::ifstream fin("input.txt");
     if(!fin){
          std::cerr<<"Cannot open input file";
          return 1;
     } 

     std::ofstream fout("output.txt");
     if(!fout){
          std::cerr<<"Cannot open output.txt file";
          return 1;
     } 

     int curr_value=START;
     int ans=0;
     std::string rotation;
     while (std::getline(fin, rotation))
     {

          if(rotation.size()<2) continue;

          char direction = rotation[0];
          int magnitude = std::stoi(rotation.substr(1));
          int step = (direction=='L'?-magnitude:magnitude);
          
          curr_value= (curr_value + step + MOD)%MOD;
          if(curr_value==0) ans++;
     }
     std::cout<<ans<<'\n';
     fout<<ans<<'\n';
     fin.close();
     fout.close();
     return 0;
}
