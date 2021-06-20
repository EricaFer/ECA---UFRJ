#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <stdio.h>

int vetorauxiliar[1000],figurinhas_coladas[1000]={0},numero_do_vetor=0,repetidas[1000]={0},numero_de_repetidas=0,auxiliar7=0;

int user_logon;

void menu_cadastro();
void cadastro();
void iniciar_vetor();
void login();
void logon();
void menu_album();
void Mostrar();
void ver_se_possui();
void Compra();
void MostraRepetidas();
void linha(int num, char ch);

///ARQUIVO DO LOGIN
FILE * user;
FILE * senha;
///ARQUIVO REPETIDAS
FILE * user0;
FILE * user1;
FILE * user2;
FILE * user3;
FILE * user4;
FILE * user5;
FILE * user6;
///ARQUIVO COLADAS
FILE * user0_co;
FILE * user1_co;
FILE * user2_co;
FILE * user3_co;
FILE * user4_co;
FILE * user5_co;
FILE * user6_co;
///ARQUIVO CONVITE
FILE * user0_c;
FILE * user1_c;
FILE * user2_c;
FILE * user3_c;
FILE * user4_c;
FILE * user5_c;
FILE * user6_c;


FILE * user0_r;///teste



void ENTER()
{
    char c;
    printf("Aperte ENTER para continuar\n");
    scanf("%c",&c);
    if ( c == '\n' )
    {
       system ("cls");
    }
    else
    {
        printf("Comando inv�lido.\n");
    }
}

struct dados_cadastro
{
    char user[6];
    char user_teste[5];
    char senha[4];
    char senha_teste[4];
}usuario;


void menu_cadastro()
{
    int option_user;
    printf("    Escolha uma op��o:\n");
    printf("                     1-Cadastrar novo usu�rio\n");
    printf("                     2-Fazer login de usu�rio\n");
    printf("                     3-Fazer logon de usu�rio\n");
    printf("                       J� se decidiu? Escreva o n�mero da sua op��o:\n");
    scanf("%d",&option_user);
    switch(option_user)
    {
        case 1: system ("cls");
                cadastro();
                break;

        case 2: system ("cls");
                login();
                break;

        case 3: system ("cls");
                logon();
                break;

        default: printf ("Op��o selecionada n�o dispon�vel.\nTente novamente.\n");
                 menu_cadastro();
    }
}


void iniciar_vetor()
{
        strcpy(usuario.user, "NULL");
        strcpy(usuario.senha, "NULL");
}


void cadastro()
{
    int i,compare,numero,linha,user_igual = 0;
    iniciar_vetor();

    user = fopen ("user.txt","a+");

    printf("******CADASTRO******\n");
    printf("Insira um nome de usu�rio com 5 letras: ");
    scanf("%s",&usuario.user_teste);

     while(fgets(usuario.user, 6, user) != NULL)

        {
            ///tudo que est� em uma linha do arquivo vai para a string

            for (linha = 0; linha < 6; linha ++)///at� 6 usu�rios
            {
                numero = 0;///come�a em 0 para uma nova linha

                for ( i = 0; i < 5 ; i++ )///uma linha
                {
                    if (usuario.user_teste[i]!= usuario.user[i] )///caractere por caractere
                    {
                        numero++;
                    }
                }


                if (numero == 0)///linha toda igual
                {
                    user_igual++;

                }
            }

        }
        fclose(user);


        if (user_igual == 0)///n�o tem usuario com esse nome
            {
                user = fopen ("user.txt","a+");

                strcpy(usuario.user,usuario.user_teste);///se o nome for aprovado, ele vai para a string oficial
                fprintf(user,"%s\n",usuario.user);

                fclose(user);

                insira_senha:
                printf("\nInsira uma senha de 4 letras\n");
                fflush(stdin);

                for(i=0;i<4;i++)
                {
                    usuario.senha_teste[i]=getch();
                    putchar('*');
                }

                printf("\n");
                printf("Confirme sua senha\n");
                fflush(stdin);

                for(i=0;i<4;i++)
                {
                    usuario.senha[i]=getch();
                    putchar('*');
                }
                printf("\n");

                compare = strncmp(usuario.senha,usuario.senha,4);///comparando senhas

                if(compare == 0)///se senhas forem compat�veis
                {
                    printf("Senha salva\n");
                    ENTER();
                    senha = fopen ("senha.txt","a+");
                    strcpy(usuario.senha,usuario.senha_teste);///passando senha oficial para string oficial

                    fprintf(senha,"%s\n",usuario.senha);///string oficial vai para arquivo
                    fclose(senha);
                    login();
                }
                else///se senhas n�o forem compat�veis
                {

                printf("Senhas n�o s�o compat�veis\nTente novamente\n");

                ENTER();

                goto insira_senha;

                }
            }
        else
        {
            ENTER();
            printf("O nome de usu�rio inserido j� foi utilizado.\n\nPor favor tente novamente\n");
            ENTER();
            cadastro();

        }
}

void login()
{
    iniciar_vetor();

    user = fopen ("user.txt","a+");

    if (user == NULL)///aviso de erro
    {
        printf("Erro ao abrir arquivo\n");
        exit(0);
    }

    int linha ,numero,i,option_senha_errada;
    int user_igual=0;
    int senha_igual=0;
    int aux = 0,aux1=0;
    user_logon = 0;

    printf("******LOGIN******\n");
    printf("Usu�rio: ");
    fflush(stdin);
    for(i=0;i<5;i++)
                {
                    usuario.user_teste[i]=getch();
                    printf("%c", usuario.user_teste[i] );
                }
                printf("\n");

    while(fgets(usuario.user, 6, user) != NULL)

    {///tudo que est� em uma linha do arquivo vai para a string

        for(linha = 0;linha < 6;linha++)
        {
            numero = 0;///come�a em 0 para uma nova linha

            for ( i = 0; i < 5 ; i++ )///uma linha
            {
                if (usuario.user_teste[i]!= usuario.user[i] )///caractere por caractere
                {
                    numero++;
                }
            }

            if (numero == 0)///linha toda igual
            {
                user_igual++;
                aux1 = aux1+linha;
            }
        }
    }
    fclose(user);

    if (user_igual != 0)///se existir usuario com esse nome
    {
        inserir_senha:
        printf("\n\nSenha: ");
        fflush(stdin);

        for(i=0;i<4;i++)///inserindo senha
        {
            usuario.senha_teste[i]=getch();
            putchar('*');
        }
        printf("\n");
        senha = fopen ("senha.txt","a+");

        while(fgets(usuario.senha, 5, senha) != NULL)//procurando senha
        {//tudo que est� em uma linha do arquivo vai para a string

            for(linha = 0 ; linha < 6 ;linha++)///at� 6 senhas
            {
                numero = 0;///come�a em 0 para uma nova linha

                if (aux == linha)///checa a linha do usuario
                {
                    for ( i = 0; i < 4 ; i++ )///uma linha
                    {

                        if (usuario.senha[i]!= usuario.senha_teste[i] )///caractere por caractere
                        {

                            numero++;///se um caractere for diferente, vai adicionando
                        }
                    }

                    if (numero <= 1)///linha toda igual
                    {
                        senha_igual++;///indica que existe uma senha igual
                    }
                }
            }
        }

        fclose(senha);

        if ( senha_igual != 0)///se existe senha igual
        {

            printf("\n\nUsu�rio logado com sucesso!\n\n");
            user_logon = aux1 - 15;
            ENTER();
        }

        else///essa senha n�o foi encontrada
        {
            ENTER();
            printf("Senha n�o corresponde com o usu�rio inserido\n\n");
            printf("O que deseja fazer?\n");
            printf("                    1 - Logar outro usu�rio.\n");
            printf("                    2 - Tentar outra senha.\n");
            printf("                    3 - Voltar para o menu inicial.\n");
            printf("                    Escreva o n�mero da sua op��o:");
            scanf("%d",&option_senha_errada);
            ENTER();

            switch(option_senha_errada)
            {
                case 1: system ("cls");
                        login();
                        break;

                case 2: system ("cls");
                        goto inserir_senha;
                        break;

                case 3: system ("cls");
                        menu_cadastro();

                default: system ("cls");
                         printf("Op��o selecionada n�o dispon�vel.\nPor favor tente novamente\n");
                         login();
            }
        }
    }

    else ///usuario n�o encontrado
    {
        ENTER();
        printf("N�o existe usu�rio logado com esse nome\n\n");
        ENTER();
        cadastro();
    }
}



