K11 = ((2, 1), (1, 2))
K12 = ((5, 1), (6, 2))
K13 = ((1, 5), (2, 6))
K14 = ((5, 6), (6, 5))

K21 = ((3, 0), (3, 2), (2, 3), (0, 3))
K22 = ((4, 0), (4, 2), (5, 3), (7, 3))
K23 = ((0, 4), (2, 4), (3, 5), (3, 7))
K24 = ((4, 7), (4, 5), (5, 4), (7, 4))

K3 = ((2, 2), (5, 2), (2, 5), (5, 5))

def get_coord(x: int, y: int):
    arr = [(x + 1, y - 2), (x + 2, y - 1), (x + 2, y + 1), (x + 1, y + 2), (x - 1, y + 2),
           (x - 2, y + 1), (x - 2, y - 1), (x - 1, y - 2)]

    result = []

    for el in arr:
        if not ((el[0] < 0) or (el[0] >= 8) or (el[1] < 0) or (el[1] >= 8)):
            result.append(el)

    return result

def replace(arr1, x, y):
    arr1[x][y] = "K"
    arr2 = get_coord(x, y)
    for element in arr2:
        if arr1[element[0]][element[1]] == "0":
            arr1[element[0]][element[1]] = "*"

def suka(K: list):
    coords = [["0"] * 8 for _ in range(8)]  # Заменил "0" на 0 и добавил правильное создание двумерного массива
    for k in K:
        replace(coords, k[0], k[1])

    for el in coords:
        if "0" in el:
            return None
    else:
        return coords

for K11_i in K11:
    for K12_i in K12:
        for K13_i in K13:
            for K14_i in K14:
                for K21_i in K21:
                    for K22_i in K22:
                        for K23_i in K23:
                            for K24_i in K24:
                                arr = [K11_i, K12_i, K13_i, K14_i, K21_i, K22_i, K23_i, K24_i, K3[0], K3[1], K3[2], K3[3]]
                                res = suka(arr)
                                if res is not None:
                                    for i in res:
                                        for j in i:
                                            print(j, end=" ")
                                        print(" ")

                                    print("\n")
