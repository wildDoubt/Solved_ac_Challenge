#include <algorithm>

using namespace std;

long long solution(int price, int money, int count)
{
    long long total = price*((long long)count*(count+1ll))/2ll;
    return max(total - money, 0ll);
}