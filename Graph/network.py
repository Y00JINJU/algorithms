import sys

computer_num = int(input())
line_num = int(input())
info = [list(sys.stdin.readline().split()) for _ in range(line_num)]

computer_dict = dict()
for info_ in info:
    fr_com = info_[0]
    scd_com = info_[1]
    cost = info_[2]
    if not fr_com in computer_dict:
        computer_dict[fr_com] = dict()
    if not scd_com in computer_dict[fr_com]:
        computer_dict[fr_com][scd_com] = cost

minimum_cost = 0
for key in computer_dict:
    pass

