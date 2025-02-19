[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/v-HoDfMe)
# HW04: Object oriented doubly-linked list

Do NOT use `using namespace std` for this homework assignment

## Problem Statement

Write a program that will take the Spotify daily artist charts and construct a doubly-linked list that will allow the user to interact with a database by finding entries by artist name and displaying contents of the list that are of interest.

## Program Organization
You should have one header file `artistList.hpp` that declares the `Artist` and `ArtistList` classes.
`ArtistList` is the doubly-linked list of `Artist`s that the user will be interacting with.

Your job is to implement the functions provided in `artistList.hpp` in separate files for each class (`artist.cpp` for `Artist` and `artistList.cpp` for `ArtistList`).

### For `ArtistList`
- Constructor should setup an empty list
- Copy constructor copies all nodes of an existing list into `this` new list
- Destructor should cleanup all nodes *without leaking*
- Prepend adds the artist to the front of the list
- Append adds the artist to the end of the list
- Insert adds the artist *before* the index specified
  - index 0 means the same as prepend 
  - index `length` is the same as append
  - If the index is larger than the length, no modification to the list occurs
  - If the list is "ABC" and we `insert(1, D)`, the result should be "ADBC"
- `at()` returns the pointer to the `Artist` at that number node in the list
  - 0 means the same `Artist` as `firstArtist()`
  - `size() - 1` means the same `Artist` as `lastArtist()`
  - If the index is >= `size()`, return `nullptr`
  - If the list is "ADBC", `at(1)` should be `D` and `at(2)` should be `B`
- Remove first drops the first artist from the list, if such an artist exists (otherwise the function does nothing)
- Remove last drops the last artist from the list, if such an artist exists (otherwise the function does nothing)
- Find artist by name returns a pointer to the first `Artist` with the same name, or `nullptr` if no `Artist` has that name in the list
- `size()` returns the count of nodes in the list (should be one line)
- `is_empty()` returns whether the list is empty (i.e., no nodes) (should be one line)

Notes regarding the provided special member functions of `ArtistList` (for those who are curious):
1. all `noexcept` means is that the keyword `throw` cannot be used in that function or any function that it calls.
2. the `= delete` tells both humans and compilers that this function cannot be called because it was not and *will not* be implemented, so do not write them.
3. Both of these are previews of coming attractions.

### For `Artist`
- Constructor copy initalizes all of the fields from the parameters
- `name()` allows access to the `artist_name` member variable (should be one line)
- `id()` allows access to the `artist_id` member variable (should be one line)
- `printArtist()` prints the `Artist` as follows
```
Artist ID: 0du5cEVh5yTK9QJze8zA0C
Artist Name: Bruno Mars
Total Followers: 43236735
Genres: dance pop, pop,
Popularity: 87
```
Note the trailing comma and the fact that none of the empty genres are printed.

## Driver code
A main function in `src/main.cpp` is provided to help you troubleshoot your code in addition to public test cases. Please feel free to make changes as you develop depending on your needs.

## CSV File Read Using C++
Use the following format for the input file (Note that first row contains headings for the `csv`, not actual data):
```
artist_id,artist_name,total_followers,genres,popularity
0du5cEVh5yTK9QJze8zA0C,Bruno Mars,43236735,"['dance pop', 'pop']",87
4IWBUUAFIplrNtaOHcJPRM,James Arthur,10293374,"['pop', 'talent show', 'uk pop']",80
69GGBxA162lTqCwzJG5jLp,The Chainsmokers,19465938,"['dance pop', 'edm', 'electropop', 'pop', 'pop dance', 'tropical house']",80
3iri9nBFs9e4wN7PLIetAw,gnash,1583798,['pop'],64
7nKeLE1toRtW4M279iS26h,Zay Hilfigerrr,62422,[],41
```
Note the variations in the genres column. If the artist is classified under only one genre, the genres field has square brackets while the genre string is in single quotes.
If the artist is classified under multiple genres, the value in the column is in double quotes followed by square brackets while the genre string is in single quotes and genres are comma separated.
For the case where an artist is not classified under any genres, the genres column will contain only the empty square brackets.
If an artist has more than `Artist::max_genres` (i.e., 10) genres listed, only the first ones are kept.
Your CSV parser should call the provided `parse_genres` function, which handles all three genres column formats.
`parse_genres` effectively consumes everything between the first `[` and the following `]` (inclusive on both ends), so you need to parse all of the columns to the left *before* calling it.

**It is your job to parse all the other columns and store them into an `ArtistList`.**

For more information on how to manage CSV, refer to this article from [geeksforgeeks](https://www.geeksforgeeks.org/csv-file-management-using-c/).


## Note
In order to receive full credit for this homework assignment, you must complete:

 - `src/artist.cpp`
 - `src/artistList.cpp`
 - `src/Makefile`
 - `src/parse_csv.cpp`

While a `main.cpp` is provided to you in the `hw04` directory, this main function serves as a driver for you to quickly evaluate your code functions.
You may change the code to suit your needs during development.
Please keep in mind that your class definitions should remain in the directory `src` and the declarations in `include`.

Make sure your last push is before the deadline. Your last push will be considered as your final submission.
