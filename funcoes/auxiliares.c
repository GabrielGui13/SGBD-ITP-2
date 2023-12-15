#include "auxiliares.h"

Tabela coletarDadosTabela(char nome[])
{
	Tabela tabela;
	FILE *arquivo;
	char nomeArquivo[NOME_LIMITE * 2];
	sprintf(nomeArquivo, "tabelas/%s.txt", nome);

	arquivo = fopen(nomeArquivo, "rb");
	if (arquivo == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO %s \n", nomeArquivo);
		strcpy(tabela.nome, "");
		tabela.numColunas = 0;
		tabela.colunas = NULL;
		strcpy(tabela.colunaChavePrimaria, "");
		return tabela;
	}

	// Leitura dos dados do arquivo
	fscanf(arquivo, "nome: %s\n", tabela.nome);
	fscanf(arquivo, "numeroColunas: %d\n", &(tabela.numColunas));
	fscanf(arquivo, "colunaChavePrimaria: %s\n", tabela.colunaChavePrimaria);
	tabela.colunas = malloc(tabela.numColunas * sizeof(Coluna));
	if (tabela.colunas == NULL)
	{
		printf("ERRO AO ALOCAR MEMORIA PARA AS COLUNAS\n");
		exit(1);
	}
	for (int i = 0; i < tabela.numColunas; i++)
	{
		fscanf(arquivo, "nomeColuna: %s\n", tabela.colunas[i].nome);
		fscanf(arquivo, "tipoColuna: %d\n", &tabela.colunas[i].tipo);
	}

	fclose(arquivo);
	return tabela;
}

int existeChavePrimaria(Tabela *tabela, int num)
{
	FILE *arquivo;
	char nomeArquivo[NOME_LIMITE + 4];
	sprintf(nomeArquivo, "tabelas/%s.txt", tabela->nome);

	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO %s \n", nomeArquivo);
		return 0;
	}

	char chavePrimaria[NOME_LIMITE];
	int valor;
	// Modificando o formato de leitura para se adaptar ao conteúdo do arquivo
	while (fscanf(arquivo, "%[^:]: ", chavePrimaria) == 1)
	{
		// Leitura do valor da chave primária
		if (strcmp(chavePrimaria, tabela->colunaChavePrimaria) == 0)
		{
			fscanf(arquivo, "%d", &valor);
			// Verificar se o valor corresponde à chave primária
			if (valor == num)
			{
				fclose(arquivo);
				return 1; // Retorna 1 se encontrar a chave primária com valor igual
			}
		}
		else
		{
			// Se a chave primária não corresponde, avança para a próxima linha
			fgets(chavePrimaria, NOME_LIMITE, arquivo);
		}
	}

	fclose(arquivo);
	return 0; // Retorna 0 se não encontrar a chave primária com valor igual
}

int existeTabela(char nome[])
{
	const char* caminho = "./tabelas";
	struct dirent* entrada;
	DIR* pasta;
	int existe = 0;

	pasta = opendir(caminho);
	if (pasta == NULL) {
		perror("Não foi possível abrir a pasta!");
		return;
	}

	while ((entrada = readdir(pasta)) != NULL) {
			if (strstr(entrada->d_name, nome + '.txt')) existe = 1;
	}

	return existe;
}

int existeValorNaString(char valor[], char string[])
{
	if (strlen(valor) > strlen(string))
	{
		return 0;
	}
	for (unsigned int i = 0; i <= strlen(string) - strlen(valor); i++)
	{
		int esta = 1;
		for (unsigned int j = 0; j < strlen(valor); j++)
		{
			if (tolower(valor[j]) != tolower(string[i + j]))
			{
				esta = 0;
				break;
			}
		}
		if (esta)
		{
			return 1; // Valor encontrado na string
		}
	}
	return 0; // Valor não encontrado na string
}