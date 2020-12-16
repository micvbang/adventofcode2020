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

int main()
{
    ifstream input("day8_input.txt");
    vector<Instruction> instructions = read_input(&input);

    long acc = 0;
    bool executed_instructions[instructions.size()];
    for (int i = 0; i < instructions.size(); i++)
    {
        executed_instructions[i] = false;
    }

    for (int ip = 0; !executed_instructions[ip];)
    {
        executed_instructions[ip] = true;
        Instruction i = instructions[ip];
        if (i.ins == Instruction::nop)
        {
            ip++;
        }
        else if (i.ins == Instruction::acc)
        {
            ip++;
            acc += i.val;
        }
        else if (i.ins == Instruction::jmp)
        {
            ip += i.val;
        }
    }

    printf("acc: %ld\n", acc);
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
