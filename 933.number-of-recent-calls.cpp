// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class RecentCounter
{
public:
  RecentCounter() {}

  int ping(int t)
  {
    auto it = ranges::lower_bound(pings, t - 3000);
    pings.erase(pings.begin(), it);
    pings.push_back(t);
    return pings.size();
  }

private:
  deque<int> pings;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @leet end