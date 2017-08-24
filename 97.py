'''
简单的dp问题
'''
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s1)+len(s2)!=len(s3):
            return False
        flag = [[0 for i in range (len(s2)+1)] for j in range (len(s1)+1)]
        flag[0][0] = 1
        for i in range(len(s1)):
            if s1[i] == s3[i]:
                flag[i+1][0] = i+1
            else:
                break
        for i in range(len(s2)):
            if s2[i] == s3[i]:
                flag[0][i+1] = i+1
            else:
                break
        for i in range(1,len(s1)+1):
            for j in range(1,len(s2)+1):
                tmp1,tmp2 = 0,0
                if s1[i-1] == s3[i+j-1]:
                    tmp1 = flag[i-1][j]
                if s2[j-1] == s3[i+j-1]:
                    tmp2 = flag[i][j-1]
                flag[i][j] = 1 if max(tmp1,tmp2)>0  else 0
     
        return True if flag[-1][-1]!=0 else False

if __name__ == "__main__":
    s = Solution()
    print(s.isInterleave("a","b","cbb"))