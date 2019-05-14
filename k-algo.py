print("k-algo")

data = [150, 500, 360, 275, 600, 550, 520, 100, 380, 200]
data.sort()
data2 = [2,4,10,12,3,20,30,11,25]
data2.sort()

newm1 = 150
newm2 = 455
oldm1 = 0
oldm2 = 0

def createCluster(m1, m2, data):
    newk1 = []
    newk2 = []
    for e in data:
        d1 = abs(e - m1)
        d2 = abs(e - m2)
        if d1 < d2:
            newk1.append(e)
        elif d1 > d2:
            newk2.append(e)
        else:
            newk1.append(e)
            newk2.append(e)
    return newk1, newk2

def calMean(k1, k2):
    m1 = sum(k1) / len(k1)
    m2 = sum(k2) / len(k2)
    return m1, m2


while round(oldm1, 2) != round(newm1, 2) or round(oldm2, 2) != round(newm2, 2):
    oldm1 = newm1
    oldm2 = newm2
    k1, k2 = createCluster(oldm1, oldm2, data)
    print(k1, k2)
    newm1, newm2 = calMean(k1, k2)
    print(oldm1, newm1, oldm2, newm2)
