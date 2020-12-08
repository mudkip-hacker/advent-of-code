#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
using namespace std;

int main()
{
    ifstream f("input.txt");
    vector<string> xx;
    vector<int> yy;
    string line;
    while (getline(f, line))
    {
        xx.push_back(line.substr(0, 3));
        yy.push_back(stoi(line.substr(3)));
    }

    //part 1
    int acc = 0, rip = 0;
    vector<int> visited;

    while (true)
    {
        if (find(visited.begin(), visited.end(), rip) != visited.end())
            break;
        visited.push_back(rip);
        string x = xx[rip];
        int y = yy[rip];
        // cout << "executing " << x << " " << y << endl;
        if (x == "nop")
        {
            rip++;
        }
        else if (x == "acc")
        {
            acc += y;
            rip++;
        }
        else if (x == "jmp")
        {
            rip += y;
        }
    }

    cout << acc << endl;
    vector<string> pp;
    for (size_t rep = 0; rep < xx.size(); rep++)
    {
        visited.clear();
        pp.clear();
        for (size_t i = 0; i < xx.size(); i++)
        {
            pp.push_back(xx[i]);
        }
        acc = 0, rip = 0;
        if (xx[rep] == "acc")
            continue;
        if (xx[rep] == "nop")
            pp[rep] = "jmp";
        else if (xx[rep] == "jmp")
            pp[rep] = "nop";

        // cout << "doing\n";
        // for (size_t k = 0; k < pp.size(); k++)
        // {
        //     cout << pp[k] << " " << yy[k] << endl;
        // }
        // cout << endl;

        while (true)
        {
            if (find(visited.begin(), visited.end(), rip) != visited.end())
                break;
            if (rip >= pp.size())
                break;

            visited.push_back(rip);
            string x = pp[rip];
            int y = yy[rip];
            // cout << "executing " << x << " " << y << endl;
            if (x == "nop")
            {
                rip++;
            }
            else if (x == "acc")
            {
                acc += y;
                rip++;
            }
            else if (x == "jmp")
            {
                rip += y;
            }
            // cout << "rip " << rip << endl;
        }
        if (rip >= pp.size())
        {

            break;
            cout << "-----------------------------------------------" << acc << endl;
        }
    }

    cout << acc << endl;

    return 0;
}