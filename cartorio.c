#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação  de espaço em memória
#include <locale.h> //biblioteca  de alocações  de texto  por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // função responsável por cadastrar o usuário no sistema
{
	//início da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário (printf = converçar com usuário)
	scanf("%s", cpf); //%s refere-se as string
	
	strcpy(arquivo, cpf); //Responsável por copiar os  valores  das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w");  // w de write (escrever) Cria o arquivo
	fprintf(file,cpf); // Salvo o valor na variável CPF
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); // armazena o aqruivo solicitado
	fprintf(file, ","); // virgula entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", nome); //%s refere-se as string
	
	file = fopen(arquivo, "a"); //armazena o arquivo 
	fprintf(file,nome); //Salvor na variável nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file, ",");// virgula entre os dados
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // comunica com o usuário
	scanf("%s", sobrenome); //%s refere-se as string
	
    file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file,sobrenome);  //Salvor na variável sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file, ","); // virgula entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // comunica com o usuário
	scanf("%s", cargo); //%s refere-se as string
	
	file = fopen(arquivo, "a"); // busca o aqruivo solicitado
	fprintf(file,cargo); //Salvor na variável cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); // pausa para usuário 
	
}
	int consulta() // função responsável por consultar o usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // variável string CPF
	char conteudo[200]; 
	
	printf("Digite o CPF a ser consultado: "); // comunicação com o usuário
	scanf("%s", cpf); //%s refere-se as string
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf, "r"); // abrir e ler o aquivo (r) de read
	
	if(file == NULL) // e se o arquivo pesquisado for igual a nulo 
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); // comunicação com o usuário
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto a busca der nula 
	{
	    printf("\n Essas são  as informações do usuário: "); // comunicação com o usuário
		printf("%s" , conteudo); 
		printf("\n\n");	// \n = pular linha
	}
	
	system("pause"); // pausa para o usuário
	
}
int deletar()
{
	char cpf[40]; // variável string CPF
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf); // String são conjuntos de variáveis.
    
    remove(cpf); 
    
    FILE *file; //criar pasta/arquivo
    file = fopen(cpf, "r"); // Buscar e ler no aquivo salvo
    
    if(file == NULL) //e se o aqruivo for nulo
	{ 
	    printf("O usuário não se  encontra no sistema!.\n"); // comunicação com o usuário
    	system("pause"); // pausa para usuário

	}
    
    else 
	{
		fclose(file); // Fecha o arquivo, pois ele existe

        remove(cpf); // Agora você pode remover o arquivo

        printf("Usuário deletado!\n"); // comunicação com usuário

        system("pause"); // pausa para usuário
	}
}

int main() //definindo o menu
{
	int opcao=0; //Definindo variáveis de opção
	int laco=1; //Definindo variáveis de laço
	
	for(laco=1;laco=1;)
	{
	    system("cls"); //responsável por limpar tela
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("### Cartório da EBAC ###\n\n"); //Iníco do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n"); 
	    printf("Opção:");//Fim do menu
	
	    scanf("%d",&opcao); //Armazenando a escolha do usuário
	
	    
		system("cls"); //responsável por limpar tela
	
	
	    switch(opcao) //Inicio  da seleção  do menu
		{
			case 1:
		    registro(); //chamada de função
     	    break; //Fim da seleção
     	    
     	    case 2:
     	    consulta(); //chamada de função
		    break; //Fim da seleção
		    
		    case 3:
		    deletar(); //chamada de função
    	    break; //Fim da seleção
    	    
    	    case 4:
    	    printf("Obrigado por utilizar o sistema!\n");
    	    return 0; //quebrar laço e sair do sistema
    	    break; // Fim da seleção
    	    
    	     
    	    default:
    	    printf("Essa opção não está disponível!\n");
		    break; //Fim da seleção
     	    	
		}
	
	
        
	}
}


