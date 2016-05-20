#include <stdio.h>
#include <string.h>
#define MAX 100

int currentState(char[],int);

int main(){
    FILE *in = fopen("inputs.txt", "r");
    char inputs[100];
    int i=0,state=1;

    while(fgets(inputs, 100, in)!=NULL){
        currentState(inputs,state);
            if(currentState(inputs,state)==1)
                printf("VALID MOVE\n");
            else
                printf("INVALID MOVE!\n");
        }
        printf("END");
    fclose(in);
    return 0;
}
int currentState(char in[],int state){
    int i = 1,flag;
    if(state == 1){
        if(in[0] == 'R'){ //LC_MR
            if(in[i] == 'N'){
                while(in[i] == 'N'){
                    i++;
                }
            }
            if(in[i]!='L' && in[i]!='C'){
                return 0;
            }else
            if(in[i]=='L' || in[i]=='C'){
                i++;
                flag = 1;
            }
            if(flag==1){ // C_MLR
                if(in[i]!='R'){
                    return 0;
                }else
                if(in[i]=='R'){
                    i++;
                    flag = 2;
                }
            }
            if(flag==2){ // CR_ML
                if(in[i]!='C' && in[i]!='L'){
                    return 0;
                }else
                if(in[i]=='C' || in[i]=='L'){
                    i++;
                    flag = 3;
                }
            }
            if(flag==3){ // R_MLC
                if(in[i] == 'N'){
                    while(in[i] == 'N'){
                        i++;
                    }
                }
                if(in[i]!='R'){
                    return 0;
                }else
                if(in[i]=='R'){
                    return 1; // MLCR
                }
            }
        }else
            return 0;
    }
}

