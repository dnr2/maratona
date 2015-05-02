import math,string,itertools,fractions,heapq,collections,re,array,bisect

class Similars:
  def maxsim(self,L,R) :
    D = collections.Counter(fronzenset(str(i)) for i in range(L,R+1))
    ans = max([len(d) for d in D if D[d] > 1] + [0])
    for i in D:
      for j in D:
        if i != j:
          ans = max(ans,len(i&j))
    return ans
    
 