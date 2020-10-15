class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        if len(s) > 12:
            return []
        for i in range(0,3):
            for j in range(i+1,i+4):
                for k in range(j+1,min(j+4,len(s)-1)):
                    if len(s)-1-k>3:
                        continue
                    a = s[:i+1]
                    b = s[i+1:j+1]
                    c = s[j+1:k+1]
                    d = s[k+1:]
                    print(a,b,c,d)
                    print(i,j,k)
                    if self.isNumber(a) and self.isNumber(b) and self.isNumber(c) and self.isNumber(d):
                        result.append(a+'.'+b+'.'+c+'.'+d)
        return result
   
    def isNumber(self,s):
        if len(s)==1:
            return True
        else:
            if s[0] == '0':
                return False
            else:
                return True if int(s)<=255 else False