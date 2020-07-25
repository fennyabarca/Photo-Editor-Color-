// Fernanda Carolina Aguilera Abarca

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

typedef struct pixel{
    int R, G, B;
} PIXEL;

//Aumentar brilho
void aumentarBrilho(PIXEL** original, int linhas, int colunas, int maxValor)
{    int l, c;
    for(l=0; l<linhas; l++)
    {    for(c=0; c<colunas; c++)
        {    original[l][c].R = (int)(original[l][c].R * 1.2);
            if(original[l][c].R > maxValor)
                original[l][c].R = maxValor;
            original[l][c].G = (int)(original[l][c].G * 1.2);
            if(original[l][c].G > maxValor)
                original[l][c].G = maxValor;
            original[l][c].B = (int)(original[l][c].B * 1.2);
            if(original[l][c].B > maxValor)
                original[l][c].B = maxValor;
        }
    }
}

//Diminuir brilho
void diminuirBrilho(PIXEL** original, int linhas, int colunas, int maxValor)
{    int l, c;
    for(l=0; l<linhas; l++)
    {    for(c=0; c<colunas; c++)
    {    original[l][c].R = (int)(original[l][c].R * 0.8);
            if(original[l][c].R > maxValor)
                original[l][c].R = maxValor;
            original[l][c].G = (int)(original[l][c].G * 0.8);
            if(original[l][c].G > maxValor)
                original[l][c].G = maxValor;
            original[l][c].B = (int)(original[l][c].B * 0.8);
            if(original[l][c].B > maxValor)
                original[l][c].B = maxValor;
        }
    }
}

//Borrar (desfocar imagem)
void borrar (PIXEL** original, int linhas, int colunas){
    int l, c;
    for (l=1; l<linhas-1; l++){
        for (c=1; c<colunas-1; c++){
            original[l][c].R = (original[l][c].R + original[l-1][c].R + original[l+1][c].R + original[l][c-1].R + original[l][c+1].R + original[l-1][c-1].R + original[l+1][c+1].R + original[l-1][c+1].R + original[l+1][c-1].R) / 9;
            original[l][c].G = (original[l][c].G + original[l-1][c].G + original[l+1][c].G + original[l][c-1].G + original[l][c+1].G + original[l-1][c-1].G + original[l+1][c+1].G + original[l-1][c+1].G + original[l+1][c-1].G) / 9;
            original[l][c].B = (original[l][c].B + original[l-1][c].B + original[l+1][c].B + original[l][c-1].B + original[l][c+1].B + original[l-1][c-1].B + original[l+1][c+1].B + original[l-1][c+1].B + original[l+1][c-1].B) / 9;
        }
    }
}

//Inserindo moldura
void moldura(PIXEL** original, int linhas, int colunas){
    int l, c;
        for(l=0; l<linhas; l++){
            for(c=0; c<colunas; c++){
                if(l<linhas*0.1 || l>linhas-linhas*0.1
                    || c<colunas*0.1 || c>colunas-colunas*0.1)
                original[l][c]= 0;
            }
    }
}

//Cor de pixel aleatoria
PIXEL sorteiaCor(int maxValor)
{   PIXEL ponto;
    ponto.R = rand() % maxValor;
    ponto.G = rand() % maxValor;
    ponto.B = rand() % maxValor;
    return ponto;
}

//Criando desenho de rodamoinho
PIXEL** rodamoinho(int *pLinhas, int *pColunas, int *pMaxValor)
{    PIXEL **mat;
    int i;

    *pLinhas = 200;
    *pColunas = 300;
    *pMaxValor = 255;
    
    //criando a matriz
    mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
    for(i=0; i< *pLinhas; i++)
        mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));
    
    int l, c;
    
    for(l=0; l<*pLinhas; l++)
        for(c=0; c<*pColunas; c++)
        {   mat[l][c].R = 0;
            mat[l][c].G = 0;
            mat[l][c].B = 0; //preto
        }
    
    l=10; c=10;
    int largura = *pColunas-20;
    int altura = *pLinhas-20;
    PIXEL ponto;
    
    while(largura>0 && altura>0)
    {   ponto = sorteiaCor(*pMaxValor);
        for(i=0; i<largura; i++)
        {   mat[l][c] = ponto;
            c++;
        }
        
        ponto = sorteiaCor(*pMaxValor);
        for(i=0; i<altura; i++)
        {   mat[l][c] = ponto;
            l++;
        }
        
        largura = largura - *pColunas/100;
        altura = altura - *pLinhas/100;
        
        ponto = sorteiaCor(*pMaxValor);
        for(i=0; i<largura; i++)
        {   mat[l][c] = ponto;
            c--;
        }
        
        ponto = sorteiaCor(*pMaxValor);
        for(i=0; i<altura; i++)
        {   mat[l][c] = ponto;
            l--;
        }
        
        largura = largura - *pColunas/100;
        altura = altura - *pLinhas/100;
    }
    
    return mat;
}

