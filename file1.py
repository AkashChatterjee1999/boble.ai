
                            #written by Akash Chatterjee

import csv,sys
from itertools import permutations # importing the itertools module
file_path=sys.argv[1] # taking the file name as path

with open(file_path,"rt") as f:
    hola=list(csv.reader(f)) #create a list of the words
arr = []
for i in hola:
    for j in i:
        prem=permutations(j) #tuples are returned
        x=list(prem)
        for k in range(len(x)):
            s="".join(x[k])
            x[k]=s
        arr.append(x)   #array of words
for i in arr:
    for j in i:print(j,end=" ")