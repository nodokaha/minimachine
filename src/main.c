#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM_INIT() for(int i=0; i<100; i++){ num[i] = ' '; }; i=0;

int main(void){
  typedef enum {
    ADD=1,
    SUB,
    MUL,
    DIV,
  }TOKEN;
  char code[1000];
  char num[100];
  num[100] = '\0';
  char *nump;
  int i=0, op[50], deps=0, ndpx=0, ndpy=0, ndx[50], ndy[50];
  for(int i=0; i<50; i++)
    {
      op[i] = NULL;
      ndx[i] = NULL;
      ndy[i] = NULL;
    }
  long n[100][50][50];
  fscanf(stdin, "%[^\n]", code);
  puts(code);
  puts("\n");
  //10+20*5 -> MUL * MUL -> NUM + NUM * MUL -> NUM + NUM * NUM
  for(int x=0; x<1000 && code[x] != NULL; x++)
    {
      switch(code[x]){
      case '+':  op[deps] = ADD; printf("op: add, deps : %d\n", deps); NUM_INIT(); break;
      case '-':  if(isdigit(code[x+1]) != 0){ num[i++] = '-'; break; }; op[deps] = SUB; printf("op: sub, deps : %d\n", deps); NUM_INIT(); break;
      case '*':  op[deps] = MUL; printf("op: mul, deps : %d\n", deps); NUM_INIT(); break;
      case '/':  op[deps] = DIV; printf("op: div, deps : %d\n", deps); NUM_INIT(); break;
      case '(': if(isdigit(code[x-1]) != 0){ n[deps][ndpx][ndpy++]=strtol(num, NULL, 10); printf("push %ld\n", n[deps][ndpx][ndpy-1]); NUM_INIT();} n[deps][ndpx][ndpy++] = 0; printf("push %ld (deps++)\n", n[deps][ndpx][ndpy-1]); ndy[deps]=ndpy; printf("ndy: %d\n", ndy[deps]); deps++; ndpy=0; break;
      case ')': if(isdigit(code[x-1]) != 0){ n[deps][ndpx][ndpy++]=strtol(num, NULL, 10); printf("push %ld\n", n[deps][ndpx][ndpy-1]); NUM_INIT();}; for(int i=0; i<ndpy; i++){ printf("%ld : %d\n", n[deps][ndpx][i], deps); }; if(deps>0){ deps--; }else{ printf("Error!"); return -1; } ndpy=ndy[deps]; printf("ndy: %d\n", ndy[deps]); if(code[x+1] == ' '){ x++; break; } break;
      case ' ': if(isdigit(code[x-1]) != 0){n[deps][ndpx][ndpy++]=strtol(num, NULL, 10); NUM_INIT(); printf("push %ld\n", n[deps][ndpx][ndpy-1]);}; break;
      case '0': num[i++] = '0'; break;
      case '1': num[i++] = '1'; break;
      case '2': num[i++] = '2'; break;
      case '3': num[i++] = '3'; break;
      case '4': num[i++] = '4'; break;
      case '5': num[i++] = '5'; break;
      case '6': num[i++] = '6'; break;
      case '7': num[i++] = '7'; break;
      case '8': num[i++] = '8'; break;
      case '9': num[i++] = '9'; break;
      default: NUM_INIT(); printf("not support!\n"); break;
      }
    }
  printf("compile end!\n");
  /* for(int m=1; m<10; m++){ */
  /*   int stack=0; */
  /*   if(op[m] != 0){ */
  /*     switch(op[m]){ */
  /*     case 1:	stack=0; for(int j=0; j<10; j++){ stack += n[0][m][j]; printf("%d\n", n[0][m][j]); }; printf("stack = %d\n", stack); break; */
  /*     case 2:   stack=n[m][0]; for(int j=1; j<10; j++){ stack -= n[0][m][j]; printf("%d\n", n[0][m][j-1]); }; printf("stack = %d\n", stack); break; */
  /*     case 3:   stack=1; for(int j=0; n[m][j] != 0; j++){ stack *= n[0][m][j]; printf("%d\n", n[0][m][j]); }; printf("stack = %d\n", stack); break; */
  /*     default : printf("Error!"); */
  /* 	} */
  /*     } */
  /*   } */
   return 0;
}
