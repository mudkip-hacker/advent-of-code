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

    vector<string> last = xx;
    // do
    // {
    //     last = xx;
    //     for (size_t i = 0; i < xx.size(); i++)
    //     {
    //         // cout << xx[i] << endl;
    //     }

    //     cout << endl;

    //     for (size_t i = 0; i < xx.size(); i++)
    //     {
    //         for (size_t j = 0; j < xx[i].size(); j++)
    //         {
    //             char c = xx[i][j];
    //             int count = 0;

    //             if (j > 0 && last[i][j - 1] == '#')
    //             {
    //                 // cout << "left";
    //                 count++;
    //             }
    //             if (j < xx[i].size() - 1 && last[i][j + 1] == '#')
    //             {
    //                 // cout << "right";
    //                 count++;
    //             }
    //             if (i > 0 && last[i - 1][j] == '#')
    //             {
    //                 // cout << "up";
    //                 count++;
    //             }
    //             if (i < xx.size() - 1 && last[i + 1][j] == '#')
    //             {
    //                 // cout << " down" << xx[i + 1][j];
    //                 count++;
    //             }
    //             if (i > 0 && j > 0 && last[i - 1][j - 1] == '#')
    //             {
    //                 // cout << " top left" << xx[i - 1][j - 1];
    //                 count++;
    //             }
    //             if (i > 0 && j < xx[i].size() - 1 && last[i - 1][j + 1] == '#')
    //             {
    //                 // cout << " top right" << xx[i - 1][j + 1];
    //                 count++;
    //             }
    //             if (i < xx.size() - 1 && j > 0 && last[i + 1][j - 1] == '#')
    //             {
    //                 // cout << "bottom left";
    //                 count++;
    //             }
    //             if (i < xx.size() - 1 && j < xx[i].size() - 1 && last[i + 1][j + 1] == '#')
    //             {
    //                 // cout << "bottom right";
    //                 count++;
    //             }
    //             // printf("in %d %d counted %d \n", i, j, count);
    //             if (count == 0 && c == 'L')
    //                 xx[i][j] = '#';
    //             else if (count >= 4 && c == '#')
    //                 xx[i][j] = 'L';
    //         }
    //     }

    //     int ct = 0;
    //     for (size_t i = 0; i < xx.size(); i++)
    //     {
    //         for (size_t j = 0; j < xx[i].size(); j++)
    //         {
    //             if (xx[i][j] == '#')
    //                 ct++;
    //         }
    //     }
    //     // cout << "seats" << ct << endl;

    // } while (last != xx);
    //
    //
    // part 2
    last = xx;
    do
    {
        last = xx;
        for (size_t i = 0; i < xx.size(); i++)
        {
            cout << xx[i] << endl;
        }

        cout << endl;

        for (size_t i = 0; i < xx.size(); i++)
        {
            for (size_t j = 0; j < xx[i].size(); j++)
            {
                int count = 0;
                int ii = i, jj = j;
                while (jj > 0)
                {
                    if (last[ii][jj - 1] == '#')
                    {
                        // cout << "left";
                        count++;
                        break;
                    }
                    if (last[ii][jj - 1] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        jj--;
                    }
                }
                ii = i, jj = j;
                while (jj < xx[ii].size() - 1)
                {
                    if (last[ii][jj + 1] == '#')
                    {
                        // cout << "right";
                        count++;
                        break;
                    }
                    if (last[ii][jj + 1] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        jj++;
                    }
                }
                ii = i, jj = j;
                while (ii > 0)
                {
                    if (last[ii - 1][jj] == '#')
                    {
                        // cout << "up";

                        count++;
                        break;
                    }
                    if (last[ii - 1][jj] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        ii--;
                    }
                }
                ii = i, jj = j;
                while (ii < xx.size() - 1)
                {
                    if (last[ii + 1][jj] == '#')
                    {
                        // cout << " down";
                        count++;
                        break;
                    }
                    if (last[ii + 1][jj] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        ii++;
                    }
                }
                ii = i, jj = j;
                while (ii > 0 && jj > 0)
                {
                    if (last[ii - 1][jj - 1] == '#')
                    {
                        // cout << " top left";
                        count++;
                        break;
                    }
                    if (last[ii - 1][jj - 1] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        ii--;
                        jj--;
                    }
                }
                ii = i, jj = j;
                while (ii > 0 && jj < xx[ii].size() - 1)
                {
                    if (last[ii - 1][jj + 1] == '#')
                    {
                        // cout << " top right";
                        count++;
                        break;
                    }
                    if (last[ii - 1][jj + 1] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        ii--;
                        jj++;
                    }
                }
                ii = i, jj = j;
                while (ii < xx.size() - 1)
                {
                    if (jj > 0 && last[ii + 1][jj - 1] == '#')
                    {
                        // cout << "bottom left";
                        count++;
                        break;
                    }
                    if (jj > 0 && last[ii + 1][jj - 1] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        ii++;
                        jj--;
                    }
                }
                ii = i, jj = j;
                while (ii < xx.size() - 1 && jj < xx[ii].size() - 1)
                {
                    if (last[ii + 1][jj + 1] == '#')
                    {
                        // cout << "bottom right";
                        count++;
                        break;
                    }
                    if (last[ii + 1][jj + 1] == 'L')
                    {
                        break;
                    }
                    else
                    {
                        ii++;
                        jj++;
                    }
                }
                // printf("in %d %d counted %d \n", i, jj, count);
                if (count == 0 && last[i][j] == 'L')
                    xx[i][j] = '#';
                else if (count >= 5 && last[i][j] == '#')
                    xx[i][j] = 'L';
            }
        }

        int ct = 0;
        for (size_t i = 0; i < xx.size(); i++)
        {
            for (size_t j = 0; j < xx[i].size(); j++)
            {
                if (xx[i][j] == '#')
                    ct++;
            }
        }
        cout << "seats" << ct << endl;

    } while (last != xx);

    return 0;
}
