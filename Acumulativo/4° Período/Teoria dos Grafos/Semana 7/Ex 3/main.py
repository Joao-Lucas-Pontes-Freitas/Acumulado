from collections import deque
import sys

sys.stdin = open("entrada.txt", "r")
sys.stdout = open("saida.txt", "w")

while True:
    r, c = map(int, input().split())
    if r == 0 and c == 0:
        break

    linhas = int(input())
    visited = set()
    bombs = set()

    for _ in range(linhas):
        row, num, *bombas = map(int, input().split())
        bombs.update((row, col) for col in bombas)

    Xi, Yi = map(int, input().split())
    Xf, Yf = map(int, input().split())
    deslocamento = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    fila = deque([(Xi, Yi)])
    steps = 0
    found = False

    while fila and not found:

        for _ in range(len(fila)):
            x, y = fila.popleft()
            if x == Xf and y == Yf:
                found = True
                break

            for dx, dy in deslocamento:
                nextX = x + dx
                nextY = y + dy

                if (nextX, nextY) in visited:
                    continue
                if nextX < 0 or nextY < 0 or nextX >= r or nextY >= c:
                    continue
                if (nextX, nextY) in bombs:
                    continue

                fila.append((nextX, nextY))
                visited.add((nextX, nextY))

        if not found:
            steps += 1

    print(steps)