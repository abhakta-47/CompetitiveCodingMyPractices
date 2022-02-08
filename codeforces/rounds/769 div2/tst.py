def fun(s):
    a = s.split(' ')
    x = -1
    for ia in a:
        # print(ia, type(ia), end=", ")
        if(x!=-1):
            print( int(ia)^x,end=", " )
        x=int(ia)
    print()

s = [
    "0 1",
    "2 0 1",
    "3 2 1 0 4",
    "4 6 3 2 0 8 9 1 7 5",
    "0 1",
    "0 1 2",
    "0 1 2 3 4",
    "0 1 2 3 4 5 6 7 8 9",
    ]
# for itrs in s:
#     fun(itrs)
for n in range(10):
    x=0
    for i in range(1,n+1):
        x = x^i
    print(n,"=",x, end=", ")