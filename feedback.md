**3/24/2025**
* class definition style & standards:  first, member vars and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
* missing: Army class -20
* Army class should be responsible for loading, searching, sorting, keeping track of the number of creatures “in use”, printing creatures sorted/unsorted, or any other operation performed on a group of creatures; army class should not be responsible for menu; the array of pointers should be the member of the Army class
* search and/or sort produce invalid results due to capitalization; all the records should have been stored in all uppercase or lowercase -10
* sort/search do(es) not comply with the assignment -20
* file name(s) and/or file/folder structure/capitalization do not comply with posted instructions; folder- CSXXX_LN_FL (all caps, X – class catalog number, N- lab number, FL- your initials;  files:  all lower case, main() – main.cpp, input - “in_\*.txt”, output –“out_\*.txt”, error –“err_\*.txt”; do not include any other files or folders;  -5
* const; if it is not 1 or 0 make it const; in case of ASCII values, use chars, e.g., temp>’a’  -5
* modularization: each menu option should have its own function with a possible exception of the QUIT case; as a rule of thumb, if a case in a switch has more than 2 statements, make it a function; should have let it fall through -5
* each menu should start with item number one -1;
* #116-118 and like – redundant; invalid menu choice should be handled by default case of the menu switch; menu needs only one loop; should create a highly reusable function that takes an error message string as a parameter and clears the failed input, it does not need to ask user to re-enter, the menu loop already does it -2
* should initialize all variables, members or not, to appropriate default values at the time of definition; improves readability, in case of member variables, helps to avoid initialization lists, helps with  the exception handling and providing a strong exception guarantee; strings should be initialized to something other than “” n/a for example -2
* getter/accessor function(s) allow object state modification -2
```
    string getDamage() { return to_string(damage); }
```
* 83 and like: what is 4? (e.g., while!=QUIT) -2

