#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Policy
{
public:
    int min;
    int max;
    char letter;
    string password;

    bool is_valid()
    {
        int s = 0;

        s += int(letter == password[min - 1]);
        s += int(letter == password[max - 1]);

        return s == 1;
    };
};

vector<Policy> read_input(ifstream *);
Policy parse_line(string);

int main()
{
    ifstream input_ints("day2_input.txt");
    vector<Policy> v = read_input(&input_ints);

    int nvalid = 0;
    for (int i1 = 0; i1 < v.size(); i1++)
    {
        Policy p = v[i1];
        nvalid += int(p.is_valid());
    }

    printf("num valid: %d", nvalid);
}

vector<Policy>
read_input(ifstream *f)
{
    vector<Policy> v;
    string line;
    while (getline(*f, line))
    {
        v.push_back(parse_line(line));
    }

    return v;
}

Policy
parse_line(string s)
{
    int sdash = s.find("-");
    int sspace = s.find(" ");
    int scolon = s.find(":");

    string mins = s.substr(0, sdash);
    string maxs = s.substr(sdash + 1, sspace - (sdash + 1));
    string letter = s.substr(sspace + 1, scolon - (sspace + 1));
    string password = s.substr(scolon + 2, s.length() - (scolon + 2));

    Policy p;
    p.min = stoi(mins);
    p.max = stoi(maxs);
    p.letter = letter.c_str()[0];
    p.password = password;
    return p;
}
