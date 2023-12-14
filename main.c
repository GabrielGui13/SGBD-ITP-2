#include <stdio.h>
#include <unistd.h>
#include "funcoes/criar.c"
#include "funcoes/busca.c"
#include "funcoes/listar.c"
#include "funcoes/auxiliares.c"

void imprimirSeletor() {
	sleep(2);
	printf("\n*** Bem-vindo ao SGBD ITP! ***\n");
	sleep(1);
	printf("> 0. Encerrar\n");
	printf("> 1. Criar uma tabela\n");
	printf("> 2. Listar todas as tabelas\n");
	printf("> 3. Criar uma linha na tabela\n");
	printf("> 4. Listar dados de uma tabela\n");
	printf("> 5. Procurar valor em uma tabela\n");
	printf("> 6. Apagar uma linha na tabela\n");
	printf("> 7. Apagar uma tabela\n");
}

int main(){
	int seletor;

	printf("teste");

	while(1) {
		int seletor;
		Tabela tabela;
		imprimirSeletor();

		scanf("%d", &seletor);

		switch (seletor) {
			case 0:
				return 0;
			case 1:
				criarTabela(&tabela);
				break;
			case 2:
				listarTabelas();
				break;
			case 3:
				criarRegistro(&tabela);
				break;
			case 4:
				listarDadosTabela(&tabela);
				break;
			case 5:
				procurarValor(&tabela);
				break;
			case 6:
				apagarRegistro(&tabela);
				break;
			case 7:
				apagarTabela();
				break;
			default:
				printf("INVALIDO! \n");
				break;
		}
	}
	
	return 0;
}