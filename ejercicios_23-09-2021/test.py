# arr = [4,5,0,-2,-3,1]
# k=5

arr = [2,-2,2,-4]
k = 6
def subArray(A,k):
    # N = len(A)
    # p = [0]*(N+1)
    # print(p)

    d = {0: 1}
    prefix_sum, count = 0, 0
    print(d)
    for num in A:
        prefix_sum = (prefix_sum + num) % k
        print(prefix_sum)
        # print(d.get(prefix_sum, 0))
        count += d.get(prefix_sum, 0)
        # print(d.get(prefix_sum, 0))
        # make the new prefix_sum key be whatever the old value was + 1
        d[prefix_sum] = d.get(prefix_sum, 0) + 1
    print(d)
    return count

print(subArray(arr,k))