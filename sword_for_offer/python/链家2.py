# -*- coding:utf-8 -*-

import collections
def func():
    n = int(input())
    data = []
    for i in range(n):
        data.append(int(input()))
    cnt = collections.Counter(data)
    size1 = cnt[1]
    size3 = cnt[2]
    point2 = cnt[1]
    point1 = 0
    point3 = len(data)-1
    while True:
        while data[point1] == 1:
            point1 += 1
        while data[point2] == 2:
            point2 += 1
        while data[point3] == 3:
            point3 -= 1
        if data[point]


if __name__ == '__main__':
    func()