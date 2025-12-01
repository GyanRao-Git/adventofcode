#include <iostream>
#include <fstream>

/* SOME OBSERVATIONS

     some added checks can be to see if it crossed 0

*/

// constants
#define MOD 100
#define START 50
int main()
{

     std::ifstream fin("../input.txt");
     // std::ifstream fin("../test_input.txt");
     if (!fin)
     {
          std::cerr << "Cannot open input file";
          return 1;
     }

     std::ofstream fout("output.txt");
     if (!fout)
     {
          std::cerr << "Cannot open output.txt file";
          return 1;
     }

     int curr_value = START;
     int ans = 0;
     std::string rotation;
     while (std::getline(fin, rotation))
     {
          if (rotation.empty())
               continue;

          char direction = rotation[0];
          int magnitude = std::stoi(rotation.substr(1));
          int step = (direction == 'L') ? -magnitude : magnitude;

          if (direction == 'L')
          {
               if (curr_value > 0 && curr_value - magnitude <= 0)
                    ans++;
               ans += (curr_value - magnitude) / -100;
          }
          if (direction == 'R')
               ans += (curr_value + step) / 100;

          curr_value = ((curr_value + step) % MOD + MOD) % MOD;
     }
     std::cout << ans << '\n';
     fout << ans << '\n';
     fin.close();
     fout.close();
     return 0;
}

// std::cout<<rotation<<" "<<curr_value<<" "<< curr_value+step<<" "<<ans2<<std::endl;
// std::cout<<rotation<<" "<<temp<<" "<< temp+magnitude<<" "<<ans<<std::endl;