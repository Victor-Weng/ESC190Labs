def binary_search_deluxe(s, target):
    '''
    Takes in a sorted list of integers (s) and a target and returns both the first and the last index where the target appears
    '''

    sval = s[len(s)//2]
    
    #[1,2,3,10,10,11,11,12,12]

    if(sval>target):
        s[:(len(s)//2)]
    elif(sval<target):
        s[(len(s)//2):]


    pass


if __name__ == "__main__":
    binary_search_deluxe([1,2,3,10,10,10,10,12,12],10);  

