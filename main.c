#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

float gaiola[9][7];
float precoTotal[9];
int indiceMenu;
float precoTotalGaiola(int indice);


//funcao loadiang tela inicio//
void Loading(void)
{
    int i;
    system("cls");
    printf("Seja bem vindo!!");
    printf("\nPor favor aguarde carregando....");
    for(i=0; i<50; i++)
    {
        Sleep(35);
        printf("%c",219);
    }
    SegundaParte();

}
// segunda parte da funcao de carregamento//
void SegundaParte(void)
{
    system("cls");
    printf("\n\nSistema carregado com sucesso!!\n\n");
    Sleep(800);
    system("cls");
    system("color F4");
}

void menu(void)
{
    setlocale(LC_ALL,"Portuguese");
    int i,j;
    printf("1 Para cadastrar nova gaiola:\n");
    printf("2 Para ver gaiolas\n");
    printf("3 Para alimentar uma gaiola\n");
    printf("4 Para medicar uma gaiola\n");
    printf("5 Para alterar uma gaiola\n");
    printf("7 Para simular uma mutação\n");
    printf("8 Para vender um filhote\n");
    printf("9 Para sair\n\n");
    printf("Qual opção: ");
    scanf("%i",&indiceMenu);
    switch(indiceMenu)
    {
    case 1:
        printf("Cadastrar gaiola escolhido\n");
        system("cls");
        cadastrarGaiola();
        break;
    case 2:
        printf("Vizualizar gaiola escolhido\n");
        system("cls");
        verGaiolas();
        break;
    case 3:
        system("cls");
        alimentarGaiola();
        break;
    case 4:
        system("cls");
        medicarGaiola();
        break;
    case 5:
        system("cls");
        alterarGaiola();
        break;
    case 7:
        system("cls");
        simularMutacao();
        break;

    case 8:
        system("cls");
        venderFilhote();
        break;
    case 9:
        system("cls");
        printf("Ok volte logo\n");

    }
}
//Cadastrar gaiola//
void cadastrarGaiola(void)
{
    int verifica,i,j;
    for(i=1; i<9; i++)
    {
        buscarGaiolaVazia(i);
    }
    printf("\n");
    printf("\n");
    printf("Qual gaiola deseja cadastrar?\n");
    scanf("%d",&i);
    while(i==0 || (i>8))
    {
        system("cls");
        printf("Pressione 0 para ir ao menu\n");
        printf("Escolha apenas gaiolas de 1 a 8:\n");
        printf("digite a gaiola que deseja cadastrar:\n");
        scanf("%d",&i);
        if(i==0)
        {
            menu();
        }

    }
    verifica=verificarGaiola(i);
    if(verifica==1)
    {
        for(j=1; j<=3; j++)
        {
            if(j==1)
            {
                printf("Por favor digite o codigo da cor do pai: ");
                scanf("%f",&gaiola[i][j]);
                while(gaiola[i][j]==0 || gaiola[i][j]<0)
                {
                    printf("Por favor digite o codigo da cor do pai: ");
                    scanf("%f",&gaiola[i][j]);

                }

            }
            if(j==2)
            {
                printf("Por favor digite o codigo da  cor da mãe: ");
                scanf("%f",&gaiola[i][j]);
                while(gaiola[i][j]==0  || gaiola[i][j]<0)
                {
                    printf("Por favor digite o codigo da cor do pai: ");
                    scanf("%f",&gaiola[i][j]);

                }
            }
            if(j==3)
            {
                printf("Por favor informe o preço do kg da ração: ");
                scanf("%f",&gaiola[i][j]);
                while(gaiola[i][j]==0  || gaiola[i][j]<0)
                {
                    printf("Por favor informe o preço do kg da ração: ");
                    scanf("%f",&gaiola[i][j]);
                }
            }

        }
    }
    //posicao 4 peso entregue ao passaro
    //posicao 5 quantos dias foram entregues ração
    //posicao 6 quantos dias foram entregue de remedio
    //posicao 7 preco por dose remedio


    else
    {
        printf("Gaiola numero:%i já esta sendo ocupada\n",i);
        printf("Por favor escolha uma gaiola disponível\n");
        printf("\n");

        pausarLimparTela();
        printf("Lista com todas as gaiolas\n");
        cadastrarGaiola();
    }
    pausarLimparTela();
    menu();

}

