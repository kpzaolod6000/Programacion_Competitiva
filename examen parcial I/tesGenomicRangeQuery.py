
def solution(S,P,Q):
    result = []
    len_ = len(P)
    for i in range(len_):
        slice = (S[P[i] : Q[i] + 1])
        print(slice)
        if 'A' in slice:
            result.append(1)
        elif 'C' in slice:
            result.append(2)
        elif 'G' in slice:
            result.append(3)
        elif 'T' in slice:
            result.append(4)
    print(result)
            

S = "CAGCCTA"
P = [2,5,0]
Q = [4,5,6]
solution(S,P,Q)