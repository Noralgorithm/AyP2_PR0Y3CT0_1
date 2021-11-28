
typedef struct node {
  int value;
  struct node *next;
} Node;

int sumar(Node *stack) {
  int result = 0;
  for(;stack != NULL;stack = stack->next) {
    result = result + stack->value;
  } 
  return result;
}

int restar(Node *stack) {
  int result = 0;
  for(;stack != NULL;stack = stack->next) {
    result = result - stack->value;
  } 
  return result;
}

int multiplicar(Node *stack) {
  int result = 0;
  for(;stack != NULL;stack = stack->next) {
    result = result * stack->value;
  } 
  return result;
}

int dividir(Node *stack) {
  int result = 0;
  for(;stack != NULL;stack = stack->next) {
    result = result / stack->value;
  } 
  return result;
}

Node newItem(int value) {
  Node *newint;
  newint = (Node*)malloc(sizeof(Node));
  if(newint == NULL) {
    fprintf(stderr, "Error in malloc\n");
    exit(1);
  }
  newint->value = value;
  
  return *newint;
}

Node addItem(Node *stack, Node* newint) {
  Node *p;
  if(stack == NULL)
    return *newint;
  for(p=stack;p->next!=NULL;p=p->next);
  p->next = newint;
  return *stack;
}

void clear(Node *stack) {
  Node *next;
  for(; stack != NULL; stack = next) {
    next = stack->next;
    free(stack);
  }
}

void display(Node *stack) {
  for(; stack != NULL; stack = stack->next) {
    printf("%d ", stack->value);
  }
  printf("\n");
}


