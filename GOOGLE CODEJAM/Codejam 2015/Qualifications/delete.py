for t in range(int(input())):

    D = int(input())

    P = list(map(int, input().split() ))

    # Result is clearly up to no more than max (P), which is totally not the case assignment
    ans = max(P)

    # Traversing block allocation size, and then optimize the time 
    Z = 2
    while Z < ans:
        ans = min(ans, sum([(x - 1) // Z for x in P]) + Z)
        Z += 1

    print('Case #%d: %s' % (t + 1, ans))