void logon()///fechar arquivo aqui
{
    char resposta;
    printf("Tem certeza que gostaria de sair desse usu�rio?\n\n");
    printf("Insira S ou N\n\n");
    scanf("%c", &resposta);

    switch (resposta)
    {
        case 'S':

            {
                ENTER();

             switch(user_logon)
            {
                case 1: {fclose(user0);
                        menu_cadastro();
                        break;}

                case 2: {fclose(user1);
                        menu_cadastro();
                        break;}


                case 3: {fclose(user2);
                        menu_cadastro();
                        break;}

                case 4: {fclose(user3);
                        menu_cadastro();
                        break;}

                case 5: {fclose(user4);
                        menu_cadastro();
                        break;}

                case 6: {fclose(user5);
                        menu_cadastro();
                        break;}

                case 7:{fclose(user6);
                       menu_cadastro();
                        break;}
            }}




        case 'N':

            {
              ENTER();
                      printf("Voc� ser� redirecionado para o menu de cadastro");
                      menu_cadastro();
                      break;
            }

        default: {
                printf("Op��o selecionada n�o dispon�vel.\nTente novamente.\n");
                ENTER();
                logon();
                ENTER();
                menu_cadastro;

                }

    }
}


 menu_album()
{
    int option,pacotes_comprados,numerodafig,figurinha_buscada,escolha,auxiliar5,auxiliar8;
    printf("MENU:\n\n");
    printf("    Escolha uma op��o:\n\n");/*Pensei em colocar strings no lugar de numeros, mas teria que colocar if else, o que acha?*/
    printf("                     1-Verificar o estado atual do �lbum\n\n");
    printf("                     2-Ver figurinhas faltantes\n\n");
    printf("                     3-Comprar pacotes de figurinhas\n\n");/*iv*/
    printf("                     4-Buscar figurinha\n\n");/*vi*/
    printf("                     5-Ver  figurinhas repetidas\n\n\n");/*vi | O que acha de criarmos multiplos usuarios ?*/
    printf("    Escreva o n�mero da sua op��o: ");
    scanf("%d",&option);

    switch (option)
        {
            case 1 :
                {
                  system ("cls");
                  Mostra_pagina();
                  break;
                }

            case 2 :
                {
                  system ("cls");
                  printf("Essas s�o as figurinhas faltantes:\n");
                  figurinhas_faltantes();

                  break;
                }

            case 3 :
               {  system ("cls");
                  Compra();
                  break;
               }
            case 4 :
                {
                  system ("cls");
                  printf("Digite o numero da figurinha que voc� deseja buscar:");
                  scanf("%i",&figurinha_buscada);
                 while (figurinha_buscada==0,figurinha_buscada>680)//Dependera do numero de figurinhas
                 {
                   printf("Essa figurinha n�o existe, por favor digite o numero da figurinha novamente:");
                   scanf("%i",&figurinha_buscada);
                  }
                  ver_se_possui(figurinha_buscada,figurinhas_coladas,repetidas);
                  Mostrar(figurinha_buscada);
                  printf("\n                                        1-Voltar ao menu\n");
                  scanf("%i",&auxiliar5);
                  switch(auxiliar5)
                  {
                      case 1:
                      {
                          system("cls");
                          menu_album();
                      }
                  }
                  break;
                }
            case 5 :
                {
                  system ("cls");
                  MostraRepetidas(repetidas);

                  break;
                }

            case 6:
                {
                    system("cls");
                    logon();
                    break;





                }
            default: printf ("Op��o selecionada n�o dispon�vel.\n");

        }
}
struct DATA
{
    int dia;
    int mes;
    long int ano;
};

struct ficha_jogador
{
    int num_fig;
    char nome[100];
    char pais[100];
    char time[100];
    int peso;
    float altura;
    char posicao[100];
    struct DATA nasc;
    int raro;
};


