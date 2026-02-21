// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int countPrimeSetBits(int left, int right)
  {
    auto is_prime = [p = { 2, 3, 5, 7, 11, 13, 17, 19 }](unsigned n) {
      return ranges::find(p, popcount(n)) != p.end();
    };
    return ranges::count_if(views::iota(left, right + 1), is_prime);
  }
};
// @leet end