#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
using namespace std;

int main()
{
    ifstream f("input.txt");

    vector<string> xx;

    string foo;
    while (getline(f, foo))
    {
        xx.push_back(foo);
    }

    size_t pos = 0;
    vector<uint64_t> asd;
    string t;
    while ((pos = xx[1].find(',')) != string::npos)
    {
        string f = xx[1].substr(0, pos);
        if (f == "x")
        {
            asd.push_back(1e9);
            xx[1].erase(0, pos + 1);
            continue;
        }
        asd.push_back(stoi(f));
        xx[1].erase(0, pos + 1);
    }
    asd.push_back(stoi(xx[1]));
    int d = stoi(xx[0]);
    vector<int> earliest;
    for (size_t i = 0; i < asd.size(); i++)
    {
        int foo = 0;
        while (foo < d)
        {
            // cout << foo << " " << d << endl;
            foo += asd[i];
        }
        earliest.push_back(foo);
    }
    int min = 1e9, num = 0;
    for (size_t i = 0; i < earliest.size(); i++)
    {
        if (earliest[i] < min)
        {
            min = earliest[i];
            num = asd[i];
        }
        // cout << "bus " << asd[i] << "time" << earliest[i] << endl;
    }

    cout << " bus " << num << " time " << min << " " << (min - d) * num << endl;
    //422010821 wrong

    vector<pair<uint64_t, int>> sorted;
    uint64_t start = asd[0];
    for (size_t i = 0; i < asd.size(); i++)
    {
        uint64_t lg = *max_element(asd.begin(), asd.end());
        int lgind = max_element(asd.begin(), asd.end()) - asd.begin();
        if (lg == 0)
        {
            break;
        }
        if (lg == 1e9)
        {
            asd[lgind] = 0;
            continue;
        }
        cout << "largest " << lg << "ind" << lgind << endl;
        sorted.push_back(pair<uint64_t, int>(lg, lgind));
        asd[lgind] = 0;
    }

    // uint64_t a = 100000000000000 / start * start + start;
    uint64_t a = 0;
    uint64_t m = start;
    for (auto i = sorted.begin(); i != sorted.end(); i++)
    {
        uint64_t match = (*i).first;
        int ind = (*i).second;
        cout << "locking in " << match << " a " << a << " ind " << ind << endl;
        if (match == start)
            continue;
        uint64_t diff = a + ind - a / match * match + match;
        while (diff % match != 0)
        {
            // cout << "check " << a << " with " << a / match * match + match << " difference " << diff << " add " << m << endl;
            a += m;
            diff = a + ind - a / match * match + match;
        }
        m *= match;
        cout << "m is now " << m << endl;
    }

    cout << a << endl;
    return 0;
}
