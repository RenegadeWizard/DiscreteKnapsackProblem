import random

ilosc1 = [20,21,22,23,24,25,26,27,28,29]
C1 = 25
ilosc2 = 25
C2 = [20,21,22,23,24,25,26,27,28,29]

def losowo(ile):
    return [random.randrange(i+1)+1 for i in range(ile)]

def losowo2(ile,C):
    return [random.randrange(C+1)+1 for i in range(ile)]

def malejace(ile):
    return sorted([i+1 for i in range(ile)],reverse=True)

def rosnace(ile):
    return [i+1 for i in range(ile)]

def aksztaltne(ile):
    return [i+1 if i < ile/2 else ile-i for i in range(ile)]

def staly(ile):
    i = random.randrange(ile+1%20+1)
    return [i for j in range(ile)]

def los_bez_pow(ile):
    a = [i+1 for i in range(ile)]
    return shuffle(a)

def shuffle(tab):
    for i in range(len(tab)):
        r1 = random.randrange(len(tab))
        r2 = random.randrange(len(tab))
        tab[r1],tab[r2] = tab[r2],tab[r1]
    return tab


def adjacency_random(ile):
    ones = [1 for i in range(int((ile*(ile-1))/4))]
    zeros = [0 for i in range(int((ile*(ile-1))/4))]
    whole_tab = ones + zeros
    return shuffle(whole_tab)


def Main():
    with open('dane_1.txt','w') as f:
        for i in ilosc1:
            f.write(str(C1)+'\n')
            f.write(str(i)+'\n')
            w = losowo2(i,C1)
            p = losowo(i)
            for j in range(i):
                f.write(str(w[j])+' '+str(p[j])+'\n')
    with open('dane_2.txt','w') as f:
        for i in C2:
            f.write(str(i)+'\n')
            f.write(str(ilosc2)+'\n')
            w = losowo2(ilosc2,i)
            p = losowo(ilosc2)
            for j in range(ilosc2):
                f.write(str(w[j])+' '+str(p[j])+'\n')

if __name__=="__main__":
    Main()
