# class Solution(object):
# '''
# 二进制码第n位 = 二进制码第（n+1）位+格雷码第n位。因为二进制码和格雷码皆有相同位数，所以二进制码可从最高位的左边位元取0，以进行计算。（注：遇到1+1时结果视为0）
# 例如： 格雷码0111，为4位数，所以其所转为之二进制码也必为4位数，因此可取转成之二进制码第五位为0，即0 b3 b2 b1 b0。
# 0+0=0，所以b3=0
# 0+1=1，所以b2=1
# 1+1取0，所以b1=0
# 0+1取1，所以b0=1
# 因此所转换为之二进制码为0101
# '''
#     def grayCode(self, n):
#         """
#         :type n: int
#         :rtype: List[int]
#         """
#         result = []
#         for i in range(1<<n):
#             result.append(i^i>>1)
#         return result


class Solution(object):
    '''
    # 镜射排列[编辑]

    # 二进制格雷码镜射建构法
    # n位元的格雷码可以从n-1位元的格雷码以上下镜射后加上新位元的方式快速的得到，如右图所示一般。
    '''
    def grayCode(self, n):
        """
    :type n: int
    :rtype: List[int]
    """
        if n == 0:
            return 0
        elif n == 1:
            return [0,1]
        else:
            pre_one = self.grayCode(n-1)
            delta = 1<<(n-1)
            return pre_one+[item+delta for item in pre_one[::-1]]
