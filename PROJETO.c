#include  <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>


char number;
char name[30];
char prontuario[20];
void createFile(name,prontuario);
void test(void);
void question1(void);
void question2(void);
void question3(void);
void question4(void);
void question5(void);
float calculate();
void resultado(void);
void interface3(void);
void perfil(void);
int questionario(void);
void copiarArquivo(FILE *file_quest, FILE *file_quest2);
void option2(void);
char perfils();

int aud[5];
int cin[5];
int vis[5];
int dig[5];


char User_Profile[] = "Seu perfil:";
FILE *file_quest;



int main(){
	
	setlocale(LC_ALL,"portuguese");	
	void login(void);
	void layout(void);	
	login();
	int compare;
	compare = stricmp(name, "MASTER"); //coloquei aqui para arrumar o momento do createFile
	if(compare == 0){
		layout();
	}
	else{
		interface3();
		createFile(name,prontuario);
	}					

	return 0;				
}


void login(void){
	
	
	printf("DIGITE SEU NOME:   ");
	gets(name);
	printf("DIGITE SEU PRONTUÁRIO:  ");
	scanf("%s", prontuario);
	
	return;
}



void layout(void){
	setbuf(stdin,NULL);	
	system("cls");	
	printf("================================================================================\n");
	printf("\t              TESTE DOS SISTEMAS REPRESENTACIONAIS\n");
	printf("================================================================================\n");
	printf("                      1. Cadastrar questionário\n");
	printf("                      2. Visualizar questionário\n");
	printf("                      3. Realizar teste\n");
	printf("                      4. Sobre o teste\n");
	printf("                      F. Fim\n");
	printf("================================================================================\n");
	printf("                      Escolha-> ");
	scanf("%c",&number);
	
	switch(number)
	{
	
		case 49:
			system("cls");									
			questionario();
			layout();
		break;
		case 50:
			option2();
			system("QUESTIONÁRIO_1.txt");
			layout();
		break;
		case 51:
			{
				interface3();				
				system("pause");
				layout();				
			}
		break;
		case 52:
			{			
				system("REFERENCIAL_TEORICO.txt"); //mostra o arquivo na tela
				layout();
			}
		break;
		case 102:
			printf("Finalizado\n");
			createFile(name,prontuario);
			exit(0);
		break;
		case 70:
			printf("Finalizado\n");
			createFile(name,prontuario);
			exit(0);
		break;
		default:
			system("cls");
			printf("\t     ===========Comando inválido===========\n");
			printf("                  \n");
			printf("                  \n");
			system("pause");
			
			layout();
			break;
	};
	return;
} 	
	
void createFile(char nome[30], char pront[20]){
	char txt[] = ".txt";
	char replacement = '_';
	char file_name[30];
	char resultados[100] = "RESULTADO_";
	int tamanho;
	int i;
	char user[30] = "";
	strcpy(user,nome);
	 
	FILE *pont_arq; // cria variável ponteiro para o arquivo
  	char palavra[100] = "Eu"; // variável do tipo string
  
  //abrindo o arquivo com tipo de abertura w
  
  strcat(nome," ");
  strcat(nome,pront);
  strcat(nome,txt);
  strcpy(file_name,nome);
  
  for(i=0; i<(strlen(file_name)-1); i++){
  	if(isspace(file_name[i])){
  		file_name[i] = replacement;
	  }	 
	if(file_name[i] == '\n'){
		file_name[i] = replacement;
	} 	
  } 
  strcat(resultados,file_name);
  pont_arq = fopen(resultados, "w");
  
  fprintf(pont_arq, "================ Perfil representacional de %s ================\n",user);
  fprintf(pont_arq, "Visual: %.0f%% || Auditivo: %.0f%% || Cinestésico: %.0f%% || Digital: %.0f%%\n", calculate(vis),calculate(aud),calculate(cin),calculate(dig));
  fprintf(pont_arq, "================================================================================================================================================\n");
  fprintf(pont_arq, "* Algumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.\n");
  fprintf(pont_arq, "* Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais.\n");
  fprintf(pont_arq, "* As cinestésicas aprendem melhor por meio das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções..\n");
  fprintf(pont_arq, "* Já as pessoas visuais aprendem melhor quando se valendo da visão.\n"); 
  fprintf(pont_arq, "================================================================================================================================================\n");
  fprintf(pont_arq, "\nSeu perfil é: %s", perfils());
	
  
  
  fclose(pont_arq);
  printf("%s", pont_arq);
  system("pause");
  
  
  
  
  
  //testando se o arquivo foi realmente criado
  if(pont_arq == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }
  
  return 0;
	
}


