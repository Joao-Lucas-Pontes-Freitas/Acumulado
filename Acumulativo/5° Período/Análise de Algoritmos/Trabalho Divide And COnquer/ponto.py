import math


class Ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dist(self, p2):
        return math.sqrt((self.x - p2.x) ** 2 + (self.y - p2.y) ** 2)
