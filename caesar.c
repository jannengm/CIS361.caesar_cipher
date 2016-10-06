/*Project 1 - Substitution Ciphers
 *CIS 361 System Programming F16
 *@author Mark Jannenga*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_LEN 26

char * removeDuplicates(char word []);
int targetFound(char charArray[], int num, char target);
void initializeEncryptArray(char key[], char encrypt[]);
void initializeDecryptArray(char encrypt[], char decrypt[]);
void processInput(FILE * inf, FILE * outf, char substitute[]);

int main(int argc, char* argv[]){
  char encrypt[ALPHA_LEN], decrypt[ALPHA_LEN];
  FILE *in_file, *out_file;

  // Check that the correct number of arguments was supplied
  if(argc != 5){
    printf("Usage: option key infile outfile\n");
    printf("Option: 1 for encryption, 2 for decryption\n");
    return 1;
  }

  //Try to open input file and output file
  if ( ( in_file = fopen( argv[3], "r" ) ) == NULL ){
    printf( "Error opening input file: %s\n", argv[3] );
    return 1;
  }
  if ( ( out_file = fopen( argv[4], "w+" ) ) == NULL ){
    fclose(in_file);
    printf( "Error opening output file: %s\n", argv[4] );
    return 1;
  }

  //Remove duplicates from the key, initialize encrypt and
  //decrypt arrays
  initializeEncryptArray(removeDuplicates(argv[2]), encrypt);
  initializeDecryptArray(encrypt, decrypt);

  //Either encrypt or decrypt based on option paraneter
  //Print error if invalid option specified
  if( *argv[1] == '1' ){
    processInput(in_file, out_file, encrypt);
  }
  else if( *argv[1] == '2' ){
    processInput(in_file, out_file, decrypt);
  }
  else {
    printf("Usage: option key infile outfile\n");
    printf("Option: 1 for encryption, 2 for decryption\n");
  }

  //Close input and out files and exit
  fclose(in_file);
  fclose(out_file);
  return 0;
}

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []){
  static char str[ALPHA_LEN] = {'\0'};
  char ch;
  int i, j;

  // Loopthrough all characters in word. If the character is not already
  // in the output string, add it to the output string
  j = 0;
  for( i = 0; i < strlen(word); ++i ){
    ch = toupper(word[i]);
    if ( targetFound(str, i, ch) == 0 ){
      str[j] = ch;
      j++;
    }
  }

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
void initializeEncryptArray(char key[], char encrypt[]){
  char alphabet[ALPHA_LEN];
  int i, key_len, j;
  key_len = strlen(key);

  // Create an array holding the alphabet
  for(i = 0; i < ALPHA_LEN; ++i){
    alphabet[i] = 'A' + i;
  }

  // Put the key in the beginning of the encryption array
  // Remove those letters from the alphabet
  for(i = 0; i < key_len; ++i){
    encrypt[i] = key[i];
    alphabet[ key[i] - 'A' ] = '\0';
  }

  // Loop through the alphabet backwards, add any unused characters
  // to the array
  j = 0;
  for(i = 1; i <= ALPHA_LEN; ++i){
    if(alphabet[ALPHA_LEN - i] != '\0'){
      encrypt[key_len + j++] = alphabet[ALPHA_LEN - i];
    }
  }
}

// initialize the decrypt array with appropriate substitute letters based
// on the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[]){
  int i;
  for(i = 0; i < ALPHA_LEN; ++i){
    decrypt[ encrypt[i] - 'A' ] = 'A' + i;
  }
}

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]){
  char ch;
  while( ( ch = fgetc(inf) ) && !feof(inf) ){
    if( ch >= 'A' && ch <= 'Z' ){
      ch = substitute[ch - 'A'];
    }
    if( ch >= 'a' && ch <= 'z' ){
      ch = tolower( substitute[ toupper(ch) - 'A' ] );
    }
    fputc(ch, outf);
  }
}
