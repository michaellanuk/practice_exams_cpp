# Playfair cipher

A simplified version of this scheme works as follows:

1. A 6 x 6 encoding grid containing the letters of the alphabet A-Z and 
the digits 0-9 is set up. The order in which these 36 characters appear 
in the grid is determined by a codeword. The first occurrence of the letters
or digits in the codeword appear first, followed by the unused letters and 
digits in lexical order. For example, an encoding grid with the codeword
IMPERIAL is shown as:

```
    1 2 3 4 5 6
   ____________
1 | I M P E R A 
2 | L B C D F G 
3 | H J K N O Q 
4 | S T U V W X 
5 | Y Z 0 1 2 3 
6 | 4 5 6 7 8 9 

```

2. The message to be encrypted (the plain text) is then split into bigrams 
(groups of two letters). Spaces and punctuation in the plain text are ignored, 
and an X is added to the plain text to com- plete the last pair if necessary. 
Thus the message “COME TO THE QUEEN’S TOWER AT 7 O’CLOCK.” is divided up into 
the bigrams CO ME TO TH EQ UE EN ST OW ER AT 7O CL OC KX.

3. Each plain text bigram is then encoded into two cipher characters as follows. 
The first cipher character is the grid character at the intercept of the row of 
the first bigram character and the column of the second bigram character. The second 
cipher character is the grid character at the intercept of the column of the first 
bigram character and the row of the second bigram character. Thus the bigram CO is 
encoded as FK, and the resulting cipher text for the whole message is:

```
FKEMWJSJANVPENTSOWREMX8NLCKFQU
```

example output:

```
'Come to the Queen's Tower at 7 o'clock!' has been prepared for encoding as:
'COMETOTHEQUEENSTOWERAT7OCLOCKX'.

The encoding grid corresponding to the codeword 'IMPERIAL' is:
I M P E R A 
L B C D F G 
H J K N O Q 
S T U V W X 
Y Z 0 1 2 3 
4 5 6 7 8 9 

The bigram 'CO' encodes as 'FK'
The bigram 'N9' encodes as 'Q7'

The string 'COMETOTHEQUEENSTOWERAT7OCLOCKX' encodes as:
'FKEMWJSJANVPENTSOWREMX8NLCKFQU'
```
