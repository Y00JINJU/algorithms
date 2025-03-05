import sys

if __name__ == "__main__":
    all_price = int(input())
    all_num = int(input())
    prices = [list(sys.stdin.readline().split(' ')) for _ in range(all_num)]
    
    sum_price = 0
    for info in prices:
        price = int(info[0])
        num = int(info[1].split('\n')[0])
        sum_price += price * num

    if  all_price == sum_price:
        print('YES')
    else:
        print('NO')
