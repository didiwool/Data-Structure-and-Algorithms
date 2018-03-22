// Copy input to output
// COMP1521 18s1

#include <stdlib.h>
#include <stdio.h>

void copy(FILE *, FILE *);

int main(int argc, char *argv[])
{   
    if(argc == 1){
	copy(stdin,stdout);
	} else {
	    FILE *input;
	    int i = 1;
	    for(i = 1; i < argc; i++) {
	        input =  fopen(argv[i], "r");
	        if(input == NULL){
	            printf("Can't open the file.\n");
	        } else{
	            copy(input,stdout);
	        }
	        
	    }
	}
	return EXIT_SUCCESS;
}

// Copy contents of input to output, char-by-char
// Assumes both files open in appropriate mode

void copy(FILE *input, FILE *output)
{
    char c[BUFSIZ];
    while (fgets(c, BUFSIZ, input) != NULL){
        fputs(c, output);
    }   
}

