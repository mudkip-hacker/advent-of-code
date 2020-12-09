#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
using namespace std;

bool contains(map<string, map<string, int>> m, string containingBag, string findBag, vector<string> searched)
{
    bool a = false;
    // cout << "find " << findBag << " in " << containingBag << endl;
    if (find(searched.begin(), searched.end(), containingBag) != searched.end())
        return false;
    searched.push_back(containingBag);
    for (auto i = m[containingBag].begin(); i != m[containingBag].end(); i++)
    {
        if ((*i).first == findBag)
            a = true;
    }
    bool b = false;
    for (auto i = m[containingBag].begin(); i != m[containingBag].end(); i++)
    {
        if (contains(m, (*i).first, findBag, searched))
            b = true;
    }
    return a || b;
}

int count(map<string, map<string, int>> m, string containingBag)
{
    int ct = 0;
    // cout << "looking in " << containingBag << endl;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if ((*i).first == containingBag)
        {
            if ((*i).second.size() == 0)
            {
                // cout << "terminal" << endl;
                return 1;
            }
            for (auto j = (*i).second.begin(); j != (*i).second.end(); j++)
            {
                // cout << "in " << containingBag << " has " << (*j).second << (*j).first << endl;
                int asd = (*j).second * count(m, (*j).first);
                ct += asd;
                // cout << "counted " << asd << " bags inside ct now " << ct << endl;
            }
        }
    }
    // cout << "returning" << ct << endl;
    return ct + 1;
}

int main()
{
    ifstream f("input.txt");

    vector<int> xx;
    string foo;
    while (getline(f, foo))
    {
        xx.push_back(stoi(foo));
    }
    int x = 0;
    int b = 5;
    for (size_t j = b; j < xx.size(); j++)
    {
        x = xx[j];
        bool found = false;
        for (size_t i = 0; i < xx.size(); i++)
        {
            for (size_t k = 0; k < xx.size(); k++)
            {
                printf("check %d + %d = %s against %d", xx[i], xx[k], xx[i] + xx[k], x);
                if (xx[i] + xx[k] == x)
                {
                    found = true;
                    break;
                }
                if (found)
                    break;
            }
        }
        if (!found)
        {
            break;
        }
    }

    cout << x << endl;

    return 0;
}
