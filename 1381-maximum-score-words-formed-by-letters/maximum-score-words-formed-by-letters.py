# class Solution:
#     def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
#         count_score=[(0, 0) for _ in range(26)]
#         for letter in letters:
#             index = ord(letter) - ord('a')
#             count, _ = count_score[index]
#             count_score[index] = (count + 1, score[index])
#         maxScore = 0
#         def wordScore(word, count_score):
#             temp_score = 0
#             temp_count_score = count_score.copy()
#             for i in word:
#                 index = ord(i) - ord('a')
#                 count, letter_score = temp_count_score[index]
#                 if count == 0:
#                     return 0
#                 else:
#                     temp_count_score[index] = (count - 1, letter_score)
#                     temp_score += letter_score           
#             return temp_score
#         for word in words:
#             temp = wordScore(word,count_score)
#             print(word,temp)
#             maxScore = max(maxScore,temp)
#         return maxScore

class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        count = [0] * 26
        letters_count = [0] * 26
        
        for c in letters:
            count[ord(c) - ord('a')] += 1
        
        self.ans = 0
        self.backtracking(words, score, count, letters_count, 0, 0)
        return self.ans
    
    def backtracking(self, words, score, count, letters_count, pos, temp):
        for i in range(26):
            if letters_count[i] > count[i]:
                return
        
        self.ans = max(self.ans, temp)
        
        for i in range(pos, len(words)):
            for c in words[i]:
                letters_count[ord(c) - ord('a')] += 1
                temp += score[ord(c) - ord('a')]
            
            self.backtracking(words, score, count, letters_count, i + 1, temp)
            
            for c in words[i]:
                letters_count[ord(c) - ord('a')] -= 1
                temp -= score[ord(c) - ord('a')]