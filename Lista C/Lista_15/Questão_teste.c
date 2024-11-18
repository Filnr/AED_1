#include <stdlib.h>
#include <stdio.h>

int funcao(int num){
    int k = 0;
    //num = num/10;
    if (num == 0){
        return 0;
    }
    k = 1+ funcao(num/10);
    return k;
}

int main(){
    int num;
    scanf("%d", &num);
    int vezes = funcao(num);
    printf("%d", vezes);

}