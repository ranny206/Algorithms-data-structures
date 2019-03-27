f = open('input.txt', 'r')
w = open('output.txt', 'w')
n = int(f.readline())
Colors = {}
for i in range(n):
    color = f.readline()
    if color in Colors.keys():
        Colors[color].append(i)
    else:
        Colors[color] = [i]
m = int(f.readline())
list = []
for i in range(m):
    first = f.readline()
    second = f.readline()
    if second[-1] != '\n':
        second += '\n'
    if first not in Colors.keys() or second not in Colors.keys():
        list.append('-1')
    elif first == second and len(Colors[first]) == 1:
        list.append('-2')
    else:
        r = 0
        l = 0
        answer = 2 ** 32 - 1
        while l < len(Colors[first]) and r < len(Colors[second]):
            if first != second or l != r:
                answer = min(answer, abs(Colors[first][l] - Colors[second][r]))
            if Colors[second][r] > Colors[first][l]:
                l += 1
            else:
                r += 1
        if answer == 0:
            list.append(str(answer))
        else:
            list.append(str(answer - 1))
w.writelines("%s\n" % line for line in list)
