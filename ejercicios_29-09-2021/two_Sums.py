
n, t = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

def two_sums(arr,target):
    arr_index = [(v,p) for p,v in enumerate(arr)] # listar el valor con su respectivo indice
    print(arr_index)
    arr_index.sort(key=lambda x : x[0]) # ordenar segun los valores x[0] (x[0],x[1])
    print(arr_index)
    left = 0
    right = len(arr)-1

    while left < right:
        curr_ = arr_index[left][0] + arr_index[right][0]
        if curr_ < target:
            left +=1
        elif curr_ > target:
            right -=1
        else:
            return [arr_index[left][1],arr_index[right][1]]
    return [-1,-1]
    

a,b = two_sums(A,t)
if(a,b) == (-1,-1):
    print("IMPLOSSIBLE")
else:
    print(a+1,b+1)




#4 8
#2 7 5 1
