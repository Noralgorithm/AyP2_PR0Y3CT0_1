#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {

  //Pila de numeros
  Node* stack = (Node*)malloc(sizeof(Node));
  
  // Bucle de input de usuario
  while(1) {
    char input[10];
    printf("CALC>");
    scanf("%s", &input);
    
    // Redirije el flujo del codigo segun el input del usuario
    if(strcmp(input, "+") == 0) {
      printf("working\n");
      exit(0);
    }
    else{
      printf("nani\n");
    }
  }
  return 0;
}
