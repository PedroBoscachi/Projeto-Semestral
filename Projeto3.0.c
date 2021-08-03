#include  <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

char resultados[100] = "RESULTADO_";
char number, name[30], prontuario[20];
void createFile(name,prontuario);
void test(void);
void question1(void);
void question2(void);
void question3(void);
void question4(void);
void question5(void);
float calculate();
void interface3(void);
void perfil(void);
int questionario(void);
void copiarArquivo(FILE *file_quest, FILE *file_quest2);
void option2(void);
void perfils(void);
int aud[5], cin[5], vis[5], dig[5];
int nrofrase[5] = {1,2,3,4,5};
char frase[5][100], item_1[5][100], item_2[5][100], item_3[5][100], item_4[5][100];
char perfis[4][100] = {"Cinestesico","Auditivo","Visual","Digital"};
char error[] = "Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n";
char perfilDominante[100] = "";
int auxiliar = 0, file_conter=0;
FILE *file_quest;

int main(){	
	setlocale(LC_ALL,"portuguese");	
	void layout(void);	
	printf("DIGITE SEU NOME:   ");
	gets(name);
	printf("DIGITE SEU PRONTU�RIO:  ");
	scanf("%s", prontuario);
	int compare;
	compare = stricmp(name, "MASTER"); //coloquei aqui para simplificar
	if(compare == 0){
		layout();
	}
	else{
		interface3();		
	}					
	return 0;				
}

