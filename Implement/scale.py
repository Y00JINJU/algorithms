import sys

if __name__ == "__main__":
    input_ = input()
    split_input = input_.split(' ')
    acending = False
    decending = False
    mixed = False
    for i, in_ in enumerate(split_input):
        in_ = int(in_)
        if i < len(split_input) - 1:
            if int(split_input[i+1]) == in_ + 1:
                acending = True
                decending = False
            elif int(split_input[i+1]) == in_ - 1:
                acending = False
                decending = True
            else:
                mixed = True
                acending = False
                decending = False
    
    if acending and not mixed:
        print('ascending')
    elif decending and not mixed:
        print('descending')
    elif mixed:
        print('mixed')
            