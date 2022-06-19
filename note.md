# problem
I can't create todo
- buffer
- scanf
- fflush
- fgets
* Shit!, its in main(), a scanf there it's return a '\n' to buffer, fuck. --> fixed it by put a getchar() before createTodo.

## solution
### combine fgets and sscanf
not work as expected!
--> must be the scanf in the main that fuck this solution up.
### change the algorithm to recursive from while loop
working nice;
## understand
getchar() return \n to buffer
scanf() behave like getchar()
fgets() contain \n as well, wait, it consume the '\n' but not put it in the result (string);
