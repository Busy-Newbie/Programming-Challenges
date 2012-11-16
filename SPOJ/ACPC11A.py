#Busy Newbie got AC somehow :)
import re
T=[]
found=False
for i in xrange(input()):
        input()
        L=raw_input().split()
        for index,item in enumerate(L):
                if (re.match("[a-z]", item)):
                        TL=L[:]
                        if (index==0):
                                TL.pop(0)
                                TL.append(item)
                        elif (index==len(L)-1):
                                TL.pop()
                                TL.insert(0,item)
                        else:
                                TL[:index+1]=L[index+1:]
                                TL[len(L)-index:]=L[:index]
                                TL[len(L)-index-1]=item
                        T.append(TL)
                        found=True
        if (not found):
                T.append(L)
        else:
                found=False
for i in T:
        for j in xrange(0,len(i)-1):
                print i[j],
        print i.pop()
        