void test(void){//função para enunciado do arquivo
	
	printf("\nNas frases a seguir, pontue com: ");
	printf("\n4- a que melhor descreve você; ");
	printf("\n3- a próxima melhor descrição; ");
	printf("\n2- a próxima melhor; ");
	printf("\n1- aquela que menos descreve você. \n");
	
}


void question1(void){
	
	int a1, b1, c1, d1;
			
	printf("\n1. Eu tomo decisões importantes baseado em: ");
	printf("\na) Intuição. ");
	printf("\nb) O que me soa melhor. ");
	printf("\nc) O que me parece melhor. ");
	printf("\nd) Um estudo preciso e minucioso do assunto. \n");
	
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a1);
	cin[0] = a1;	
	while(a1<1 || a1>4){
		printf("Digite um número válido [1-4]:\n");
		printf("[a] -> ");
		scanf("%d", &a1);
		cin[0] = a1;	
	}
	
	printf("[b] -> ");
	scanf("%d", &b1);
	aud[0] = b1;	
	while(b1<1 || b1>4 || b1==a1){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b1);
		aud[0] = b1;
	}	
	
	printf("[c] -> ");
	scanf("%d", &c1);
	vis[0] = c1;
	while(c1<1 || c1>4 || c1==a1 || c1==b1){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c1);
		vis[0] = c1;
	}	
	
	printf("[d] -> ");
	scanf("%d", &d1);
	dig[0] = d1;
	while(d1<1 || d1>4 || d1==a1 || d1==b1 || d1==c1){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d1);
		dig[0] = d1;
	}
				
}

void question2(void){
	
	int a2, b2, c2, d2;	
	
	printf("\n2. Durante uma discussão eu sou mais influenciado por: ");
	printf("\na) O tom da voz da outra pessoa.");
	printf("\nb) Se eu posso ou não ver o argumento da outra pessoa.");
	printf("\nc) A lógica do argumento da outra pessoa.");
	printf("\nd) Se eu entro em contato ou não com os sentimentos reais do outro.\n");
	
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a2);
	aud[1] = a2;	
	while(a2<1 || a2>4){
		printf("Digite um número válido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a2);
		aud[1] = a2;	
	}
	
	printf("[b] -> ");
	scanf("%d", &b2);
	vis[1] = b2;	
	while(b2<1 || b2>4 || b2==a2){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b2);
		vis[1] = b2;
	}
	
	printf("[c] -> ");
	scanf("%d", &c2);
	dig[1] = c2;
	while(c2<1 || c2>4 || c2==a2 || c2==b2){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c2);
		dig[1] = c2;
	}	
	
	printf("[d] -> ");
	scanf("%d", &d2);
	cin[1] = d2;
	while(d2<1 || d2>4 || d2==a2 || d2==b2 || d2==c2){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d2);
		cin[1] = d2;
	}			
}

