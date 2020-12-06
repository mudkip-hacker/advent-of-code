#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <regex>
using namespace std;

int main()
{
    ifstream f("input.txt");

    vector<string> xx;
    string line;
    while (getline(f, line))
    {
        xx.push_back(line);
    }

    //part 1
    int max = 0;
    vector<int> seats;
    for (int i = 0; i < xx.size(); i++)
    {
        int lower = 0, upper = 127, cl = 0, cu = 7;
        string x = xx[i];
        for (int j = 0; j < 7; j++)
        {
            char s = x[j];
            if (s == 'F')
            {
                upper = upper - (upper - lower + 1) / 2;
                // cout << "low " << lower << " high " << upper << endl;
            }
            else
            {
                lower = lower + (upper - lower + 1) / 2;
                // cout << "low " << lower << " high " << upper << endl;
            }
        }
        for (int j = 7; j < 10; j++)
        {
            char s = x[j];
            if (s == 'L')
            {
                cu = cu - (cu - cl + 1) / 2;
                // cout << "low " << lower << " high " << upper << endl;
            }
            else
            {
                cl = cl + (cu - cl + 1) / 2;
                // cout << "low " << lower << " high " << upper << endl;
            }
        }
        // cout << "low " << lower << " high " << upper << endl;
        // cout << "slow " << cl << " shigh " << cu << endl;
        // cout << "id " << lower * 8 + cl << endl;
        int id = lower * 8 + cl;
        seats.push_back(id);
        if (id > max)
            max = id;
    }
    cout << max << endl;

    //part2
    int mi = *min_element(seats.begin(), seats.end()), me = 0;

    for (int i = mi; i < max; i++)
    {
        if (find(seats.begin(), seats.end(), i) == seats.end())
        {
            me = i;
        }
    }
    cout << me << endl;
    return 0;
}