//Criando a bandeira da França :)
PIXEL** bandeiraFranca(int *pLinhas, int *pColunas, int *pMaxValor)
{    PIXEL **mat;
    int i;

    *pLinhas = 200;
    *pColunas = 300;
    *pMaxValor = 255;
    
    //criando a matriz
    mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
    for(i=0; i< *pLinhas; i++)
        mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));
    
    int l, c;
    for(l=0; l<*pLinhas; l++)
        for(c=0; c<*pColunas; c++)
            if(c<*pColunas/3)
            {   mat[l][c].R = 0;
                mat[l][c].G = 0;
                mat[l][c].B = *pMaxValor; //azul
            }
            else if(c<*pColunas*2/3)
            {   mat[l][c].R = *pMaxValor;
                mat[l][c].G = *pMaxValor;
                mat[l][c].B = *pMaxValor; //branco
            }
            else
            {   mat[l][c].R = *pMaxValor;
                mat[l][c].G = 0;
                mat[l][c].B = 0; //vermelho
            }

    return mat;
}

//Lendo imagem
PIXEL** lerImagem(char * nomeArquivo, int *pLinhas, int *pColunas, int *pMaxValor)
{    FILE *fp;
    fp = fopen(nomeArquivo,"r");
    /* Arquivo ASCII, para leitura */
    if(!fp)
    {    printf( "\nErro na abertura do arquivo\n\n");
        exit(-1);
    }

    //leia tipo do arquivo
    char buffer[1001];
    fgets (buffer, 1000, fp); //Primeira linha
    if(strstr(buffer, "P3") == NULL) // o tipo de arquivo eh diferente de P3?
    {    printf( "\nErro no tipo do arquivo\n\n");
        exit(-2);
    }

    //leia comentario
    fgets (buffer, 1000, fp);
    
    //leia dados da imagem
    fscanf(fp, "%d%d%d", pColunas, pLinhas, pMaxValor);

    //criando a matriz
    PIXEL **mat;
    int i;
    mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
    for(i=0; i< *pLinhas; i++)
        mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));

    int l, c;
    for(l=0; l<*pLinhas; l++)
    {    for(c=0; c<*pColunas; c++)
        {    fscanf(fp, "%d", &mat[l][c].R);
            fscanf(fp, "%d", &mat[l][c].G);
            fscanf(fp, "%d", &mat[l][c].B);
        }
    }
    fclose(fp);
    return mat;
}

//Escrevendo imagem
void escreverImagem(char * nomeArquivo, PIXEL ** mat, int linhas, int colunas, int maxValor)
{    FILE *fp;
    fp = fopen(nomeArquivo,"w");
    // Arquivo ASCII, para leitura
    if(!fp)
    {    printf( "\nErro na abertura do arquivo\n\n");
        exit(-1);
    }

    //escreva tipo do arquivo
    fprintf (fp, "P3\n");
    //escreva comentario
    fprintf (fp, "#Figura modificada...\n");
    //colunas, linhas
    fprintf(fp, "%d %d\n", colunas, linhas);
    //maxValor
    fprintf(fp, "%d\n", maxValor);

    int l, c;
    for(l=0; l<linhas; l++)
    {    for(c=0; c<colunas; c++)
            fprintf(fp, "%d\n%d\n%d\n", mat[l][c].R, mat[l][c].G, mat[l][c].B);
    }
    fclose(fp);
}

//MAIN

