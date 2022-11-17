inputFile = open('independence.txt' , 'r')
outputFile = open('count.dat' , 'w')

#A list to store the frequencies of 26b letters from A-Z (Case insensitive).
#All values are initialized to 0.
freq = [0 for i in range(26)]

#Reading the input file
for line in inputFile:
    #Iterating through all the characters of the line.
    for c in line:
        #Check if c is uppercase character
        if(c.isupper()):
            #ord(c) gives us the ASCII value of c. ord(c) - ord('A') gives us the position of
            #the character in the alphabet and the index corresponding to it in the list.
            freq[(ord(c))-ord('A')]+=1
        elif(c.islower()):
            freq[ord(c)-ord('a')]+=1

for i in range(26):
    #chr(x) returns the character corresponding to ASCII value x.
    #chr(x + ord('A')) gives us the xth letter in the alphabet.
    #file.write() accepts a string input so I am converting everything to strings.
    outputFile.write(chr(i+ord('A')) + " " + str(freq[i])+"\n")