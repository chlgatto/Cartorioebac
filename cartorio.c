#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o  de espa�o em mem�ria
#include <locale.h> //biblioteca  de aloca��es  de texto  por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o respons�vel por cadastrar o usu�rio no sistema
{
	//in�cio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio (printf = conver�ar com usu�rio)
	scanf("%s", cpf); //%s refere-se as string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os  valores  das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w");  // w de write (escrever) Cria o arquivo
	fprintf(file,cpf); // Salvo o valor na vari�vel CPF
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); // armazena o aqruivo solicitado
	fprintf(file, ","); // virgula entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", nome); //%s refere-se as string
	
	file = fopen(arquivo, "a"); //armazena o arquivo 
	fprintf(file,nome); //Salvor na vari�vel nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file, ",");// virgula entre os dados
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // comunica com o usu�rio
	scanf("%s", sobrenome); //%s refere-se as string
	
    file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file,sobrenome);  //Salvor na vari�vel sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file, ","); // virgula entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // comunica com o usu�rio
	scanf("%s", cargo); //%s refere-se as string
	
	file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file,cargo); //Salvor na vari�vel cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); // pausa para usu�rio 
	
}
	int consulta() // fun��o respons�vel por consultar o usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // vari�vel string CPF
	char conteudo[200]; 
	
	printf("Digite o CPF a ser consultado: "); // comunica��o com o usu�rio
	scanf("%s", cpf); //%s refere-se as string
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf, "r"); // abrir e ler o aquivo (r) de read
	
	if(file == NULL) // e se o arquivo pesquisado for igual a nulo 
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); // comunica��o com o usu�rio
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto a busca der nula 
	{
	    printf("\n Essas s�o  as informa��es do usu�rio: "); // comunica��o com o usu�rio
		printf("%s" , conteudo); 
		printf("\n\n");	// \n = pular linha
	}
	
	system("pause"); // pausa para o usu�rio
	
}
int deletar()
{
	char cpf[40]; // vari�vel string CPF
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf); // String s�o conjuntos de vari�veis.
    
    remove(cpf); 
    
    FILE *file; //criar pasta/arquivo
    file = fopen(cpf, "r"); // Buscar e ler no aquivo salvo
    
    if(file == NULL) //e se o aqruivo for nulo
	{ 
	    printf("O usu�rio n�o se  encontra no sistema!.\n"); // comunica��o com o usu�rio
    	system("pause"); // pausa para usu�rio

	}
    
    else 
	{
		fclose(file); // Fecha o arquivo, pois ele existe

        remove(cpf); // Agora voc� pode remover o arquivo

        printf("Usu�rio deletado!\n"); // comunica��o com usu�rio

        system("pause"); // pausa para usu�rio
	}
}

int main() //definindo o menu
{
	int opcao=0; //Definindo vari�veis de op��o
	int laco=1; //Definindo vari�veis de la�o
	
	for(laco=1;laco=1;)
	{
	    system("cls"); //respons�vel por limpar tela
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("### Cart�rio da EBAC ###\n\n"); //In�co do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n"); 
	    printf("Op��o:");//Fim do menu
	
	    scanf("%d",&opcao); //Armazenando a escolha do usu�rio
	
	    
		system("cls"); //respons�vel por limpar tela
	
	
	    switch(opcao) //Inicio  da sele��o  do menu
		{
			case 1:
		    registro(); //chamada de fun��o
     	    break; //Fim da sele��o
     	    
     	    case 2:
     	    consulta(); //chamada de fun��o
		    break; //Fim da sele��o
		    
		    case 3:
		    deletar(); //chamada de fun��o
    	    break; //Fim da sele��o
    	    
    	    case 4:
    	    printf("Obrigado por utilizar o sistema!\n");
    	    return 0; //quebrar la�o e sair do sistema
    	    break; // Fim da sele��o
    	    
    	     
    	    default:
    	    printf("Essa op��o n�o est� dispon�vel!\n");
		    break; //Fim da sele��o
     	    	
		}
	
	
        
	}
}