void layout(void){
	int auxi;	
	void customQuest(void);	

	setbuf(stdin,NULL);	
	system("cls");	
	printf("================================================================================\n");
	printf("\t              TESTE DOS SISTEMAS REPRESENTACIONAIS\n");
	printf("================================================================================\n");
	printf("                      1. Cadastrar question�rio\n");
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
			system("cls");									
			questionario();
			layout();
		break;
		case 50:
			option2();
			system("QUESTION�RIO_1.txt");
			layout();
		break;
		case 51:
			{
				if(auxiliar == 1){
				printf("\n");			
				printf("Qual teste deseja realizar?\n");								
				printf("1. Padr�o\n");
				printf("2. Personalizado\n");
				scanf("%i",&auxi);
				switch(auxi){					
					case 1:
						system("cls");
						interface3();
						layout();
						break;
					case 2:
						customQuest();
						createFile(name,prontuario);
						system(resultados);
						layout();
						break;
				}				
				} else{
					interface3();
					layout();
				}										
			}
		break;
		case 52:
			{			
				FILE *pont_ref;
				pont_ref = fopen("REFERENCIAL_TEORICO.txt","w");
				fprintf(pont_ref, "Referencial te�rico\nSegundo Albert Merabian, em seu livro �Silent Messages�, o poder de influ�ncia das palavras n�o passa de 7%%, \nenquanto a forma como as palavras s�o ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.\n\nPara Merabian 55%% do impacto da comunica��o � n�o-verbal. Corresponde � postura, gestos e contato visual da pessoa enquanto se comunica.\n");
				fprintf(pont_ref, "\nO tom da voz representa 38%% do impacto da comunica��o.\n\nPor fim, as palavras propriamente ditas det�m 7%% do impacto da comunica��o.\n\nAssim sendo, conclui Merabian, n�o � o que dizemos, mas como dizemos que faz a diferen�a na comunica��o.\n");
				fprintf(pont_ref, "\nAs portas da percep��o s�o os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos �nicos pontos de contato com o mundo exterior. \nDa mesma forma que utilizamos os sentidos para filtrarmos as experi�ncias, utilizamos sentidos para estruturar nosso pensamento e nossa comunica��o.");
				fprintf(pont_ref, "\nDe acordo com a Programa��o Neurolingu�stica existem os seguintes sistemas representacionais.\n-Auditivo\n-Digital\n-Cinest�sico\n-Visual\n\nAlgumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.\n");
				fprintf(pont_ref, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.\nAs cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas e as emo��es.\nJ� as pessoas visuais aprendem melhor quando se valendo da vis�o.\n");
				fprintf(pont_ref, "\nCada pessoa tem um sistema representacional predominante e adequar a comunica��o ao sistema representacional dominante dela fundamental\npara di�logos eficientes.\n");
				fclose(pont_ref);
				system("REFERENCIAL_TEORICO.txt");
				layout();
		}
		break;
		case 102:
			printf("Finalizado\n");			
			exit(0);
		break;
		case 70:
			printf("Finalizado\n");						
			exit(0);
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
	return;
} 	
	
void createFile(char nome[30], char pront[20]){

	char txt[5] = ".txt", replacement = '_', file_name[30];


	//resultados[100] = "RESULTADO_";
	int tamanho, i;
	char user[30] = "";
	strcpy(user,nome);	 
	FILE *pont_arq; // cria vari�vel ponteiro para o arquivo 
 
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
  
  perfils();
  if(file_conter == 0){
  	strcat(resultados,file_name);
	  file_conter = 1;	
  } 
  pont_arq = fopen(resultados, "w");  
  fprintf(pont_arq, "================ Perfil representacional de %s ================\n",user);
  fprintf(pont_arq, "Visual: %.0f%% || Auditivo: %.0f%% || Cinest�sico: %.0f%% || Digital: %.0f%%\n================================================================================================================================================\n* Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.\n* Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.\n* As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas e as emo��es..\n* J� as pessoas visuais aprendem melhor quando se valendo da vis�o.\n", calculate(vis),calculate(aud),calculate(cin),calculate(dig));
  fprintf(pont_arq, "================================================================================================================================================\n");
  fprintf(pont_arq, "\nSeu perfil �: %s", perfilDominante);	  
  fclose(pont_arq);
  printf("%s", pont_arq);
  system("pause");          
  
  if(pont_arq == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }
  	

  return 0;	
}

void test(void){//fun��o para enunciado do arquivo	
	printf("\nNas frases a seguir, pontue com: \n4- a que melhor descreve voc�; \n3- a pr�xima melhor descri��o; \n2- a pr�xima melhor; \n1- aquela que menos descreve voc�. \n");
}

void question1(void){	
	int a1, b1, c1, d1;
			
	printf("\n1. Eu tomo decis�es importantes baseado em: \na) Intui��o. \nb) O que me soa melhor. \nc) O que me parece melhor. \nd) Um estudo preciso e minucioso do assunto. \n");	
	printf("\n");	
	printf("[a] -> ");
	scanf("%d", &a1);
	cin[0] = a1;	
	while(a1<1 || a1>4){
		printf("Digite um n�mero v�lido [1-4]:\n");
		printf("[a] -> ");
		scanf("%d", &a1);
		cin[0] = a1;	
	}	
	printf("[b] -> ");
	scanf("%d", &b1);
	aud[0] = b1;	
	while(b1<1 || b1>4 || b1==a1){
		printf("%s", error);
		printf("[b] -> ");
		scanf("%d", &b1);
		aud[0] = b1;
	}		
	printf("[c] -> ");
	scanf("%d", &c1);
	vis[0] = c1;
	while(c1<1 || c1>4 || c1==a1 || c1==b1){
		printf("%s", error);
		printf("[c] -> ");
		scanf("%d", &c1);
		vis[0] = c1;
	}		
	printf("[d] -> ");
	scanf("%d", &d1);
	dig[0] = d1;
	while(d1<1 || d1>4 || d1==a1 || d1==b1 || d1==c1){
		printf("%s", error);
		printf("[d] -> ");
		scanf("%d", &d1);
		dig[0] = d1;
	}				
}

void question2(void){	
	int a2, b2, c2, d2;	
	
	printf("\n2. Durante uma discuss�o eu sou mais influenciado por: \na) O tom da voz da outra pessoa.\nb) Se eu posso ou n�o ver o argumento da outra pessoa.\nc) A l�gica do argumento da outra pessoa.\nd) Se eu entro em contato ou n�o com os sentimentos reais do outro.\n");		
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a2);
	aud[1] = a2;	
	while(a2<1 || a2>4){
		printf("Digite um n�mero v�lido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a2);
		aud[1] = a2;	
	}	
	printf("[b] -> ");
	scanf("%d", &b2);
	vis[1] = b2;	
	while(b2<1 || b2>4 || b2==a2){
		printf("%s", error);
		printf("[b] -> ");
		scanf("%d", &b2);
		vis[1] = b2;
	}	
	printf("[c] -> ");
	scanf("%d", &c2);
	dig[1] = c2;
	while(c2<1 || c2>4 || c2==a2 || c2==b2){
		printf("%s", error);
		printf("[c] -> ");
		scanf("%d", &c2);
		dig[1] = c2;
	}		
	printf("[d] -> ");
	scanf("%d", &d2);
	cin[1] = d2;
	while(d2<1 || d2>4 || d2==a2 || d2==b2 || d2==c2){
		printf("%s", error);
		printf("[d] -> ");
		scanf("%d", &d2);
		cin[1] = d2;
	}			
}

void question3(void){	
	int a3, b3, c3, d3;
	
	printf("\n3. Eu comunico mais facilmente o que se passa comigo: \na) Do modo como me visto e aparento.\nb) Pelos sentimentos que compartilho.\nc) Pelas palavras que escolho.\nd) Pelo tom da minha voz.\n");	
	printf("\n");
		
	printf("[a] -> ");
	scanf("%d", &a3);
	vis[2] = a3;	
	while(a3<1 || a3>4){
		printf("Digite um n�mero v�lido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a3);
		vis[2] = a3;	
	}	
	printf("[b] -> ");
	scanf("%d", &b3);
	cin[2] = b3;	
	while(b3<1 || b3>4 || b3==a3){
		printf("%s", error);
		printf("[b] -> ");
		scanf("%d", &b3);
		cin[2] = b3;
	}		
	printf("[c] -> ");
	scanf("%d", &c3);
	dig[2] = c3;
	while(c3<1 || c3>4 || c3==a3 || c3==b3){
		printf("%s", error);
		printf("[c] -> ");
		scanf("%d", &c3);
		dig[2] = c3;
	}		
	printf("[d] -> ");
	scanf("%d", &d3);
	aud[2] = d3;
	while(d3<1 || d3>4 || d3==a3 || d3==b3 || d3==c3){
		printf("%s", error);
		printf("[d] -> ");
		scanf("%d", &d3);
		aud[2] = d3;
	}			
}

void question4(void){	
	int a4, b4, c4, d4;
	
	printf("\n4. � muito f�cil para mim: \na) Achar o volume e a sintonia ideais num sistema de som.\nb) Selecionar o ponto mais relevante relativo a um assunto interessante.\nc) Escolher os m�veis mais confort�veis.\nd) Escolher as combina��es de cores mais ricas e atraentes.\n");
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a4);
	aud[3] = a4;	
	while(a4<1 || a4>4){
		printf("Digite um n�mero v�lido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a4);
		aud[3] = a4;	
	}	
	printf("[b] -> ");
	scanf("%d", &b4);
	dig[3] = b4;	
	while(b4<1 || b4>4 || b4==a4){
		printf("%s", error);
		printf("[b] -> ");
		scanf("%d", &b4);
		dig[3] = b4;	
	}	
	printf("[c] -> ");
	scanf("%d", &c4);
	cin[3] = c4;
	while(c4<1 || c4>4 || c4==a4 || c4==b4){
		printf("%s", error);
		printf("[c] -> ");
		scanf("%d", &c4);
		cin[3] = c4;
	}	
	printf("[d] -> ");
	scanf("%d", &d4);
	vis[3] = d4;
	while(d4<1 || d4>4 || d4==a4 || d4==b4 || d4==c4){
		printf("%s", error);
		printf("[d] -> ");
		scanf("%d", &d4);
		vis[3] = d4;
	}	
}

void question5(void){	
	int a5, b5, c5, d5;
	
	printf("\n5. Eu me percebo assim: \na) Se estou muito em sintonia com os sons dos ambientes.\nb) Se sou muito capaz de raciocinar com fatos e dados novos.\nc) Eu sou muito sens�vel � maneira como a roupa veste meu corpo.\nd) Eu respondo fortemente �s cores e � apar�ncia de uma sala.\n");	
	
	printf("\n");
	
	printf("[a] -> ");
	scanf("%d", &a5);
	aud[4] = a5;	
	while(a5<1 || a5>4){
		printf("Digite um n�mero v�lido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a5);
		aud[4] = a5;	
	}	
	printf("[b] -> ");
	scanf("%d", &b5);
	dig[4] = b5;	
	while(b5<1 || b5>4 || b5==a5){
		printf("%s", error);
		printf("[b] -> ");
		scanf("%d", &b5);
		dig[4] = b5;
	}		
	printf("[c] -> ");
	scanf("%d", &c5);
	cin[4] = c5;
	while(c5<1 || c5>4 || c5==a5 || c5==b5){
		printf("%s", error);
		printf("[c] -> ");
		scanf("%d", &c5);
		cin[4] = c5;
	}	
	printf("[d] -> ");
	scanf("%d", &d5);
	vis[4] = d5;
	while(d5<1 || d5>4 || d5==a5 || d5==b5 || d5==c5){
		printf("%s", error);
		printf("[d] -> ");
		scanf("%d", &d5);
		vis[4] = d5;
	}			
}


float calculate(int type[5]){
	int perfil[4], sum = 0, i;	
	float result;	
	
	for(i = 0; i<5 ; i++){
		sum = sum + type[i];
	}	
	result = sum * 2;		
	return result;
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
	createFile(name,prontuario);
	system(resultados);
}


int questionario(void){
	setbuf(stdin,NULL);	
	auxiliar = 1;	
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
	fprintf(file_quest, "========================================================================================================================================================================================================================================================================================================================================================================\n");
	fprintf(file_quest, "%-5s                                          %20s                                         %20s                                                %20s                                                %20s                                                  %20s                                                  %20s                                                  %20s                                                %20s                                               %20s\n", "NroFrase", "Frase", "Cinest�sico", "item_1", "Auditivo", "item_2", "Visual", "item_3", "Digital", "item_4");
	fprintf(file_quest, "========================================================================================================================================================================================================================================================================================================================================================================\n");
	for(i=0; i<5; i++){
		fprintf(file_quest, " %-5d%64s", nrofrase[i], frase[i]);
		fprintf(file_quest, " %55d %72s  ", val, item_1[i]);
		fprintf(file_quest, " %62d %72s  ", val, item_2[i]);
		fprintf(file_quest, " %65d %71s  ", val, item_3[i]);
		fprintf(file_quest, " %62d %69s\n", val, item_4[i]);
		fprintf(file_quest, "========================================================================================================================================================================================================================================================================================================================================================================\n");		
	}
	fclose(file_quest);					
	return 0;	
}

void option2(void){
	file_quest = fopen("TESTE_SISTEMA_REPRESENTACIONAL.dat", "rb");		
	FILE *file_quest2;
	file_quest2 = fopen("QUESTION�RIO_1.txt", "w");	
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

void perfils(void){
	int perfilgroup[4];
	memset(perfilDominante, 0, 100);
	perfilgroup[0] = calculate(cin);
	perfilgroup[1] = calculate(dig);
	perfilgroup[2] = calculate(vis);
	perfilgroup[3] = calculate(aud);
	
	int maior = 0, i, ja;
	
	for(i=0;i<4;i++){
		if(perfilgroup[i] > maior){
			maior = perfilgroup[i];
		}
	}		
	perfilgroup[0] == maior ? strcat(perfilDominante," / Cinest�sico") : ja--;
	perfilgroup[1] == maior ? strcat(perfilDominante," / Digital") : ja--;
	perfilgroup[2] == maior ? strcat(perfilDominante," / Visual") : ja--;
	perfilgroup[3] == maior ? strcat(perfilDominante," / Auditivo") : ja--;	
	return ;	
}

void customQuest(){
	char abc[4][10] = {"a","b","c","d"};		
	int resp, i, j;
	for(i=0;i<5;i++){
		system("cls");
		test();
		printf("\n%i. %s",nrofrase[i],frase[i]);
		printf("\n%s) %s",abc[0],item_1[i]);
		printf("\n%s) %s",abc[1],item_2[i]);
		printf("\n%s) %s",abc[2],item_3[i]);
		printf("\n%s) %s\n",abc[3],item_4[i]);
		printf("\n");
		for(j=0;j<4;j++){
			printf("[%s] -> ", abc[j]);
			scanf("%i",&resp);
			switch(j){
				case 0:
					while(resp <1 || resp>4){
						printf("Digite um n�mero v�lido [1-4]\n");
						printf("[%s] -> ", abc[j]);
						scanf("%i",&resp);
					}
				cin[i] = resp;
				break;
				case 1:
					while(resp <1 || resp>4 || resp == cin[i]){
						printf("%s", error);
						printf("[%s] -> ", abc[j]);
						scanf("%i",&resp);
					}
				aud[i] = resp;
				break;
				case 2:
				while(resp <1 || resp>4 || resp == cin[i] || resp == aud[i]){
						printf("%s", error);
						printf("[%s] -> ", abc[j]);
						scanf("%i",&resp);
					}
				vis[i] = resp;
				break;
				case 3:
					while(resp <1 || resp>4 || resp == cin[i] || resp == aud[i]|| resp == vis[i]){
						printf("%s", error);
						printf("[%s] -> ", abc[j]);
						scanf("%i",&resp);
					}
				dig[i] = resp;
				break;
			}			
		}				
	}			
}

