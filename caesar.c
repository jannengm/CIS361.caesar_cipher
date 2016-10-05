#include <stdio.h>
#include <string.h>

#define ALPHA_LEN 26

char * removeDuplicates(char word []);
int targetFound(char charArray[], int num, char target);
void initializeEncyptArray(char key[], char encrypt[]);
void initializeDecyptArray(char encypt[], char decrypt[]);
void processInput(FILE * inf, FILE * outf, char substitute[]);

int main(int argc, char* argv[]){
  char encrypt[ALPHA_LEN], decrypt[ALPHA_LEN];

  initializeEncyptArray(removeDuplicates(argv[1]), encrypt);


  //Test initializeEncyptArray

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
  char alphabet[ALPHA_LEN + 1];
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
