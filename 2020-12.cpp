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

    vector<string> xx;

    string foo;
    while (getline(f, foo))
    {
        xx.push_back(foo);
    }

    int x = 0, y = 0, dir = 0; //eswn 0123
    for (size_t i = 0; i < xx.size(); i++)
    {
        string s = xx[i];
        if (s[0] == 'F')
        {
            switch (dir)
            {
            case 0:
            {
                cout << "east" << s.substr(1) << endl;
                x += stoi(s.substr(1));
                break;
            }
            case 1:
            {
                y -= stoi(s.substr(1));
                cout << "sou" << s.substr(1) << endl;
                break;
            }
            case 2:
            {
                x -= stoi(s.substr(1));
                cout << "west" << s.substr(1) << endl;
                break;
            }
            case 3:
            {
                y += stoi(s.substr(1));
                cout << "nor" << s.substr(1) << endl;
                break;
            }
            }
        }
        else if (s[0] == 'R')
        {
            switch (stoi(s.substr(1)))
            {
            case 90:
            {
                dir++;
                break;
            }
            case 180:
            {
                dir++;
                dir++;
                break;
            }
            case 270:
            {
                dir++;
                dir++;
                dir++;
                break;
            }
            }
            dir %= 4;
        }
        else if (s[0] == 'L')
        {
            switch (stoi(s.substr(1)))
            {
            case 90:
            {
                dir--;
                break;
            }
            case 180:
            {
                dir--;
                dir--;
                break;
            }
            case 270:
            {
                dir--;
                dir--;
                dir--;
                break;
            }
            }
            if (dir < 0)
                dir += 4;
        }
        else if (s[0] == 'E')
        {
            x += stoi(s.substr(1));
        }
        else if (s[0] == 'W')
        {
            x -= stoi(s.substr(1));
        }
        else if (s[0] == 'N')
        {
            cout << "nor" << s.substr(1) << endl;
            y += stoi(s.substr(1));
        }
        else if (s[0] == 'S')
        {
            y -= stoi(s.substr(1));
        }
    }

    cout << abs(x) + abs(y) << endl;

    x = 0, y = 0; //eswn 0123
    int wx = 10, wy = 1;
    for (size_t i = 0; i < xx.size(); i++)
    {
        string s = xx[i];
        if (s[0] == 'F')
        {
            x += wx * stoi(s.substr(1));
            y += wy * stoi(s.substr(1));
            cout << "east " << wx * stoi(s.substr(1)) << " north " << wy * stoi(s.substr(1)) << endl;
            ;
        }
        else if (s[0] == 'R')
        {
            switch (stoi(s.substr(1)))
            {
            case 90:
            {
                int tmpx = wx;
                int tmpy = wy;
                wx = tmpy;
                wy = -tmpx;
                break;
            }
            case 180:
            {
                wx = -wx;
                wy = -wy;
                break;
            }
            case 270:
            {
                int tmpx = wx;
                int tmpy = wy;
                wx = -tmpy;
                wy = tmpx;
                break;
            }
            }
        }
        else if (s[0] == 'L')
        {
            switch (stoi(s.substr(1)))
            {
            case 90:
            {
                int tmpx = wx;
                int tmpy = wy;
                wx = -tmpy;
                wy = tmpx;
                break;
            }
            case 180:
            {
                wx = -wx;
                wy = -wy;
                break;
            }
            case 270:
            {
                int tmpx = wx;
                int tmpy = wy;
                wx = tmpy;
                wy = -tmpx;
                break;
            }
            }
        }
        else if (s[0] == 'E')
        {
            wx += stoi(s.substr(1));
        }
        else if (s[0] == 'W')
        {
            wx -= stoi(s.substr(1));
        }
        else if (s[0] == 'N')
        {

            wy += stoi(s.substr(1));
        }
        else if (s[0] == 'S')
        {
            wy -= stoi(s.substr(1));
        }
    }

    cout << abs(x) + abs(y) << endl;

    return 0;
}
