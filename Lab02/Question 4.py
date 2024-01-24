def binary_search_deluxe_left(L, target):
    '''
    Takes in a sorted list of integers (s) and a target and returns both the first and the last index where the target appears
    '''
    
    #[1,2,3,10,10,11,11,12,12]

    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def binary_search_deluxe_right(L, target):
    '''
    Takes in a sorted list of integers (s) and a target and returns both the first and the last index where the target appears
    '''
    
    #[1,2,3,10,10,11,11,12,12]

    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
        if L[mid] > target:
            right = mid - 1
        else:
            left = mid + 1

    return right

def binary_search_deluxe(L, target):
    return binary_search_deluxe_left(L, target), binary_search_deluxe_right(L, target)


if __name__ == "__main__":
    print(binary_search_deluxe([1,2,3,10,10,10,10,12,12],10));  

