#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <list>

using namespace std;

vector<long> read_input(ifstream *);
long sum(vector<long> ns, int start, int end);

int main()
{
    ifstream input_ints("day9_input.txt");
    auto inputs = read_input(&input_ints);
    long target = 373803594;

    for (int i = 0; i < inputs.size(); i++)
    {
        for (int u = i + 1; u < inputs.size(); u++)
        {
            auto s = sum(inputs, i, u);
            if (s > target)
            {
                break;
            }

            if (s == target)
            {
                auto weakness = vector<long>();
                for (int w = i; w < u; w++)
                {
                    weakness.push_back(inputs[w]);
                }
                sort(weakness.begin(), weakness.end());
                long min = weakness[0];
                long max = weakness[weakness.size() - 1];
                long sum = min + max;

                printf("sum of %ld + %ld = %ld\n", min, max, sum);
                exit(0);
            }
        }
    }
}

long sum(vector<long> ns, int start, int end)
{
    long sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += ns[i];
    }

    return sum;
}

vector<long>
read_input(ifstream *f)
{
    vector<long> v;
    string line;
    while (getline(*f, line))
    {
        long n = stol(line);
        v.push_back(n);
    }

    return v;
}
