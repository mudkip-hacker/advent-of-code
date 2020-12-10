#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
using namespace std;

void startFrom(vector<int> xx, int ind, int volt, long long count)
{
    // cout << "checking from ind " << ind << " val " << xx[ind] << " volt " << volt << " count " << count << endl;
    if (ind == xx.size() - 1)
    {
        // cout << "valid" << ++bar << endl;
        // return 1;
    }
    if (ind < xx.size() - 3 && xx[ind + 3] <= volt + 3 && xx[ind + 2] <= volt + 3 && xx[ind + 1] <= volt + 3)
    {
        // cout << "checking3 " << xx[ind + 1] << " " << xx[ind + 2] << " " << xx[ind + 3] << " " << endl;
        startFrom(xx, ind + 1, xx[ind + 1], 0);
        startFrom(xx, ind + 2, xx[ind + 2], 0);
        startFrom(xx, ind + 3, xx[ind + 3], 0);
    }
    else if (ind < xx.size() - 2 && xx[ind + 1] <= volt + 3 && xx[ind + 2] <= volt + 3)
    {
        // cout << "checking2 " << xx[ind + 1] << xx[ind + 2] << " " << endl;
        startFrom(xx, ind + 1, xx[ind + 1], 0);
        startFrom(xx, ind + 2, xx[ind + 2], 0);
    }
    else if (ind < xx.size() - 1 && xx[ind + 1] <= volt + 3)
    {
        // cout << "checkin1 " << xx[ind + 1] << endl;
        startFrom(xx, ind + 1, xx[ind + 1], 0);
    }
    else
    {
        // cout << "dead end \n";
        // return 0;
    }

    // cout << "return " << count << endl;
    // return count;
}

int main()
{
    ifstream f("input.txt");

    vector<int> xx;
    set<int> yy;
    string foo;
    while (getline(f, foo))
    {
        xx.push_back(stoi(foo));
        yy.insert(stoi(foo));
    }
    sort(xx.begin(), xx.end());
    int j1 = 0, j3 = 0;
    int last = 0;
    for (size_t i = 0; i < xx.size(); i++)
    {
        int x = xx[i];
        if (x - last == 1)
        {
            j1++;
        }
        if (x - last == 3)
        {
            j3++;
        }
        last = x;
    }

    cout << "1j " << j1 << " j3 " << j3 + 1 << endl;

    xx.insert(xx.begin(), 0);

    // first attempt
    // startFrom(xx, 0, 0, 0);
    // cout << bar << endl;

    // second attempt
    map<int, long long> m;
    m[0] = 1;
    size_t i = 1;
    for (; i <= xx[xx.size() - 1]; i++)
    {
        long long currentCount = 0;
        if (yy.find(i) == yy.end())
        {
            m[i] = 0;
            continue;
        }
        if (m.find(i - 1) != m.end())
            currentCount += m[i - 1];
        if (m.find(i - 2) != m.end())
            currentCount += m[i - 2];
        if (m.find(i - 3) != m.end())
            currentCount += m[i - 3];
        m[i] = currentCount;
        cout << "there are " << m[i] << " " << i << endl;
    }
    return 0;
}
