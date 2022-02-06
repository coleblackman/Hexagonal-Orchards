import math

# n = 100000000
# n = 1000
n = 10
greenPoints = 0
primeList = [2,3,5,7,11,13,17,19]

def canBeSimplified(num, den):
  if math.gcd(num, den) > 1:
    return True
  return False

for y in range(1,n+1):
  distance = y-1
  if y not in primeList: # Not prime  
    for x in range(1,int((distance)/2)-1):
      if canBeSimplified(x, distance+1):
        greenPoints += 2
    if y % 2 == 1:
        greenPoints -= 0
  else:
    greenPoints += 1

greenPoints *= 6
print(f"Greenpoints: {greenPoints}")



