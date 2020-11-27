#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Estrutura para data e hora locais
typedef struct data{
  int hora, minuto, segundo;
  int ano, mes, dia;
  char data_atual[30];
}Data;


typedef struct adm{
unsigned long int codigo;
unsigned long int senha;
unsigned long int cargo;
}ADM;

typedef struct agenda {

  int mes[5], dia[5], hora[5];
  int contador;

}Agenda;

typedef struct ficha {

char receituario[500];
char obs[500];
char atestado[500];

}Ficha;

typedef struct lista{
/*--------funcion�rios--------*/
  char f_nome[100];
  char f_endereco[100];
  char f_sexo[11];
  char f_CPF[11];
  char CRM[20];
  int especialidade;
  int cargo;
  unsigned long int senha;
  unsigned long int f_codigo;
/*---------pacientes--------*/
  char nome[100];
  char endereco[100];
  char sexo[20];
  char CPF[11];
  char RG[9];
  char data_cadastro[30];
  char data_nascimento[11];
  unsigned long int codigo;
  struct data nascimento;
  struct agenda agendamento;
  struct ficha ficha_medica;
  struct adm login_adm;
  struct lista *prox;
}Lista;

//Criando nomes globais para as listas
  Data d;
  Lista paciente;
  Lista funcionario;

//Zerando o c�digo e o contador somente quando o programa � iniciado
  codigo = 0;
  contador = 0;

//Criando o primeiro ponteiro para apontar aos demais elementos
  Lista *primeiro = NULL;


