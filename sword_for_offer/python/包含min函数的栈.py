#!/usr/bin/env python
#  -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.data = []
        self.state = []
    def push(self, node):
        self.data.append(node)
        if self.state:
            self.state.append(min(self.state[-1],node))
        else:
            self.state.append(node)
    def pop(self):
        del self.data[-1]
        del self.state[-1]
    def top(self):
        return self.data[-1]
    def min(self):
        return self.state[-1] if self.state else None