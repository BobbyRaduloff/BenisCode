# BenisCode
BenisCode is simple inefficient bloating encoder based on the word "benis".
*Please* don't take this seriously.

## Encoding Method
This program encodes messages by placing single bits in the capitalization of the word "benis".
This is best shown by example:
```
bEnIS
01011 = 11
```
The biggest number that can be stored with this encoding is
```
BENIS
11111 = 31
```
As you can see, a one corresponds to upper case and a zero corresponds to lower case.
This method isn't efficient at all, but it isn't meant to. **Zheliazkov** :heart:

## Table of characters
| Number | Corresponding Character |
| ------ | ----------------------- |
| 0 | SPACE | 
| 1 - 26 | lower case alphabet |
| 27 | capitalize all following characters |
| 28 | stop capitalizing |
| 29 | PERIOD |
| 30 | QUESTION MARK |
| 31 | EXCLAMATION MARK |
 
# Building and using
To build BenisCode, just run the `make` command in the project root.
Then run `sudo make install` to install it.
To use it just run `beniscode` in a terminal.
To delete `beniscode`, run `sudo make delete`.
