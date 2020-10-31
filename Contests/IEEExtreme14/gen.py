from interpretador import *

def create_jumps_dictionary(program):
    lbraces = list()
    res = dict()

    for index, command in enumerate(program):
        if command == '[':
            lbraces.append(index)
        elif command == ']':
            if len(lbraces) == 0:
                raise SyntaxError("Brainfuck: mismatched parentheses")

            lbrace_index = lbraces.pop()
            res[lbrace_index] = index
            res[index] = lbrace_index

    return res


def brainfuck(program, jumps, s):

    leu = 0
    data = dict()
    data_pointer = 0

    instruction_pointer = 0

    while instruction_pointer < len(program):
        command = program[instruction_pointer]

        if command == '>':
            data_pointer += 1
        elif command == '<':
            data_pointer -= 1
        elif command == '+':
            data[data_pointer] = (data.get(data_pointer, 0) + 1)
            if data[data_pointer] == 256:
                data[data_pointer] = 0
        elif command == '-':
            data[data_pointer] = (data.get(data_pointer, 0) - 1)
            if data[data_pointer] == -1:
                data[data_pointer] = 255
        elif command == ',':
            data[data_pointer] = ord(s[leu]) % 256
            leu = leu + 1
        elif command == '.':
            print(chr(data.get(data_pointer, 0)), end='', flush=True)
        elif command == '[':
            if data.get(data_pointer, 0) == 0:
                instruction_pointer = jumps[instruction_pointer]
        elif command == ']':
            if data.get(data_pointer, 0) != 0:
                instruction_pointer = jumps[instruction_pointer]
        else:  # everything else is comment
            pass

        instruction_pointer += 1


if __name__ == '__main__':
    fpath = "code.bf"
    with open(fpath, "rt") as f:
        code = f.read()
    jumps = create_jumps_dictionary(code)

    for c1 in range(33, 127):
        for c2 in range(33, 127):
            for c3 in range(33, 127):
                s = "" + chr(c1) + chr(c2) + chr(c3)
                print("// calculando " + s)
                print("res[\"" + s + "\"] = ", end='');
                brainfuck(code, jumps, s)
