def find_minimal_path(matrix):
    n = len(matrix)
    min_path = [[0] * n for _ in range(n)]

    min_path[0][0] = matrix[0][0]

    for i in range(1, n):
        min_path[0][i] = min_path[0][i - 1] + matrix[0][i]
        min_path[i][0] = min_path[i - 1][0] + matrix[i][0]

    for i in range(1, n):
        for j in range(1, n):
            min_path[i][j] = min(min_path[i - 1][j], min_path[i][j - 1]) + matrix[i][j]

    return min_path[n - 1][n - 1]

n = 3
matrix = [[1, 3, 1], [2, 1, 2], [4, 3, 1]]
minimal_path_sum = find_minimal_path(matrix)
print("Минимальная сумма чисел в промежуточных клетках:", minimal_path_sum)
