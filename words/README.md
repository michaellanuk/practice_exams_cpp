# Palindromes and Anagrams

A palindrome is a word or phrase which contains the same sequence of letters 
when read forwards or backwards.

Characters other than letters (including spaces) are ignored and the case of 
letters (i.e. whether they are upper case i.e. A-Z or lower case i.e. a-z) is 
irrelevant. An empty string and a string containing a single letter are both 
palindromes (by definition).

For example,
- The words “rotor” and “Radar” are palindromes.
- The sentence “A man, a plan, a canal, Panama!” is a palindrome, and so is 
“Mr. Owl ate my metal worm.”
- The strings “a. ..” and “.. ..!” are palindromes.

An anagram is a word or phrase formed by reordering the letters of another
word or phrase. Again, characters other than letters (including spaces) are 
ignored and the case of letters is irrelevant. 

For example:
- “stain” is an anagram of “satin”
- “I am a weakish speller!” is an anagram of “William Shakespeare”
- “Here come dots...” is an anagram of “The Morse Code”.

example output:

```
'lairepmi' reversed is 'imperial'
'desserts' reversed is 'stressed'

The strings 'this, and THAT......' and 'THIS and THAT!!!' are the same
  (ignoring punctuation and case)
The strings 'this, and THAT' and 'THIS, but not that' are NOT the same
  (ignoring punctuation and case)

The string 'rotor' is a palindrome.
The string 'Madam I'm adam' is a palindrome.
The string 'Madam I'm not adam' is NOT a palindrome.

The string 'I am a weakish speller!' is an anagram of 'William Shakespeare'
The string 'I am a good speller!' is NOT an anagram of 'William Shakespeare'
```
