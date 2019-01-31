#define ex2
#include "stdio.h"
#include "stdlib.h"

// Igor Augusto Monteiro Silva - ADS Manhã 2 ciclo
#ifdef ex1
/*
1 – Com a estrutura de dados abaixo, defina um vetor de tamanho 2. Crie as seguintes funções:
A - receba os dados via teclado
B – imprima no vídeo os dados recebidos
C – subtraia os elementos int
D – multiplique os elementos long
E – divida os elementos float
Imprima os resultados no vídeo mostrando o índice de cada elemento nas funções C, D e E..

Estrutura : inteiro 10, long 10 e float 10 (vetor como membro da estrutura).

*/

struct dados{
    int numInt[10];
    long numLong[10];
    float numFloat[10];

};

struct dados usuario[2];

armazena(){
    int i = 0, cI = 0, cLI = 0, cF = 0;

    for(i = 0; i < 2; i++){
        printf("\nVamos armazenar os numeros  do vetor %d\n", i + 1);
        for(cI = 0; cI < 10; cI++){
            printf("\nDigite o numero inteiro da posicao %d\n", cI + 1);
            scanf("%d", &usuario[i].numInt[cI]);
        }
        for(cLI = 0; cLI < 10; cLI++){
            printf("\nDigite agora o numero long int da posicao %d\n", cLI + 1);
            scanf("%ld", &usuario[i].numLong[cLI]);
        }
        for(cF = 0; cF < 10; cF++){
            printf("\nDigite agora o numero float da posicao %d\n", cF + 1);
            scanf("%f", &usuario[i].numFloat[cF]);
        }

    }

}

imprime(){
    int i = 0, cI = 0, cLI = 0, cF = 0;

    for(i = 0; i < 2; i++){
        printf("\nVamos imprimir os numeros do vetor %d\n", i + 1);
        for(cI = 0; cI < 10; cI++){
            printf("\n Numero inteiro digitado na posicao [%d] - %d\n", cI, usuario[i].numInt[cI]);
        }
        for(cLI = 0; cLI < 10; cLI++){
            printf("\n Numero long int digitado na posicao [%d] - %d\n", cLI, usuario[i].numLong[cLI]);

        }
        for(cF = 0; cF < 10; cF++){
            printf("\n Numero Float digitado na posicao [%d] - %.2f\n", cF, usuario[i].numFloat[cF]);
        }

    }

}

subtrai(){
    int i = 0, c = 0;
    int resultado[10];
    printf("Vamos ao resultado das subtracoes dos inteiros:\n");
    printf("O primeiro numero representa o vetor 1, o segundo numero representa o vetor 2\n");
    for(i = 0; i < 10; i++){
        resultado[i] = usuario[c].numInt[i] - usuario[c + 1].numInt[i];
        printf("\n%d - %d = %d\n", usuario[c].numInt[i], usuario[c + 1].numInt[i], resultado[i]);
    }
}

multiplica(){
    int i = 0, c = 0;
    long resultado[10];
    printf("Vamos ao resultado das multiplicacoes dos longs:\n");
    printf("O primeiro numero representa o vetor 1, o segundo numero representa o vetor 2\n");
    for(i = 0; i < 10; i++){
        resultado[i] = usuario[c].numLong[i] * usuario[c + 1].numLong[i];
        printf("\n%d * %d = %d\n", usuario[c].numLong[i], usuario[c + 1].numLong[i], resultado[i]);
    }
}



divide(){
    int i = 0, c = 0;
    float resultado[10];
    printf("Vamos ao resultado das divisoes dos floats:\n");
    printf("O primeiro numero representa o vetor 1, o segundo numero representa o vetor 2\n");
    for(i = 0; i < 10; i++){
        if(usuario[c + 1].numFloat[i] != 0){
            resultado[i] = usuario[c].numFloat[i] / usuario[c + 1].numFloat[i];
            printf("\n%.2f / %.2f = %.2f\n", usuario[c].numFloat[i], usuario[c + 1].numFloat[i], resultado[i]);
        }else{
            printf("\n%.2f / %.2f - Nao e possivel calcular o numero pois o denominador equivale a 0\n", usuario[c].numFloat[i], usuario[c + 1].numFloat[i]);
        }
    }
}

pulaLinha(){
    printf("\n\n\n");
}
main(){
    for( ; ; ){
            char sair;
            armazena();
            pulaLinha();
            imprime();
            pulaLinha();
            subtrai();
            pulaLinha();
            multiplica();
            pulaLinha();
            divide();
            getchar();
            printf("\nDeseja sair? S/N\n");
            sair = getchar();
            if((sair == 'S') || (sair == 's')){
                break;
            }else{
                system("cls");
            }
    }

}

#endif // ex1

#ifdef ex2
/*
2 – Com a estrutura de dados abaixo, defina um vetor de tamanho 10. Crie as seguintes funções:
A – receba dados via teclado
B – imprima no vídeo os dados recebidos
C – monta os itens de uma venda (pesquise pelo nome)
D – mostre os itens incluídos na venda e o valor total da venda

Estrutura: nome do item, quantidade, estoque mínimo e preço do item.

*/

struct dados{
    char itens[30];
    int quantidade;
    int estoque;
    float preco;
};

struct dados venda[10];

