class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        word_cnt = {}
        for ch in magazine:
            if ch not in word_cnt:
                word_cnt[ch] = 0
            word_cnt[ch] += 1
        for ch in ransomNote:
            if ch not in word_cnt:
                return False
            word_cnt[ch] -= 1
            if word_cnt[ch] < 0:
                return False
        return True