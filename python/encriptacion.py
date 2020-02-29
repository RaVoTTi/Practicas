word = 'CatBatSatFatOr'
CP = 3
for i in range(int(len(word)/CP)):
    print( word[CP*i:(1+i)*CP])
