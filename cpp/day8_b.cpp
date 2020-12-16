#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Instruction
{
    enum ins : int
    {
        nop = 1,
        jmp,
        acc
    } ins;

    int val;
};

vector<Instruction> read_input(ifstream *f);
pair<bool, int> terminates(vector<Instruction>, int);

int main()
{
    ifstream input("day8_input.txt");
    vector<Instruction> instructions = read_input(&input);

    for (int i = 0; i < instructions.size(); i++)
    {
        pair<bool, int> p = terminates(instructions, i);
        if (p.first)
        {
            printf("acc: %d\n", p.second);
            exit(0);
        }
    }
    printf("faiiiil\n");
}

pair<bool, int> terminates(vector<Instruction> instructions, int jmpNopSwapPos)
{
    long acc = 0;
    bool executed_instructions[instructions.size()];
    for (int i = 0; i < instructions.size(); i++)
    {
        executed_instructions[i] = false;
    }

    int ip = 0;
    int nJmpNop = 0;
    for (; !executed_instructions[ip] && ip < instructions.size();)
    {
        executed_instructions[ip] = true;
        Instruction i = instructions[ip];

        if (nJmpNop == jmpNopSwapPos)
        {
            if (i.ins == Instruction::nop)
            {
                i.ins = Instruction::jmp;
            }
            if (i.ins == Instruction::jmp)
            {
                i.ins = Instruction::nop;
            }
        }

        if (i.ins == Instruction::nop)
        {
            nJmpNop += 1;

            ip++;
        }
        else if (i.ins == Instruction::acc)
        {
            ip++;
            acc += i.val;
        }
        else if (i.ins == Instruction::jmp)
        {
            nJmpNop += 1;
            ip += i.val;
        }
    }

    if (ip == instructions.size())
    {
        return make_pair(true, acc);
    }

    return make_pair(false, 0);
}

Instruction
parse_line(string line)
{
    Instruction instruction;

    string ins = line.substr(0, 3);
    if (ins == "nop")
    {
        instruction.ins = Instruction::nop;
    }
    else if (ins == "jmp")
    {
        instruction.ins = Instruction::jmp;
    }
    else if (ins == "acc")
    {
        instruction.ins = Instruction::acc;
    }

    instruction.val = stoi(line.substr(4));

    return instruction;
}

vector<Instruction>
read_input(ifstream *f)
{
    vector<Instruction> instructions;
    string line;
    while (getline(*f, line))
    {
        instructions.push_back(parse_line(line));
    }

    return instructions;
}
