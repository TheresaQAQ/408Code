//
// Created by zhouq on 25-8-11.
//
//括号匹配

#include "ArrayStack.c"
#include "string.h"

int parenthesisMatch(char* string){
  ArrayStack* stack = initArrayStack();
  printf("string length:%llu\n", strlen(string));
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
      push(stack, string[i]);
    }else if (string[i] == ')') {
      int temp = 0;
      getTop(stack, &temp);
      printf("stack is '%c',match char is '%c'\n", temp,string[i]);
      if('('==temp){
        pop(stack, &temp);
      }
    }else if (string[i] == '}') {
      int temp = 0;
      getTop(stack, &temp);
      printf("stack is '%c',match char is '%c'\n", temp,string[i]);
      if('{'==temp){
        pop(stack, &temp);
      }
    }else if (string[i] == ']') {
      int temp = 0;
      getTop(stack, &temp);
      printf("stack is '%c',match char is '%c'\n", temp,string[i]);
      if('['==temp){
        pop(stack, &temp);
      }
    }
  }
  if (isEmpty(stack)) return 1;
  return 0;
  }


int main(){
  char string[] = "[[[sfgrgha(f{})]]]";
  if (parenthesisMatch(string)){
    printf("YES\n");
  }else {
    printf("NO\n");
  }
  return 0;
  }