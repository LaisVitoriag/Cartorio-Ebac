#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include<string.h>  // biblioteca responsável por cuidar da string

int registro()  // função responsávio por cadastrar oa usuários no sistema
{
	// início da criação de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criação de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
    scanf("%s",cpf); // %s referice a string
    
    strcpy(arquivo,cpf); // responsável por copiar o valor das string
    
       FILE*file;  // cria o arquivo
       file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
       fprintf(file,cpf); // salva o valor da variável
       fclose(file); // fecha o arquivo
       
       file = fopen(arquivo,"a"); // a letra "a" é para incluir ao arquivo
       fprintf(file,",");
       fclose(file);
       
       printf("Digite o nome a ser cadastrado:"); // coletando informação do usuário
       scanf("%s",nome); // salvando a informação na variavel
       
       file = fopen(arquivo,"a"); // cria o arquivo
       fprintf(file,nome); // salva a informação
       fclose(file); // fecha arquivo
       
       file = fopen(arquivo,"a"); // abre o aquivo e inclui a informação
       fprintf(file,",");
       fclose(file); // fecha arquivo
       
       printf("Digite o sobrenome a ser cadastrado: "); // coletando informação 
       scanf("%s", sobrenome); // salvando informação na variavel
       
       file = fopen(arquivo,"a"); // cria o arquivo
       fprintf(file,sobrenome); // salva a informaçao
       fclose(file); // fecha o arquivo
       
       file = fopen(arquivo,"a"); // abre o arquivo e inclui a informação 
       fprintf(file,",");
       fclose(file); // fechao arquivo
       
       printf("Digite o cargo a ser cadastrado: "); // coletando informação
       scanf("%s", cargo); // salvando a informação na variavel
       
       file = fopen(arquivo, "a"); // abre o arquivo e inclui a informação
       fprintf(file,cargo); // salva a informação
       fclose(file); // fecha o arquivo
       
       system("pause"); // dar pausa no sistema
	} 


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // deve ser usado para acentuar
	
   char cpf[40]; // uma variável e o numero de caractere
   char conteudo[200]; // uma variável e o numero de caractere
   
   printf("Digite o CPF a ser consultado: "); // coletando informação
   scanf("%s",cpf); //
   
   FILE * file;
   file = fopen(cpf,"r");  // o "r" é para ler o cpf
   
   if(file== NULL)//  o cpf não consta no sistema 
   {
   	  printf("Não foi possivel abrir o arquivo, não foi localizado!.\n");
   }
   
   while(fgets(conteudo, 200, file)  != NULL)
   {
   	 printf("\nEssas são as informaações do usuário: \n\n"); 
   	 printf("%s", conteudo); // mostrando a variavel referida
   	 printf("\n\n"); // colocado para pular linha
   }
   
   system("pause"); // pausa na tela para ler a  informação
   	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado:"); // coletando informação
    scanf("%s", cpf);
    
    remove(cpf); // usado para deletar a informação
    
    FILE *file;
    file = fopen(cpf,"r"); // abrir arquivo e ler informação
    
    if(file == NULL) // não consta no sistema
    { 
       printf(" O usuário não se encontra no sistema!.\n");
       system("pause"); // pause na tela para ler a informação
	}
}

int main()
{
   int opcao=0;	//Definindo as variáveis
   int laco=1;
   
	for(laco=1;laco=1;)
	{
	
	system("cls"); // responsável por limpar a telaa
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("### cartório da EBAC ###\n\n");  // Ínicio do menu
	printf(" Escolha a opção desejada do menu:\n\n");
  	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção:"); // fim do menu
	
	scanf("%d", & opcao);  // Armazenando a escolha do usuario
	
	system("cls"); // responsavel por limpar a tela
	
	switch(opcao) // inicio da seleção
	{ 
	   case 1:
	   registro(); // chamada de funções
	   break;
	   
	   
	   case 2:
	   consulta(); // chamada de funções
	   break;
	   
	   
	   case 3:
	   deletar(); // chamada de finções
	   break; 
	   
	   case 4:
	   printf(" Obrigado por utilizar o sistema!\n");
	   return 0;
	   break;
	   	
	   default:
	   printf("Está opção não está disponível!\n");
	   system("pause");
	   break;
	   	
	} //fim da seleção
	
	
	
}
}
