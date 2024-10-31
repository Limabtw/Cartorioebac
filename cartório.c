#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //bibliotca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
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
	setlocale(LC_ALL, "portuguese"); //definição de linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	 if(file == NULL)
	 {
	 	printf("Arquivo não localizado!.\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\n Informações do usuáriio: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	 while(fgets(cpf, 40, file) != NULL)
	{
		printf("usuário deletado com sucesso!.\n");
		system("pause");
	}
	
	if(file == NULL)
	{
		printf("o usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	
}



int main()
{
	int opcao=0; //Definição de variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
     system("cls");
		
	setlocale(LC_ALL, "portuguese"); //definição de linguagem
	
	
	printf("### cartório da EBAC ###\n\n"); //Inicio do menu
	printf("escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registra nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n\n"); 
	printf("opção: "); //Final do menu
	
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
		printf("*essa opção não esta disponivel!\n");
		system("pause");
		break;
		
		
		
		
	}

	}
}
