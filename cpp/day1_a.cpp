#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read_input(ifstream *);

int main()
{
    ifstream input_ints("day1_input.txt");
    vector<int> v = read_input(&input_ints);
    sort(v.begin(), v.end());

    for (int i1 = 0; i1 < v.size(); i1++)
    {
        int n1 = v[i1];

        for (int i2 = i1 + 1; i2 < v.size(); i2++)
        {
            int n2 = v[i2];

            int n1n2 = n1 + n2;
            if (n1n2 == 2020)
            {
                printf("%d * %d = %d", n1, n2, n1 * n2);
                exit(0);
            }

            if (n1n2 > 2020)
            {
                break;
            }
        }
    }
}

vector<int>
read_input(ifstream *f)
{
    vector<int> v;
    string line;
    while (getline(*f, line))
    {
        istringstream iss(line);
        int n;
        if (!(iss >> n))
        {
            break;
        }

        v.push_back(n);
    }

    return v;
}
