#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include<string.h>  // biblioteca respons�vel por cuidar da string

int registro()  // fun��o respons�vio por cadastrar oa usu�rios no sistema
{
	// in�cio da cria��o de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da cria��o de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
    scanf("%s",cpf); // %s referice a string
    
    strcpy(arquivo,cpf); // respons�vel por copiar o valor das string
    
       FILE*file;  // cria o arquivo
       file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
       fprintf(file,cpf); // salva o valor da vari�vel
       fclose(file); // fecha o arquivo
       
       file = fopen(arquivo,"a"); // a letra "a" � para incluir ao arquivo
       fprintf(file,",");
       fclose(file);
       
       printf("Digite o nome a ser cadastrado:"); // coletando informa��o do usu�rio
       scanf("%s",nome); // salvando a informa��o na variavel
       
       file = fopen(arquivo,"a"); // cria o arquivo
       fprintf(file,nome); // salva a informa��o
       fclose(file); // fecha arquivo
       
       file = fopen(arquivo,"a"); // abre o aquivo e inclui a informa��o
       fprintf(file,",");
       fclose(file); // fecha arquivo
       
       printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��o 
       scanf("%s", sobrenome); // salvando informa��o na variavel
       
       file = fopen(arquivo,"a"); // cria o arquivo
       fprintf(file,sobrenome); // salva a informa�ao
       fclose(file); // fecha o arquivo
       
       file = fopen(arquivo,"a"); // abre o arquivo e inclui a informa��o 
       fprintf(file,",");
       fclose(file); // fechao arquivo
       
       printf("Digite o cargo a ser cadastrado: "); // coletando informa��o
       scanf("%s", cargo); // salvando a informa��o na variavel
       
       file = fopen(arquivo, "a"); // abre o arquivo e inclui a informa��o
       fprintf(file,cargo); // salva a informa��o
       fclose(file); // fecha o arquivo
       
       system("pause"); // dar pausa no sistema
	} 


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // deve ser usado para acentuar
	
   char cpf[40]; // uma vari�vel e o numero de caractere
   char conteudo[200]; // uma vari�vel e o numero de caractere
   
   printf("Digite o CPF a ser consultado: "); // coletando informa��o
   scanf("%s",cpf); //
   
   FILE * file;
   file = fopen(cpf,"r");  // o "r" � para ler o cpf
   
   if(file== NULL)//  o cpf n�o consta no sistema 
   {
   	  printf("N�o foi possivel abrir o arquivo, n�o foi localizado!.\n");
   }
   
   while(fgets(conteudo, 200, file)  != NULL)
   {
   	 printf("\nEssas s�o as informaa��es do usu�rio: \n\n"); 
   	 printf("%s", conteudo); // mostrando a variavel referida
   	 printf("\n\n"); // colocado para pular linha
   }
   
   system("pause"); // pausa na tela para ler a  informa��o
   	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado:"); // coletando informa��o
    scanf("%s", cpf);
    
    remove(cpf); // usado para deletar a informa��o
    
    FILE *file;
    file = fopen(cpf,"r"); // abrir arquivo e ler informa��o
    
    if(file == NULL) // n�o consta no sistema
    { 
       printf(" O usu�rio n�o se encontra no sistema!.\n");
       system("pause"); // pause na tela para ler a informa��o
	}
}

int main()
{
   int opcao=0;	//Definindo as vari�veis
   int laco=1;
   
	for(laco=1;laco=1;)
	{
	
	system("cls"); // respons�vel por limpar a telaa
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("### cart�rio da EBAC ###\n\n");  // �nicio do menu
	printf(" Escolha a op��o desejada do menu:\n\n");
  	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o:"); // fim do menu
	
	scanf("%d", & opcao);  // Armazenando a escolha do usuario
	
	system("cls"); // responsavel por limpar a tela
	
	switch(opcao) // inicio da sele��o
	{ 
	   case 1:
	   registro(); // chamada de fun��es
	   break;
	   
	   
	   case 2:
	   consulta(); // chamada de fun��es
	   break;
	   
	   
	   case 3:
	   deletar(); // chamada de fin��es
	   break; 
	   
	   case 4:
	   printf(" Obrigado por utilizar o sistema!\n");
	   return 0;
	   break;
	   	
	   default:
	   printf("Est� op��o n�o est� dispon�vel!\n");
	   system("pause");
	   break;
	   	
	} //fim da sele��o
	
	
	
}
}
