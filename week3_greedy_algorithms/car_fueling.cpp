#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    int count = 0, rCount = 0;
    int r_Pos = -2, c_Loc = 0;
    int i = 0;

    stops.push_back(dist);

    while (true)
    {
        if (tank + c_Loc >= dist)
        {
            return rCount;
        }
        if (tank < stops[i] - c_Loc)
        {
            r_Pos = i - 1;
            if (c_Loc == stops[r_Pos])
            {
                return -1;
            }
            rCount++;
            c_Loc = stops[i - 1];
            i -= 1;
            continue;
        }
        i++;
    }
    return -1;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}