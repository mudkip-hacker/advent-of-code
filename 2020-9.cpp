#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
using namespace std;

int main()
{
    ifstream f("input.txt");

    vector<long long> xx;
    string foo;
    while (getline(f, foo))
    {
        xx.push_back(stoll(foo));
    }
    int x = 0;
    int b = 25;
    int ind = 0;
    for (size_t i = b; i < xx.size(); i++)
    {
        x = xx[i];
        ind = i;
        bool found = false;
        for (size_t j = i - b; j < i; j++)
        {
            for (size_t k = i - b + 1; k < i; k++)
            {
                if (k == j)
                    continue;
                // printf("check %d %d    %d + %d = %d against %d\n", j, k, xx[j], xx[k], xx[j] + xx[k], x);
                if (xx[j] + xx[k] == x)
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found)
        {
            break;
        }
    }

    //25

    cout << x << " " << ind << endl;

    int low = 0, high = 0;
    for (low; low < ind; low++)
    {
        high = 0;
        bool found = false;
        long long acc = xx[low];
        // cout << "start from " << acc << endl;
        for (high = low + 1; high < ind; high++)
        {
            acc += xx[high];
            // cout << "now is " << acc << endl;
            if (acc == x)
            {
                // cout << "found " << acc << endl;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    long long m = *min_element(xx.begin() + low, xx.begin() + high);
    long long ma = *max_element(xx.begin() + low, xx.begin() + high);

    cout << m << " " << ma << " " << m + ma << endl;

    return 0;
}
