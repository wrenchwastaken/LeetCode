class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        Row = 1
        r = len(matrix)
        c = len(matrix[0])
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    if i != 0:
                        matrix[i][0] = 0
                    else:
                        Row = 0
        for i in reversed(range(r)):
            for j in reversed(range(c)):
                if i == 0:
                    matrix[i][j] *= Row
                elif matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0