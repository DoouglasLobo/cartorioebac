#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int registro() //Fun��o Reistro
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser Cadastrado: "); //coletando informa��o do usu�rio(cpf)
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por Copiar os Valores das String
	
	FILE *file; //Cria o Arquivo no Banco de Dados "PC"
	file = fopen(arquivo, "w"); // Cria o arquivo "PC" "w" significa escrever
	fprintf(file,cpf); //Salva o Valor da Variavel
	fclose(file);//Fecha o Arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser Cadastrado: "); //coletando informa��o do usu�rio(nome)
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser Cadastrado: "); //coletando informa��o do usu�rio(sobrenome)
	scanf("%s,", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: "); //coletando informa��o do usu�rio(cargo)
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado: "); //coletando informa��o do usu�rio(cpf)
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //Arquivo n�o localizado
	{
		printf("Esse CPF n�o est� Cadastrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Buscando Arquivo
	{
		printf("\nEssas s�o as Informa��es do Usu�rio: "); //Mostrando informa�oes do arquivo
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do Usu�rio a ser Deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse CPF n�o est� Cadastrado! \n");
		system("pause");
	}
	
}

int main() //Menu
{
	int opcao = 0;  //Definindo Vari�veis
	int VoltarMenu = 1;
	
	for(VoltarMenu = 1;VoltarMenu = 1;)
	{
	
		system("cls"); //resposavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf("\tCart�rio EBAC\n\n"); //In�cio Meno
		printf("Escolha a Op��o Desejada do Menu: \n\n");
		printf("\t1 - Registrar Nome\n");
		printf("\t2 - Consultar os Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 Sair do Menu\n\n");
		printf("Op��o: "); //Fim Menu
	
		scanf("%d", &opcao); //Armazenando Escolha do Usu�rio
	
		system("cls");
		
		switch(opcao) //Opc�es do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Volte Sempre!\n");
			return 0;
			
			default:
			printf("Est� Op��o n�o Existe!\n");
			system("pause");
			break; //Fim Op��es do menu
		}
	}
}
