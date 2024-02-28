import numpy as np


# basic usages
# a = np.array([1, 2, 3])
# b = np.array([4, 5, 6])
# c  = a + b
# print(c)


# a = np.array([[1, 2, 3], [4, 5, 6]])
# print(a.ndim) # number of dimensions
# print(a.shape) # shape of array(rows, columns)
# print(a.size) # number of elements
# print(a.dtype) # data type of elements
# print(a.itemsize) # size of each element in bytes
# print(a.data) # buffer containing actual elements of the array

# b = np.array([[1, 2, 3], [4, 5, 6]], dtype=np.complex128)
# print(b)

c = np.zeros((3, 4), dtype=np.int16)
# print(c)

# d = np.ones((2, 3, 4), dtype=np.int16) # (dimensions, rows, columns)
# print(d)

# e = np.empty((2, 3))
# print(e)

# b = np.arange(10, 30, 5) # start, end, step
# print(b)

# c = np.linspace(0, 2, 9) # start, end, number of elements
# print(c)

# d = np.random.random((2, 3)) # random numbers
# print(d)

# print(np.arange(12).reshape(4, 3)) # reshape

# print(np.identity(3, dtype=np.int16)) # identity matrix


# basic operations
a = np.array([20, 30, 40, 50])
b = np.arange(4)

# c = a - b
# print(c)

# d = b**2
# print(d)

# e = a * b # elementwise product
# print(e)

# f = a @ b # matrix product
# print(f)



# list to array
# list = []
# for i in range(5):
#     a = int(input())
#     list.append(a)

# list2 =  list

# arr = np.array([list, list2])
# print(arr.ndim)

list1 = [1, 2, 3, 4, 5]
list2 = [2, 3, 4, 5, 6]

# print(np.array([list1, list2]))

print(np.eye(3, dtype=np.int16))
print(np.mean(np.eye(3, dtype=np.int16)))
print(np.std(np.eye(3, dtype=np.int16)))
print(np.median(np.eye(3, dtype=np.int16)))
print(np.var(np.eye(3, dtype=np.int16)))
print(np.sum(np.eye(3, dtype=np.int16)))


# print(np.he)