armazena(){
    int cS;
    for(cS = 0; cS < 10; cS++){
        fflush(stdin);
        printf("\nDigite o nome do produto %d\n", cS + 1);
        gets(venda[cS].itens);
        do{
            printf("\nInforme a quantidade disponivel do produto %s\n", venda[cS].itens);
            scanf("%d", &venda[cS].quantidade);
            if(venda[cS].quantidade < 0){
                printf("Numero invalido. Tente de novo\n");
            }
        }while(venda[cS].quantidade < 0);
        do{
            printf("\nInforme o estoque minimo necessario do produto %s\n", venda[cS].itens);
            scanf("%d", &venda[cS].estoque);
            if(venda[cS].estoque < 0){
                printf("Numero invalido. Tente de novo\n");
            }else if(venda[cS].estoque > venda[cS].quantidade){
                printf("Atencao, voce ja esta abaixo do estoque ideal\n");
            }
        }while(venda[cS].estoque < 0);
        do{
            printf("\nInforme o preco unitario do produto %s\n", venda[cS].itens);
            printf("R$");
            scanf("%f", &venda[cS].preco);
            if(venda[cS].preco < 0){
                printf("\nNumero invalido. Tente de novo\n");
            }
        }while(venda[cS].preco < 0);



    }

}

imprime(){
    int cS;
    for(cS = 0; cS < 10; cS++){
        printf("\nProduto %d = %s\n", cS + 1, venda[cS].itens);
        printf("Quantidade disponivel do produto %s - %d itens\n", venda[cS].itens, venda[cS].quantidade);
        printf("Estoque minimo do produto %s - %d itens\n", venda[cS].itens, venda[cS].estoque);
        printf("Preco unitario do produto %s - R$ %.2f\n", venda[cS].itens, venda[cS].preco);
        printf("-----------------------------------------------------------------\n");
    }
}
int tipoProduto;
int totalProduto;
montaItens(){
    int cS = 0;

        printf("\nTemos os seguintes produtos em nosso catalogo\n");
        for(cS = 0; cS < 10; cS++){
            printf("[%d] %s\n", cS + 1, venda[cS].itens);
        }
        do{
            printf("\nQual produto voce gostaria de levar? Escolha pelo numero\n");
            scanf("%d", &tipoProduto);
            if((tipoProduto > 10) || (tipoProduto < 1)){
                printf("Voce nao escolheu uma opcao valida. Tente de novo\n");
            }
            if(venda[tipoProduto - 1].quantidade == venda[tipoProduto - 1].estoque){
                printf("Infelizmente, estamos sem unidades a venda desse produto. Escolha outro da nossa lista\n");
            }
        }while((tipoProduto > 10) || (tipoProduto < 1) ||
               (venda[tipoProduto - 1].quantidade == venda[tipoProduto - 1].estoque));



        do{
            printf("Quantos itens voce gostaria de levar?\n");
            scanf("%d", &totalProduto);
            if(totalProduto > venda[tipoProduto - 1].quantidade - venda[tipoProduto - 1].estoque){
                printf("Nao temos o total de itens suficientes para essa venda\n");
            } else if(totalProduto <= 0){
                printf("Voce nao escolheu a quantidade valida de produtos. Tente de novo\n");
            }

        }while((totalProduto > venda[tipoProduto - 1].quantidade - venda[tipoProduto - 1].estoque)
               || (totalProduto <=0));
        venda[tipoProduto - 1].quantidade -= totalProduto;




}

float somaTotal = 0;
mostraVenda(){
    float valorPago;
    printf("\n\nVoce escolheu o item %d - %s da nossa lista\n", tipoProduto, venda[tipoProduto - 1].itens);
    printf("Voce escolheu %d unidades.\n", totalProduto);
    valorPago = totalProduto * venda[tipoProduto - 1].preco;
    printf("Valor a ser pago e: %.2f\n", valorPago);
    somaTotal += valorPago;
}

pulaLinha(){
    printf("\n\n\n");
}
main(){
    int sair;
    int segueCompra;
    for( ; ; ){
        armazena();
        pulaLinha();
        imprime();
        pulaLinha();
        montaItens();
        mostraVenda();

        for( ; ; ){

            do{
                printf("\nDesejaria comprar algo mais?\n");
                printf("[1] Sim\n");
                printf("[2] Nao\n");
                scanf("%d", &segueCompra);
                if(segueCompra == 2){
                    break;
                }else if(segueCompra == 1){
                    montaItens();
                    mostraVenda();
                }else{
                    printf("Voce nao digitou uma opcao valida. Tente de novo\n");
                }
            }while((segueCompra != 1) && (segueCompra != 2));
            if(segueCompra == 2){
                break;
            }


        }
        pulaLinha();
        printf("Valor total de todas as compras - R$ %.2f\n", somaTotal);
        do{
            printf("Deseja sair?\n");
            printf("[1] Sim\n");
            printf("[2] Nao\n");
            scanf("%d", &sair);
            if((sair < 1) || (sair > 2)){
                printf("Voce digitou uma opcao invalida. Tente de novo");
                system("pause");
                system("cls");
            }
        }while((sair < 1) || (sair > 2));
        if(sair == 1){
            break;
        }else{
            system("cls");
        }
    }



}
#endif // ex2
