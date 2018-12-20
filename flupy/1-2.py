#熟悉使用doctest
#一个简单的二维向量类

from math import hypot

'''
>>>v1 = Vector(2, 4)
>>>v2 = Vector(2, 1)
>>>v2 + v1
Vector(4, 5)
>>>v = Vector(3, 4)
>>>abs(v)
5.0
>>>v * 3
Vector(9, 12)
>>>abs(v * 2)
15.0
'''

class Vector:

    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return 'Vector(%r, %r)' % (self.x, self.y)

    def __abs__(self):
        return hypot(self.x, self.y)

    def __bool__(self):
        return bool(abs(self))

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Vector(x, y)

    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)

#if __name__ == "__main__":
import doctest
doctest.testmod()
v1 = Vector(2, 4)
v2 = Vector(2, 1)
print(v2 + v1)