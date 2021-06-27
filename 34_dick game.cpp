#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef  long long  p; 
struct State
{
   int red;
   int blue;
   p possibilities;
};

int main()
{
   int t;
   cin >> t;

  while (t--)
  {
     int maxRounds = 15;
     cin >> maxRounds;

     int availableRed   = 1;
     int availableBlue  = 1;
     p possibilities = 1;
     vector<State> open = { { 0, 0, 1 } };

    for ( int round = 1; round <= maxRounds; round++)
    {
      possibilities *= availableRed + availableBlue;
       vector<State> next;
      for ( int blue = 0; blue <= round; blue++)
      {
        State state;
        state.red  = round - blue;
        state.blue = blue;
        state.possibilities = 0;
        next.push_back(state);
      }

      for (auto current : open)
      {
        next[current.blue].possibilities += current.possibilities * availableRed;
        next[current.blue + 1].possibilities += current.possibilities * availableBlue;
      }
      open = next;
      availableRed++;
    }


     p moreBlue = 0;
    for (auto current : open)
      if (current.blue > current.red)
        moreBlue += current.possibilities;

     int prize = possibilities / moreBlue; 
     cout << prize <<  endl;
  }

  return 0;
}
