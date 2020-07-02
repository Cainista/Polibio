#include <string.h>
#include <stdio.h>
#include <ctype.h>


/* */
int polibio(const char c){
  /* Matriz de Polibio */
  const char cUp = toupper(c);

  if (cUp=='I')
    return 24;

  const char polybius_quadrant[5][5]={
    {'A','B','C','D','E'},
    {'F','G','H','J','K'},
    {'L','M','N','O','P'},
    {'Q','R','S','T','U'},
    {'V','W','X','Y','Z'}
  };

  /* */
  int i, j;
  int res;
   /* output each array element's value */

   for ( i = 0; i < 5; i++ ) {
      for ( j = 0; j < 5; j++ ) {
        if (cUp==polybius_quadrant[i][j]){
          res = (i+1)*10+(j+1);
          return res;
        }
      }
   }  // for

  return 0;
}  // polibio


/*************************************/
/* main */
/* */
/*************************************/
int *encrypt (char* str){
  int *cifrado;
  return NULL;
}

/*************************************/
/* main */
/* */
/*************************************/
int main( int argc, char *argv[] )  {
  char fileName[122];

  /* Evalua si se ingresó bien el argumento */
  if( argc == 2 ) {
    strcpy(fileName,argv[1]);
    printf("El archivo de datos es: %s\n", fileName);
  }
  else if( argc > 2 ) {
    printf("Demasiados argumentos.\n");
  }
  else {
    printf("Debe ingresar el nombre del archivos de datos como argumento.\n");
  }

  /* Lee archivo de datos */
  FILE *fp;
  char linea[255];
  const char sep[2] = ",";
  char *token;

  /* Revisa que se puede abrir */
  if ((fp = fopen(fileName, "r")) == NULL){
    printf("Error! Archivo %s invalido", fileName);
    return(-1);
  }

  int cc = 0;

  /* Leemos el archivo linea a linea */
  while( fgets (linea, 255, fp)!=NULL ) {
    /* writing content to stdout */
    token = strtok(linea, sep);
    while( token != NULL ) {
       printf( "%2d) %s\n", cc++, token );
       token = strtok(NULL, sep);
    }
  } /* while */
  fclose(fp);

  return 0;
}
