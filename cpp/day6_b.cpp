#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> read_input(ifstream *);

int main()
{
    ifstream input_ints("day6_input.txt");
    vector<vector<string>> groups = read_input(&input_ints);

    int numFullGroupAnswers = 0;
    int answerLookSize = 256;

    for (int groupI = 0; groupI < groups.size(); groupI++)
    {
        char groupAnswers[answerLookSize] = {};
        vector<string> groupPeople = groups[groupI];

        for (int personI = 0; personI < groupPeople.size(); personI++)
        {
            string groupPerson = groupPeople[personI];
            for (int answerI = 0; answerI < groupPerson.size(); answerI++)
            {
                char answer = groupPerson[answerI];
                groupAnswers[answer] += 1;
            }
        }

        int gsize = groupPeople.size();
        for (int i = 0; i < answerLookSize; i++)
        {
            numFullGroupAnswers += int(groupAnswers[i] == gsize);
        }
    }

    printf("numFullGroupAnswers: %d\n", numFullGroupAnswers);
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
