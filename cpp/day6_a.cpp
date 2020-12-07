#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> read_input(ifstream *);

int main()
{
    ifstream input_ints("day6_input.txt");
    vector<vector<string>> gs = read_input(&input_ints);

    int numAnswers = 0;

    for (int gi = 0; gi < gs.size(); gi++)
    {
        unordered_map<char, bool> groupAnswers;
        vector<string> groupPeople = gs[gi];

        for (int i = 0; i < groupPeople.size(); i++)
        {
            string groupPerson = groupPeople[i];
            for (int n = 0; n < groupPerson.size(); n++)
            {
                char answer = groupPerson[n];
                groupAnswers.insert(make_pair(answer, true));
            }
        }

        numAnswers += groupAnswers.size();
    }

    printf("numAnswers: %d\n", numAnswers);
}

vector<vector<string>>
read_input(ifstream *f)
{
    string line;
    vector<string> lines;
    vector<vector<string>> groupLines;
    while (getline(*f, line))
    {
        if (line.length() == 0)
        {
            groupLines.push_back(lines);
            lines = vector<string>();
            continue;
        }

        lines.push_back(line);
    }

    if (lines.size() > 0)
    {
        groupLines.push_back(lines);
    }

    return groupLines;
}
