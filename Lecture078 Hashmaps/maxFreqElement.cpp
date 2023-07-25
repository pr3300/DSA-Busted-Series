#include <bits/stdc++.h>
using namespace std;
int maximumFrequency(vector<int> &arr, int n)
{
    map<int, int> m;
    int maxFreq = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        maxFreq = max(maxFreq, m[arr[i]]);
    }
    for (int i = 0; i < n; i++)
    {
        if (maxFreq == m[arr[i]])
        {
            ans = arr[i];
            break;
        }
    }

    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 1, 4, 3, 4, 2, 6};
    int n = arr.size();
    int ans = maximumFrequency(arr, n);
    cout << "Answer is: " << ans << endl;
    return 0;
}