//Buscar gaiola vazia//
buscarGaiolaVazia(int indice)
{
    if(gaiola[indice][1]==0)
    {
        printf("Gaiola:");
        printf("%i",indice);
        printf(" Vazia \n");
    }
    else
    {
        printf("Gaiola:");
        printf("%i",indice);
        printf("Está cheia\n");
    }
}
//verificar Gaiola//
int verificarGaiola(int indiceGaiola)
{
    if((gaiola[indiceGaiola][1]==0) && (gaiola[indiceGaiola][2]==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Vizualizar Gaiolas//
void verGaiolas(void)
{
    int j,verifica;
    int i;
    for(i=1; i<=8; i++)
    {
        buscarGaiolaVazia(i);
    }
    printf("\n");
    printf("\n");
    printf("Pressione 0 para voltar ao menu ou escolha uma gaiola valída\n");
    printf("Digite o número da gaiola: \n");
    scanf("%i",&i);
    system("cls");

    if(i==0)
    {
        system("cls");
        menu();
    }
    if(i<9)
    {
        verifica=verificarGaiola(i);
        if(verifica==0)
        {
            for(j=1; j<7; j++)
            {
                if(j==1)
                {
                    printf("Codigo da cor do pai: ");
                    printf("%.2f\n",gaiola[i][j]);
                }
                if(j==2)
                {
                    printf("Codigo da cor da mae: ");
                    printf("%.2f\n",gaiola[i][j]);
                }
                if(j==3)
                {
                    printf("Preço do kilo da ração: ");
                    printf("%.2f\n",gaiola[i][j]);
                }
                if(j==4)
                {
                    printf("Ultima quantidade de comida entregue ao passario: ");
                    printf("%.2f",gaiola[i][j]);
                    printf(" gramas\n");
                }
                if(j==5)
                {
                    printf("Foram entregues: ");
                    printf("%.2f",gaiola[i][j]);
                    printf(" porções de ração ao passaro\n");
                }
                if(j==6)
                {
                    printf("Já foram entregues: ");
                    printf("%.2f",gaiola[i][j]);
                    printf(" Doses de remedio\n");
                }
                if(j==7)
                {
                    printf("Preço do ultimo remedio utilizado R$: ");
                    printf("%.2f\n",gaiola[i][j]);
                }


            }
            printf("\n");
            printf("Preço de custo do passaro até o momento: ");
            printf("%.2f",precoTotal[i]);
            printf("\n");
            pausarLimparTela();
        }
        else
        {
            if(i<10)
            {
                printf("Gaiola não cadastrada\n");
                verGaiolas();
            }
        }
    }
    else
    {
        if(i>9)
        {
            printf("Entrada invalida\n");
            verGaiolas();
        }
    }
    menu();

}
void pausarLimparTela(void)
{
    system("PAUSE");
    system("cls");
}


//alimentar gaiola//
void alimentarGaiola(void)
{
    int i,j;
    printf("Entre com a gaiola que deseja alimentar:");
    scanf("%d",&i);
    printf("\n");
    printf("Por favor informe quantas gramas foram entregues:");
    scanf("%f",&gaiola[i][4]);
    precoTotal[i]=precoTotalGaiola(i);
    gaiola[i][5]=gaiola[i][5]+1;
    menu();

}

//medicar gaiola//
void medicarGaiola(void)
{
    int verifica,i,j;
    for(i=1; i<9; i++)
    {
        buscarGaiolaVazia(i);
    }
    printf("Se deseja voltar ao menu pressione 0\n");
    printf("Entre com o numero da gaiola a ser medicada\n");
    scanf("%d",&i);
    if(i==0)
    {
        menu();
    }
    verifica=verificarGaiola(i);
    if(verifica==0)
    {
        printf("Por favor informe o preço da dose de remedio\n");
        scanf("%f",&gaiola[i][7]);
        precoTotal[i]=precoTotalGaiola(i);
        gaiola[i][6]=gaiola[i][6]+1;
        menu();

    }
    else
    {
        printf("Entrada invalida\n");
        medicarGaiola();
    }

}

//Preco total gastto em cada
float precoTotalGaiola(int indice)
{
    float resultado;
    if(indiceMenu==3)
    {
        return  precoTotal[indice]+(gaiola[indice][3]*gaiola[indice][4]/1000);
    }
    if(indiceMenu==4)
    {
        return precoTotal[indice]+gaiola[indice][7];
    }

}
//Alterar a gaiola atualizar dados//
void alterarGaiola(void)
{


    int i,verifica,numAlteracao;
    for(i=1; i<9; i++)
    {
        buscarGaiolaVazia(i);
    }
    printf("Por favor informe a gaiola que deseja alterar:\n");
    scanf("%i",&i);
    verifica=verificarGaiola(i);
    if(verifica==0)
    {
        printf("Digite 1 para alterar a cor do paí\n");
        printf("Digite 2 para alterar a cor da mãe\n");
        printf("Digite 3 para alterar o preço da ração\n");
        printf("Digite 0 para retornar ao menu\n");
        scanf("%d",&numAlteracao);
        if(numAlteracao==0)
        {
            menu();
        }

        switch(numAlteracao)
        {

        case 1:
            printf("Digite qual a nova cor do paí: ");
            scanf("%f",&gaiola[i][1]);
            printf("Cor do paí alterada com sucesso\n");
            pausarLimparTela();
            menu();
            break;

        case 2:
            printf("Digite qual a nova cor da mae: ");
            scanf("%f",&gaiola[i][2]);
            printf("Cor da mãe alterada com sucesso\n");
            pausarLimparTela();
            menu();;
            break;


        case 3:

            printf("Digite qual a o novo preço da racão: ");
            scanf("%f",&gaiola[i][3]);
            printf("Preço alterado com sucesso\n");
            pausarLimparTela();
            menu();
            break;

        default:
            printf("Por favor escolha dentre as opções\n");
            alterarGaiola();

        }
    }
    else
    {
        printf("Por favor informe uma gaiola cadastrada\n");
    }
}
//simularutacao//
void simularMutacao(void)
{
    int cormacho,opcaoMutacao;
    printf("Entre com a cor do macho: ");
    scanf("%i",&cormacho);
    system("cls");
    switch(cormacho)
    {
    case 1:
        printf("1) Silvestres Macho:\n");
        printf("M Silvestre x F Silvestre = FM Silvestres e FF Silvestres\n");
        printf("M Silvestre x F pérola = FM Silvestre/pérola e FF Silvestres\n");
        printf("M Silvestre x F Lutino = FM Silvestre/INO e FF Silvestres\n");
        printf("M Silvestre x F Canela = FM Silvesre/Canela e FF Silvestres\n");
        printf("M Silvestre x F CB = FM Silvestre/CB e FF Silvestre/CB\n");
        printf("M Silvestre x F Arlequim= FM silvestre/arlequim e FF Sivestre/arlequim\n\n");
        break;

    case 2:
        printf("2) Pérola Macho:\n");
        printf("M Pérola x F Pérola = FM Pérolas e FF Pérolas\n");
        printf("M Pérola x F Silvestre = FM Silvestre/pérola e FF Pérola\n");
        printf("M Pérola x F Lutino = FM Silvestres/Pérola/Lutino e FF Pérolas\n");
        printf("M Pérola x F Canela = FM Silvestre/Pérola/Canela e FF Pérolas\n");
        printf("M Pérola x F CB= FM Silvestre/pérola/CB e FF pérolas/CB\n");
        printf("M Pérola x F arlequim = FM silvestre/pérola/arlequim e FF Pérolas/Arlequim\n\n");
        break;


    case 3:
        printf("3) Lutino Macho:\n");
        printf("M Lutino x F Lutino = FM Lutinos e FF Lutinos\n");
        printf("M Lutino x F Silvestre= FM Silvestres/Lutino e FF Lutinos\n");
        printf("M Lutino x F Pérola = FM Silvestres/Lutino/Pérola e FF Lutinos\n");
        printf("M Lutino x F Canela = FM Silvestres/Lutino/Canela e FF Lutinos\n");
        printf("M Lutino x F CB = FM Silvestres/Lutino/CB e FF Lutinos/CB\n");
        printf("M Lutino x F Arlequim= FM Silvestres/Lutino/Arlequim e FF lutinos/Arlequim\n\n");
        break;

    case 4:
        printf("4) Canela Macho:\n");
        printf("M Canela x F Canela =FM Canela e FFCanela\n");
        printf("M Canela x F Silvestre =FM Silvestre/Canela e FF Canela\n");
        printf("M Canela x F Pérola =FM Silvestre/Canela/Pérola e FF Canela\n");
        printf("M Canela x F Lutino =FM Silvestre/Canela/Lutino e FF Canela\n");
        printf("M Canela x F CB =FM Silvestre/Canela/CB e FF Canela/CB\n");
        printf("M Canela x F Arlequim =FM Silvestre/Canela/Arlequim e FF Canela/Arlequim\n\n");
        break;
    case 5:
        printf("5) Cara Branca Macho\n");
        printf("M CB x F CB = FM CB e FF CB\n");
        printf("M CB x F Silvestre = FM Silvestre/CB e FF Silvestre/CB\n");
        printf("M CB x F Pérola M = FM Silvestre/CB/Pérola e FF Silvestre/CB\n");
        printf("M CB x F Lutino = FM Silvestre/CB/Lutino e FF Silvestre/CB\n");
        printf("M CB x F Canela = FM Silvestre/CB/Canela e FF Silvestre/CB\n");
        printf("M CB x F Arlequim = FM Silvestre/CB/Arlequim e FF Silvestre/CB/ Arlequim\n\n");
        break;


    case 6:
        printf("7) Arlequim Macho\n");
        printf("M arlequim x F Arlequim = FM Arlequim e FF Arlequim\n");
        printf("M arlequim x F Silvestre= Silvestre/Arlequim e FF Silvestre/arlequim\n");
        printf("M arlequim x F Pérola = Silvestre/Arlequim/Pérola e FF Silvestre/arlequim\n");
        printf("M arlequim x F Lutino= Silvestre/Arlequim/Lutino e FF Silvestre/arlequim\n");
        printf("M arlequim x F CB= Silvestre/Arlequim/CBe FF Silvestre/arlequim/CB\n");
        printf("M arlequim x F Canela= Silvestre/Arlequim/Canela e FF Silvestre/arlequim\n\n");
        break;


    case 7:
        printf("7) Fulvo Macho");
        printf("M Fulvo x F Fulvo = FM Fulvo e FF Fulvo\n");
        printf("M Fulvo x F Silvestre = FM Silvestre/Fulvo e FF SIlvestre/Fulvo\n");
        printf("M Fulvo x F Pérola= FM Silvestre/Fulvo/Pérola e FF Silvestre/Fulvo\n");
        printf("M Fulvo x F Lutino= FM Silvestre/Fulvo/Lutino e FF SIlvestre/Fulvo\n");
        printf("M Fulvo x F CB= FM Silvestre/Fulvo/CB e FF SIlvestre/Fulvo/CB\n");
        printf("M Fulvo x F Arlequim= FM Silvestre/Fulvo/Arlequim e FF SIlvestre/Fulvo/Arlequim\n\n");
        break;

    default:
        printf("Cor não cadastrada digite uma cor valída\n");
        pausarLimparTela();
        codigoCor();
        pausarLimparTela();
        simularMutacao();
        break;
    }

    for (int i = 0; i<1; i++)
    {
        printf("Digite 1 para simular uma nova mutação ou 0 para voltar ao menu inicial\n");
        scanf("%i",&opcaoMutacao);

        if(opcaoMutacao==1)
        {
            simularMutacao();
            system("cls");
        }
        if(opcaoMutacao==0)
        {
            system("cls");
            menu();

        }
        else
        {
            printf("Por favor escolha 1 ou 0\n");
            i--;
            pausarLimparTela();
        }
    }
}

//venderfilhotye//
void venderFilhote(void)
{
    int i;
    printf("Qual gaiola? ");
    scanf("%i",&i);

}
//CodigoCor//
//tabela//
void codigoCor(void)
{
    printf("1 Silvestre\n");
    printf("2 Pérola\n");
    printf("3 Lutino\n");
    printf("4 Canela\n");
    printf("5 Cara Branca\n");
    printf("6 Arlequim\n");
    printf("7 Fulvo\n");
}

int main()
{
    Loading();
    menu();

    return 0;
}
