#include <stdio.h>
#include <windows.h>
//#include <stdlib.h>
//#include <string.h> 

typedef struct agenda{
	char nome[50];
	char telefone[20];
}Agenda;

// prototipo de função
void entrada(void);
void gravar(Agenda a);
Agenda leitura(void);
Agenda exclusao(void);

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

int main(void){
	
	int menu;
	

	do{
		printf("Agenda Telefonica\n");
		printf("Digite 1 para criar novo contato\n");
		printf("Digite 2 para ver a agenda\n");
		printf("Digite 3 para excluir um contato\n");
		printf("Digite 4 para sair\n");
		printf("Digite a opcao desejada: ");
		scanf("%i" ,&menu);
		fflush(stdin);
		system("cls");
			switch (menu){
		case 1:
     	entrada();
   		break;

   case 2:
     leitura();
   	break;
   	
   	case 3:
   		leitura();
   		excluir();
   		break;
	
	case 4:
	printf("Saindo...")	;
	break;
	
   default:
     printf ("Opcao invalida\n\n");
}
	}while (menu != 4);

	return 0;
	}	

void entrada(void){
	gotoxy (25,5);
	Agenda a;
	system("cls");
	
	printf("Digite o Nome: ");
	gets(a.nome);
	fflush(stdin);
	
	
	printf("Digite o Telefone: ");
	gets(a.telefone);
	fflush(stdin);
	
	gravar(a);
	system("cls");
	printf("Contato salvo com sucesso!!!\n\n\n");
	
}

void gravar(Agenda a){
	
	FILE * arquivo;
	arquivo = fopen("Agenda.txt","a+");
	fprintf(arquivo,"%s || %s \n",a.nome,a.telefone);
	fclose(arquivo);
}

Agenda leitura(void){
	Agenda a;
	char leitura [100];
	int x=25;
	int y=6;
	int id=1;
	
	
	FILE * arquivo;
	arquivo = fopen("Agenda.txt","r+");
	
	gotoxy (25,5);
	printf("ID    Nome \t--------------------- \tTelefone\n");
	
	while(fgets(leitura,100,arquivo) != NULL){
		gotoxy (x,y);
		printf("%i     %s",id,leitura);
		y++;
		id++;
	}
	printf("\n\n\n\n");
	fclose(arquivo);
	return a;
} 
	

int excluir(void){
	
	int linha;
	int flag=0;
	
	printf("Digite a ID do contato que deseja deletar: ");
	scanf("%i" ,&linha);
	fflush(stdin);
	
    FILE *input = fopen("Agenda.txt", "r"); //Arquivo de entrada.
    FILE *output = fopen("transferindo.txt", "w"); //Arquivo de saída.
    char texto[1001]; //Uma string larga o suficiente para extrair o texto total de cada linha.
    int linha_selecionada = linha;
    int linha_atual = 1;
    while(fgets(texto, 1001, input) != NULL){
        if(linha_atual != linha_selecionada){
            fputs(texto, output);
            //printf("%s" ,texto);
        }else{
        memset(texto, 0, sizeof(char) * 1001);
        flag = 1;
        }
        linha_atual += 1;
    }
    fclose(input);
    fclose(output);
    remove("Agenda.txt");
    rename("transferindo.txt", "Agenda.txt");
    if(flag == 1){
    system("cls");
    printf("Contato removido com sucesso! \n\n");
}else{
	system("cls");
	printf("Contato nao encontrado... \n\n");
}
    return 0;
}



