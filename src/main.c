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
  int i=0, op[50], deps=0, nd=0, ndi[50];
  for(int i=0; i<50; i++)
    {
      op[i] = NULL;
      ndi[i] = NULL;
    }
  long n[100][50];
  fscanf(stdin, "%[^\n]", code);
  puts(code);
  puts("\n");
  //10+20*5 -> MUL * MUL -> NUM + NUM * MUL -> NUM + NUM * NUM
  for(int x=0; x<1000 && code[x] != NULL; x++)
    {
      switch(code[x]){
      case '+':  op[deps] = ADD; printf("op: add, deps : %d\n", deps); NUM_INIT(); break;
      case '-':  op[deps] = SUB; printf("op: sub, deps : %d\n", deps); NUM_INIT(); break;
      case '*':  op[deps] = MUL; printf("op: mul, deps : %d\n", deps); NUM_INIT(); break;
      case '/':  op[deps] = DIV; printf("op: div, deps : %d\n", deps); NUM_INIT(); break;
      case '(': ndi[deps]=nd; printf("ndi: %d\n", ndi[deps]); deps++; nd=0; break;
      case ')': n[deps][nd++]=strtol(num, NULL, 10); printf("push %ld\n", n[deps][nd-1]); NUM_INIT(); for(int i=0; i<nd; i++){ printf("%ld : %d\n", n[deps][i], deps); }; if(deps>0){ deps--; }else{ printf("Error!"); return -1; } nd=ndi[deps]; printf("ndi: %d\n", ndi[deps]); if(code[x+1] == ' '){ x++; break; } break;
      case ' ': if(isdigit(code[x-1]) != 0){n[deps][nd++]=strtol(num, NULL, 10); NUM_INIT();}; break;
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
  for(int m=1; m<10; m++){
      for(int j=0; j<10; j++){
	printf("ndi[deps] %d : deps : %d [op %d] : %ld\n", ndi[m], m, op[m], n[m][j]);
      }
    }
  return 0;
}
