#include <stdio.h>
#include <string.h>

#define ALPHA_LEN 26

char * removeDuplicates(char word []);
int targetFound(char charArray[], int num, char target);
void initializeEncyptArray(char key[], char encrypt[]);
void initializeDecyptArray(char encypt[], char decrypt[]);
void processInput(FILE * inf, FILE * outf, char substitute[]);

int main(int argc, char* argv[]){
  //Test removeDuplicates
  // printf("Original string: %s\n", argv[1]);
  // printf("Duplciates removed: %s\n", removeDuplicates(argv[1]));

  return 0;
}

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []){
  static char str[ALPHA_LEN];
  int i, j;

  j = 0;
  memset( str, '\0', ALPHA_LEN );

  for( i = 0; i < strlen(word); ++i ){
    if ( strchr(str, word[i]) == NULL ){
      str[j] = word[i];
      j++;
    }
  }

  return str;

}

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target){
  return 0;
}

// initialize the encrypt array with appropriate cipher letters according
// to the given key
void initializeEncyptArray(char key[], char encrypt[]){

}

// initialize the decrypt array with appropriate substitute letters based
// on the encrypt array
void initializeDecyptArray(char encypt[], char decrypt[]){

}

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]){

}
