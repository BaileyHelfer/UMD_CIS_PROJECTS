def encryption(fileName,writeFileName):
    fileRead = open(fileName, 'r') #open file in reading
    fileWrite = open(writeFileName, 'a') #open in append mode
    Lines = fileRead.readlines() #read each line and save into Lines list
    #run a loop to traverse each line
    for line in Lines:
        newLine=""#create a new empty string
        for i in line:
            char = i#store i(letter) in char
            Ascii=ord(char) #get ascii value of char (ord return ascii)
            #check char between A-Z or a-z
            if (Ascii>=65 and Ascii<=90) or (Ascii>=97 and Ascii<=122):
                #add 3 to it
                newAscii=Ascii+3#add 3 into new Ascii
                #after addition check new Ascii greater than Z(ascii value)
                #so now we have to assign it a-z
                if Ascii<90 and newAscii>90:
                    newAscii+=6#add 6 to it ascii of a-97
                    newLine+=chr(newAscii)#convert into char
                    #add char to newLine string
                elif Ascii<122 and newAscii>122:#if ascii-a-z and new one >z
                    newAscii-=58#subtract 58
                    newLine+=chr(newAscii)#convert into char
                  
                else:#if char after addition 3 between a-z or A-Z
                    newLine+=chr(newAscii) #add as it is
                  
                #special char add as it is
            else:
                newLine+=str(char)
        #write empty string
        fileWrite.write(newLine)
    fileWrite.close()#close file object
    fileRead.close()

def decryption(fileName,writeFileName):
    fileRead = open(fileName, 'r') #open in read mode
    fileWrite = open(writeFileName, 'a') #open in append mode
    Lines = fileRead.readlines()
    #traverse each line of decrypted file
    for line in Lines:
        newLine=""
        for i in line:
            char = i
            Ascii=ord(char) #get ascii
            #check ascii between a-z or A-Z
            if (Ascii>=65 and Ascii<=90) or (Ascii>=97 and Ascii<=122):
              
                newAscii=Ascii-3 #sub 3
                #if after sub ascii value less than A
                if Ascii>65 and newAscii<65:
                    newAscii+=58 #add 58 to convert into a-Z
                    newLine+=chr(newAscii)
                  
                  
                #if ascii after sub value less than a
                elif Ascii>97 and newAscii<97:
                    newAscii-=6#sub -6 to make A-Z
                    newLine+=chr(newAscii)  
                  
                else:
                    newLine+=chr(newAscii)
                  
                  
                #write special char as it is
            else:
                newLine+=char
                #write file
        fileWrite.write(newLine)
    fileWrite.close()#close file object
    fileRead.close()
      
      #main execution   start from here

if __name__=="__main__":
    encryption("independence.txt","independence2.txt")
    decryption("independence2.txt","independence3.txt")
