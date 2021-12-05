typedef struct node {
    float value;
    struct node *next;
} Node;

void push(Node **stack, float x) {
    Node *p = (Node*)malloc(sizeof(Node));

    p->value = x;
    p->next = *stack;
    *stack = p;
}
float pop(Node **head) {
    Node *p;
    float v;
    v = (*head)->value;
    p = (*head)->next;
    free(*head);
    *head = p;
    return v;
}
//FUNCION DISPLAY//
void display(Node *stack) {
    for(;stack != NULL; stack = stack->next) {
        printf("%.2f   ",stack->value);
    }
    printf("\n");
}
//FUNCION CLEAR//
Node *liberar(Node *raiz){
    Node *reco = raiz;
   Node *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->next;
        free(bor);
    }
return reco;
}
//FUNCION PARA CONVERTIR A RADIANES//
float radianes(float valor){
    const double PI=3.141592653589;
    double rad;
    rad=valor*PI/180;
 return rad;
}
//FUNCION PARA CONVERTIR DE RADIANES A GRADOS//
float grados(float valor){
    const double PI=3.141592653589;
    double grad;
    grad=valor*180/PI;
 return grad;
}
//FUNCION CONVERTIR A BINARIO//
 float binario(float n){
    float binary=0;
    int n1=n;
    int a[n1], i=0;
    while (n1>0){
        a[i]=n1%2;
        i=i+1;
        n1=n1/2;
    }
    while(0<=i){
     if (a[i]==1 && i !=0)
       if (binary ==0){
    binary++;
    binary*=10;
       } 
           else{
    binary*=10;
           binary++;
       }
          else if(a[i]==1 && i==0){
   binary ++;
     }
         else if(a[i]==0)
      binary*= 10;
         i--;
    }
    return binary;
}

//FUNCION CONVERTIR A OCTADECIMAL//
float octadecimal(float v1){
    float NumOctal = 0, i = 1;
    int a= v1;

    while (a != 0)
    {
        NumOctal += (a % 8) * i;
        a /= 8;
        i *= 10;
    }
    return NumOctal;
}
//FUNCION CONVERTIR A HEXADECIMAL//
void Hexa(float v1) {
   long int quotient;
   int i=1,j,temp;
   char hexadecimalNumber[100];
   quotient = v1;
   while(quotient!=0) {
    temp = quotient % 16;
    //Para convertir el entero a char
    if( temp < 10)
             temp =temp + 48; else
             temp = temp + 55;
    hexadecimalNumber[i++]= temp;
    quotient = quotient / 16;
   }
   for (j = i -1 ;j> 0;j--)
        printf("%c",hexadecimalNumber[j]);
    printf("\n");
  }
