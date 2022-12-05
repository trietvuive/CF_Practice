# calculate number of pairs of same values

def same_pairs(values):
    dict = {}
    ans = 0
    for i in values:
        if i in dict:
            dict[i] += 1
        else:
            dict[i] = 1
        ans += dict[i] - 1
    return ans

