class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        pre1,pre2 = 1,1
        for i in range(len(s)):
            if i == 0:
                tmp = 1
            else:
                if int(s[i-1]+s[i]) >10 and s[j]!='0':
                    tmp = pre1 + pre2
                else:
                    tmp = pre1
            
            pre1,pre2 = pre2,tmp
        return pre2