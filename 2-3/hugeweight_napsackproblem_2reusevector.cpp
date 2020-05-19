#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void printdp(vector<int> &dp) {
  cout << "dp=";
  for (auto i : dp)
    cout << i << ' ';
  cout << endl;
}

int main() {
  // input
  vector<int> w = {2, 1, 3, 2}; // weight
  vector<int> v = {3, 2, 4, 2}; // value
  int W = 5;                    // limit weight

  // define values
  int n = w.size();
  int vsum = accumulate(v.begin(), v.end(), 0);
  vector<int> dp(vsum + 1, INT_MAX - vsum);
  //< minimum weight for the value < j, selection from 0-i. we add w[i] later,
  // so INT_MAX,UINT_MAX will overflow.
  dp[0] = 0;

  // solve
  for (int i = 0; i < n; ++i) {
    for (int j = vsum; j >= v[i]; --j) {
      dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    }
    printdp(dp);
  }

  // compute answer as max value.
  int ans = 0;
  for (int j = 0; j <= vsum; ++j)
    if (dp[j] <= W)
      ans = j;
  cout << "answer = " << ans << endl;

  return 0;
}