void question3(void){
	
	int a3, b3, c3, d3;
	
	printf("\n3. Eu comunico mais facilmente o que se passa comigo: ");
	printf("\na) Do modo como me visto e aparento.");
	printf("\nb) Pelos sentimentos que compartilho.");
	printf("\nc) Pelas palavras que escolho.");
	printf("\nd) Pelo tom da minha voz.\n");
	
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a3);
	vis[2] = a3;	
	while(a3<1 || a3>4){
		printf("Digite um número válido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a3);
		vis[2] = a3;	
	}
	
	printf("[b] -> ");
	scanf("%d", &b3);
	cin[2] = b3;	
	while(b3<1 || b3>4 || b3==a3){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b3);
		cin[2] = b3;
	}	
	
	printf("[c] -> ");
	scanf("%d", &c3);
	dig[2] = c3;
	while(c3<1 || c3>4 || c3==a3 || c3==b3){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c3);
		dig[2] = c3;
	}	
	
	printf("[d] -> ");
	scanf("%d", &d3);
	aud[2] = d3;
	while(d3<1 || d3>4 || d3==a3 || d3==b3 || d3==c3){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d3);
		aud[2] = d3;
	}			
}

void question4(void){
	
	int a4, b4, c4, d4;
	
	printf("\n4. É muito fácil para mim: ");
	printf("\na) Achar o volume e a sintonia ideais num sistema de som.");
	printf("\nb) Selecionar o ponto mais relevante relativo a um assunto interessante.");
	printf("\nc) Escolher os móveis mais confortáveis.");
	printf("\nd) Escolher as combinações de cores mais ricas e atraentes.\n");
	
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a4);
	aud[3] = a4;	
	while(a4<1 || a4>4){
		printf("Digite um número válido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a4);
		aud[3] = a4;	
	}
	
	printf("[b] -> ");
	scanf("%d", &b4);
	dig[3] = b4;	
	while(b4<1 || b4>4 || b4==a4){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b4);
		dig[3] = b4;	
	}
	
	printf("[c] -> ");
	scanf("%d", &c4);
	cin[3] = c4;
	while(c4<1 || c4>4 || c4==a4 || c4==b4){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c4);
		cin[3] = c4;
	}
	
	printf("[d] -> ");
	scanf("%d", &d4);
	vis[3] = d4;
	while(d4<1 || d4>4 || d4==a4 || d4==b4 || d4==c4){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d4);
		vis[3] = d4;
	}	
}

void question5(void){
	
	int a5, b5, c5, d5;
	
	printf("\n5. Eu me percebo assim: ");
	printf("\na) Se estou muito em sintonia com os sons dos ambientes.");
	printf("\nb) Se sou muito capaz de raciocinar com fatos e dados novos.");
	printf("\nc) Eu sou muito sensível à maneira como a roupa veste meu corpo.");
	printf("\nd) Eu respondo fortemente às cores e à aparência de uma sala.\n");
	
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a5);
	aud[4] = a5;	
	while(a5<1 || a5>4){
		printf("Digite um número válido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a5);
		aud[4] = a5;	
	}
	
	printf("[b] -> ");
	scanf("%d", &b5);
	dig[4] = b5;	
	while(b5<1 || b5>4 || b5==a5){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b5);
		dig[4] = b5;
	}	
	
	printf("[c] -> ");
	scanf("%d", &c5);
	cin[4] = c5;
	while(c5<1 || c5>4 || c5==a5 || c5==b5){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c5);
		cin[4] = c5;
	}
	
	printf("[d] -> ");
	scanf("%d", &d5);
	vis[4] = d5;
	while(d5<1 || d5>4 || d5==a5 || d5==b5 || d5==c5){
		printf("Digite um número válido [1-4] ou ainda não utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d5);
		vis[4] = d5;
	}			
}


float calculate(int type[5]){
	int perfil[4];
	float result;
	int sum = 0;
	int i;
	
	for(i = 0; i<5 ; i++){
		sum = sum + type[i];
	}
	
	result = sum * 2;
	

	
	return result;
}


void resultado(void){
	
	system("cls");
	printf("\n");
	printf("============================RESULTADO============================");
	printf("\n");
	printf("Visual: %.0f%%", calculate(vis));
	printf(" || ");
	printf("Digital: %.0f%% ", calculate(dig));
	printf(" || ");
	printf("Cinestésico: %.0f%%", calculate(cin));
	printf(" || ");
	printf("Auditivo: %.0f%%", calculate(aud));
	
	printf("\n");
	perfils();
	printf("Seu perfil é: %s", resultado);
	perfils();


	printf("\n");
	
	return 	0;
}

