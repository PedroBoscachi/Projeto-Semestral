#include  <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


char number;
char name[30];
char prontuario[20];
void test(void);
void question(void);


int main(){
	
	setlocale(LC_ALL,"portuguese");
	void createFile(name,prontuario);
	void login(void);
	void layout(void);
	login();
	layout();
	createFile(name,prontuario);

	return 0;
}


void login(void){
	
	
	printf("DIGITE SEU NOME:   ");
	gets(name);
	printf("DIGITE SEU PRONTU�RIO:  ");
	scanf("%s", prontuario);
	
	
	return;
}



void layout(void){

	int compare;
	compare = stricmp(name, "MASTER");

	if(compare == 0)
	{
	system("cls");	
	printf("================================================================================\n");
	printf("\t              TESTE DOS SISTEMAS REPRESENTACIONAIS\n");
	printf("================================================================================\n");
	printf("                      1. Cadastrar question�rio\n");
	scanf("%c", &number);
	printf("                      2. Visualizar question�rio\n");
	printf("                      3. Realizar teste\n");
	printf("                      4. Sobre o teste\n");
	printf("                      F. Fim\n");
	printf("================================================================================\n");
	printf("                      Escolha-> ");
	scanf("%c",&number);
	
	switch(number)
	{
	
		case 49:
			printf("Voc� escolheu a op��o 1\n");
		break;
		case 50:
			printf("Voc� escolheu a op��o 2\n");
		break;
		case 51:
			printf("Voc� escolheu a op��o 3\n");
		break;
		case 52:
			{
				printf("Voc� escolheu a op��o 4\n");
				system("REFERENCIAL_TEORICO.txt"); //mostra o arquivo na tela
				layout();
			}
		break;
		case 102:
			printf("Finalizado\n");
		break;
		case 70:
			printf("Finalizado\n");
		break;
		default:
			system("cls");
			printf("\t     ===========Comando inv�lido===========\n");
			printf("                  \n");
			printf("                  \n");
			system("pause");
			
			layout();
			break;
	};

} else{
	
	system("cls");
	test();
	
}

	return;
}



void createFile(char nome[30], char pront[20]){
	char txt[] = ".txt";
	
	int tamanho;
	int i;
	
	FILE *pont_arq; // cria vari�vel ponteiro para o arquivo
  	char palavra[100]; // vari�vel do tipo string
  
  //abrindo o arquivo com tipo de abertura w
  
  pont_arq = fopen(strcat(strcat(nome,pront),txt), "w");
  
  //testando se o arquivo foi realmente criado
  if(pont_arq == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }
  
  
 
  return;
	
}


void test(void){
	
	printf("Nas frases a seguir, pontue com: ");
	printf("\n4- a que melhor descreve voc�; ");
	printf("\n3- a pr�xima melhor descri��o; ");
	printf("\n2- a pr�xima melhor; ");
	printf("\n1- aquela que menos descreve voc�. ");
	
}


void question1(void){
	
	int a1, b1, c1, d1;
	
	
	
	printf("\n1. Eu tomo decis�es importantes baseado em: ");
	printf("\na) Intui��o. ");
	printf("\nb) O que me soa melhor. ");
	printf("\nc) O que me parece melhor. ");
	printf("\nd) Um estudo preciso e minucioso do assunto. ");
	
	printf("[a] -> ");
	scanf("%d", &a1);
	
	while(a1<1 || a1>4)
	{
		scanf("%d", a1);	
	}
	
	printf("[b] -> ");
	scanf("%d", &b1);
	
	while(b1<1 || b1>4)
	{
		scanf("%d", &b1);
	}
	while(b1 == a1)
	{
		scanf("%d", &b1);
	}
	
	printf("[c] -> ");
	scanf("%d", &c1);
	printf("[d] -> ");
	scanf("%d", &d1);
	
	
	
}




