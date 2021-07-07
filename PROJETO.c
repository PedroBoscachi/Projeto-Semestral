#include  <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


char number;
char name[30];
char prontuario[20];
void test(void);
void question1(void);
void question2(void);
void question3(void);
void question4(void);
void question5(void);
float calculate();
void resultado(void);

int aud[5];
int cin[5];
int vis[5];
int dig[5];




int main(){
	
	setlocale(LC_ALL,"portuguese");
	void createFile(name,prontuario);
	void login(void);
	void layout(void);
	login();
	layout();
	createFile(name,prontuario);
	resultado();
	
		

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
			{
				system("cls");
				printf("Voc� escolheu a op��o 3\n");				
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


void test(void){//fun��o para enunciado do arquivo
	
	printf("\nNas frases a seguir, pontue com: ");
	printf("\n4- a que melhor descreve voc�; ");
	printf("\n3- a pr�xima melhor descri��o; ");
	printf("\n2- a pr�xima melhor; ");
	printf("\n1- aquela que menos descreve voc�. \n");
	
}


void question1(void){
	
	int a1, b1, c1, d1;
			
	printf("\n1. Eu tomo decis�es importantes baseado em: ");
	printf("\na) Intui��o. ");
	printf("\nb) O que me soa melhor. ");
	printf("\nc) O que me parece melhor. ");
	printf("\nd) Um estudo preciso e minucioso do assunto. \n");
	
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
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b1);
		aud[0] = b1;
	}	
	
	printf("[c] -> ");
	scanf("%d", &c1);
	vis[0] = c1;
	while(c1<1 || c1>4 || c1==a1 || c1==b1){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c1);
		vis[0] = c1;
	}	
	
	printf("[d] -> ");
	scanf("%d", &d1);
	dig[0] = d1;
	while(d1<1 || d1>4 || d1==a1 || d1==b1 || d1==c1){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d1);
		dig[0] = d1;
	}
				
}

void question2(void){
	
	int a2, b2, c2, d2;	
	
	printf("\n2. Durante uma discuss�o eu sou mais influenciado por: ");
	printf("\na) O tom da voz da outra pessoa.");
	printf("\nb) Se eu posso ou n�o ver o argumento da outra pessoa.");
	printf("\nc) A l�gica do argumento da outra pessoa.");
	printf("\nd) Se eu entro em contato ou n�o com os sentimentos reais do outro.\n");
	
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
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b2);
		vis[1] = b2;
	}
	
	printf("[c] -> ");
	scanf("%d", &c2);
	dig[1] = c2;
	while(c2<1 || c2>4 || c2==a2 || c2==b2){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c2);
		dig[1] = c2;
	}	
	
	printf("[d] -> ");
	scanf("%d", &d2);
	cin[1] = d2;
	while(d2<1 || d2>4 || d2==a2 || d2==b2 || d2==c2){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
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
		printf("Digite um n�mero v�lido [1-4]\n");
		printf("[a] -> ");
		scanf("%d", &a3);
		vis[2] = a3;	
	}
	
	printf("[b] -> ");
	scanf("%d", &b3);
	cin[2] = b3;	
	while(b3<1 || b3>4 || b3==a3){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b3);
		cin[2] = b3;
	}	
	
	printf("[c] -> ");
	scanf("%d", &c3);
	dig[2] = c3;
	while(c3<1 || c3>4 || c3==a3 || c3==b3){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c3);
		dig[2] = c3;
	}	
	
	printf("[d] -> ");
	scanf("%d", &d3);
	aud[2] = d3;
	while(d3<1 || d3>4 || d3==a3 || d3==b3 || d3==c3){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d3);
		aud[2] = d3;
	}			
}

void question4(void){
	
	int a4, b4, c4, d4;
	
	printf("\n4. � muito f�cil para mim: ");
	printf("\na) Achar o volume e a sintonia ideais num sistema de som.");
	printf("\nb) Selecionar o ponto mais relevante relativo a um assunto interessante.");
	printf("\nc) Escolher os m�veis mais confort�veis.");
	printf("\nd) Escolher as combina��es de cores mais ricas e atraentes.\n");
	
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
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b4);
		dig[3] = b4;	
	}
	
	printf("[c] -> ");
	scanf("%d", &c4);
	cin[3] = c4;
	while(c4<1 || c4>4 || c4==a4 || c4==b4){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c4);
		cin[3] = c4;
	}
	
	printf("[d] -> ");
	scanf("%d", &d4);
	vis[3] = d4;
	while(d4<1 || d4>4 || d4==a4 || d4==b4 || d4==c4){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
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
	printf("\nc) Eu sou muito sens�vel � maneira como a roupa veste meu corpo.");
	printf("\nd) Eu respondo fortemente �s cores e � apar�ncia de uma sala.\n");
	
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
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[b] -> ");
		scanf("%d", &b5);
		dig[4] = b5;
	}	
	
	printf("[c] -> ");
	scanf("%d", &c5);
	cin[4] = c5;
	while(c5<1 || c5>4 || c5==a5 || c5==b5){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[c] -> ");
		scanf("%d", &c5);
		cin[4] = c5;
	}
	
	printf("[d] -> ");
	scanf("%d", &d5);
	vis[4] = d5;
	while(d5<1 || d5>4 || d5==a5 || d5==b5 || d5==c5){
		printf("Digite um n�mero v�lido [1-4] ou ainda n�o utilizado:\n");
		printf("[d] -> ");
		scanf("%d", &d5);
		vis[4] = d5;
	}			
}


float calculate(int type[5]){
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
	printf("Cinest�sico: %.0f%%", calculate(cin));
	printf(" || ");
	printf("Auditivo: %.0f%%", calculate(aud));


	

	return 0;
}




