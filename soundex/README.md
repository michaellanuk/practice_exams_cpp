# The Soundex coding system

The Soundex coding system represents surnames according to the way they sound rather 
than the way they are spelt. Surnames that sound the same but are spelt differently 
(e.g. PAYNE and PAINE) have the same Soundex code.
All Soundex codes take the form of an upper case letter followed by three digits 
(e.g. B652, E255 or M263). The rules for mapping a surname onto its corresponding 
Soundex code are as follows:

1. The letter at the start of the Soundex code is always the first letter of the surname.
2. The digits of the Soundex code are assigned using the remaining letters of the surname 
according to the mapping:

```
b,f,p,v → 1
l → 4
c,g,j,k,q,s,x,z → 2 
m,n → 5 
d,t → 3 
r → 6
```

All occurrences of the letters a, e, h, i, o, u, w and y are ignored. If there are not 
enough digits to make up a four character code, zeroes are added to the end. Additional 
letters are disregarded.
For example, `Washington` is coded `W252` (W, 2 for the S, 5 for the N, 2 for the G, 
remaining letters disregarded). `Lee` is coded `L000` (L, 000 added).

3. If the surname has two or more adjacent letters that have the same number in the 
Soundex coding, they should be treated as one letter.For example, `Jackson` is coded 
as `J250` (J, 2 for the C, K ignored, S ignored, 5 for the N, 0 added). Note that this 
rule does not imply that it is impossible for adjacent repeated digits to occur in a 
Soundex coding.

example output:

```
The soundex coding for 'Washington' is W252
The soundex coding for 'Lee' is L000
The soundex coding for 'Jackson' is J250

There are 2 surnames in the sentence 'Linnings, Leasonne, Lesson and Lemon.'
  that have the same Soundex encoding as 'Leeson'
There are 1 surnames in the sentence 'Jakes, Jaxin, J acksin, Jones.'
  that have the same Soundex encoding as 'Jackson'
```
