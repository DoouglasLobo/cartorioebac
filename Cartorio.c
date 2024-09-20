#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro() //Função Reistro
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variáveis/string
	
	printf("Digite o CPF a ser Cadastrado: "); //coletando informação do usuário(cpf)
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por Copiar os Valores das String
	
	FILE *file; //Cria o Arquivo no Banco de Dados "PC"
	file = fopen(arquivo, "w"); // Cria o arquivo "PC" "w" significa escrever
	fprintf(file,cpf); //Salva o Valor da Variavel
	fclose(file);//Fecha o Arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser Cadastrado: "); //coletando informação do usuário(nome)
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser Cadastrado: "); //coletando informação do usuário(sobrenome)
	scanf("%s,", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: "); //coletando informação do usuário(cargo)
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
	
	printf("Digite o CPF a ser Consultado: "); //coletando informação do usuário(cpf)
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //Arquivo não localizado
	{
		printf("Esse CPF não está Cadastrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Buscando Arquivo
	{
		printf("\nEssas são as Informações do Usuário: "); //Mostrando informaçoes do arquivo
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do Usuário a ser Deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse CPF não está Cadastrado! \n");
		system("pause");
	}
	
}

int main() //Menu
{
	int opcao = 0;  //Definindo Variáveis
	int VoltarMenu = 1;
	
	for(VoltarMenu = 1;VoltarMenu = 1;)
	{
	
		system("cls"); //resposavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf("\tCartório EBAC\n\n"); //Início Meno
		printf("Escolha a Opção Desejada do Menu: \n\n");
		printf("\t1 - Registrar Nome\n");
		printf("\t2 - Consultar os Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 Sair do Menu\n\n");
		printf("Opção: "); //Fim Menu
	
		scanf("%d", &opcao); //Armazenando Escolha do Usuário
	
		system("cls");
		
		switch(opcao) //Opcões do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Volte Sempre!\n");
			return 0;
			
			default:
			printf("Está Opção não Existe!\n");
			system("pause");
			break; //Fim Opções do menu
		}
	}
}
