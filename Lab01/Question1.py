def toten():
    global a
    a = 10

def changelist():
    global l
    for i, value in enumerate(l):
        value[i] = "a"

if __name__ == "__main__":
    a = 5
    print(a)
    toten()
    print(a)


    l = ["b" for i in range(20)]
    print(l)
    changelist()
    print(l)


  