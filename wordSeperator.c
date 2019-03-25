#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *inp = fopen("kelime.txt", "r");
  FILE *out = fopen("output.txt", "w");

  char word[20];
  char c;
  while((c = getc(inp)) != EOF) {
    if(c == ' ' || c == '\n')
      fputs("\n", out);
    else  
      fputc(c, out);
  }

  fclose(inp);
  fclose(out);
  return 0;

}




