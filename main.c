#include <stdio.h>
#include <string.h>
#include <stdlib.h>







int main(){
    void *pBuffer = malloc(3 * sizeof(int));
    if( pBuffer != NULL){
        *(int*)pBuffer = 0;
    }else {
        printf("NÃO FOI POSSÍVEL ALOCAR MEMORIA... SAINDO DO PROGRAMA.");
        exit(1);
    }
    
    while (*(int *)pBuffer != 5){
        printf("\n MENU DE OPÇÕES"
            "\n 1 - Adicionar Pessoa (Nome, Idade, Email)"
            "\n 2 - Remover Pessoa "
            "\n 3 - Buscar Pessoa"
            "\n 4 - Listar Todos "
            "\n 5 - Sair "
            "\n->");
        scanf("%d", (int *)pBuffer);
        
        switch (*(int *)pBuffer)
        {
            case 1:
            /* code */
            break;
            case 2:
            /* code */
            break;
            case 3:
            /* code */
            break;
            case 4:
            /* code */
            break;
            case 5:
            /* code */
            break;
            
            default:
            break;
        }
    }
    free(pBuffer);


    return 0;


}