int main(int argc, char * argv[])
{    srand(time(NULL)); //inicializa a semente aleatória
    char opcao[10]="0";
    int linhas=0, colunas=0, maxValor=0;
    PIXEL **mat=NULL;
    //int tamanhoBorrao = 8;
    char nomeArquivo[100]="";
    char nomeArquivoLeitura[100]="";
    char nomeArquivoEscrita[100]="";
    while(opcao[0] != '9')
    {    printf("\n\nMini-photoshop\n\n");
        printf("1) Ler imagem\n");
        printf("2) Gravar imagem\n");
        printf("3) Aumentar o brilho\n");
        printf("4) Diminuir o brilho\n");
        printf("5) Bandeira da França\n");
        printf("6) Rodamoinho\n");
        printf("7) Desfocar\n");
        printf("8) Fazer moldura\n");
        printf("9) Sair\n");
        printf("\nEntre a opcao desejada: ");
        fgets(opcao, 10, stdin);
        switch(opcao[0])
        {    case '1':
                printf("\n\nEntre com o nome da imagem (sem extensao): ");
                fgets(nomeArquivo, 100, stdin);
                nomeArquivo[strlen(nomeArquivo)-1]='\0';
                strcpy (nomeArquivoLeitura, nomeArquivo);
                strcat (nomeArquivoLeitura, ".ppm");
                mat = lerImagem(nomeArquivoLeitura, &linhas, &colunas, &maxValor);
                break;
            case '2':
                strcpy (nomeArquivoEscrita, nomeArquivo);
                strcat (nomeArquivoEscrita, "_editada.ppm");
                printf("\n\nA imagem sera salva como %s\n", nomeArquivoEscrita);
                escreverImagem(nomeArquivoEscrita, mat, linhas, colunas, maxValor);
                break;
            case '3':
                aumentarBrilho(mat, linhas, colunas, maxValor);
                break;
            case '4':
                diminuirBrilho(mat, linhas, colunas, maxValor);
                break;
            case '5':
                strcpy (nomeArquivoEscrita, "bandeiraFranca.ppm");
                mat =  bandeiraFranca(&linhas, &colunas, &maxValor);
                escreverImagem(nomeArquivoEscrita, mat, linhas, colunas, maxValor);
                break;
            case '6':
                strcpy (nomeArquivoEscrita, "rodamoinho.ppm");
                mat =  rodamoinho(&linhas, &colunas, &maxValor);
                escreverImagem(nomeArquivoEscrita, mat, linhas, colunas, maxValor);
                break;
            case '7':
                borrar (mat, linhas, colunas);
                break;
            case '8':
                moldura(mat, linhas, colunas);
                break;
        }
    }
    return 0;
}

/*OUTRAS FUNCOES
Fundo branco recursivo
void pintarBranco(int** original, int linhas, int colunas, int maxValor, int inicioX, int inicioY)
{    if(inicioX>=0 && inicioX<linhas && inicioY>=0 && inicioY<colunas && original[inicioX][inicioY] != maxValor)
        {   original[inicioX][inicioY] = maxValor;
            pintarBranco(original, linhas, colunas, maxValor, inicioX+1, inicioY);
            pintarBranco(original, linhas, colunas, maxValor, inicioX-1, inicioY);
            pintarBranco(original, linhas, colunas, maxValor, inicioX, inicioY-1);
            pintarBranco(original, linhas, colunas, maxValor, inicioX, inicioY+1);
        }
}

 Aumentar contraste
 void aumentarContraste(PIXEL** original, int linhas, int colunas, int maxValor){
     int l, c;
     for (l=0; l<linhas; l++){
         for (c=0; c<colunas; c++){
             original[l][c].R = (maxValor / (1.0 + exp(-(10.0 * original[l][c].R / (float)maxValor - 5.0))));
             original[l][c].G = (maxValor / (1.0 + exp(-(10.0 * original[l][c].G / (float)maxValor - 5.0))));
             original[l][c].B = (maxValor / (1.0 + exp(-(10.0 * original[l][c].B / (float)maxValor - 5.0))));
         }
     }
 }

 Diminuir contraste
 void diminuirContraste(PIXEL** original, int linhas, int colunas, int maxValor){
     int l, c;
     for (l=0; l<linhas; l++){
         for (c=0; c<colunas; c++){
             original[l][c].R = (maxValor / (1.0 + exp(-(2.0 * original[l][c].R / (float)maxValor - 1.0))));
             original[l][c].G = (maxValor / (1.0 + exp(-(2.0 * original[l][c].G / (float)maxValor - 1.0))));
             original[l][c].B = (maxValor / (1.0 + exp(-(2.0 * original[l][c].B / (float)maxValor - 1.0))));
         }
     }
 }*/
