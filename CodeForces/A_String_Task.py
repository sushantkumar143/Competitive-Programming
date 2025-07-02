s = input().lower()
ans = "."
def isVowel(st):
    if st!='a' and st!='e' and st!='i' and st!='o' and st!='u' and st!='y':
        return 0
    return 1 
for i in s:
    if isVowel(i) == 0:
        ans+=i
        ans += "."

if ans[-1] == '.':
    print(ans[:len(ans)-1])
else:
    print(ans)