#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int> > deq;
int val, i, j, n, k, cases;

int main()
{
    scanf("%d", &cases);
    for(j = 0; j < cases; j++)
    {
        deq.clear();
        scanf("%d %d", &n, &k);
        for(i = 0; i < k; i++)
        {
            scanf("%d", &val);
            while(!deq.empty() && deq.back().second < val)
                deq.pop_back();

            deq.push_back(make_pair(i, val));
        }
        for(i = k; i < n; i++)
        {
            printf("%d ", deq.front().second);
            scanf("%d", &val);

            if(!deq.empty() && i - k + 1 > deq.front().first)
                deq.pop_front();
            while(!deq.empty() && deq.front().second <= val)
                deq.pop_back();

            deq.push_back(make_pair(i,val));
        }
        printf("%d\n", deq.front().second);
    }
    return 0;
}
