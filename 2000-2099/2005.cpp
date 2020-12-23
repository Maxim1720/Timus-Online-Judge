#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <queue>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <iomanip>
#include <functional>
#include <list>
#include <cctype>
#include <array>
#include <algorithm>

using namespace std;
int main() {
    int n;
    n = 5;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }
    cout << min(min(min(vec[0][0] + vec[1][0] + vec[2][1] + vec[2][3] + vec[3][4],
                        vec[0][0] + vec[3][0] + vec[2][3] + vec[1][2] + vec[1][4]),
                    vec[0][0] + vec[0][2] + vec[1][2] + vec[1][3] + vec[3][4]),
                vec[0][0] + vec[0][2] + vec[2][3] + vec[1][3] + vec[1][4]) << endl;

    if (min(min(min(vec[0][0] + vec[1][0] + vec[2][1] + vec[2][3] + vec[3][4],
                    vec[0][0] + vec[3][0] + vec[2][3] + vec[1][2] + vec[1][4]),
                vec[0][0] + vec[0][2] + vec[1][2] + vec[1][3] + vec[3][4]),
            vec[0][0] + vec[0][2] + vec[2][3] + vec[1][3] + vec[1][4]) ==
        vec[0][0] + vec[1][0] + vec[2][1] + vec[2][3] + vec[3][4])
    {
        cout << "1 2 3 4 5";
    }
    else if(min(min(min(vec[0][0] + vec[1][0] + vec[2][1] + vec[2][3] + vec[3][4],
                        vec[0][0] + vec[3][0] + vec[2][3] + vec[1][2] + vec[1][4]),
                    vec[0][0] + vec[0][2] + vec[1][2] + vec[1][3] + vec[3][4]),
                vec[0][0] + vec[0][2] + vec[2][3] + vec[1][3] + vec[1][4]) ==
            vec[0][0] + vec[3][0] + vec[2][3] + vec[1][2] + vec[1][4])
    {
        cout << "1 4 3 2 5";
    }
    else if (min(min(min(vec[0][0] + vec[1][0] + vec[2][1] + vec[2][3] + vec[3][4],
                         vec[0][0] + vec[3][0] + vec[2][3] + vec[1][2] + vec[1][4]),
                     vec[0][0] + vec[0][2] + vec[1][2] + vec[1][3] + vec[3][4]),
                 vec[0][0] + vec[0][2] + vec[2][3] + vec[1][3] + vec[1][4]) ==
             vec[0][0] + vec[0][2] + vec[1][2] + vec[1][3] + vec[3][4])
    {
        cout << "1 3 2 4 5";
    }
    else {
        cout << "1 3 4 2 5";
    }
    cout << endl;
}
