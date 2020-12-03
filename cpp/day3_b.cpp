#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <inttypes.h>

using namespace std;

vector<string> read_input(ifstream *);
int slope_count_trees(vector<string> v, int right, int down);

int main()
{
    ifstream input_ints("day3_input.txt");
    vector<string> v = read_input(&input_ints);
    int64_t right1_down1 = slope_count_trees(v, 1, 1);
    int64_t right3_down1 = slope_count_trees(v, 3, 1);
    int64_t right5_down1 = slope_count_trees(v, 5, 1);
    int64_t right7_down1 = slope_count_trees(v, 7, 1);
    int64_t right1_down2 = slope_count_trees(v, 1, 2);

    uint64_t mult = right1_down1 * right3_down1 * right5_down1 * right7_down1 * right1_down2;

    printf("trees multiplied: %lu\n", mult);
}

int slope_count_trees(vector<string> v, int right, int down)
{
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
