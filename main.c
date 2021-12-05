#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"

//----PROGRAMA PRINCIPAL----//
int main(int argc, char *argv[]) {

  //Pila de numeros
    Node* stack=(Node*)malloc(sizeof(Node));
  //Modo de operacion en terminal UNIX
    float memory=0;
    int i, chara = 0;
    int flag = 0; // 0=Menu interactivo // 1=Operando desde el terminal//
    if(argc>1) {
        flag = 1;
        for(i=1;argv[i] != NULL && atof(argv[i]) != 0; i++) {
            push(&stack,atof(argv[i]));
        }
        i--;
    }
  // Bucle de input de usuario
    while(1) {
        char input[10];
        int valor2;
        float v1,v2,valor;
        if(flag==1) {
            i++;
            if(argv[i]==NULL)
                exit(0);
            strcpy(input, argv[i]);
        }
        if(flag==0) {
            printf("CALC>");
            scanf("%s", &input);
        }
//Redirije el flujo del codigo segun el input del usuario
    //SUMA//
    if(strcmp(input, "+") == 0) {
        v1 = pop(&stack);
        v2 = pop(&stack);
        valor = v1 + v2;
        push(&stack, valor);
        valor2=valor;
        print(valor2,valor);
    }else
    //RESTA//
    if(strcmp(input, "-") == 0) {
        v1 = pop(&stack);
        v2 = pop(&stack);
        valor = v2 - v1;
        push(&stack, valor);
        valor2=valor;
        print(valor2,valor);
    }else
    //MULTIPLICACION//
    if(strcmp(input, "x") == 0) {
        v1 = pop(&stack);
        v2 = pop(&stack);
        valor = v1 * v2;
        push(&stack, valor);
        valor2=valor;
        print(valor2,valor);
    }else
    //DIVISION//
    if(strcmp(input, "/") == 0) {
        v1 = pop(&stack);
        v2 = pop(&stack);
        valor = v2 / v1;
        push(&stack, valor);
        valor2=valor;
        print(valor2,valor);
    }else
    //RAIZ CUADRADA//
    if(strcmp(input , "RA") == 0){
        valor=sqrt(v1=pop(&stack));
        push(&stack, valor);
        valor2=valor;
        print(valor2,valor);
    }else
    //POTENCIA//
    if(strcmp(input, "PO")==0){
        v1= pop(&stack);
        v2= pop(&stack);
        valor = pow(v2,v1);
        push(&stack, valor);
        valor2=valor;
        print(valor2,valor);
     }else
    //FACTORIAL//
    if(strcmp(input , "FACT") == 0){
        valor=1;
        v1 = pop(&stack);
        for (; v1>1; v1--)
           valor *= v1;
        valor2=valor;
        print(valor2,valor);
        push(&stack, valor);
    }else
    //LOGARITMO//
    if(strcmp(input , "LOG")==0){
        v1= pop(&stack);
        valor=(log(v1));
        valor2=valor;
        print(valor2,valor);
        push(&stack, valor);
    }else
    //COSENO//
    if(strcmp(input , "COS")==0){
        v1=pop(&stack);
        valor=cos(radianes(v1));
        valor2=valor;
        print(valor2,valor);
        push(&stack,valor);
    }else
    //SENO//
    if(strcmp(input , "SEN")==0){
        v1=pop(&stack);
        valor=sin(radianes(v1));
        valor2=valor;
        print(valor2,valor);
        push(&stack,valor);
    }else
    //TANGENTE//
    if(strcmp(input , "TAN")==0){
        v1=pop(&stack);
        valor=tan(radianes(v1));
        valor2=valor;
        print(valor2,valor);
        push(&stack,valor);
    }else
    //ARCOSENO//
    if(strcmp(input , "ASEN")==0){
        v1= pop(&stack);
        if ((v1>=-1) && (v1<=1)){
            valor=(grados(asin(v1)));
            valor2=valor;
            print(valor2,valor);        }
        else{
            printf("ERROR DE DOMINIO");
            push(&stack, v1);
        }
    //ARCOCOSENO//
    }else
    if (strcmp(input , "ACOS")==0){
        v1= pop(&stack);
        if ((v1>=-1) && (v1<=1)){
            valor=(grados(acos(v1)));
            valor2=valor;
            print(valor2,valor);
            push(&stack, valor);
        }else{
            printf("ERROR DE DOMINIO");
            push(&stack, v1);
        }
    //ARCOTANGENTE//
    }else
    if (strcmp(input , "ATAN")==0){
        v1=pop(&stack);
        valor=grados((atan(v1)));
        valor2=valor;
        print(valor2,valor);
        push(&stack,valor);
    }else
    //FUNCION DISPLAY//
    if(strcmp(input, "DSP") == 0) {
        display(stack);
    }else
    //FUNCION RECALL//
    if(strcmp(input , "RCL") == 0){
        if (stack != NULL){
            valor=pop(&stack);
            valor2=valor;
            print(valor2,valor);
            push(&stack,valor);
        }else
        printf("La lista esta vacia\n");
    }else
    //FUNCION CLEAR//
    if(strcmp(input, "CLR") == 0) {
        stack=liberar(stack);
    }else
    //FUNCION SWAP//
    if (strcmp(input, "SWAP")==0){
        v1=pop(&stack);
        v2=pop(&stack);
        push(&stack,v1);
        push(&stack,v2);
        printf("Cambiados con exito\n");
    }else
    //FUNCION BINARIO//
    if(strcmp(input, "BINARY")==0){
        v1=pop(&stack);
        v1=v1/1;
        valor=binario(v1);
        push(&stack,valor);
        if(flag == 1)
            printf("%.0f\n", valor);
    }else
    //FUNCION OCTADECIMAL//
    if(strcmp(input, "OCTAL")==0){
        v1=pop(&stack);
        valor=octadecimal(v1);
        push(&stack,valor);
        if(flag == 1)
            printf("%.0f\n", valor);
    }
    //FUNCION HEXADECIMAL//
    else
    if(strcmp(input, "HEXAL")==0){
        v1=pop(&stack);
        Hexa(v1);
        push(&stack,v1);
    }else
    if(strcmp(input, "STO")==0){
        v1=pop(&stack);
        memory=v1;
        printf("Se ha realizado el almacenado con exito\n");
        push(&stack,memory);
    }else
    if(strcmp(input, "MRCL")==0){
        valor2=memory;
        print(valor2,memory);
    }else
    if(strcmp(input, "S+")==0){
        v1=pop(&stack);
        memory+=v1;
        valor2=memory;
        print(valor2,memory);
    }else
    if(strcmp(input, "S-")==0){
        v1=pop(&stack);
        memory-=v1;
        valor2=memory;
        print(valor2,memory);
    }else
    //FUNCION QUIT//
    if(strcmp(input, "QUIT")==0) {
        exit(0);
    }else
    if(strcmp(input,"0")==0){
        push(&stack,0);
    }else
    if(input != '\0' && atof(input) != 0){
        push(&stack,atof(input));
    }
}
    return 0;
}
