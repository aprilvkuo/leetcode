#!/usr/bin/env python
# encoding: utf-8


"""
@author: aprilvkuo
@license: Apache Licence 
@site: http://aprilvkuo.github.io
@software: PyCharm Community Edition
@file: 能源1.py
@time: 2017/8/17 17:37
"""


def func():
    while True:
        try:
            data = input().split(' ')
            x,y = int(data[0]),int(data[1])
            while x!=y:
                if x>y:
                    x = x >> 1
                else:
                    y = y >> 1
            print(x)
        except:
            return




if __name__ == '__main__':
    func()