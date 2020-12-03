#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> read_input(ifstream *);
int slope_count_trees(vector<string> v, int right, int down);

int main()
{
    ifstream input_ints("day3_input.txt");
    vector<string> v = read_input(&input_ints);
    int trees = slope_count_trees(v, 3, 1);
    printf("trees: %d", trees);
}

int slope_count_trees(vector<string> v, int right, int down)
{
    int row = down;
    int column = right;
    int width = v[0].length();
    int trees = 0;

    for (int row = down; row < v.size(); row += down)
    {
        trees += int(v[row][column] == '#');
        column = (column + right) % width;
    }

    return trees;
}

vector<string>
read_input(ifstream *f)
{
    vector<string> v;
    string line;
    while (getline(*f, line))
    {
        v.push_back(line);
    }

    return v;
}