void interface3(void){
	
	system("cls");
	test();
	question1();
	system("cls");
	test();
	question2();
	system("cls");
	test();
	question3();
	system("cls");
	test();
	question4();
	system("cls");
	test();
	question5();	
}


int questionario(void){
	setbuf(stdin,NULL);
	
	int nrofrase[5] = {1,2,3,4,5};
	char frase[5][100];
	char item_1[5][100]; // cinestesico
	char item_2[5][100]; // auditivo
	char item_3[5][100]; // visual
	char item_4[5][100]; // digital
	char perfis[4][100] = {"Cinestesico","Auditivo","Visual","Digital"};
	char aux[100];
	
	int i,j,k;
	for(i=0;i<5;i++){
		system("cls");
		printf("Digite a frase %i: ", nrofrase[i]);
		gets(frase[i]);
		printf("======================================\n");
		
		for(k=0;k<4;k++){
			printf("%s -> %s: ", perfis[k],frase[i]);
			
			switch(k){
				case 0:
				gets(item_1[i]);
				break;
				case 1:
				gets(item_2[i]);
				break;	
				case 2:
				gets(item_3[i]);
				break;	
				case 3:
				gets(item_4[i]);
				break;		
			}							
	}			
	}
	int val = 0;
	file_quest = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat", "wb");	
	
	fprintf(file_quest, "=================================================================================================================================================================================\n");
	fprintf(file_quest, "%-10s%20s %20s%20s%20s%20s%20s%20s%20s%20s\n", "NroFrase", "Frase", "Cinestésico", "item_1", "Auditivo", "item_2", "Visual", "item_3", "Digital", "item_4");
	fprintf(file_quest, "=================================================================================================================================================================================\n");
	for(i=0; i<5; i++){
		fprintf(file_quest, "%-5d%20s     %20d     %20s     %20d     %20s     %20d     %20s     %20d     %20s\n", nrofrase[i], frase[i], val, item_1[i], val, item_2[i], val, item_3[i], val, item_4[i]);
		fprintf(file_quest, "=================================================================================================================================================================================\n");		
	}
	fclose(file_quest);					
	return 0;	
}

void option2(void){
	file_quest = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat", "rb");		
	FILE *file_quest2;
	file_quest2 = fopen("QUESTIONÁRIO_1.txt", "w");
	
	copiarArquivo(file_quest, file_quest2);
	fclose(file_quest2);
	fclose(file_quest);
}


void copiarArquivo(FILE *file_quest, FILE *file_quest2){
	char leitor[10000];
	while(fgets(leitor, 1000, file_quest) != NULL){
		fputs(leitor, file_quest2);
	}
	return 0;
}

char perfils(){
	int perfil[4];
	perfil[0] = calculate(cin);
	perfil[1] = calculate(dig);
	perfil[2] = calculate(vis);
	perfil[3] = calculate(aud);
	
	char resultado[100] = "->";
	
	int maior = 0;
	int i;
	int ja;
	
	for(i=0;i<4;i++){
		if(perfil[i] > maior){
			maior = perfil[i];
		}
	}
	
//	perfil[0] == maior ? printf("/ Cinestésico ") : ja--;
//	perfil[1] == maior ? printf("/ Digital") : ja--;
//	perfil[2] == maior ? printf("/ Visual ") : ja--;
//	perfil[3] == maior ? printf("/ Auditivo ") : ja--;
	
	perfil[0] == maior ? strcat(resultado," / Cinestésico") : ja--;
	perfil[1] == maior ? strcat(resultado," / Digital") : ja--;
	perfil[2] == maior ? strcat(resultado," / Visual") : ja--;
	perfil[3] == maior ? strcat(resultado," / Auditivo") : ja--;

	return resultado;
	
}
	

		





