#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <list>

using namespace std;

vector<long> read_input(ifstream *);
unordered_set<long> compute_sums(list<long> ns);

int main()
{
    ifstream input_ints("day9_input.txt");
    vector<long> inputs = read_input(&input_ints);

    int rsize = 25;

    auto ns = list<long>();
    for (int i = 0; i < rsize; i++)
    {
        ns.push_back(inputs[i]);
    }

    for (int i = rsize + 1; i < inputs.size(); i++)
    {
        auto sums = compute_sums(ns);

        long n = inputs[i];

        auto r = sums.find(n);
        if (r == sums.end())
        {
            printf("%ld not found in sums\n", n);
            exit(0);
        }

        ns.pop_front();
        ns.push_back(n);
    }
}

unordered_set<long>
compute_sums(list<long> ns)
{
    auto sums = unordered_set<long>();

    for (auto i = ns.begin(); i != ns.end(); i++)
    {
        auto u = i;
        u++;
        for (; u != ns.end(); u++)
        {
            sums.insert(*i + *u);
        }
    }

    return sums;
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