//Declara��o de fun��es (prot�tipos).
  Lista *inserir_adm();
  void inicio();
  void valida_Login(Lista *primeiro);
  void menu_Medico(); //63
  void agenda();
  void menu_Secretario();//111
  void menu_Administrador();
  void Cadastros();//146
  void Agendamentos();//232
  Lista* inserir_funcionario(Lista* primeiro);
  Lista* inserir_paciente(Lista* primeiro);//293
  void listar_paciente(Lista* primeiro);//358
  void listar_funcionario(Lista* primeiro);//358
  Lista* buscar(Lista* primeiro);//387
  Lista* excluir_paciente(Lista* primeiro);//427
  Lista* excluir_funcionario(Lista *primeiro);
  void alterar_paciente(Lista* primeiro);//469
  void alterar_funcionario(Lista* primeiro);
  void data();//519

  void agendar () {
  //ponteiro para apontar o atual ao primeiro elemento da lista (como o i = 0 para vetores, aponta para o primeiro campo para apontar aos pr�ximos, poss�velmente).
  Lista *atual = primeiro;
  Lista *atual_funcionario = primeiro;
  unsigned long int codigo_valida = 0, codigo_medico = 0;
  int i = 0;

  //Requisitando e lendo o c�digo do paciente a ser alterado.
  printf("  C�digo do paciente para efetuar o agendamento: ");
  fflush(stdin);
  scanf("%u",&codigo_valida);


  //Procurando o paciente na lista.
  while(atual != NULL && atual->codigo != codigo_valida){
  atual = atual->prox;
  }


  if(atual != NULL) {
  //Listando os dados do paciente.
  printf("\n  Paciente Encontrado!\n");
  printf("\n  Nome: %s", atual->nome);
  printf("\n  Endere�o: %s", atual->endereco);
  printf("\n  Sexo: %s", atual->sexo);
  printf("\n  Data de nascimento: %d/%d/%d", atual->nascimento.dia, atual->nascimento.mes, atual->nascimento.ano);
    //printf("Documento: %s \n\n", atual->CPF);

    printf("\n  Escolha a especialidade: \n");
    printf("  (1) Cardiologia\n  (2) Endocrinologia\n  (3) Neurologia\n  (4) Nutri��o\n  (5) Psicologia da Sa�de\n  (6) Psiquiatria\n");
    do{
      printf("\n  Informe um n�mero v�lido: ");
      fflush(stdin); scanf("%d", &funcionario.especialidade);
  }while(funcionario.especialidade != 1 && funcionario.especialidade != 2 && funcionario.especialidade != 3 && funcionario.especialidade != 4 && funcionario.especialidade != 5 && funcionario.especialidade != 6);


        //Imprimindo os funcion�rios da lista, e suas repectivas informa��es.
       for(atual_funcionario = primeiro; atual_funcionario != NULL; atual_funcionario = atual_funcionario->prox){
            if (atual_funcionario->cargo == 2 && funcionario.especialidade == atual_funcionario->especialidade) {
      printf("\n  Nome: %s", atual_funcionario->f_nome);
      printf("\n  Sexo: %s", atual_funcionario->f_sexo);
      printf("\n  CRM: %s", atual_funcionario->CRM);
      printf("\n  C�digo: %u", atual_funcionario->f_codigo);
        }
    }

    atual_funcionario = primeiro;
    printf("\n\n  Informe o c�digo do m�dico que realizar� a consulta: ");
    fflush(stdin); scanf("%d", &codigo_medico);
      while(atual_funcionario != NULL && atual_funcionario->f_codigo != codigo_medico)
      //Procurando o m�dico na lista
      atual_funcionario = atual_funcionario->prox;
      }
      if (atual_funcionario == NULL) {
        printf("\n\n  M�dico n�o encontrado.\n");
        system("pause");
        system("cls");
        Agendamentos();
      }

      if(atual_funcionario != NULL && atual != NULL) {
        int  i, cont = 0, dia, mes, ano, agen=0;
    printf("\n\n\tCALENDARIO DE 2021");
    ano = 2021;

    printf("\n\n  Informe o mes: ");
    scanf("%d", &mes);
    printf("\n\n");

        switch(mes){

            case 1:
                printf("           JANEIRO 2021       \n");
                printf(" |-----------------------------|\n");
                printf(" | dom seg ter qua qui sex sab |\n");
                printf(" | --  --  --  --  --   1   2  |\n");
                printf(" |  3   4   5   6   7   8   9  |\n");
                printf(" | 10  11  12  13  14  15  16  |\n");
                printf(" | 17  18  19  20  21  22  23  |\n");
                printf(" | 24  25  26  27  28  29  30  |\n");
                printf(" | 31  --  --  --  --  --  --  |\n");
                printf(" |-----------------------------|\n");

                do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);
                    if(dia<1 || dia>31){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 3 || dia == 10 || dia == 17 || dia == 24 || dia == 31){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }

                    else if(dia == 1){
                        printf("  FECHADO! Ano novo\n");
                        cont = 1;
                    }
                    else  {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }

                    }while(cont == 1);
                    break;


            case 2:
                printf("           FEVEREIRO 2021       \n");
                printf(" |-----------------------------|\n");
                printf(" | dom seg ter qua qui sex sab |\n");
                printf(" | --   1   2   3   4   5   6  |\n");
                printf(" |  7   8   9  10  11  12  13  |\n");
                printf(" | 14  15  16  17  18  19  20  |\n");
                printf(" | 21  22  23  24  25  26  27  |\n");
                printf(" | 28  --  --  --  --  --  --  |\n");
                printf(" |-----------------------------|\n");

                do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 28){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 7 || dia == 14 || dia == 21 || dia == 28){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 15 || dia == 16){
                        printf("FECHADO!\n dias 15 e 16 Carnaval!\n");
                        cont = 1;
                    }
                    else if(dia == 17){
                        printf("  FECHADO!\n Feriado de Cinzas!\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                    }while(cont == 1);
                    break;

            case 3:
                printf("           MAR�O 2021       \n");
                printf(" |-----------------------------|\n");
                printf(" | dom seg ter qua qui sex sab |\n");
                printf(" | --   1   2   3   4   5   6  |\n");
                printf(" |  7   8   9  10  11  12  13  |\n");
                printf(" | 14  15  16  17  18  19  20  |\n");
                printf(" | 21  22  23  24  25  26  27  |\n");
                printf(" | 28  29  30  31  --  --  --  |\n");
                printf(" |-----------------------------|\n");

                do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 31){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 7 || dia == 14 || dia == 21 || dia == 28){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else {
                            printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                }while(cont == 1);
            break;

            case 4:
                printf("           ABRIL 2021       \n");
                printf(" |-----------------------------|\n");
                printf(" | dom seg ter qua qui sex sab |\n");
                printf(" | --  --  --  --   1   2   3  |\n");
                printf(" |  4   5   6   7   8   9  10  |\n");
                printf(" | 11  12  13  14  15  16  17  |\n");
                printf(" | 18  19  20  21  22  23  24  |\n");
                printf(" | 25  26  27  28  29  30  --  |\n");
                printf(" |-----------------------------|\n");

                do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 30){
                        printf("Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 11 || dia == 18 || dia == 25){
                        printf("FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 2){
                        printf("  FECHADO!\n Feriado Paix�o de Cristo!\n");
                        cont = 1;
                    }
                    else if(dia == 4){
                        printf("  FECHADO! Domingo de P�scoa\n");
                        cont = 1;
                    }
                    else if(dia == 21){
                        printf("  FECHADO!\n Feriado Tiradentes!\n");
                        cont = 1;
                    }
                    else {
                            printf("  dia %d Ok\n", dia);
                    cont = 0;
                    }

                    }while(cont == 1);
                    break;

            case 5:
                    printf("            MAIO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" | --  --  --  --  --   --  1  |\n");
                    printf(" |  2   3   4   5   6   7   8  |\n");
                    printf(" |  9  10  11  12  13  14  15  |\n");
                    printf(" | 16  17  18  19  20  21  22  |\n");
                    printf(" | 23  24  25  26  27  28  29  |\n");
                    printf(" | 30  31  --  --  --  --  --  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 31){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 2 || dia == 16 || dia == 23 || dia == 30){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 1){
                        printf("  FECHADO!\n Feriado Dia do Trabalho!\n");
                        cont = 1;
                    }
                    else if(dia == 9){
                        printf("  FECHADO! Domingo Dia das M�es\n");
                        cont = 1;
                    }

                    else {
                            printf("  dia %d Ok\n", dia);
                    cont = 0;
                    }

                    }while(cont == 1);
                    break;

            case 6:
                    printf("           JUNHO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" | --  --   1   2   3   4   5  |\n");
                    printf(" |  6   7   8   9  10  11  12  |\n");
                    printf(" | 13  14  15  16  17  18  19  |\n");
                    printf(" | 20  21  22  23  24  25  26  |\n");
                    printf(" | 27  28  29  30  --  --  --  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 30){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 6 || dia == 13 || dia == 20 || dia == 27){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 3){
                        printf("  FECHADO!\n Feriado Corpus Christi!\n");
                        cont = 1;
                    }
                    else if(dia == 12){
                        printf("  FECHADO! Dia dos Namorados\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                    }while(cont == 1);
                    break;
            case 7:
                    printf("           JULHO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" | --  --  --  --   1   2   3  |\n");
                    printf(" |  4   5   6   7   8   9  10  |\n");
                    printf(" | 11  12  13  14  15  16  17  |\n");
                    printf(" | 18  19  20  21  22  23  24  |\n");
                    printf(" | 25  26  27  28  29  30  31  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 31){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 4 || dia == 11 || dia == 18 || dia == 25){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                    }while(cont == 1);
                    break;

            case 8:
                    printf("           AGOSTO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" |  1   2   3   4   5   6   7  |\n");
                    printf(" |  8   9  10  11  12  13  14  |\n");
                    printf(" | 15  16  17  18  19  20  21  |\n");
                    printf(" | 22  23  24  25  26  27  28  |\n");
                    printf(" | 29  30  31  --  --  --  --  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 31){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 1 || dia == 15 || dia == 22 || dia == 29){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 8){
                        printf("  FECHADO!\n Domingo Dia dos Pais!\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                    }while(cont == 1);
                    break;

            case 9:
                    printf("           SETEMBRO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" | --  --   --  1   2   3   4  |\n");
                    printf(" |  5   6   7   8   9  10  11  |\n");
                    printf(" | 12  13  14  15  16  17  18  |\n");
                    printf(" | 19  20  21  22  23  24  25  |\n");
                    printf(" | 26  27  28  29  30  --  --  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n   Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 30){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 5 || dia == 12 || dia == 19 || dia == 26){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 7){
                        printf("  FECHADO!\n Feriado de Independ�ncia!\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                    }while(cont == 1);
                    break;

            case 10:
                    printf("           OUTUBRO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" | --  --  --  --  --   1   2  |\n");
                    printf(" |  3   4   5   6   7   8   9  |\n");
                    printf(" | 10  11  12  13  14  15  16  |\n");
                    printf(" | 17  18  19  20  21  22  23  |\n");
                    printf(" | 24  25  26  27  28  29  30  |\n");
                    printf(" | 31  --  --  --  --  --  --  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 31){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 3 || dia == 10 || dia == 17 || dia == 24 || dia == 31){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 12){
                        printf("  FECHADO!\n Feriado Nossa Senhora de Aparecida!\n Dia das Crian�as!\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                    }while(cont == 1);
                    break;


           case 11:
                    printf("           NOVEMBRO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" | --   1   2   3   4   5   6  |\n");
                    printf(" |  7   8   9  10  11  12  13  |\n");
                    printf(" | 14  15  16  17  18  19  20  |\n");
                    printf(" | 21  22  23  24  25  26  27  |\n");
                    printf(" | 28  29  30  --  --  --  --  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 30){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 7 || dia == 14 || dia == 21 || dia == 28){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 15){
                        printf("  FECHADO!\n Feriado Proclama��o da Rep�blica!\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }
                    }while(cont == 1);
                    break;

            case 12:
                    printf("           DEZEMBRO 2021       \n");
                    printf(" |-----------------------------|\n");
                    printf(" | dom seg ter qua qui sex sab |\n");
                    printf(" | --  --   --  1   2   3   4  |\n");
                    printf(" |  5   6   7   8   9  10  11  |\n");
                    printf(" | 12  13  14  15  16  17  18  |\n");
                    printf(" | 19  20  21  22  23  24  25  |\n");
                    printf(" | 26  27  28  29  30  31  --  |\n");
                    printf(" |-----------------------------|\n");

                    do{
                    printf("\n  Informe o dia: ");
                    scanf("%d", &dia);

                    if(dia < 1 || dia > 31){
                        printf("  Dia Inexistente!\n");
                        cont = 1;
                    }
                    else if(dia == 5 || dia == 12 || dia == 19 || dia == 26){
                        printf("  FECHADO! Domingo\n");
                        cont = 1;
                    }
                    else if(dia == 25){
                        printf("  FECHADO!\n Feriado Natal!\n");
                        cont = 1;
                    }
                    else if(dia == 31){
                        printf("  FECHADO!\n V�spera de Ano Novo!\n");
                        cont = 1;
                    }
                    else {
                        printf("  dia %d Ok\n", dia);
                        cont = 0;
                    }

                    }while(cont == 1);
                    break;

            default:
                printf("  Mes n�o encontrado!\n");
                system("pause");
                system("cls");
                break;
        }

    paciente.agendamento.contador = atual->agendamento.contador;

    if (paciente.agendamento.contador == 4) {
        printf("\n  Limite de agendamentos excedido.\n");
        system("pause");
        system("cls");
        Agendamentos();
    }


    paciente.agendamento.dia[paciente.agendamento.contador] = dia;

    printf("  +-----------------+-----------------+\n");
    printf("  | M |  (8)  8:00  | T |  (13) 13:00  |\n");
    printf("  | A |  (9)  9:00  | A |  (14) 14:00  |\n");
    printf("  | N |  (10) 10:00 | R |  (15) 15:00  |\n");
    printf("  | H |  (11) 11:00 | D |  (16) 16:00  |\n");
    printf("  | � |   -- -- --  | E |   -- -- --  |\n");
    printf("  +-----------------+-----------------+\n\n");

    do {
    printf("\n  Escolha uma hora de 8 a 16: ");
    scanf("%d", &paciente.agendamento.hora[paciente.agendamento.contador]);
    }while(paciente.agendamento.hora[paciente.agendamento.contador] < 8 && paciente.agendamento.hora[paciente.agendamento.contador] > 16);


    //Adicionando as informa��es do agendamendo ao paciente
    atual->agendamento.contador++;
    atual->agendamento.dia[atual->agendamento.contador] = paciente.agendamento.dia[paciente.agendamento.contador];
    atual->agendamento.hora[atual->agendamento.contador] = paciente.agendamento.hora[paciente.agendamento.contador];
    }

  //Mensagem caso o paciente n�o seja encontrado.
  if(atual == NULL)
  printf("\n  paciente n�o encontrado.\n");
  system("pause");
  }

 //Fun��o do tipo Lista (estrutura) para inserir o primeiro login do Administrador
Lista* inserir_adm (Lista *primeiro){
  //Cria��o de uma lista que aponta para o primeiro elemento nulo
  Lista *atual = primeiro;

    funcionario.login_adm.cargo = 0;
    funcionario.login_adm.senha = 123456;
    funcionario.login_adm.codigo = 123456;

    //Alocando os espa�os e guardando as informa��es do paciente.
    Lista* Novofuncionario = (Lista*) malloc (sizeof(Lista));

    Novofuncionario->cargo = funcionario.login_adm.cargo;
    Novofuncionario->senha = funcionario.login_adm.senha;
    Novofuncionario->f_codigo = funcionario.login_adm.codigo;
    Novofuncionario->prox = primeiro;
    system("cls");
    return Novofuncionario;
}

//Programa principal
void main(Lista *primeiro) {
  //Para o programa suportar o teclado ABNT2
  setlocale(LC_ALL, "portuguese");
  //Ponteiro para apontar a lista (atual) ao primeiro elemento (nulo) da lista
  Lista *atual = primeiro;
      primeiro = inserir_adm(primeiro);
      inicio();
}

void inicio () {
  char op;

  do{

    printf(" *----------------------------------------------------------------------------*\n");
    printf(" | ");printf("\t\t\t              Inicio");printf("\t\t                      |\n");
    printf(" *----------------------------------------------------------------------------*\n");

  //Menu de op��es da tela inicial
  printf("  <1> Para efetuar o login\n");
  printf("  <S> Para sair do programa\n\n");

  //Lendo a op��o do menu
  printf("  Escolha uma op��o: ");
  op = getch();
  system("cls");

  switch (op) {
    case '1': //Levar para o procedimento de valida��o de login
              valida_Login(primeiro);

    case 's': //Fechar o programa
              //exit(0);
              system("taskkill/IM cb_console_runner.exe"); //Fechar o programa.

    default: printf("\n\n  Op��o inv�lida.\n");
                    system("pause");
                    system("cls");
              break;
  }
}while(op != '1');

}

//Procedimento para validar o login
void valida_Login(Lista *primeiro) {

  //Limpar a tela
  system("cls");

  //Ponteiro para apontar atual ao primeiro elemento (nulo) da lista
  Lista *atual = primeiro;

  //Vari�veis
  unsigned long int f_codigo = 0;
  unsigned long int valida_senha;


do{
  printf(" *----------------------------------------------------------------------------*\n");
  printf(" | ");printf("\t\t\t            Login");printf("\t\t                      |\n");
  printf(" *----------------------------------------------------------------------------*\n");

    //Requisitando e lendo o c�digo do paciente a ser alterado.
    printf("\n\n  C�digo do funcion�rio: ");
     fflush(stdin);
    scanf("%u",&f_codigo);

    printf("  Senha: ");
    fflush(stdin); scanf("%u", &valida_senha);

    //Para o login do ADM
    if (funcionario.login_adm.codigo == f_codigo) {
      if (funcionario.login_adm.senha == valida_senha) {
        system("cls");
        menu_Administrador();
        }
    }

    //Procurando o funcionario na lista.
    while(atual != NULL && atual->f_codigo != f_codigo){
      atual = atual->prox;
      /*Para enquanto atual n�o for nulo (tiver dados preenchidos) e para enquanto atual->f_codigo (ponteiro para o "atual" c�digo armazenado na lista)
       for diferente do c�digo inderido no requisito (linha ), o atual aponta para o pr�ximo elemento da lista.*/
    }

            if(atual == NULL){
      printf("\n  funcion�rio n�o encontrado.\n");
          system("  pause");
           system("cls");
            inicio();
      }



    //Validando a senha e direcionando para a respectiva tela a partir do cargo (informado ao cadastrar um funcion�rio)
    if (valida_senha == atual->senha) {
        system("cls");
      if(atual->cargo == 1)
        menu_Secretario();
      if(atual->cargo == 2)
        menu_Medico();
    }

    if(valida_senha != atual->senha) {
        printf("\n  Senha incorreta.\n");
        system("  pause");
        system("cls");
        inicio();
    }
    //Mensagem caso o funcionario n�o seja encontrado.
  }while (atual != NULL);
}

//Procedimento para criar a tela do Administrador
void menu_Administrador() {

  //Vari�veis
  char op;

  //Artif�cio para repetir as op��es do menu enquando n�o for digitada a para voltar
  while(op != 'v'){
    //Menu de opcoes
    printf(" *----------------------------------------------------------------------------*\n");
    printf(" | ");printf("\t\t\t     Bem-vindo(a), ADM");printf("\t\t                      |\n");
    printf(" *----------------------------------------------------------------------------*\n");
    printf("  <1> Para inserir funcion�rios\n");
    printf("  <2> Para excluir funcion�rios\n");
    printf("  <3> Para listar funcion�rios\n");
    printf("  <4> Para alterar dados de funcion�rios\n");
    printf("  <V> Para voltar ao in�cio\n\n");

    //Lendo a op��o do menu
    printf("  Escolha uma op��o: ");
    fflush(stdin);
    op = getch();

    switch (op) {
      case '1': //Apontanto o ponteiro primeiro para a fun��o inserir_funcionario()
              system("cls");
    printf(" *----------------------------------------------------------------------------*\n");
    printf(" | ");printf("\t\t\t     NOVO CADASTRO DE FUNCION�RIO");printf("\t\t      |\n");
    printf(" *----------------------------------------------------------------------------*\n");
              primeiro = inserir_funcionario(primeiro);
              break;


      case '2': system("cls");
                    primeiro = excluir_funcionario(primeiro);

      case '3':  //Chamando o procedimento listar_funcionario()
                    system("cls");
                    printf(" *----------------------------------------------------------------------------*\n");
                    printf(" | ");printf("\t\t\t     FUNCION�RIOS CADASTRADOS");printf("\t\t      |\n");
                    printf(" *----------------------------------------------------------------------------*\n");
                    listar_funcionario(primeiro);

      case '4':
      system("cls");
      printf(" *----------------------------------------------------------------------------*\n");
      printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");
      alterar_funcionario(primeiro);


      case 'V':
      case 'v': //Artif�cio para aceitar tanto mai�scula como min�scula
              system("cls");
              //Voltar ao in�cio do programa
              inicio();
              break;

      default: //Mensagem para caso o usu�rio digite uma op��o inv�lida
               printf("\n  Escolha uma op��o v�lida.\n");
               system("cls");
               break;
    }
  }
}

//Procedimento para criar a tela do M�dico
void menu_Medico() {

  //Vari�veis
  char op_med;

  //Menu de opcoes
  printf(" *----------------------------------------------------------------------------*\n");
  printf(" | ");printf("\t\t\t     Bem-vindo(a), Dr.(a)");printf("\t\t              |\n");
  printf(" *----------------------------------------------------------------------------*\n");
  printf("\t\t\t         |   MENU   ");printf("|\t\t\t\t\n\n");
  printf("\t\t   |-----------------------------------|\n");
  printf("\t\t   | <1>  Agenda                       |\n");
  printf("\t\t   |-----------------------------------|\n");
  printf("\t\t   | <2>  Buscar                       |\n");
  printf("\t\t   |-----------------------------------|\n");
  printf("\t\t   | <S>  Sair                         |\n");
  printf("\t\t   |-----------------------------------|");
  printf("\n\n\n\n");

  do {
      printf("\t\t   Escolha uma op��o: ");

      //Lendo a op��o do menu
      fflush(stdin);
      op_med = getch();

      //Menu de opcoes
      switch(op_med) {
      case '1': //Chamando o procedimento para listar os agendamentos do m�dico
                system("cls");
              agenda();
              break;

      case '2': //Chamando o procedimento para buscar a ficha m�dica do paciente
                system("cls");
                primeiro = buscar(primeiro);
                break;

      case 'S': //Artif�cio para aceitar tanto mai�scula como min�scula
      case 's':
              //Voltar ao in�cio do programa
              inicio();
              break;

      default: //Mensagem para caso o usu�rio digite uma op��o inv�lida
              printf("\n  Escolha uma op��o v�lida.\n");
              system("cls");
              break;
      }
  }while(op_med != 's');
}

void agenda() {
//Ponteiro para percorrer a lista sem perder a refer�ncia do primeiro elemento da lista.
  Lista* atual;

  int i;

  //Imprimindo os pacientes da lista, e suas repectivas informa��es.
  for(atual = primeiro; atual != NULL; atual = atual->prox){
    if (atual->cargo != 1 && atual->cargo != 2 && atual->cargo != 3) {
       // if(atual->agendamento.especialidade == atual->especialidade) {
      printf("\n  Nome: %s", atual->nome);
      printf("\n  Sexo: %s", atual->sexo);
      printf("\n  Data de nascimento: %d/%d/%d", atual->nascimento.dia, atual->nascimento.mes, atual->nascimento.ano);
      printf("\n  C�digo: %u", atual->codigo);

      if(atual->agendamento.contador != 0) {

      for(i = 1; i <= atual->agendamento.contador; i++) {
      printf("\n  Agendamentos: \n");
       printf("%d  Dia %d, %d:00 Horas\n", i, atual->agendamento.dia[i], atual->agendamento.hora[i]);
      }
     // }
      printf("\n\n");
    }
  }
}
}

//Procedimento para criar a tela do Secret�rio
void menu_Secretario() {

  //Vari�veis
  char op_sec;

  //Artif�cio para repetir as op��es do menu enquando n�o for digitada a para voltar
  while(op_sec != 's'){

    printf(" *----------------------------------------------------------------------------*\n");
    printf(" | ");printf("\t\t\t     Bem-vindo(a), secret�rio(a)");printf("\t\t      |\n");
    printf(" *----------------------------------------------------------------------------*\n");
    printf("\t\t\t         |   MENU   ");printf("|\t\t\t\t\n\n");
    printf("\t\t   | <1>  Menu de Cadastros            |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <2>  Menu de Agendamentos         |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <S>  Sair                         |\n");
    printf("\t\t   |-----------------------------------|");
    printf("\n\n\n\n");
    printf("\t\t   Escolha uma op��o: ");

    //Lendo a op��o do menu
    fflush(stdin);
    op_sec = getche();
    system("cls");

    //Menu de opcoes
    switch(op_sec){
      case '1': Cadastros(); //Chamando o procedimento de cadastros

      case '2': Agendamentos(); //Chamando o procedimento de agendamentos

      case 'S': //Artif�cio para aceitar tanto mai�scula como min�scula
      case 's': inicio(); //Voltar ao in�cio do programa
    }
  }
}

//Procedimento para criar a tela de Cadastros de paciente.
void Cadastros() {

  //Vari�veis
  char op;

  //Artif�cio para repetir o programa.
  while(op!='s') {

    //Menu de op��es
    printf("\n");
    printf("\t\t\t         |   MENU Cadastros ");printf("|\t\t\t\t\n\n");
    printf("\t\t   | <1>  Novo cadastro                |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <2>  Listar                       |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <3>  Excluir cadastro             |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <4>  Alterar cadastro             |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <V>  Voltar                       |\n");
    printf("\t\t   |-----------------------------------|");
    printf("\n\n\n\n");
    printf("\t\t   Escolha uma op��o: ");

    //Lendo as op��es do menu
    fflush(stdin);
    op = getch();
    //Aplicando as funcionalidades do menu
    switch(op) {

      case '1':
      //Chamando a fun��o para cadastrar um paciente.
      fflush(stdin);
      system("cls");
      printf(" *----------------------------------------------------------------------------*\n");
      printf(" | ");printf("\t\t\t       NOVO CADASTRO DE PACIENTE     ");printf("\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");
      primeiro = inserir_paciente(primeiro);
      getch();
      system("cls");
      break;

      case '2':
      //Chamando o procedimento para listar os pacientes.
      system ("cls");
      printf(" *----------------------------------------------------------------------------*\n");
      printf(" | ");printf("\t\t\t     PACIENTES CADASTRADOS");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");
      listar_paciente(primeiro);
      system("cls");
      break;

      case '3':
      //Chamando a fun��o para excluir um cadastro de paciente.
      system ("cls");
      primeiro = excluir_paciente(primeiro);
      getch();
      system("cls");
      break;

      case '4':
      //Chamando um procedimento para alterar os dados de um cadastro.
      system ("cls");
      printf(" *----------------------------------------------------------------------------*\n");
      printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");
      alterar_paciente(primeiro);
      getch();
      system("cls");
      break;

      case 'V':
      case 'v':
      //Voltando ao menu do Secret�rio.
      system("cls");
      menu_Secretario();
      break;

      default:
      //Previnindo a situa��o de um usu�rio qualquer, digitar uma opc�o inexistente no menu.
      system("cls");
      break;
    }
  }
}

//Procedimento para criar a tela de Agendamentos do paciente.
void Agendamentos() {

  //Vari�veis
  char op;

  //Artif�cio para repetir o programa.
  while(op!='s') {

    //Menu de opcoes-cadastro
    printf("\n");
    printf("\t\t\t         |   MENU Cadastros ");printf("|\t\t\t\t\n\n");
    printf("\t\t   | <1>  Novo agendamento             |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <2>  Cancelar agendamento         |\n");
    printf("\t\t   |-----------------------------------|\n");
    printf("\t\t   | <S>  Voltar                       |\n");
    printf("\t\t   |-----------------------------------|");
    printf("\n\n\n\n");
    printf("\t\t   Escolha uma op��o: ");

    //Lendo as op��es do menu
    fflush(stdin);
    op = getch();

    //Menu de opcoes
    switch(op) {
      case '1':
      //Chamando o procedimento de agendar consultas.
      fflush(stdin);
      system("cls");
      printf(" *----------------------------------------------------------------------------*\n");
      printf(" | ");printf("\t\t\t       NOVO AGENDAMENTO     ");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");
      agendar(primeiro);
      getch();
      system("cls");
      break;

      case '2':
      //Chamando o procedimento de cancelar consultas.
      system ("cls");
      printf(" *----------------------------------------------------------------------------*\n");
      printf(" | ");printf("\t\t\t     CANCELAR AGENDAMENTO");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");
      listar_paciente(primeiro);
      getch();
      system("cls");
      break;

      case 'S':
      case 's':
            //Voltano ao menu do Secret�rio.
            system("cls");
            menu_Secretario();
            break;

      default:
            //Previnindo a situa��o de um usu�rio digitar uma opc�o inv�lida no menu.
            system("cls");
            break;
    }
  }
}

//Fun��o do tipo Lista (estrutura) para inserir funcion�rios
Lista* inserir_funcionario (Lista *primeiro){

  //Cria��o de uma lista que aponta para o primeiro elemento nulo
  Lista *atual = primeiro;

  //Vari�veis
  char identificador= 'F';
  char opcao, digitos[6];

  //Lendo as informa��es do paciente.
  printf("  Nome: ");
  fflush (stdin); gets(funcionario.f_nome); strlwr(funcionario.f_nome);

  printf("\n  Endere�o - rua, n�mero, bairro e cidade: ");
  fflush (stdin); gets(funcionario.f_endereco); strlwr(funcionario.f_endereco);

  printf("\n  Sexo: ");
  fflush(stdin); gets(funcionario.f_sexo); strlwr(funcionario.f_sexo);

  printf("\n  Documento (CPF): ");
  fflush(stdin); gets(funcionario.f_CPF); strlwr(funcionario.f_CPF);

  printf("\n  Cargo: \n  (1) Secret�rio\n  (2) M�dico\n  (3) Recepcionista\n  (4) Faxineiro\n");
  //Artif�cio para que somente os seguintes n�meros sejam utilizados
  do{
        printf("  Informe um n�mero v�lido: ");
      fflush(stdin); scanf("%d", &funcionario.cargo);
  }while(funcionario.cargo != 1 && funcionario.cargo != 2 && funcionario.cargo != 3 && funcionario.cargo != 4);

  //Condi��o para que seja armazenado o CRM apenas aos m�dicos
  if(funcionario.cargo == 2) {
    printf("\n  Informe o CRM: ");
    fflush(stdin); gets(funcionario.CRM);
    printf("\n  Especialidade: \n");
    printf("  (1) Cardiologia\n  (2) Endocrinologia\n  (3) Neurologia\n  (4) Nutri��o\n  (5) Psicologia da Sa�de\n  (6) Psiquiatria\n");
    do{
      printf("  Informe um n�mero v�lido: ");
      fflush(stdin); scanf("%d", &funcionario.especialidade);
  }while(funcionario.especialidade != 1 && funcionario.especialidade != 2 && funcionario.especialidade != 3 && funcionario.especialidade != 4 && funcionario.especialidade != 5 && funcionario.especialidade != 6);
  }
    //Condi��o para pegar senha somente aos funcion�rios secret�rio, m�dico e recepcionista.
  if (funcionario.cargo == 1 || funcionario.cargo == 2) {
  printf("\n  Senha: ");
  fflush(stdin); scanf("%u", &funcionario.senha);
  }
  data();


  printf("\n  Confirmar o cadastro de %s? (s/n) ", funcionario.nome);
  do{
  fflush(stdin);
  opcao = getch();
      switch (opcao) {

      case 's':
        fflush(stdin);
        break;

      case 'n':
        system("cls");
        menu_Administrador();
        break;

      default:
        printf("\n  Escolha uma op��o v�lida: ");
        break;
      }
  }while(opcao != 's');


  /*Pegar somente os 6 primeiros digitos do CPF e coloc�-los no c�digo do paciente*/
  memcpy(digitos, &funcionario.f_CPF[0], 6);
  digitos[6] = '\0'; // adiciona o terminador de linha
  funcionario.f_codigo = atol(digitos);

  //Verificando os campos do CPF (limitando somente a n�meros)

  //Verificando se o cadastro j� existe.
  for(atual=primeiro; atual!=NULL; atual=atual->prox){
    if(atual->f_codigo==funcionario.f_codigo){
      identificador = 'V';
    break;
    }
  }


  if(identificador!='V' && (strlen(funcionario.f_nome)!=1 && strlen(funcionario.f_endereco)!=1 && strlen(funcionario.f_sexo) !=1 && strlen(funcionario.f_CPF) !=1)){
    //Alocando os espa�os e guardando as informa��es do paciente.
    Lista* Novofuncionario = (Lista*) malloc (sizeof(Lista));
    strcpy(Novofuncionario->f_nome, funcionario.f_nome);
    strcpy(Novofuncionario->f_endereco, funcionario.f_endereco);
    strcpy(Novofuncionario->f_sexo, funcionario.f_sexo);
    strcpy(Novofuncionario->f_CPF, funcionario.f_CPF);
    strcpy(Novofuncionario->CRM, funcionario.CRM);
    Novofuncionario->cargo = funcionario.cargo;
    if (funcionario.cargo == 2)
        Novofuncionario->especialidade = funcionario.especialidade;
    Novofuncionario->senha = funcionario.senha;
    Novofuncionario->f_codigo = funcionario.f_codigo;
    strcpy(Novofuncionario->data_cadastro, d.data_atual);
    Novofuncionario->prox = primeiro;
    printf("\n\n  Cadastro realizado com sucesso.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    getch();
    system("cls");
    return Novofuncionario;
  }else{
     printf("  Cadastro inv�lido.");
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
     getch();
     system("cls");
     return primeiro;
  }
}

//Fun��o do tipo Lista (estrutura) para inserir pacientes
Lista *inserir_paciente (Lista *primeiro){

  //Cria��o de uma lista que aponta para o primeiro elemento nulo
  Lista *atual = primeiro;

  //Vari�veis
  char identificador= 'F';
  char opcao, digitos[6];

  //Lendo as informa��es do paciente.
  printf("  Nome: ");
   fflush (stdin); gets(paciente.nome); strlwr(paciente.nome);
  printf("\n  Endere�o: ");
   fflush (stdin); gets(paciente.endereco); strlwr(paciente.endereco);
  printf("\n  Sexo: ");
   fflush(stdin); gets(paciente.sexo); strlwr(paciente.sexo);
   printf("\n  Data de nascimento: \n");
   fflush(stdin);
   printf("\n  Dia: "); scanf("%d", &paciente.nascimento.dia);
   fflush(stdin);
   printf("\n  M�s: "); scanf("%d", &paciente.nascimento.mes);
   fflush(stdin);
   printf("\n  Ano: "); scanf("%d", &paciente.nascimento.ano);
  printf("\n  Documento (CPF): ");
   fflush(stdin); gets(paciente.CPF); strlwr(paciente.CPF);
  data(); //Chama o procedimento data() para pegar a data/hora do cadastro

  //Lendo as op��es do menu
  printf("\n  Confirmar o cadastro de %s? (s/n) ", paciente.nome);
  fflush(stdin);
  opcao = getch();

  //Tornando o menu funcional
  switch (opcao){
    case 's': break;

    case 'n': system("cls");
              menu_Secretario();
              break;

    default: printf("Escolha uma op��o v�lida: ");
    }

    fflush(stdin);

  /*Pegar somente os 6 primeiros digitos do CPF e coloc�-los no c�digo do paciente*/
  memcpy(digitos, &paciente.CPF[0], 6);
  digitos[6] = '\0'; // adiciona o terminador de linha
  paciente.codigo = atol(digitos);

//Verificando os campos do CPF (limitando somente a n�meros)

  //Verificando se o cadastro j� existe.
  for(atual=primeiro; atual!=NULL; atual=atual->prox){
    if(atual->codigo==paciente.codigo){
    identificador = 'V';
    break;
    }
  }


if(identificador!='V' && (strlen(paciente.nome)!=1 && strlen(paciente.endereco)!=1 && strlen(paciente.sexo) !=1 && strlen(paciente.CPF) !=1)){
  //Alocando os espa�os e guardando as informa��es do paciente.
  Lista* Novopaciente=(Lista*) malloc (sizeof(Lista));
  strcpy(Novopaciente->nome, paciente.nome);
  strcpy(Novopaciente->endereco, paciente.endereco);
  strcpy(Novopaciente->sexo, paciente.sexo);
  Novopaciente->nascimento.dia = paciente.nascimento.dia;
  Novopaciente->nascimento.mes = paciente.nascimento.mes;
  Novopaciente->nascimento.ano = paciente.nascimento.ano;
  strcpy(Novopaciente->CPF, paciente.CPF);
  Novopaciente->codigo= paciente.codigo;
  strcpy(Novopaciente->data_cadastro, d.data_atual);
  Novopaciente->prox = primeiro;
  printf("\n\n  Cadastro realizado com sucesso.");
  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  return Novopaciente;
  }else{
    printf("  Cadastro inv�lido.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
  }
}


//Procedimento para listar todos os pacientes cadastrados.
void listar_paciente (Lista* primeiro){

  //Ponteiro para percorrer a lista sem perder a refer�ncia do primeiro elemento da lista.
  Lista* atual;

  int i;

  //Imprimindo os pacientes da lista, e suas repectivas informa��es.
  for(atual = primeiro; atual != NULL; atual = atual->prox){
    if (atual->cargo != 1 && atual->cargo != 2 && atual->cargo != 3) {
      printf("\n  Nome: %s", atual->nome);
      printf("\n  Endere�o: %s", atual->endereco);
      printf("\n  Sexo: %s", atual->sexo);
      printf("\n  Data de nascimento: %d/%d/%d", atual->nascimento.dia, atual->nascimento.mes, atual->nascimento.ano);
      printf("\n  Documento: %s\n", atual->CPF);
      printf("\n  C�digo: %u", atual->codigo);
      printf("\n  Data do cadastro: %s", atual->data_cadastro);

      if(atual->agendamento.contador != 0) {

      for(i = 1; i <= atual->agendamento.contador; i++)
      printf("\n  Agendamentos: Dia %d, %d:00 Horas", atual->agendamento.dia[i], atual->agendamento.hora[i]);

      if (atual->agendamento.hora[i] == 1)
            printf("10:00");
      if (atual->agendamento.hora[i] == 2)
            printf("11:00");
            if (atual->agendamento.hora[i] == 3)
            printf("12:00");

      }
      printf("\n\n");
    }
  }

      if(primeiro == NULL)
    printf("  Nenhum paciente cadastrado.");

  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  getch();
  system("cls");
  //Caso n�o seja o Secret�rio que emitiu o relat�rio, retornar� ao menu do ADM, pois s�o os dois �nicos que utilizar�o este procedimento.

    Cadastros();

}

//Procedimento para listar todos os funcion�rios cadastrados.
void listar_funcionario (Lista* primeiro){

  //Ponteiro para percorrer a lista sem perder a refer�ncia do primeiro elemento da lista.
  Lista* atual;

  //Imprimindo os pacientes da lista, e suas repectivas informa��es.
  for(atual = primeiro; atual != NULL; atual = atual->prox){
    printf("\n  Nome: %s", atual->f_nome);
    printf("\n  Endere�o: %s\n", atual->f_endereco);
    printf("  Sexo: %s\n", atual->f_sexo);
    printf("  Documento: %s\n", atual->f_CPF);
    printf("\n  Cargo: ");

    //Condi��es para que o programa exiba os respectivos cargos.
    if(atual->cargo == 1)
      printf("Secret�rio");
    if(atual->cargo == 2){
      printf("M�dico");
      printf("\n  Especialidade: ");
      if(atual->especialidade == 1)
        printf("Cardiologista");
     if(atual->especialidade == 2)
        printf("Endocrinologista");
      if(atual->especialidade == 3)
        printf("Neurologista");
      if(atual->especialidade == 4)
        printf("Nutricionista");
      if(atual->especialidade == 5)
        printf("Psicologo(a) da Sa�de");
      if(atual->especialidade == 6)
        printf("Psiquiatra");
        printf("\n  CRM: %s", atual->CRM);
    }
    if(atual->cargo == 3)
        printf("Recepcionista");
    if(atual->cargo == 4)
        printf("Faxineiro(a)");
    printf("\n  Data do cadastro: %s", atual->data_cadastro);
    printf("\n\n");
  }

  if(primeiro==NULL)
    printf("  Nenhum funcion�rio cadastrado.");

  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
  getch();
  system("cls");
  menu_Administrador();
}

/* fun��o busca: busca um elemento (pacientes espec�ficos) na lista */
Lista* buscar(Lista *primeiro) {

  //ponteiro para apontar o atual ao primeiro elemento da lista (como o i = 0 para vetores, aponta para o primeiro campo para apontar aos pr�ximos, poss�velmente).
  Lista *atual = primeiro;
  Lista *atual_funcionario = primeiro;
  unsigned long int codigo = 0;
  char op;
  int i = 1;
      printf(" *----------------------------------------------------------------------------*\n");
      printf(" | ");printf("\t\t\t       FICHA M�DICA     ");printf("\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");
  //Requisitando e lendo o c�digo do paciente a ser alterado.
  printf("  C�digo do paciente a ser pesquisado: ");
  fflush(stdin);
  scanf("%u",&codigo);


  //Procurando o paciente na lista.
  while(atual != NULL && atual->codigo != codigo){
    atual = atual->prox;
  }

    if(atual != NULL) {
          //Listando os dados do paciente.
          printf("\n  Paciente Encontrado!\n");
          printf("\n  Nome: %s ", atual->nome);
          //printf("Endere�o: %s \n", atual->endereco);
          printf("\n  Sexo: %s \n", atual->sexo);
          printf("\n  Data de nascimento: %d/%d/%d", atual->nascimento.dia, atual->nascimento.mes, atual->nascimento.ano);

           if(atual->agendamento.contador != 0) {
              for(i = 1; i <= atual->agendamento.contador; i++) {
                printf("\n  Agendamentos: \n");
                printf("  %d:  Dia %d, %d:00 Horas\n", i, atual->agendamento.dia[i], atual->agendamento.hora[i]);
              }
          }

        //  printf("\n\n  <1> Para receitu�rios");
       //   printf("\n  <2> Para atestados");
       //   printf("\n  <3> Para adicionar observa��es");
          printf("\n\n  <V> Para voltar");
          do {
          printf("\n  Escolha uma op��o v�lida: ");
          fflush(stdin); op = getch();

          switch (op) {
        //      case '1':
        //            break;

       //       case '2':
         //       break;

       //       case '3':
        //        break;

              case 'V':
              case 'v': system("cls");
                   menu_Medico();
          }
         }while(op != '1' && op != '2' && op != '3' && op != 'v');
     }


  //Mensagem caso o paciente n�o seja encontrado.
  if(atual == NULL)
    printf("\n  paciente n�o encontrado.");

  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  getch();
  system("cls");
  menu_Medico();
}

//Fun��o para excluir algum cadastro de paciente.
Lista* excluir_paciente(Lista *primeiro){

  Lista *anterior = NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
  Lista *atual = primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.

  //Vari�vel local codigo para fazer a compara��o.
  unsigned long int codigo = 0;
  char op;
        printf(" *---------------------------------------------------------------------------\n");
      printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");


  //Requisitando e lendo o c�digo do paciente a ser exclu�do.
  printf("  C�digo do paciente a ser exclu�do: ");
  fflush(stdin);
  scanf("%u",&codigo);
do {
    system("cls");
      printf(" *---------------------------------------------------------------------------\n");
      printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");

  //Procurando o paciente na lista.
  while(atual != NULL && atual->codigo != codigo){
    anterior = atual;
    atual = atual->prox;
  }

  //Mensagem caso o paciente n�o seja encontrado na lista.
  if(atual == NULL){
    printf("\n  paciente n�o encontrado.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
  }

    printf("\n  Deseja excluir o paciente? (s/n)");

    op = getch();

    switch (op) {

    //Desalocando o espa�o da mem�ria (somente ao paciente atual/selecionado).
    case 'S':
  case 's': free(atual);
                break;
    case 'N':
  case 'n': printf("\n\n  Paciente n�o exclu�do. Pressione qualquer tecla para voltar.");
                getch();
                system("cls");
                Cadastros();
                break;
    default: printf("\n\n  Op��o inv�lida. Tente novamente.\n");
                    system("pause");
                    break;
}
}while (op != 's' && op != 'S');
  //Excluindo o primeiro paciente da lista (o anterior estar� apontando � posi��o zero da lista).
  if(anterior == NULL){
    printf("\n  Paciente exclu�do com sucesso.");
    primeiro = atual->prox;
    //Excluindo um paciente do meio da lista.
  }else{
    printf("\n  Paciente exclu�do com sucesso.");
    anterior->prox = atual->prox;
   }


  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  return primeiro;
}

//Fun��o para excluir algum cadastro espec�fico de funcion�rio.
Lista* excluir_funcionario(Lista *primeiro){

  Lista *anterior = NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
  Lista *atual = primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.

  //Vari�vel local codigo para fazer a compara��o.
  unsigned long int f_codigo = 0;
  char op;
        printf(" *---------------------------------------------------------------------------\n");
      printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");

  //Requisitando e lendo o c�digo do paciente a ser exclu�do.
  printf("  C�digo do funcion�rio a ser exclu�do: ");
  fflush(stdin);
  scanf("%u",&f_codigo);
do {
    system("cls");
      printf(" *---------------------------------------------------------------------------\n");
      printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
      printf(" *----------------------------------------------------------------------------*\n");

  //Procurando o paciente na lista.
  while(atual != NULL && atual->f_codigo != f_codigo){
    anterior = atual;
    atual = atual->prox;
  }

  //Mensagem caso o paciente n�o seja encontrado.
  if(atual == NULL){
    printf("\n  Funcion�rio n�o encontrado.");
      printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
                getch();
                system("cls");
                menu_Administrador();
  }

    printf("\n  Deseja excluir o funcion�rio? (s/n)");
    op = getch();

    switch (op) {
    //Desalocando o espa�o da mem�ria (somente ao paciente atual/selecionado).

    case 'S':
  case 's': free(atual);
                break;
    case 'N':
  case 'n': printf("\n\n  Funcion�rio n�o exclu�do. Pressione qualquer tecla para voltar.");
                getch();
                system("cls");
                menu_Administrador();
                break;
    default: printf("\n\n  Op��o inv�lida. Tente novamente.\n");
                    system("pause");
                    break;
    }

}while (op != 's' && op != 'S');

//Excluindo o primeiro funcion�rio da lista.
  if(anterior == NULL){
    printf("\n  Funcion�rio exclu�do com sucesso.");
    primeiro = atual->prox;
    //Excluindo um funcion�rio do meio da lista.
  }else{
    printf("\n  Funcion�rio exclu�do com sucesso.");
    anterior->prox = atual->prox;
   }
  printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  getch();
  system("cls");
  return primeiro;
}


//Fun��o para alterar dados de pacientes.
void alterar_paciente(Lista* primeiro){

  //Vari�veis para fazer a altera��o
  char nome_substituto[100], endereco_substituto[100], sexo_substituto[20], documento_substituto[20];
  int dia_substituto, mes_substituto, ano_substituto;
  unsigned long int codigo;
  char digitos[4];
  Lista* atual = primeiro;

  //Requisitando e lendo o c�digo do paciente a ser alterado.
  printf("  C�digo do paciente a ser alterado: ");
  fflush(stdin);
  scanf("%u",&codigo);

  //Procurando o paciente na lista.
  while(atual != NULL && atual->codigo != codigo){
    atual = atual->prox;
  }

  //Alterando os dados do paciente.
  if(atual != NULL){
    printf("\n  Novo nome: ");
    fflush (stdin); gets(nome_substituto);
    strcpy(atual->nome,nome_substituto);
    printf("\n  Novo endere�o: ");
    fflush (stdin); gets(endereco_substituto);
    strcpy(atual->endereco,endereco_substituto);
    printf("\n Novo sexo: ");
    fflush(stdin); gets(sexo_substituto);
    strcpy(atual->sexo, sexo_substituto);
    printf("\n  Nova data de nascimento: \n");
   fflush(stdin);
   printf("\n  Dia: "); scanf("%d", &dia_substituto);
   fflush(stdin);
   printf("\n  M�s: "); scanf("%d", &mes_substituto);
   fflush(stdin);
    printf("\n  Ano: "); scanf("%d", &ano_substituto);

  atual->nascimento.dia = dia_substituto;
  atual->nascimento.mes = mes_substituto;
  atual->nascimento.ano = ano_substituto;

    printf("\n  Novo documento: ");
    fflush(stdin); gets(documento_substituto);
    strcpy(atual->CPF, documento_substituto);

    /*Pegar somente os 6 primeiros digitos do CPF e coloc�-los no c�digo do funcion�rio*/
    memcpy(digitos, &documento_substituto[0], 4);
    digitos[4] = '\0'; // adiciona o terminador de linha
    codigo = atol(digitos);

    atual->codigo = codigo;

    printf("  Dados alterados com sucesso.\n");
  }else printf("\n  paciente n�o encontrado.");

  printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  getche();
  system("cls");
  Cadastros();
}

//Fun��o para alterar dados de funcion�rios.
void alterar_funcionario(Lista* primeiro){

  //Vari�veis para fazer a altera��o
  char nome_substituto[100], endereco_substituto[100], sexo_substituto[20], documento_substituto[20];
  int cargo_substituto;
  unsigned long int f_codigo;
  unsigned long int senha_substituta;
  char op, digitos[6];
  Lista* atual = primeiro;

  //Requisitando e lendo o c�digo do funcion�rio a ser alterado.
  printf("  C�digo do funcion�rio a ser alterado: ");
  fflush(stdin);
  scanf("%u",&f_codigo);

  //Procurando o paciente na lista.
  while(atual != NULL && atual->f_codigo != f_codigo){
    atual = atual->prox;
  }

  //Alterando os dados do paciente.
  if(atual != NULL){

printf("\n\n  <1> Para alterar o nome;\n  <2> Para alterar o endere�o;\n  <3> Para alterar o sexo;\n  <4> Para alterar o documento;\n  <5> Para alterar o cargo;\n  <6> Para alterar a senha.\n  <V> Para voltar.\n\n");
  do {
    printf("\n  Escolha uma op��o: ");
    op = getche();

    switch (op) {

    case '1': printf("\n  Novo nome: ");
    fflush (stdin); gets(nome_substituto);
    strcpy(atual->f_nome, nome_substituto);
    break;

    case '2': printf("\n  Novo endere�o: ");
    fflush (stdin); gets(endereco_substituto);
    strcpy(atual->f_endereco, endereco_substituto);
    break;

    case'3': printf("\n Novo sexo: ");
    fflush(stdin); gets(sexo_substituto);
    strcpy(atual->f_sexo, sexo_substituto);
    break;

    case '4': printf("\n Novo documento: ");
    fflush(stdin); gets(documento_substituto);
    strcpy(atual->f_CPF, documento_substituto);

    /*Pegar somente os 4 primeiros digitos do CPF e coloc�-los no c�digo do funcion�rio*/
    memcpy(digitos, &documento_substituto[0], 6);
    digitos[6] = '\0'; // adiciona o terminador de linha
    f_codigo = atol(digitos);

    atual->f_codigo = f_codigo;
    break;

    case '5':
    printf("\n  Novo cargo: \n  (1) Secret�rio\n  (2) M�dico\n  (3) Recepcionista\n  (4) Faxineiro\n");
  //Artif�cio para que somente os seguintes n�meros sejam utilizados

  do{
        printf("  Informe um n�mero v�lido: ");
        fflush(stdin); scanf("%d", &cargo_substituto);
  }while(cargo_substituto != 1 && cargo_substituto != 2 && cargo_substituto != 3 && cargo_substituto != 4);
    atual->cargo = cargo_substituto;
    //if(cargo_substituto == 1 || cargo_substituto == 2)
    case '6':
        if (atual->cargo == 1 || atual->cargo == 2) {
            printf("\n Nova senha: ");
            fflush(stdin); scanf("%u", &senha_substituta);
            atual->senha = senha_substituta;
        }
        else printf("\n  Este cargo n�o possui senha.");
    break;

    case 'V':
    case 'v': system("cls");
    menu_Administrador();

    }
    }while(op != '1' && op != '2' && op != '3' && op != '4' && op != '5' && op != 'v');
    printf("  Dados alterados com sucesso.\n");
  }else printf("\n  Funcion�rio n�o encontrado.");

  printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
  getche();
  system("cls");
  menu_Administrador();
}

//Procedimento para capturar a data/hora local (da CPU)
void data() {
  time_t now = time(0);
  struct tm temp;

  // get current local date and time ...
  temp = *localtime( &now );
  const char *format = "%d/%m/%Y %H:%M:%S";

  //Alocando as informa��es do tempo (pela biblioteca time.h) na estrutura data
  d.dia     = temp.tm_mday;
  d.mes     = temp.tm_mon;
  d.ano     = temp.tm_year;
  d.hora    = temp.tm_hour;
  d.minuto  = temp.tm_min;
  d.segundo = temp.tm_sec;

  // ... and may safely display
  strftime (d.data_atual, 30, format, &temp);
  printf("\n  Data/hora atuais: %s", d.data_atual);
}
