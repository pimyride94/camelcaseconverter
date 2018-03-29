
#include "ccc_lib.h"
#include <stdio.h>

void camelcase_to_underline(char *input, char *output) {
    
    int i=0;
    int j=0;

    output[j]=input[i]+32;
    i++;
    j++;
    while(input[i]!=0){
        while(input[i]>='a' && input[i]<='z'){
            output[j]=input[i];
            i++;
            j++;
        }
        if(input[i] == 0) break;
        output[j]='_';
        j++;
        output[j]=input[i]+32;
        j++;
        i++;
    }
    output[j]='\0';

  return;
}

void underline_to_camelcase(char *input, char *output) {
    
    int i=0;
    int j=0;
    
    output[j]=input[i]-32;
    i++;
    j++;
    while(input[i]!=0){

        while(input[i]!='_'){
            if(input[i] == 0) break;
            output[j]=input[i];
            i++;
            j++;

        }
        if(input[i] == 0) break;
        i++;
        output[j]=input[i]-32;
        i++;
        j++;
    }
    output[j]='\0';

  return;
}




