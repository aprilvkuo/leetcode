#!/usr/bin/env python
# encoding: utf-8


"""
@author: aprilvkuo
@license: Apache Licence 
@site: http://aprilvkuo.github.io
@software: PyCharm Community Edition
@file: 链家1.py
@time: 2017/8/19 20:07
5 5 4
5 2
4 7
3 1
3 2
2 5
"""


def func():
    data = list(map(int,input().split(' ')))
    n, r, avg = data[0],data[1],data[2]
    data = []
    now_score = 0
    for i in range(n):
        score = list(map(int,input().split()))
        now_score+=score[0]
        data.append(score)
    data = sorted(data,key= lambda x:x[1])
    cost = 0
    index = 0
    while now_score < n*avg:
        if data[index][0] < r:
            if n*avg - now_score <= r-data[index][0]:
                cost += (n*avg - now_score)*data[index][1]
                return cost
            else:
                now_score += (r-data[index][0])
                cost += (r-data[index][0])*data[index][1]
        index += 1
    return False



if __name__ == '__main__':
    print(func())