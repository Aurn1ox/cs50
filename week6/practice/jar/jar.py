class Jar:
    def __init__(self, capacity=12, size=0):
        self.capacity = capacity
        self.size = size

    def __str__(self):
        return "🍪" * self.capacity

    def deposit(self, n):
        self.size += n

    def withdraw(self, n):
        self.size -= n

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        if capacity < 0:
            raise ValueError
        self._capacity = capacity

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, size):
        if size < 0 or size > self.capacity:
            raise ValueError
        self._size = size

def main():
    jar = Jar()
    print(jar.capacity)
    print(jar)
    jar.deposit(2)
    print(jar.size)
    jar.withdraw(1)
    print(jar.size)
    jar.withdraw(3)
    print(jar.size)

main()