//CriandoFigurinhas

 struct ficha_jogador jogadores[]=
    {
     {0,"Luka Modric","Croacia","Real Madrid",70,1.70,"Meia Atacante",{12,07,1985},1},
     {1,"ESCUDO DA FIFA","-----","-----",0,0,"-----",{0,0,0},1},
     {2,"TROF�U DA COPA","-----","-----",0,0,"-----",{0,0,0},1},
     {3,"Arena Kazan (Kazan)   ","-----","-----",0,0,"-----",{0,0,0},0},
     {4,"Est�dio Lujniki (Moscou)","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {5,"Est�dio Spartak (Moscou)","-----","-----",0,0,"-----",{0,0,0},0},
     {6,"Est�dio S�o Petesburgo (S�o Petesburgo) ","-----","-----",0,0,"-----",{0,0,0},0},
     {7,"Est�dio Nizhny Novgorod (Nizhny Novgorod)","-----","-----",0,0,"-----",{0,0,0},0},
     {8,"Est�dio Ol�mpico de Sochi (Sochi)       ","-----","-----",0,0,"-----",{0,0,0},0},
     {9,"Arena Samara (Samara)","-----","-----",0,0,"-----",{0,0,0},0},
     {10,"Arena Rostov (Rostov-on-Don)","-----","-----",0,0,"-----",{0,0,0},0},
     {11,"Arena Ecaterimburgo (Ecaterimburgo)","-----","-----",0,0,"-----",{0,0,0},0},
     {12,"Est�dio de Saransk (Saransk)","-----","-----",0,0,"-----",{0,0,0},0},
     {13,"Arena Volgogrado (Volgogrado)","-----","-----",0,0,"-----",{0,0,0},0},
     {14,"ESCUDO DA R�SSIA","R�ssia","-----",0,0,"-----",{0,0,0},1},
     {15,"TIME DA R�SSIA","R�ssia","-----",0,0,"-----",{0,0,0},0},
     {16,"Igor Akinfeev","R�ssia","CSKA Moscou",82,1.86,"Goleiro",{8,4,1986},0},
     {17,"M�rio Fernandes","R�ssia","CSKA Moscou",80,1.87,"Defensor",{19,9,1990},0},
     {18,"Ilya Kutepov","R�ssia","Spartak Moscou",83,1.92,"Defensor",{29,7,1993},0},
     {19,"Viktor Vasin","R�ssia","CSKA Moscou",83,1.92,"Defensor",{8,4,1986},0},
     {20,"Dmitri Kombarov","R�ssia","Spartak Moscou",72,1.82,"Defensor",{22,1,1987},0},
     {21,"Aleksandr Golovin","R�ssia","CSKA Moscou",69,1.80,"Meio-campista",{30,5,1996},0},
     {22,"Aleksandr Samedov","R�ssia","Spartak Moscou",72,1.77,"Meio-campista",{19,7,1984},0},
     {23,"Alan Dzagoev","R�ssia","CSKA Moscou",75,1.79,"Meio-campista",{17,6,1990},0},
     {24,"Dmitry Poloz","R�ssia","Zenit",73,1.83,"Atacante",{12,7,1991},0},
     {25,"Fedor Smolov","R�ssia","Krasnodar",80,1.87,"Atacante",{9,2,1990},0},
     {26,"Aleksandr Kokorin","R�ssia","Zenit",74,1.81,"Atacante",{19,3,1991},0},
     {27,"ESCUDO DA AR�BIA SAUDITA","Ar�bia Saudita","-----",0,0,"-----",{0,0,0},1},
     {28,"TIME DA AR�BIA SAUDITA","Ar�bia Saudita","-----",0,0,"-----",{0,0,0},0},
     {29,"Abdullah Al-Mayouf","Ar�bia Saudita","AL-Hilal",83,1.88,"Goleiro",{12,07,1985},0},
     {30,"Osama Hawsawi","Ar�bia Saudita","AL-Hilal",78,1.85,"Defensor",{12,07,1985},0},
     {31,"Abdullah Al-Zori","Ar�bia Saudita","AL-Hilal",73,1.78,"Defensor",{12,07,1985},0},
     {31,"Mansour Al-Harbi","Ar�bia Saudita","AL-Ahli",65,1.70,"Defensor",{12,07,1985},0},
     {33,"Omar Hawsawi","Ar�bia Saudita","AL-Nassr",74,1.84,"Defensor",{12,07,1985},0},
     {34,"Taisir Al-Jassim","Ar�bia Saudita","AL-Ahli",64,1.69,"Meio-campista",{12,07,1985},0},
     {35,"Salman Al-Faraj","Ar�bia Saudita","AL-Hilal",72,1.75,"Meio-campista",{12,07,1985},0},
     {36,"Yahya Al-Shehri","Ar�bia Saudita","CD Legan�s",60,1.64,"Meio-campista",{12,07,1985},0},
     {37,"Salman Al-Moasher","Ar�bia Saudita","AL-Ahli",62,1.65,"Meio-campista",{12,07,1985},0},
     {38,"Mohammad Al-Sahlawi","Ar�bia Saudita","Al-Nassr",72,1.80,"Atacante",{12,07,1985},0},
     {39,"Fahad Al-Muwallad","Ar�bia Saudita","Levante UD",59,1.67,"Atacante",{12,07,1985},0},
     {40,"ESCUDO DO EGITO","Egito","-----",0,0,"-----",{0,0,0},1},
     {41,"TIME DO EGITO","Egito","-----",0,0,"-----",{0,0,0},0},
     {42,"Essam El Hadary","Egito","Al-Taawoun",87,1.88,"Goleiro",{15,01,1973},0},
     {43,"Ali Gabr","Egito","West Bromwich Albion",82,1.93,"Defensor",{10,07,1989},0},
     {44,"Ahmed Elmohamady","Egito","Aston Villa",75,1.83,"Defensor",{9,9,1987},0},
     {45,"Omar Gaber","Egito","Los Angeles",71,1.74,"Defensor",{30,1,1992},0},
     {46,"Ramy Rabia","Egito","Al Ahly",80,1.86,"Defensor",{20,5,1993},0},
     {47,"Ahmed Hegazi","Egito","West Bromwich Albion",83,1.93,"Defensor",{25,1,1991},0},
     {48,"Tarek Hamed","Egito","Zamalek",74,1.79,"Meio-campista",{24,10,1988},0},
     {49,"Mohahmed Elneny","Egito","Arsenal",70,1.80,"Meio-campista",{11,07,1992},0},
     {50,"Trezeguet","Egito","Kasimpasa SK",71,1.79,"Meio-campista",{1,10,1994},0},
     {51,"Mohamed Salah","Egito","Liverpool FC",71,1.75,"Atacante",{15,06,1992},0},
     {52,"Amr Gamal","Egito","Bidvest Wits",72,1.70,"Atacante",{3,8,1991},0},
     {53,"ESCUDO DO URUGUAI","Uruguai","-----",0,0,"-----",{0,0,0},1},
     {54,"TIME DO URUGUAI","Uruguai","-----",0,0,"-----",{0,0,0},0},
     {55,"Fernando Muslera","Uruguai","Galatasaray AS",74,1.90,"Goleiro",{16,07,1986},0},
     {56,"Maxi Pereira","Uruguai","Porto FC",65,1.75,"Defensor",{1,7,1984},0},
     {57,"Diego God�n","Uruguai","Atl�tico de Madrid",79,1.87,"Defensor",{16,2,1986},0},
     {58,"Mart�n Caceres","Uruguai","Lazio",78,1.80,"Defensor",{7,04,1987},0},
     {59,"Jos� Gimenez","Uruguai","Atl�tico de Madrid",77,1.85,"Defensor",{20,1,1995},0},
     {60,"Seb�stian Coates","Uruguai","Sporting",92,1.90,"Defensor",{5,3,1989},0},
     {61,"Ar�valo R�os","Uruguai","Egito",68,1.78,"Defensor",{2,03,1981},0},
     {62,"Carlos S�nchez","Uruguai","Monterrey",69,1.71,"Meio-campista",{2,07,1990},0},
     {63,"Mat�as Veccino","Uruguai","Inter de Mil�o",81,1.87,"Meio-campista",{1,4,1990},0},
     {64,"Nicol�s Lodeiro","Uruguai","Seattle Sounders",68,1.70,"Meio-campista",{19,03,1989},0},
     {65,"Luis Suar�z","Uruguai","Barcelona",80,1.85,"Atacante",{24,01,1987},0},
     {66,"ESCUDO DE PORTUGAL","Portugal","-----",0,0,"-----",{0,0,0},1},
     {67,"TIME DE PORTUGAL","Portugal","-----",0,0,"-----",{0,0,0},0},
     {68,"Rui Patr�cio","Portugal","Sporting",86,1.90,"Goleiro",{5,7,1988},0},
     {69,"Bruno Alves","Portugal","Rangers FC",81,1.88,"Defensor",{26,2,1988},0},
     {70,"Pepe","Portugal","Besiktas",83,1.88,"Defensor",{2,12,1983},0},
     {71,"Jos� Fonte","Portugal","West Ham",81,1.90,"Defensor",{12,2,1991},0},
     {72,"Eliseu","Portugal","Benfica",71,1.75,"Defensor",{22,1,1990},0},
     {73,"Jo�o M�rio","Portugal","West Ham",76,1.79,"Meio-campista",{23,9,1989},0},
     {74,"William Carvalho","Portugal","Sporting",85,1.90,"Meio-campista",{9,3,1993},0},
     {75,"Ricardo Quaresma","Portugal","Besiktas",71,1.74,"Meio-campista",{29,9,1989},0},
     {76,"Andr� Silva","Portugal","Milan",79,1.80,"Atacante",{2,12,1981},0},
     {77,"Gelson Martins","Portugal","Sporting",73,1.70,"Atacante",{7,7,1991},0},
     {78,"Cristiano Ronaldo","Portugal","Juventus",83,1.87,"Atacante",{5,2,1985},0},
     {79,"ESCUDO DA ESPANHA","Espanha","-----",0,0,"-----",{0,0,0},1},
     {80,"TIME DA ESPANHA","Espanha","-----",0,0,"-----",{0,0,0},0},
     {81,"De Gea","Espanha","Manchester United",0,0,"-----",{0,0,0},0},
     {82,"Sergio Ramos","Espanha","Real Madrid",0,0,"-----",{0,0,0},0},
     {83,"Jordi ALba","Espanha","Barcelona",0,0,"-----",{0,0,0},0},
     {84,"Gerard Piqu�","Espanha","Barcelona",0,0,"-----",{0,0,0},0},
     {85,"Sergio Busquets","Espanha","Barcelona",0,0,"-----",{0,0,0},0},
     {86,"Sa�l N�guez","Espanha","Atl�tico de Madrid",0,0,"-----",{0,0,0},0},
     {87,"Isco","Espanha","Real Madrid",0,0,"-----",{0,0,0},0},
     {88,"Iniesta","Espanha","Barcelona",0,0,"-----",{0,0,0},0},
     {89,"Diego Costa","Espanha","Atl�tico de Madrid",0,0,"-----",{0,0,0},0},
     {90,"Rodrigo","Espanha","Valencia",0,0,"-----",{0,0,0},0},
     {91,"Iago Aspas","Espanha","Deportivo",0,0,"-----",{0,0,0},0},
     {92,"ESCUDO DE MARROCOS","Marrocos","-----",0,0,"-----",{0,0,0},1},
     {93,"TIME DE MARROCOS","Marrocos","-----",0,0,"-----",{0,0,0},0},
     {94,"Munir Mohamedi","Marrocos","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {95,"Medhi Benatia","Marrocos","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {96,"Nabil Dirar","Marrocos","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {97,"Romain Saiss","Marrocos","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {98,"Fouad Chafik","Marrocos","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {99,"Karim El Hamadi","Marrocos","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {100,"Hakim Zyech","Marrocos","Real Madrid",70,1.70,"Meia Atacante",{12,07,1985},0},
     {101,"Nordin Amrabat","Marrocos","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {102,"Rachid Alioui","Marrocos","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {103,"Khalid Boutaib","Marrocos","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {104,"Youssef En-Nesyri","Marrocos","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {105,"ESCUDO DO IR�","Ir�","-----",0,0,"-----",{0,0,0},1},
     {106,"TIME DO IR�","Ir�","-----",0,0,"-----",{0,0,0},0},
     {107,"Alireza Beiranvand","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {108,"Pejman Montarezi","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {109,"Vouria Ghafouri","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {110,"Jalal Hosseini","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {111,"Milad Mohammadi","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {112,"Omid Ebrahimi","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {113,"Saeid Ezatolahi","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {114,"Vahid Amiri","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {115,"Mehdi Taremi","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {116,"Alireza Jahanbakhsh","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {117,"Sardar Azmoun","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {118,"ESCUDO DA FRAN�A","Fran�a","-----",0,0,"-----",{0,0,0},1},
     {119,"TIME DA FRAN�A","Croacia","Monaco",0,0,"-----",{0,0,0},0},
     {120,"Hugo Lloris","Fran�a","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {121,"Pavard","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {122,"Raphael Varane","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {123,"Samuel Umtiti","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {124,"Lucas Digne","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {125,"Blaise Matuidi","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {126,"Ngolo Kante","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {127,"Paul Pogba","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {128,"Antoine Griezman","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {129,"Kylian Mbapp�","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {130,"Olivier Giroud","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {131,"ESCUDO DA AUSTR�LIA","Austr�lia","-----",0,0,"-----",{0,0,0},1},
     {132,"TIME DA AUSTR�LIA","Austr�lia","-----",0,0,"-----",{0,0,0},0},
     {133,"Mathew Ryan","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {134,"Milos Degenek","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {135,"Bailey Wright","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {136,"Ryan Mcgowan","Croacia","Real Madrid",70,1.70,"Meia Atacante",{12,07,1985},0},
     {137,"Mark Miligan","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {138,"Aaron Mooy","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {139,"James Troisi","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {140,"Mile Jedinak","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {141,"Tim Cahill","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {142,"Mathew Leckie","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {143,"Tomi Juric","Croacia","Real Madrid",70,1.70,"Meia",{12,07,1985},0},
     {144,"ESCUDO DO PERU","Peru","-----",0,0,"-----",{0,0,0},1},
     {145,"TIME DO PERU","Peru","-----",0,1.0,"-----",{0,0,0},0},
     {146,"Carlos C�ceda","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {147,"Aldo Corzo","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {148,"Miguel Trauco","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {149,"Luis Adv�ncula","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {150,"Miguel Araujo","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {151,"Christian Cueva","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {152,"Andy Polo","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {153,"Yoshimar Yotun","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {154,"Edison Flores","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {155,"Paolo Guerrero","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {156,"Raul Ruidiaz","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},1},
     {157,"ESCUDO DA DINAMARCA","Dinamarca","-----",0,0,"-----",{0,0,0},1},
     {158,"TIME DA DINAMARCA","Dinamarca","-----",0,0,"-----",{0,0,0},0},
     {159,"Kasper Schmeichel","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {160,"Jannik Vestergard","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {161,"Andreas Christensen","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {162,"Peter Ankersen","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {163,"Christian Eriksen","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {164,"Lasse Schone","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {165,"Pione Sisto","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {166,"Yussuf Poulsen","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {167,"Andreas Cornelius","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {168,"Nicklas Bendtner","Croacia","Monaco",70,1.70,"Goleiro",{12,07,1985},0},
     {169,"Thomas Delaney","Croacia","Real Madrid",70,1.70,"Meia Atacante",{12,07,1985},0},
     {170,"ESCUDO DA ARGENTINA","Argentina","-----",0,0,"-----",{0,0,0},1},
     {171,"TIME DA ARGENTINA","Argentina","-----",0,0,"-----",{0,0,0},0},
     {172,"Sergio Romero","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {173,"Gabriel Mercado","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {174,"Federico Fazio","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {175,"Javier Mascherano","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {176,"Nicol�s Otamendi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {177,"Lucas Biglia","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {178,"Enzo Perez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {179,"Angel Di Maria","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {180,"Ever banega","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {181,"Lionel Messi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {182,"Sergio Aguero","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {183,"ESCUDO DA ISL�NDIA","Isl�ndia","-----",0,0,"-----",{0,0,0},1},
     {184,"TIME DA ISL�NDIA","-----","-----",0,0,"-----",{0,0,0},0},
     {185,"Hannes Halldorsson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {186,"Ragnar Sigurdsson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {187,"K�ri Arnason","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {188,"Ari Skulason","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {189,"Sverrir Ingason","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {190,"Gylfi Sigurdson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {191,"Arnor Ingvi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {192,"Rurik G�slason","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {193,"Orna Kjartansson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {194,"Alfred Finnborgason","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {195,"Bjorn Sigurdason","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {196,"ESCUDO DA CRO�CIA","Cro�cia","-----",0,0,"-----",{0,0,0},1},
     {197,"TIME DA CRO�CIA","Cro�cia","-----",0,0,"-----",{0,0,0},0},
     {198,"Danijel Subasic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {199,"Sime Vrsaljko","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {200,"Domagoj Vida","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {201,"Dejan Lovren","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {202,"Josip Pivaric","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {203,"Ivan Rakitic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {204,"Luka Modric","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {205,"Mateo Kovacic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {206,"Ivan Perisic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {207,"Nikola Kalinic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {208,"Mario Mandzukic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {209,"ESCUDO DA NIG�RIA","Nig�ria","Time",0,0,"-----",{0,0,0},1},
     {210,"TIME DA NIG�RIA","Nig�ria","-----",0,0,"-----",{0,0,0},0},
     {211,"Ikechukwu Ezenwa","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {212,"Elderson Echi�jil�","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {213,"Shehu Abdullahi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {214,"Leon Balogun","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {215,"Ola Aina","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {216,"Ogeny Onazi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {217,"Etebo Oghenekaro","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {218,"Victor Moses","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {219,"Obi Mikel","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {220,"Alex Iwobi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {221,"Ahmed Musa","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {222,"ESCUDO DO BRASIL","Brasil","-----",0,0,"-----",{0,0,0},1},
     {223,"TIME DO BRASIL","Brasil","-----",0,0,"-----",{0,0,0},0},
     {224,"Alisson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {225,"Marcelo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {226,"Danilo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {227,"Miranda","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {228,"Thiago Silva","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {229,"Casemiro","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {230,"Paulinho","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {231,"Willian","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {232,"Philippe Coutinho","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {233,"Neymar","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {234,"Gabriel Jesus","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {235,"ESCUDO DA SUI�A","Sui�a","-----",0,0,"-----",{0,0,0},1},
     {236,"TIME DA SUI�A","Pa�s","-----",0,0,"-----",{0,0,0},0},
     {237,"Yann Sommer","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {238,"Stephan Lichtsteiner","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {239,"Michael Lang","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {240,"Johan Djorou","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {241,"Ricardo Rodriguez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {242,"Fabian Schar","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {243,"Steven Zuber","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {244,"Valon Behrami","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {245,"Xherdan Shaqiri","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {246,"Haris Seferovic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {247,"Admir Mehmedi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {248,"ESCUDO DA COSTA RICA","Costa Rica","-----",0,0,"-----",{0,0,0},1},
     {249,"TIME DA COSTA RICA","Costa Rica","-----",0,0,"-----",{0,0,0},0},
     {250,"Keylor Navas","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {251,"Giancarlo Gonz�lez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {252,"Christian Gamboa","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {253,"Bryan Oviedo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {254,"Francisco Calvo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {255,"Johnny Acosta","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {256,"Bryan Ruiz","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {257,"Celso Borges","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {258,"Randall Azoeifa","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {259,"Joel Campbell","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {260,"Marco Ure�a","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {261,"ESCUDO DA S�RVIA","S�rvia","-----",0,0,"-----",{0,0,0},1},
     {262,"TIME DA S�RVIA","S�riva","-----",0,0,"-----",{0,0,0},0},
     {263,"Vladmir Stojkovic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {264,"Branislav Ivanovic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {265,"Aleksandar Kolarov","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {266,"Antonio Rukavina","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {267,"Matija Nastasic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {268,"Nemanja Matic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {269,"Adem Ljajic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {270,"Nemanja Gudelj","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {271,"Filip Kostic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {272,"Aleksandar Mitrovic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {273,"Aleksandar Prijovic","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {274,"ESCUDO DA ALEMANHA","Alemanha","-----",0,0,"-----",{0,0,0},1},
     {275,"TIME DA ALEMANHA","Alemanha","-----",0,0,"-----",{0,0,0},0},
     {276,"Manuel Neuer","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {277,"Joshua Kimmich","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {278,"Jerome Boateng","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {279,"Matts Hummels","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {280,"Jonas Hector","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {281,"Tony Kroos","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {282,"Leon Goretzka","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {283,"Sami Khedira","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {284,"Mesut Ozil","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {285,"Timo Werner","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {286,"Thomas Muller","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {287,"ESCUDO DO M�XICO","M�xico","-----",0,0,"-----",{0,0,0},1},
     {288,"TIME DO M�XICO","M�xico","-----",0,0,"-----",{0,0,0},0},
     {289,"Guillermo Ochoa","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {290,"Diego Reyes","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {291,"Hector Moreno","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {292,"Miguel Layun","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {293,"Jesus Gallardo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {294,"Andr�s Guardado","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {295,"H�cto Herrera","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {296,"J�sus Corona","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {297,"Hirving Lozano","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {298,"Carlos Vela","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {299,"Javier Hernandez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {300,"ESCUDO DA SU�CIA","Su�cia","-----",0,0,"-----",{0,0,0},0},
     {301,"TIME DA SU�CIA","Su�cia","-----",0,0,"-----",{0,0,0},0},
     {302,"Robin Olsen","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {303,"Mikael Lustig","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {304,"Andreas Granqvist","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {305,"Martin Olsson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {306,"Luwig Augustinson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {307,"Emil Forsberg","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {308,"Jimmy Durmaz","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {309,"Marcus Berg","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {310,"John Guidetti","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {311,"Ola Toivonen","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {312,"Albin Ekdal","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {313,"ESCUDO DA COR�IA","Cor�ia","-----",0,0,"-----",{0,0,0},1},
     {314,"TIME DA COR�IA","Cor�ia","-----",0,0,"-----",{0,0,0},0},
     {315,"Kim Seunggyu","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {316,"Kim Younggwon","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {317,"Kim Jinsu","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {318,"Hong Jeongho","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {319,"Jang Hyunsoo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {320,"Koo Jacheol","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {321,"Ki Sungyueng","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {322,"Nam Taehee","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {323,"Lee Jaesung","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {324,"Heungmin Son","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {325,"Ji Dongwon","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {326,"ESCUDO DA B�LGICA","B�lgica","-----",0,0,"-----",{0,0,0},1},
     {327,"TIME DA B�LGICA","B�lgica","-----",0,0,"-----",{0,0,0},0},
     {328,"Thibaut Courtois","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {329,"Jan Vertonghen","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {330,"Vicent Kompany","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {331,"Thomas Meunier","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {332,"Axel Witsel","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {333,"Kevin de Bruyne","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {334,"Mousa Dembel�","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {335,"Nacer Chadli","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {336,"Eden Hazard","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {337,"Dries Mertens","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {338,"Romelu Lukaku","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {339,"ESCUDO DO PANAM�","Panam�","-----",0,0,"-----",{0,0,0},1},
     {340,"TIME DO PANAM�","Panam�","-----",0,0,"-----",{0,0,0},0},
     {341,"Jaime Penedo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {342,"Michael Murilo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {343,"Fidel Escobar","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {344,"Rom�n Torres","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {345,"Eric Davis","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {346,"Felipe Baloy","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {347,"Edgar Barcenas","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {348,"Armando Cooper","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {349,"Anibal Godoy","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {350,"Alberto Quintero","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {351,"Abdiel Arroyo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {352,"ESCUDO DA TUN�SIA","Tun�sia","-----",0,0,"-----",{0,0,0},1},
     {353,"TIME DA TUN�SIA","Tun�sia","-----",0,0,"-----",{0,0,0},0},
     {354,"Aymen Mathlouthi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {355,"Ali Maaloul","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {356,"Aymen Abdennour","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {357,"Hamdi Naguez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {358,"Yassine Meriah","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {359,"Oussama Haddadi","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {360,"Youssef Msakni","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {361,"Anice Badri","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {362,"Naim Sliti","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {363,"Wahni Khazri","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {364,"Amine Ben Amor","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {365,"ESCUDO DA INGLATERRA","Inglaterra","-----",0,0,"-----",{0,0,0},1},
     {366,"TIME DA INGLATERRA","Inglaterra","-----",0,0,"-----",{0,0,0},0},
     {367,"Jordan Pickford","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {368,"Gary Cahill","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {369,"Kyle Walker","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {370,"Ryan Bertrand","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {371,"Ashley Young","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {372,"Jordan Henderson","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {373,"Adam Lalanna","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {374,"Harry Kane","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {375,"Jamie Vardy","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {376,"Marcus Rashford","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {377,"Jesse Lingard","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {378,"ESCUDO DA POL�NIA","Pol�nia","-----",0,0,"-----",{0,0,0},1},
     {379,"TIME DA POL�NIA","Pol�nia","-----",0,0,"-----",{0,0,0},0},
     {380,"Lukasz Fabianski","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {381,"Lukasz Piszczek","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {382,"Kamil Glik","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {383,"Thiago Cionek","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {384,"Bartosz Berezinski","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {385,"Kamil Grosicki","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {386,"Piotr Zielinski","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {387,"Robert Lewandowski","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {388,"Lukasz Teodorczyk","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {389,"Karol Linetty","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {390,"Maciej Rybus","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {391,"ESCUDO DE SENEGAL","Senegal","-----",0,0,"-----",{0,0,0},1},
     {392,"TIME DE SENEGAL","Senegal","-----",0,0,"-----",{0,0,0},0},
     {393,"Khadim N'diaye","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {394,"Kara Mbodj","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {395,"Kalidou Koulibaily","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {396,"Salif San�","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {397,"Idrissa Gueye","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {398,"Cheikhou kouyate","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {399,"Sadio Man�","Pa�s","Time",0,0,"Posi��o",{0,0,0},1},
     {400,"Moussa Sow","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {401,"Moussa Konat�","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {402,"Keita Bald�","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {403,"Mame Diouf","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {404,"ESCUDO DA COL�MBIA","Col�mbia","-----",0,0,"-----",{0,0,0},1},
     {405,"TIME DA COL�MBIA","Col�mbia","-----",0,0,"-----",{0,0,0},0},
     {406,"David Ospina","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {407,"Yerry Mina","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {408,"Davinson Sanchez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {409,"Santiago Arias","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {410,"Frank Fabra","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {411,"Carlos Sanchez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {412,"James Rodriguez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {413,"Wilmar Barrios","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {414,"Te�filo Gutierez","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {415,"Radamel Falc�o","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {416,"Yimmi Char�","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {417,"ESCUDO DO JAP�O","Jap�o","-----",0,0,"-----",{0,0,0},1},
     {418,"TIME DO JAP�O","Jap�o","-----",0,0,"-----",{0,0,0},0},
     {419,"Eiji Kawashima","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {420,"Masato Morishiege","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {421,"Yuto Nagatomo","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {422,"Gotoku Sakai","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {423,"Tomoaki Makino","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {424,"Maya Yoshida","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {425,"Shinji Kagawa","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {426,"Keisuke Honda","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {427,"Takashi Usami","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {428,"Yuya Osako","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     {429,"Shinji Okazaki","Pa�s","Time",0,0,"Posi��o",{0,0,0},0},
     };

void Mostra_pagina()
{
  int auxiliar6;
  int auxpag,tam_vet,buscafig,veiodapagina,auxiliar10;
  printf("                                                                                             ");
  linha(25,'-');
  printf("\n                                                                                                 ");
  switch (auxiliar7)
  {

      case 0:{printf("COPA RUSSIA 2018\n");break;}
      case 13:{printf("SELE��O DA RUSSIA\n");break;}
      case 26:{printf("SELE��O DA AR�BIA SAUDITA\n");break;}
      case 39:{printf("SELE��O DO EGITO\n");break;}
      case 52:{printf("SELE��O DO URUGUAI\n");break;}
      case 65:{printf("SELE��O DE PORTUGAL\n");break;}
      case 78:{printf("SELE��O DA ESPANHA\n");break;}
      case 91:{printf("SELE��O DE MARROCOS\n");break;}
      case 104:{printf("SELE��O DO IR�\n");break;}
      case 117:{printf("SELE��O DA FRAN�A\n");break;}
      case 130:{printf("SELE��O DA AUSTR�LIA\n");break;}
      case 143:{printf("SELE��O DO PERU\n");break;}
      case 156:{printf("SELE��O DA DINAMARCA\n");break;}
      case 169:{printf("SELE��O DA ARGENTINA\n");break;}
      case 182:{printf("SELE��O DA ISLANDIA\n");break;}
      case 195:{printf("SELE��O DA CRO�CIA\n");break;}
      case 208:{printf("SELE��O DA NIG�RIA\n");break;}
      case 221:{printf("SELE��O DO BRASIL\n");break;}
      case 234:{printf("SELE��O DA SUI�A\n");break;}
      case 247:{printf("SELE��O DA COSTA RICA\n");break;}
      case 260:{printf("SELE��O DA S�RVIA\n");break;}
      case 273:{printf("SELE��O DA ALEMANHA\n");break;}
      case 286:{printf("SELE��O DO M�XICO\n");break;}
      case 299:{printf("SELE��O DA SU�CIA\n");break;}
      case 312:{printf("SELE��O DA COR�IA\n");break;}
      case 325:{printf("SELE��O DA B�LGICA\n");break;}
      case 338:{printf("SELE��O DO PANAM�\n");break;}
      case 351:{printf("SELE��O DA TUN�SIA\n");break;}
      case 364:{printf("SELE��O DA INGLATERRA\n");break;}
      case 377:{printf("SELE��O DA POL�NIA\n");break;}
      case 390:{printf("SELE��O DE SENEGAL\n");break;}
      case 403:{printf("SELE��O DA COL�MBIA\n");break;}
      case 416:{printf("SELE��O DO JAP�O\n");break;}
  }
  printf("                                                                                             ");
  linha(25,'-');
  printf("\n");


  for (auxiliar6=1;auxiliar6<13;auxiliar6++)
  {
      if (auxiliar6==1)
        {
           tam_vet=strlen(jogadores[auxiliar6+auxiliar7].nome);
           linha(tam_vet+4,'-');
           printf("\n| %s | ( %i )  ",jogadores[auxiliar6+auxiliar7].nome,auxiliar6+auxiliar7);
           colada(auxiliar6+auxiliar7,figurinhas_coladas);
           printf("    %s ( %i )",jogadores[auxiliar6+1+auxiliar7].nome,auxiliar6+auxiliar7+1);
           colada(auxiliar6+1+auxiliar7,figurinhas_coladas);
           printf("\n");
           linha(tam_vet+4,'-');
        }
    else
        {
        printf("\n\n\n    %s ( %i )",jogadores[auxiliar6+auxiliar7+1].nome,auxiliar6+auxiliar7+1);
        colada(auxiliar6+auxiliar7+1,figurinhas_coladas);
        }
    }

  switch (auxiliar7)
   {
   case 0:
    { printf("\n\n\n\n\n0-Sair                              1-Informa��es sobre uma figurinha                              2-Proxima pagina\n");
      break;
    }
       case 416:
    {
        printf("\n\n\n\n\n0-Sair                              1-Informa��es sobre uma figurinha                              2-Voltar para o menu\n");
        break;
     }
  default:
    {
     printf("\n\n\n\n\n0-Pagina anterior                   1-Informa��es sobre uma figurinha                              2-Proxima pagina\n");
     break;
    }
   }

if (auxiliar7==416)
{
scanf("%i",&auxpag);
switch (auxpag)
  {  case 2:
      {
          system("cls");
          menu_album();
          break;
      }
    case 0:
        {
            system("cls");
            if (auxiliar7>0)
            {auxiliar7=auxiliar7-13;
            Mostra_pagina();}
            else
            menu_album();
            break;
        }
    case 1:
        {
            printf("\nDigite o numero da figurinha:");
            scanf("%i",&buscafig);
            system("cls");
            Mostrar(buscafig);
            printf("\n\n                               1-Voltar para pagina\n");
            scanf("%i",&auxiliar10);
             while (auxiliar10!=1)
              {
                  scanf("%i",&auxiliar10);
              }
              system("cls");
              Mostra_pagina();




            break;
        }
     default:{
     printf("Digite 0 para voltar e 2 para avan�ar");}
  }}
else
{
   scanf("%i",&auxpag);
switch (auxpag)
  {  case 2:
      {
          system("cls");
          auxiliar7=auxiliar7+13;
          Mostra_pagina();
          break;
      }
    case 0:
        {
            system("cls");
            if (auxiliar7>0)
            {auxiliar7=auxiliar7-13;
            Mostra_pagina();}
            else
            menu_album();
            break;
        }
    case 1:
        {
            printf("\nDigite o numero da figurinha:");
            scanf("%i",&buscafig);
            system("cls");
            Mostrar(buscafig);
            printf("\n\n                               1-Voltar para pagina\n");
            scanf("%i",&auxiliar10);
             while (auxiliar10!=1)
              {
                  scanf("%i",&auxiliar10);
              }
              system("cls");
              Mostra_pagina();




            break;
        }
     default:{
     printf("Digite 0 para voltar e 2 para avan�ar");}
  }
}

}

void Mostrar (int numerodafig)
{
    printf("\n");
    if (jogadores[numerodafig].raro==1)
        printf("Figurinha Brilhante!\n");
    printf("N�mero:     %d\n",jogadores[numerodafig].num_fig);
    printf("Nome:       %s\n",jogadores[numerodafig].nome);
    printf("Dt. nasc:   %d-%d-%d\n",jogadores[numerodafig].nasc.dia,jogadores[numerodafig].nasc.mes,jogadores[numerodafig].nasc.ano);
    printf("Pa�s:       %s\n",jogadores[numerodafig].pais);
    printf("Time atual: %s\n",jogadores[numerodafig].time);
    printf("Peso:       %d kg\n",jogadores[numerodafig].peso);
    printf("Altura:     %.2f m\n",jogadores[numerodafig].altura);
    printf("Posi��o:    %s\n",jogadores[numerodafig].posicao);






}

void ver_se_possui(int num_figurinha, int vetor_figurinhas[600], int vetor_repetidas[600])
{
    int auxiliar1,auxiliar2,auxiliar3,auxiliar4=0;

    for (auxiliar1=0;auxiliar1<600;auxiliar1++)
    {
        if (vetor_figurinhas[auxiliar1]== num_figurinha)
           {
             printf("\nVoc� possui a figurinha %i colada no seu �lbum!\n", num_figurinha);
             auxiliar2=1;
             break;
           }
    }
    if (auxiliar2!=1)
        printf("\nVoc� ainda n�o possui essa figurinha!\n", num_figurinha);

    for (auxiliar3=0;auxiliar3<600;auxiliar3++)
    {
        if (vetor_repetidas[auxiliar3]== num_figurinha)
        { auxiliar4++;
        }

    }
   if (auxiliar4>0,auxiliar4!=1)
    printf("Voc� possui %i repetidas dessa figurinha\n",auxiliar4);
   if (auxiliar4==1)
    printf("Voc� possui %i repetida dessa figurinha\n",auxiliar4);
}


void Compra ()
{
    int i,j,aux,aux3=0,escolha,auxi,aux4,pos;
    int pacotes_comprados=0;
    int pacotes_desejados;
    int moedas;
    moedas=10;
    clock_t t;
    srand((unsigned) clock());

    printf("Voce possui %i moedas",moedas);
    printf("Quantos pacotes gostaria de comprar?\n");
    scanf("%d",&pacotes_desejados);
    if (pacotes_desejados*2 >= moedas)
    {
        pacotes_comprados=pacotes_desejados;
    }
    else
    {
     printf("Voc� n�o possui moedas suficientes");

    }
    moedas=moedas-(2*pacotes_comprados);
    printf("Seu novo numero de moedas e:%i",moedas);
    for (j=1;j <= pacotes_comprados;j++)
    {
        printf("\n\nPACOTE NUMERO: %i\n",j);

        for( i = 0 ; i < 5 ; i++ )
        {

            vetorauxiliar[i]=rand() % 429;
            vetorauxiliar[i]++;
            printf("\nFigurinha Nro:%i",vetorauxiliar[i]);

            for (aux=0; aux<600; aux++ )
              {
                  if (vetorauxiliar[i]==figurinhas_coladas[aux])
                    {
                        printf(" (Repetida)",vetorauxiliar[i]);
                        repetidas[numero_de_repetidas]=vetorauxiliar[i];
                        numero_de_repetidas++;
                        aux3=1;
                        break;
                     }


                       }
            if (aux3!=1)
            {
                figurinhas_coladas[numero_do_vetor]=vetorauxiliar[i];


                switch(user_logon)
                {
                case 1:
                       {
                        user0_co = fopen("user0_co.txt","a+");
                        fprintf(user0_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user0_co);

                        break;
                        }

                case 2:
                        {

                        user1_co = fopen("user1_co.txt","a+");
                        fprintf(user1_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user1_co);

                        break;
                        }

                case 3:
                       {

                        user2_co = fopen("user2_co.txt","a+");
                        fprintf(user2_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user2_co);
                        break;

                        }

                case 4:
                    {

                        user3_co = fopen("user1_co.txt","a+");
                        fprintf(user3_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user3_co);
                        break;
                    }

                case 5:
                        {

                          user4_co = fopen("user4_co.txt","a+");
                          fprintf(user4_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                          fclose(user4_co);
                          break;
                        }

                case 6:
                       {

                        user5_co = fopen("user5_co.txt","a+");
                        fprintf(user5_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user5_co);
                        break;
                       }

                case 7:
                       {

                        user6_co = fopen("user6_co.txt","a+");
                        fprintf(user6_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user6_co);
                        break;
                        }
                }

                numero_do_vetor++;

            }
            aux3=0;



            }
        }

ordena_o_vetor(figurinhas_coladas);
ordena_o_vetor(repetidas);

switch(user_logon)
                {
                case 1:
                       {
                        user0_co = fopen("user0_co.txt","a+");
                        while(1)
                        {
                            int r = (char)fgetc(user0_co);
                            int k = 0;
                            i=0;
                            while( !feof(user0_co))
                            {	//read till , or EOF
                                figurinhas_coladas[i] = r;			//store in array
                                r = (char)fgetc(user0_co);
                            }
                                figurinhas_coladas[i]=0;		//make last character of string null
                                if(feof(user0_co)){		//check again for EOF
                                break;
                            }
                            i++;
                        }
                        fclose(user0_co);

                        break;
                        }

                case 2:
                        {

                        user1_co = fopen("user1_co.txt","a+");
                        fprintf(user1_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user1_co);

                        break;
                        }

                case 3:
                       {

                        user2_co = fopen("user2_co.txt","a+");
                        fprintf(user2_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user2_co);
                        break;

                        }

                case 4:
                    {

                        user3_co = fopen("user1_co.txt","a+");
                         while(1)
                        {
                            int r = (char)fgetc(user0_co);
                            int k = 0;
                            i=0;
                            while( !feof(user0_co))
                            {	//read till , or EOF
                                figurinhas_coladas[i] = r;			//store in array
                                r = (char)fgetc(user0_co);
                            }
                                figurinhas_coladas[i]=0;		//make last character of string null
                                if(feof(user0_co)){		//check again for EOF
                                break;
                            }
                            i++;
                        }
                        fclose(user3_co);
                        break;
                    }

                case 5:
                        {

                          user4_co = fopen("user4_co.txt","a+");
                          while(1)
                        {
                            int r = (char)fgetc(user4_co);
                            int k = 0;
                            i=0;
                            while( !feof(user4_co))
                            {	//read till , or EOF
                                figurinhas_coladas[i] = r;			//store in array
                                r = (char)fgetc(user0_co);
                            }
                                figurinhas_coladas[i]=0;		//make last character of string null
                                if(feof(user4_co)){		//check again for EOF
                                break;
                            }
                            i++;
                        }
                          fclose(user4_co);
                          break;
                        }

                case 6:
                       {

                        user5_co = fopen("user5_co.txt","a+");
                        fprintf(user5_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user5_co);
                        break;
                       }

                case 7:
                       {

                        user6_co = fopen("user6_co.txt","a+");
                        fprintf(user6_co,"%i\n",figurinhas_coladas[numero_do_vetor]);
                        fclose(user6_co);
                        break;
                        }
                }



printf("\nSuas figurinhas novas foram coladas com sucesso!\n");
                  printf("                                                    1-Voltar ao menu\n");
                  printf("                                                    2-Visualizar repetidas\n");
                  printf("                                                    3-Visualizar faltantes\n");
                  printf("                                                    4-Comprar mais pacotes\n");
                  scanf("%i",&escolha);

                  switch (escolha)
                  {
                    case 1:
                        {
                           system ("cls");
                           menu_album();

                        }

                    case 2:
                        {
                            system("cls");
                            MostraRepetidas(repetidas);
                            break;

                        }

                    case 3:
                        {
                            system("cls");
                            figurinhas_faltantes();
                            break;
                        }
                    case 4:
                        {
                            system("cls");
                            Compra();
                            break;
                        }
                  }

}


void MostraRepetidas(int vetor_qualquer[600])
{
    int cont1,tam_vet,cont2,auxiliar_opcao;
    tam_vet=0;

    for (cont1=0;vetor_qualquer[cont1]!=0;cont1++)
    {
        tam_vet++;
    }


    printf("\nESSAS S�O SUAS FIGURINHAS REPETIDAS:\n");
    for (cont2=0;cont2<tam_vet;cont2++)
    {
              printf("\nFigurinha Nro:%i\n",vetor_qualquer[cont2]);
    }


printf("\n\n\n\n\n\n\n");
printf("1-Voltar ao menu\n");
scanf("%i",&auxiliar_opcao);
switch (auxiliar_opcao)
{
case 1 :
    {
        system("cls");
        menu_album();
    }
}



}

void linha (int num, char ch)
{
    int i;
    for (i=1; i<= num ; i++)
        putchar (ch);
}

void colada(int numerodafigura,int vetortantofaz[600])
{
    int i;

  for (i=0;i<600;i++)
  {if (vetortantofaz[i]==numerodafigura)
  {

      printf(" (Colada)");
      break;
  }}



}

void figurinhas_faltantes() //Depende do numero de figurinhas
{
    int i,j,auxiliar9,opcao1;
    for (i=1;i<430;i++)
    {
        auxiliar9=0;
        for (j=0;j<500;j++)
        {
         if(jogadores[i].num_fig==figurinhas_coladas[j])
             {
                auxiliar9=1;
                break;
             }
        }

       if (auxiliar9==0)
        printf("\n(%i)  %s",jogadores[i].num_fig,jogadores[i].nome);
    }

    printf("\n                                        1-Voltar ao menu\n");
    printf("                                        2-Comprar Pacotes\n");
    scanf("%i",&opcao1);

    switch (opcao1)

    {
     case 1:
        {
            system("cls");
            menu_album();

        }
       case 2:

         {
            system("cls");
            Compra();

         }

    }



}


void atualiza_coladas()
{
    int vetor_coladas[1000]={0},auxi=0,teste,i=0,x;

    user0_r= fopen("user0_r.txt","a+");

    for (i=0;i<600;i++)
    {fscanf(user0_r,"%i",&vetor_coladas[i]);
    }

     for (i=0;i<600;i++)
     {
         figurinhas_coladas[i]=vetor_coladas[i];

     }




    fclose(user0_r);






}

void ordena_o_vetor( int vetor[1000])
{  int x,y,z,tam_vet,aux,aux2=0;


for (aux=0;vetor[aux]!=0;aux++)
{
    aux2++;
}
tam_vet=aux2;



x=0;
while (x<tam_vet)
{
 y=x+1;

  while (y<tam_vet)
    { if (vetor[x]>vetor[y])
        {
          aux=vetor[x];
          vetor[x]=vetor[y];
          vetor[y]=aux;
        }
    y=y+1;
}
x=x+1;
}

}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    SetConsoleTitle("�LBUM DA COPA 2018");
    numero_do_vetor=0;
    char c;
    iniciar_vetor();
    linha(140,'+');//ESCRITA COPA 2018
    printf("\n");
    linha(140,'+');
    printf("\n\n\n");
    linha(14,' ');linha(9,'O');linha(5,' ');linha(8,'O');linha(4,' ');linha(10,'O');linha(6,' ');linha(8,'O');linha(16,' ');linha(10,'O');linha(6,' ');linha(8,'O');linha(4,' ');linha(4,'O');linha(4,' ');linha(8,'O');printf("\n");
    linha(13,' ');linha(11,'O');linha(3,' ');linha(10,'O');linha(3,' ');linha(11,'O');linha(4,' ');linha(10,'O');linha(15,' ');linha(11,'O');linha(4,' ');linha(10,'O');linha(3,' ');linha(4,'O');linha(3,' ');linha(10,'O');printf("\n");
    linha(12,' ');linha(12,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(12,'O');linha(2,' ');linha(12,'O');linha(14,' ');linha(12,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');printf("\n");
    linha(12,' ');linha(12,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(5,' ');
    linha(4,'O');linha(1,' ');linha(5,'O');linha(2,' ');linha(5,'O');linha(14,' ');linha(12,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');printf("\n");
    linha(12,' ');linha(5,'O');linha(9,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(6,' ');linha(3,'O');linha(1,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(22,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');printf("\n");
    linha(12,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(6,' ');linha(3,'O');linha(1,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(22,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');printf("\n");
    linha(12,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(5,' ');linha(4,'O');linha(1,' ');linha(12,'O');linha(16,' ');linha(10,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(12,'O');printf("\n");
    linha(12,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(12,'O');linha(2,' ');linha(12,'O');linha(15,' ');linha(11,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(3,' ');linha(10,'O');printf("\n");
    linha(12,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(11,'O');linha(3,' ');linha(12,'O');linha(14,' ');linha(10,'O');linha(4,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(8,'O');printf("\n");
    linha(12,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(10,'O'); linha(4,' ');linha(12,'O');linha(14,' ');linha(8,'O');linha(6,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(3,' ');linha(10,'O');printf("\n");
    linha(12,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(14,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');printf("\n");
    linha(12,' ');linha(5,'O');linha(9,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(14,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');printf("\n");
    linha(12,' ');linha(12,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(14,' ');linha(12,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(4,'O');linha(4,' ');linha(4,'O');printf("\n");
    linha(12,' ');linha(12,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(14,' ');linha(12,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(4,'O');linha(2,' ');linha(5,'O');linha(2,' ');linha(5,'O');printf("\n");
    linha(13,' ');linha(11,'O');linha(3,' ');linha(10,'O');linha(3,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(14,' ');linha(12,'O');linha(3,' ');linha(10,'O');linha(3,' ');linha(4,'O');linha(3,' ');linha(10,'O');printf("\n");
    linha(14,' ');linha(9,'O');linha(5,' ');linha(8,'O');linha(4,' ');linha(4,'O');linha(10,' ');linha(4,'O');linha(4,' ');linha(4,'O');linha(14,' ');linha(12,'O');linha(4,' ');linha(8,'O');linha(4,' ');linha(4,'O');linha(4,' ');linha(8,'O');
    printf("\n\n\n");
    linha(140,'+');
    printf("\n");
    linha(140,'+');
    printf("\n");
    ENTER();
    menu_cadastro();
    printf("�LBUM DA COPA 2018\n");
    atualiza_coladas();
    menu_album();
}



