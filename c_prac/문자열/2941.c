#include <stdio.h>
#include <string.h>

int main(){
    char cr[100];
    int count=0;
    gets(cr);
    
    for(int i=0;i<strlen(cr);i++){
        if((cr[i]=='c' && cr[i+1]=='=') || (cr[i]=='c' && cr[i+1]=='-')) {
            //printf("c= or c-\n");
            count++;
            i++;
        }
        else if((cr[i]=='d' && cr[i+1]=='z' && cr[i+2]=='=')){
            //printf("dz=\n");
            count++;
            i+=2;
        }
        else if(cr[i]=='d' && cr[i+1]=='-'){
            //printf("d-\n");
            count++;
            i++;
        }
        else if((cr[i]=='l' && cr[i+1]=='j') || (cr[i]=='n' && cr[i+1]=='j')){
            //printf("lj or nj\n");
            count++;
            i++;
        }
        else if((cr[i]=='s' && cr[i+1]=='=') || (cr[i]=='z' && cr[i+1]=='=')){
            //printf("s= or z=\n");
            count++;
            i++;
        }
        else count++;
    }
    printf("%d", count);
    
    return 0;
}