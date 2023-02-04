#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
int registro() //Fun��o respons�vel por cadastrar usu�rios no sistema
{
	//In�cio de cria��ode vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final de cria��ode vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es de usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo,"w"); //cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvar o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es de usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es de usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es de usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem e acentua��o
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! .\n ");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:   ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	    
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //remover informa��o
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		
		printf("\nO usu�rio n�o se encontra no sistema!. \n\n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char nomedeusuario[]="a"; //cria��o de vari�vel
	char senhadigitada[]="a"; //cria��o de vari�vel
	int comparacao;

	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite o seu usu�rio e senha:\n\n");
	scanf("%s",nomedeusuario);
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(nomedeusuario,"aluno"); //defini��o de vari�vel
	comparacao = strcmp(senhadigitada,"ebac"); //defini��o de vari�vel
	
	if(comparacao == 0)

	
	{
			
		for(laco=1;laco=1;)
		{
			
		    system("cls"); //respons�vel por limpar a tela
		
		    setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
		
			printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
			printf("Bem-vindo:\nEscolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do Sistema\n\n"); 
			printf("Op��o: "); //fim do menu
			
		
			scanf("%d", &opcao); //armazenando a escolha do usu[ario
		 		
		 	system("cls");
		 		
			switch(opcao) //in�cio da sele��o do menu	
		    {
				
				case 1:
				registro(); //chamada de fun��es
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar nosso Sistema!\n");
				return 0;
				break;
					
				
				default:
				printf("Essa op��o n�o est� dispon�vel! \n\n");
				system("pause");
				break;
			}
		}//fim da sele��o
    }
    
    else //erro de login
    	printf("\n\nLogin incorreto!\n\n");
}
