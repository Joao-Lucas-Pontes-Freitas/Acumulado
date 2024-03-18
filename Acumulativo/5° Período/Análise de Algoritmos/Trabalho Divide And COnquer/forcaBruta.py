def forcaBruta(pontos, n):
    min_dist = float('inf')
    for i in range(n):
        for j in range(i + 1, n):
            dist = pontos[i].dist(pontos[j])
            if dist < min_dist:
                min_dist = dist
    return min_dist

