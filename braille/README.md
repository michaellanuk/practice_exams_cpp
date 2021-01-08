# Braille

Braille text consists of a sequence of cells, each of which contains six dot positions 
arranged in two columns of three. The dot positions are numbered 1,2,3 downwards from 
the top of the lefthand column and 4,5,6 from the top of the righthand column.

The presence or absence of raised dots on the dot positions gives the coding for a symbol. 
By default, letters are lower case.

Capital letters are indicated by a preceding each letter by a capital sign.
Numbers are represented by preceding each digit in the number by the number sign.
digits themselves are encoded by reusing the letters a through i to represent the 
digits 1 through 9 respectively, and using j to represent the digit 0. 

Punctuation marks have their own encoding.

example output:

```
.. O. O. O. O. O. .. 
.. OO .O O. O. .O OO 
.O .. .. O. O. O. O. 
   H  e  l  l  o  !  
```

where 

```
..  
.. 
.O 
```

is a preceding capital sign to denote an uppercase 'H'.

'`O`'s denote raised 'dots'
