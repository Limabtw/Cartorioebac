#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //bibliotca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf ("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //defini��o de linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	 if(file == NULL)
	 {
	 	printf("Arquivo n�o localizado!.\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\n Informa��es do usu�riio: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	 while(fgets(cpf, 40, file) != NULL)
	{
		printf("usu�rio deletado com sucesso!.\n");
		system("pause");
	}
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
}



int main()
{
	int opcao=0; //Defini��o de variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
     system("cls");
		
	setlocale(LC_ALL, "portuguese"); //defini��o de linguagem
	
	
	printf("### cart�rio da EBAC ###\n\n"); //Inicio do menu
	printf("escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registra nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n\n"); 
	printf("op��o: "); //Final do menu
	
	scanf("%d", &opcao); //Armazenando escolhas do usuario
	
	system("cls");
	
	
	switch(opcao)
	{
		case 1:
	    registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("*essa op��o n�o esta disponivel!\n");
		system("pause");
		break;
		
		
		
		
	}

	}
}
