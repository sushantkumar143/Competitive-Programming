t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = s[0]
    b = s[1:-1]
    c = s[-1]
    if b in (a + c):
        print("Yes")
    else:
        print("No")
