#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* addPerson(void *pBuffer);
void* listPeople(void *pBuffer);
void* searchPerson(void *pBuffer);
void* deletePerson(void *pBuffer);



int main(){
    void *pBuffer = malloc(3 * sizeof(int) + 100);
    if( pBuffer != NULL){
        *(int*)pBuffer = 0;
        *(int*)((char*)pBuffer + sizeof(int)) = 0;
        *(int*)((char*)pBuffer + 2 * sizeof(int)) = 0;
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
        getchar();
        
        switch (*(int *)pBuffer)
        {
            case 1:
            pBuffer = addPerson(pBuffer);
            break;
            case 2:
            pBuffer = deletePerson(pBuffer);
            break;
            case 3:
            pBuffer = searchPerson(pBuffer);
            break;
            case 4:
            listPeople(pBuffer);
            break;
            case 5:
            printf("Obrigado por usar o Programa!");
            break;
            
            default:
            break;
        }
    }
    free(pBuffer);
    return 0;
}

void* addPerson(void* pBuffer){
    
    
    //ADICIONANDO NOME
    printf("\nNOME: \n");
    fgets((char *)pBuffer + 3 * sizeof(int), 100, stdin);
    ((char *)pBuffer + (sizeof(int)*3))[strcspn((char *)pBuffer + 3 * sizeof(int), "\n")] = '\0'; 
    pBuffer = realloc(pBuffer,3 * sizeof(int) + 100 + strlen((char *)pBuffer + (3 * sizeof(int))) + *(int*)((char *)pBuffer + sizeof(int)) + sizeof(int) + 1);    
    memcpy((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + sizeof(int)), pBuffer + ( 3 * sizeof(int)), strlen((char *)pBuffer +3*sizeof(int))+1);
    *(int *)((char *)pBuffer+sizeof(int)) += strlen((char *)pBuffer + (3 * sizeof(int)))+1 + sizeof(int);
    
    //ADICIONANDO IDADE
    printf("\nIDADE: \n");
    scanf("%d",(int*)((char*) pBuffer +3*sizeof(int)+100+*(int*)((char*)pBuffer + sizeof(int)) - sizeof(int)));
    getchar();

    //ADICIONANDO EMAIL
    printf("\nEMAIL: \n");
    fgets((char *)pBuffer + 3*sizeof(int), 100, stdin);
    ((char *)pBuffer + (sizeof(int)*3))[strcspn((char *)pBuffer + 3 * sizeof(int), "\n")] = '\0'; 
    pBuffer = realloc(pBuffer,3*sizeof(int) + 100 + (*(int *)((char *)pBuffer + sizeof(int))) + strlen((char *)pBuffer + (3 * sizeof(int))) + 1);    
    memcpy((char *)pBuffer+3*sizeof(int) + 100 + (*(int *)((char *)pBuffer + sizeof(int))) , pBuffer+(3*sizeof(int)) , strlen((char *)pBuffer +3*sizeof(int))+1);
    *(int *)((char *)pBuffer+sizeof(int)) += strlen((char *)pBuffer + (3 * sizeof(int)))+1;


    return pBuffer;
}

