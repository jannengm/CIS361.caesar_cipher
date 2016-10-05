#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_LEN 26

char * removeDuplicates(char word []);
int targetFound(char charArray[], int num, char target);
void initializeEncyptArray(char key[], char encrypt[]);
void initializeDecyptArray(char encypt[], char decrypt[]);
void processInput(FILE * inf, FILE * outf, char substitute[]);

int main(int argc, char* argv[]){
  char encrypt[ALPHA_LEN], decrypt[ALPHA_LEN];
  FILE *in_file, *out_file;

  if(argc != 5){
    printf("Usage: option key infile outfile\n");
    printf("Option: 1 for encryption, 2 for decryption\n");
    return 1;
  }

  if ( ( in_file = fopen( argv[3], "r" ) ) == NULL ){
    printf( "Error opening input file: %s\n", argv[3] );
    return 1;
  }
  if ( ( out_file = fopen( argv[4], "w+" ) ) == NULL ){
    fclose(in_file);
    printf( "Error opening output file: %s\n", argv[4] );
    return 1;
  }

  initializeEncyptArray(removeDuplicates(argv[2]), encrypt);

  fclose(in_file);
  fclose(out_file);
  return 0;
}

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []){
  static char str[ALPHA_LEN];
  char ch;
  int i, j;

  j = 0;
  memset( str, '\0', ALPHA_LEN );

  for( i = 0; i < strlen(word); ++i ){
    ch = toupper(word[i]);
    if ( strchr(str, ch) == NULL ){
      str[j] = ch;
      j++;
    }
  }

  printf("Original string: %s\n", word);
  printf("Duplciates removed: %s\n", str);
  return str;

}

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target){
  int i;
  for(i = 0; i < num; ++i){
    if(charArray[i] == target)
      return 1;
  }
  return 0;
}

// initialize the encrypt array with appropriate cipher letters according
// to the given key
void initializeEncyptArray(char key[], char encrypt[]){
  char alphabet[ALPHA_LEN];
  int i, key_len, j;
  key_len = strlen(key);

  //Create an array holding the alphabet
  for(i = 0; i < ALPHA_LEN; ++i){
    alphabet[i] = 'A' + i;
  }

  //Put the key in the beginiing of the encryption array
  //Remove those letters from the alphabet
  for(i = 0; i < key_len; ++i){
    encrypt[i] = key[i];
    alphabet[ key[i] - 'A' ] = '\0';
  }

  j = 0;
  for(i = 0; i < ALPHA_LEN; ++i){
    if(alphabet[ALPHA_LEN - i - 1] != '\0'){
      encrypt[key_len + j++] = alphabet[ALPHA_LEN - i - 1];
    }
  }

  encrypt[ALPHA_LEN] = '\0';

  //Test encryption array
  printf("Encryption key: %s\n", key);
  printf("Encryption array: %s\n", encrypt);
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
