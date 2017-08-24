#%%
class Solution(object):
    def isexist(self,board,word,begin,i,j):
        if i <0 or j<0 or i == len(board) or j == len(board[0]):

            return False
        if board[i][j] == word[begin]:
            if begin == len(word) - 1:
                return True
            else:
                board[i][j] = '0'+board[i][j]
                flag = self.isexist(board,word,begin+1,i-1,j) or self.isexist(board,word,begin+1,i+1,j) or self.isexist(board,word,begin+1,i,j+1) or self.isexist(board,word,begin+1,i,j-1) 
                board[i][j] = board[i][j][-1] 
                return flag
        return False

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.isexist(board,word,0,i,j):
                    return True
        return False
a = 1
print(a)
# %%
a+1
    
    