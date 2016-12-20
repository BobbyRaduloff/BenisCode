# BENIS ENCODING

## ENCODING METHOD
This program encodes messages by placing single bits in the capitalization of the word "benis". This is best shown by example:
```
bEnIS
01011 = 11
```
The biggest number that can be stored with this encoding is
```
BENIS
11111 = 31
```
As you can see, a one corresponds to upper case and a zero corresponds to lower case. This method isn't efficient at all, but it isn't meant to. Zheliazkov <3

## ENCODING TABLE
| Number | Corresponding Character |
| ------ | ----------------------- |
| 0 | SPACE | 
| 1 - 26 | lower case alphabet |
| 27 | capitalize all following characters |
| 28 | stop capitalizing |
| 29 | PERIOD |
| 30 | QUESTION MARK |
| 31 | EXCLAMATION MARK |