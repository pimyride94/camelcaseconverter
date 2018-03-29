

%{
    
#include <stdio.h>
#include "ccc_lib.h"

char output[1024]={0};
char temp[1024];
int flag=0;
%}

word [a-zA-Z][a-z]*
camel [A-Z][a-zA-Z]+
undersc [a-z_]+
erro [a-zA-Z|_!]+
endline ['\n']
space [' ']
%%

{word} {
    strcat(output,yytext);
}

{camel} {
    camelcase_to_underline(yytext,temp);
    strcat(output,temp);
}

{undersc} {
    underline_to_camelcase(yytext,temp);
    strcat(output,temp);
}

{erro} {
    flag=1;
    
}

{endline} {
    if(flag==1){
        printf("ERRO\n");
        flag=0;
        output[0]='\0';
    }
    else{
        printf("%s\n", output);
        output[0]='\0';
    }
}

{space} {
    strcat(output," ");
}
%%

int main() {
  yylex();
  return 0;
}


