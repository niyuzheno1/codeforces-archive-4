import sys
import argparse
import math

def prime(x):
    for i in range(2, int(math.sqrt(x))):
        if x % i == 0:
            return False
    return True


def main():
    n = int(input())
    a = [1, 3, 6]
    for i in range(3, n):
        back = a[len(a)-2]
        idx = i+1
        tt = 0
        tt = back + 5 * pow(2, idx-3, 998244353)
        tt %=  998244353 
        a.append(tt)
    print(a[len(a)-1])

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()