#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;

class Passport
{
public:
    int *byr = NULL;
    int *iyr = NULL;
    int *eyr = NULL;
    string *hgt = NULL;
    string *hcl = NULL;
    string *ecl = NULL;
    string *pid = NULL;
    string *cid = NULL;

    bool is_valid()
    {
        return (
            byr != NULL &&
            iyr != NULL &&
            eyr != NULL &&
            hgt != NULL &&
            hcl != NULL &&
            ecl != NULL &&
            pid != NULL);
    }
};

vector<Passport> read_input(ifstream *);
Passport parse_passport(vector<string>);

int main()
{
    ifstream input_ints("day4_input.txt");
    vector<Passport> ps = read_input(&input_ints);

    int nvalid = 0;
    for (int i = 0; i < ps.size(); i++)
    {
        Passport p = ps[i];
        nvalid += int(p.is_valid());
    }

    printf("num valid: %d", nvalid);
}

vector<Passport>
read_input(ifstream *f)
{
    vector<Passport> passports;
    string line;
    vector<string> lines;
    while (getline(*f, line))
    {
        if (line.size() == 0)
        {
            passports.push_back(parse_passport(lines));
            lines.clear();
            continue;
        }

        lines.push_back(line);
    }

    if (lines.size() > 0)
    {
        passports.push_back(parse_passport(lines));
    }

    return passports;
}

int *intptr(int n)
{
    return new int(n);
}

Passport
parse_passport(vector<string> v)
{
    string plines = "";
    for (int i = 0; i < v.size(); i++)
    {
        plines += v[i] + " ";
    }

    regex kvpair("\\w{3}:.*?( |\n)");
    auto kvpair_begin = sregex_iterator(plines.begin(), plines.end(), kvpair);
    auto kvpair_end = sregex_iterator();

    vector<pair<string, string>> pkvs;
    for (sregex_iterator i = kvpair_begin; i != kvpair_end; i++)
    {
        string s = (*i).str();
        string key = s.substr(0, 3);
        string value = s.substr(4);
        pkvs.push_back(make_pair(key, value));
    }

    Passport p;

    for (int i = 0; i < pkvs.size(); i++)
    {
        string k = pkvs[i].first;
        string v = pkvs[i].second;
        v.erase(remove(v.begin(), v.end(), ' '), v.end());

        if (k == "byr")
        {
            p.byr = intptr(stoi(v));
        }
        else if (k == "iyr")
        {
            p.iyr = intptr(stoi(v));
        }
        else if (k == "eyr")
        {
            p.eyr = intptr(stoi(v));
        }
        else if (k == "hgt")
        {
            p.hgt = new string(v);
        }
        else if (k == "hcl")
        {
            p.hcl = new string(v);
        }
        else if (k == "ecl")
        {
            p.ecl = new string(v);
        }
        else if (k == "pid")
        {
            p.pid = new string(v);
        }
        else if (k == "cid")
        {
            p.cid = new string(v);
        }
    }

    return p;
}
