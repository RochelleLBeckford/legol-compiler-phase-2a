/*
& A simple Legol Compiler -> Phase 2 with a code for a symbol table
~ include the libraries i will need
~ stdio.h -> input/output functions
    ~ will also use scanf to read input from a user
~ string.h -> compare strings
~ will be now adding a structure to store each symbol (word & its type)
    ~ there will be an array to hold all the symbols
    ~ a counter to track how many symbols there are
    ~ must have a function to add symbols and display the table
*/
#include <stdio.h>
#include <string.h>

/*
& Legol's idea is the same as planning building problem solving into programming languages
~ 4 relations -> door, wall, window, roof -> each is need to build a house
    ~ depend on each other to build a functional house
*/

//& Define my token types
//~ Token type for commands for the Legol Building Blocks: BUILD, STACK, END
#define tokword 1
//~ Token type for colors of the Legol Building Blocks: white, pink, mint, etc.
#define tokcolor 2
//~ Token type for sizes of the Legol Building Blocks: small, medium, large, etc.
#define toksize 3

//& New Code to now add a symbol table
//~ Will define what my new symbol table will look like -> how to remember each word
typedef struct {
    //~ The lexeme (word) -> "BUILD"
    char name[10];
    // ~ The type -> "tokword"
    int type;
    //~ the description -> Description of the symbol
    char description[50];
} Symbol;

//~ Create the symbol table (like a notebook that will keep record of all the words and their types)
//~ how many symbols we can store
#define MAX_SYMBOLS 50
Symbol symbol_table[MAX_SYMBOLS];
//~ The number of symbols written down
int symbol_count = 0;

//~ Create a function that will add a symbol to the symbol table
void add_symbol(char *name, int type) {
    if (symbol_count < MAX_SYMBOLS) {
        strcpy(symbol_table[symbol_count].name, name);
        symbol_table[symbol_count].type = type;

        //~ Will add a description based on type
        if (type == tokword) {
            if (strcmp(name, "BUILD")== 0) {
                strcpy(symbol_table[symbol_count].description, "Command to build a Legol Block");
            } else if (strcmp(name, "STACK")== 0) {
                strcpy(symbol_table[symbol_count].description, "Command to stack a Legol Blocks");
            } else if (strcmp(name, "END")== 0) {
                strcpy(symbol_table[symbol_count].description, "Command to end the program");
            }
        } else if (type ==  tokcolor) {
            strcpy(symbol_table[symbol_count].description, "Color of the Legol Block");
        } else if (type ==  toksize) {
            strcpy(symbol_table[symbol_count].description, "Size of the Legol Block");
        } else {
            strcpy(symbol_table[symbol_count].description, "Unknown symbol type");
        }

        symbol_count ++;
    }
}

//~ Will print the symbol table created
void show_symbol_table() {
    printf("\nSYMBOL TABLE:\n");
    printf("--------------------------------------\n");
    printf("Word\t\tType\t\tDescription\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < symbol_count; i++) {
        printf("%s\t\t", symbol_table[i].name);
        //~ Will print the tokword, tokcolor, toksize
        if (symbol_table[i].type == tokword) {
            printf("Command\t\t");
        } else if (symbol_table[i].type == tokcolor) {
            printf("Color\t\t");
        } else if (symbol_table[i].type == toksize) {
            printf("Size\t\t");
        } else {
            printf("Unknown\t\t");
        }

        //~ This will print the description of the symbol
        printf("%s\n", symbol_table[i].description);
    }
    printf("--------------------------------------\n");
}

//& Function to get my token type
//~ Determines the token type of a lexeme(aka word)
int getTokenType(char *word) {
    //~ Check if the word is a command (BUILD, STACK, END)
    if (strcmp(word, "BUILD") == 0 || strcmp(word, "STACK") == 0 || strcmp(word, "END") == 0){
        //~ if it is a command will return tokword
        return tokword;
    }
    //~ Check if the word is a color (white, pink, mint)
    else if (strcmp(word, "white") == 0 || strcmp(word, "pink") == 0 || strcmp(word, "mint") == 0){
        //~ if it is a color return tokcolor
        return tokcolor;
    }
    //~ Check if the word is a size (small, medium, large)
    else if (strcmp(word, "small") == 0 || strcmp(word, "medium") == 0 || strcmp(word, "large") == 0){
        //~ if it is a size return toksize
        return toksize;
    }
    //~ Default case -> what will happen for an unknown token -> return -1
    return -1;
}

//& Main Function -> where the program starts running
//~ Declare variables, get user inputs, get the tokens for each word,print it, can continue or end the program
int main () {
    //& Declare the variables
    //~ [10] -> each variable can hold up to 10 characters
    //~ variable to store the first word ("BUILD",....)
    char command[10];
    //~ variable to store the second word ("white",....)
    char color[10];
    //~ variable to store the third word ("small",....)
    char size[10];

    //~ Display welcome message to user
    printf("Welcome to the Legol Mini Compiler!\n");
    //~ Display a message to the user asking for inputs.
    printf("Enter a Legol command (BUILD <color> <size>) or STACK <color> <size> or END:\n");
    //~ Read the user input and store them in the declared variables
    scanf("%s %s %s", command, color, size);

    //& Tokenize the user input and store them in the declared variables
    //~ Get the token type for the first word
    int token1 = getTokenType(command);
    //~ Get the token type for the second word
    int token2 = getTokenType(color);
    //~ Get the token type for the third word
    int token3 = getTokenType(size);

    //& New Code to store the symbols in the symbol table
    add_symbol(command, token1);
    add_symbol(color, token2);
    add_symbol(size, token3);

    //& Print the token for the first word -> command
    //~ print the word -> command
    printf("%s\t", command);
    if (token1 == tokword){
        //~ if it is a command print "tokword"
        printf("tokword\n");
    } else if (token1 == tokcolor){
        //~ if it is a color print "tokcolor"
        printf("tokcolor\n");
    } else if (token1 == toksize){
        //~ if it is a size print "toksize"
        printf("toksize\n");
    } else {
        //~ if it is unknown print "unknown token"
        printf("unknown token\n");
    }

    //& Print the token for the second word -> color
    //~ print the word -> white,...
    printf("%s\t", color);
    if (token2 == tokword){
        //~ if it is a command print "tokword"
        printf("tokword\n");
    } else if (token2 == tokcolor){
        //~ if it is a color print "tokcolor"
        printf("tokcolor\n");
    } else if (token2 == toksize){
        //~ if it is a size print "toksize"
        printf("toksize\n");
    } else {
        //~ if it is unknown print "unknown token"
        printf("unknown token\n");
    }

    //& Print the token for the third word -> size
    //~ print the word -> small, .....
    printf("%s\t", size);
    if (token3 == tokword){
        //~ if it is a command print "tokword"
        printf("tokword\n");
    } else if (token3 == tokcolor){
        //~ if it is a color print "tokcolor"
        printf("tokcolor\n");
    } else if (token3 == toksize){
        //~ if it is a size print "toksize"
        printf("toksize\n");
    } else {
        //~ if it is unknown print "unknown token"
        printf("unknown token\n");
    }

    //& New Code to show the symbol table
    show_symbol_table();

    //~ End the program
    return 0;
}
