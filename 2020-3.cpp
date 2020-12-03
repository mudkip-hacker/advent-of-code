#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("input.txt");
    vector<string> xx;
    for (string line; getline(f, line);)
    {
        xx.push_back(line);
    }

    //part 1
    int x = 0;
    int count = 0;
    for (int i = 1; i < xx.size(); i++)
    {
        x += 3;
        string line = xx[i];
        if (line[x % line.size()] == '#')
        {
            count++;
        }
    }

    cout << count << endl;

    int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
    for (int i = 1; i < xx.size(); i++)
    {
        x1 += 1;
        x2 += 3;
        x3 += 5;
        x4 += 7;
        string line = xx[i];
        if (line[x1 % line.size()] == '#')
        {
            count1++;
        }
        if (line[x2 % line.size()] == '#')
        {
            count2++;
        }
        if (line[x3 % line.size()] == '#')
        {
            count3++;
        }
        if (line[x4 % line.size()] == '#')
        {
            count4++;
        }
    }
    for (int i = 2; i < xx.size(); i += 2)
    {
        x5 += 1;
        string line = xx[i];
        // cout << line << " " << x5 << " " << i << endl;
        if (line[x5 % line.size()] == '#')
        {
            // cout << "hit\n";
            count5++;
        }
    }

    printf("%d %d %d %d %d\n", count1, count2, count3, count4, count5);
    cout << (unsigned long long)count1 * count2 * count3 * count4 * count5;
    return 0;
}