void* listPeople(void* pBuffer){
    *(int*)((char *)pBuffer + 2 * sizeof(int)) = 0;

    while(*(int*)((char *)pBuffer + 2 * sizeof(int)) < *(int*)((char *)pBuffer + sizeof(int))){
        //IMPRIMIR NOME
        printf("\nNome: %s\n", (char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int)));
        *(int *)((char *)pBuffer + 2 * sizeof(int)) += strlen((char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

        //IMPRIMIR IDADE
        printf("Idade: %d\n",*(int*)((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))));
        *(int *)((char *)pBuffer + 2 * sizeof(int)) += sizeof(int);

        //IMPRIMIR EMAIL
        printf("Email: %s\n", (char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int)));
        *(int*)((char *)pBuffer + 2 * sizeof(int)) += strlen((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

        printf("-----------------------------\n");
    }

    return pBuffer;
}

void* searchPerson(void* pBuffer){
    *(int*)((char *)pBuffer + 2 * sizeof(int)) = 0;

    if (*(int*)((char *)pBuffer + sizeof(int)) == 0)
    {
        printf("Primeiro cadastre ao menos um usuário para poder buscar!");
        return pBuffer;
    }
    

    printf("\nDigite o nome de quem você quer buscar:\n");
    fgets((char *)pBuffer + 3 * sizeof(int), 100, stdin);
    ((char *)pBuffer + 3 * sizeof(int))[strcspn((char *)pBuffer + 3 * sizeof(int), "\n")] = '\0';

    while(*(int*)((char *)pBuffer + 2 * sizeof(int)) < *(int*)((char *)pBuffer + sizeof(int))){

        if(strcmp((char *)pBuffer + 3 * sizeof(int), (char *)pBuffer + 3 * sizeof(int) + 100 + *(int *)((char *)pBuffer + 2 * sizeof(int))) == 0){
             //IMPRIMIR NOME
            printf("\nNome: %s\n", (char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int)));
            *(int *)((char *)pBuffer + 2 * sizeof(int)) += strlen((char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

            //IMPRIMIR IDADE
            printf("Idade: %d\n",*(int*)((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))));
            *(int *)((char *)pBuffer + 2 * sizeof(int)) += sizeof(int);

            //IMPRIMIR EMAIL
            printf("Email: %s\n", (char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int)));
            *(int*)((char *)pBuffer + 2 * sizeof(int)) += strlen((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

            printf("-----------------------------\n");

            *(int*)((char *)pBuffer + 2 * sizeof(int)) = 0-*(int*)((char *)pBuffer + 2 * sizeof(int))-1;
            break;
        }

        *(int *)((char *)pBuffer + 2 * sizeof(int)) += strlen((char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;
        *(int *)((char *)pBuffer + 2 * sizeof(int)) += sizeof(int);
        *(int*)((char *)pBuffer + 2 * sizeof(int)) += strlen((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

        
    }
    if(*(int*)((char *)pBuffer + 2 * sizeof(int)) > 0){
        printf("\nNome não encontrado!\nRetornando ao menu......\n");
    }

    return pBuffer;
}

void* deletePerson(void* pBuffer){
*(int*)((char *)pBuffer + 2 * sizeof(int)) = 0;

if (*(int*)((char *)pBuffer + sizeof(int)) == 0)
{
    printf("Primeiro cadastre ao menos um usuário para poder deletar!");
    return pBuffer;
}


printf("\nDigite o nome de quem você quer deletar:\n");
fgets((char *)pBuffer + 3 * sizeof(int), 100, stdin);
((char *)pBuffer + 3 * sizeof(int))[strcspn((char *)pBuffer + 3 * sizeof(int), "\n")] = '\0';

while(*(int*)((char *)pBuffer + 2 * sizeof(int)) < *(int*)((char *)pBuffer + sizeof(int))){

    if(strcmp((char *)pBuffer + 3 * sizeof(int), (char *)pBuffer + 3 * sizeof(int) + 100 + *(int *)((char *)pBuffer + 2 * sizeof(int))) == 0){
            //IMPRIMIR NOME
        printf("\nNome: %s\n", (char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int)));
        *(int*)((char *)pBuffer + 3 * sizeof(int)) = *(int *)((char *)pBuffer + 2 * sizeof(int));
        *(int *)((char *)pBuffer + 2 * sizeof(int)) += strlen((char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

        //IMPRIMIR IDADE
        printf("Idade: %d\n",*(int*)((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))));
        *(int *)((char *)pBuffer + 2 * sizeof(int)) += sizeof(int);

        //IMPRIMIR EMAIL
        printf("Email: %s\n", (char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int)));
        *(int*)((char *)pBuffer + 2 * sizeof(int)) += strlen((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

        printf("-----------------------------\n");
        printf("Esse é o cadastro que deseja apagar?\n 1 - Sim\n 2 - Não\n->");

        scanf("%d", (int*)pBuffer);
        getchar();
        if(*(int*)pBuffer == 1){
            
            memmove(
                ((char *)pBuffer + 3 * sizeof(int)) + 100 + *(int *)((char *)pBuffer + 3 * sizeof(int)),
                ((char *)pBuffer + 3 * sizeof(int)) + 100 + *(int *)((char *)pBuffer + 2 * sizeof(int)),
                *(int *)((char *)pBuffer + sizeof(int)) - *(int *)((char *)pBuffer + 2 * sizeof(int))
            );

            *(int*)((char *)pBuffer + sizeof(int)) = *(int*)((char *)pBuffer + sizeof(int)) - (*(int *)((char *)pBuffer + 2 * sizeof(int)) - *(int *)((char *)pBuffer + 3 * sizeof(int)));

            pBuffer = realloc(pBuffer, 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + sizeof(int)));

            *(int*)((char *)pBuffer + 2 * sizeof(int)) = 0-*(int*)((char *)pBuffer + 2 * sizeof(int))-1;
            break;

        }else if(*(int*)pBuffer == 2){
            printf("\nRetornando para o Menu principal.\n");
            *(int*)((char *)pBuffer + 2 * sizeof(int)) = 0-*(int*)((char *)pBuffer + 2 * sizeof(int));
            break;
        }else{
            printf("\nOpção inválida retornando ao menu principal...\n");
            *(int*)((char *)pBuffer + 2 * sizeof(int)) = 0-*(int*)((char *)pBuffer + 2 * sizeof(int));
            break;
        }


    }

    *(int *)((char *)pBuffer + 2 * sizeof(int)) += strlen((char*)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;
    *(int *)((char *)pBuffer + 2 * sizeof(int)) += sizeof(int);
    *(int*)((char *)pBuffer + 2 * sizeof(int)) += strlen((char *)pBuffer + 3 * sizeof(int) + 100 + *(int*)((char *)pBuffer + 2 * sizeof(int))) + 1;

    
}
if(*(int*)((char *)pBuffer + 2 * sizeof(int)) > 0){
    printf("\nNome não encontrado!\nRetornando ao menu......\n");
}else if(*(int*)((char *)pBuffer + 2 * sizeof(int)) < 0){
    printf("\nNome deletado com sucesso!\n Retornando ao menu.....\n");
}
*(int*)pBuffer = 0;
return pBuffer; 


}