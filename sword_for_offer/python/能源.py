#!/usr/bin/env python
# encoding: utf-8

def func():
    while True:
        try:
            num = input().split(' ')
            m, n = int(num[0]), int(num[1])
            data = []
            for i in range(m):
                data.append(list(input()))
            mark = [[0 for _ in range(n)] for _ in range(m)]
            beginx, beginy = -1, -1
            for i in range(m):
                for j in range(n):
                    if data[i][j] == '@':
                        beginx, beginy = i, j
                        print(search(mark, data, i, j, 0)+1)
        except:
            return 0


def search(mark,data,x,y,cnt):
    if data[x][y] == '#':
        return cnt
    else:
        if data[x][y] == '.' and mark[x][y] == 0:
            mark[x][y] = 1
            cnt += 1
        elif data[x][y] == '.' and mark[x][y] != 0:
            return cnt
        else:
            pass

        if x-1 >= 0:
            cnt = search(mark,data,x-1,y,cnt)
        if y-1 >= 0:
            cnt =search(mark,data,x,y-1,cnt)
        if x+1 < len(mark):
            cnt =search(mark,data,x+1,y,cnt)
        if y+1 < len(mark[0]):
            cnt =search(mark,data,x,y+1,cnt)
        return cnt

if __name__ == '__main__':
    func()

'''
9 6
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
'''