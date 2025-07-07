n = int(input())
ans = ""

for i in range(n):
    s = input().split()
    for i in s:
        ans += i[0]

    print(ans)
    ans = ""
