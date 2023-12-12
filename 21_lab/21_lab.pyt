def read_matrix_from_file(filename, n):
    matrix = []
    with open(filename, 'r') as file:
        for _ in range(n):
            row = list(map(int, file.readline().split()))
            matrix.append(row)
    return matrix

def write_matrix_to_file(filename, matrix):
    with open(filename, 'w') as file:
        for row in matrix:
            file.write(' '.join(map(str, row)) + '\n')

def calculate_matrix_c(A, B):
    n = len(A)
    C = [[0] * n for _ in range(n)]

    # Обчислення AВ
    A_times_B = [[sum(A[i][k] * B[k][j] for k in range(n)) for j in range(n)] for i in range(n)]

    # Обчислення A^2B
    A_squared_times_B = [[sum(A[i][k] * A[k][j] for k in range(n)) * B[i][j] for j in range(n)] for i in range(n)]

    # Обчислення C = (AВ - A^2B)^3
    for _ in range(2):
        temp = [[sum((A_times_B[i][k] - A_squared_times_B[i][k]) * (A_times_B[k][j] - A_squared_times_B[k][j]) for k in range(n)) for j in range(n)] for i in range(n)]
        A_times_B = temp

    return A_times_B

def main():
    i = 9  # Ваш варіант
    n = i + 4

    # Зчитування матриць з файлів
    A = read_matrix_from_file("a.txt", n)
    B = read_matrix_from_file("b.txt", n)

    # Обчислення матриці C
    matrix_C = calculate_matrix_c(A, B)

    # Запис результату у нові файли a.txt і b.txt
    write_matrix_to_file("a.txt", matrix_C)
    write_matrix_to_file("b.txt", matrix_C)

if __name__ == "__main__":
    main()
