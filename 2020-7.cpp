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

    vector<string> xx;
    string foo;
    int i = 0;
    xx.push_back("");
    while (getline(f, foo))
    {
        xx.push_back(foo);
    }

    regex rgx("(\\w+ \\w+) bags contain(?:( no other bags\\.)|(?: (\\d+) (\\w+ \\w+) bags?, (\\d+) (\\w+ \\w+) bags?, (\\d+) (\\w+ \\w+) bags?, (\\d+) (\\w+ \\w+) bags?.)|(?: (\\d+) (\\w+ \\w+) bags?, (\\d+) (\\w+ \\w+) bags?, (\\d+) (\\w+ \\w+) bags?.)|(?: (\\d+) (\\w+ \\w+) bags?, (\\d+) (\\w+ \\w+) bags?.)|(?: (\\d+) (\\w+ \\w+) bags?.))");
    smatch matches;

    map<string, map<string, int>> m;

    for (size_t j = 0; j < xx.size(); j++)
    {
        string s = xx[j];
        // cout << "search " << s << endl;
        regex_search(s, matches, rgx);
        if (matches[2].str() == " no other bags.")
        {
            m[matches[1].str()] = {};
            continue;
        }
        // cout << s << endl;
        for (size_t i = 3; i < matches.size(); i += 2)
        {
            if (matches[i].str() == "")
                continue;
            m[matches[1].str()][matches[i + 1].str()] = stoi(matches[i].str());
            // cout << i << ": " << matches[i].str() << "\n";
        }
    }

    //part 1
    int ct = 0;
    // for (auto i = m.begin(); i != m.end(); i++)
    // {
    //     if (contains(m, (*i).first, "shiny gold", {}))
    //         ct++;
    // }

    cout << ct << endl;

    //part 2
    cout << count(m, "shiny gold") - 1 << endl;

    return 0;
}
