from sys import stdout
lo = 1
hi = 1000000
ans = -1
while(lo<=hi):
    mid = (lo+hi)//2
    print(mid)
    stdout.flush()
    s = input()
    if(s=="<"):
        hi = mid - 1
    else:
        ans = max(ans, mid)
        lo = mid+1

print("! ", ans)
stdout.flush()