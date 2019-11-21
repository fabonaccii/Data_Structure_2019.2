#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "ordenacaoVetor.h"
#include "ordenacaoLista.h"
using namespace std;

//Função que gera arquivos binarios, cada um contendo numeros aleatorios
void random_data_file_generator(int size_array_size, int *array) {
	for(int i = 0; i < array_size; i++) {
		for(int seed = 0; seed < 5; seed++) {
			string data_file_name = "inputs/file"+"-"+to_string(array[i])+"-"+to_string(seed)+".dat";
			ofstream out_file(data_file_name.c_str(), ios::binary);
			srand(time(NULL));

			for(int j = 0; j < array[i]; j++) {
				int random_number = rand()%1000000;
				//out_file.write((char*)&r, sizeof(r));
				out_file << random_number << " ";
			}
			out_file.close();
		}
	}
}

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void ler_dados(int n, int A[], const char *nomeArquivo) {	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura

	for (int i = 0; i < n; i++)
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor

	fin.close(); // fecha o arquivo de leitura
}

int main() {
	int sizes[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
	
	int size_array_size = 7;
	
	// Etapa 1: Gerar arquivos contendo números aleatórios
	random_data_file_generator(size_array_size, sizes);
	
	// ------------------------------------------------------------
	// Etapa 2 - Execução do CocktailSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs("resultados/resultadoCocktail.txt", ofstream::out ); // abre arquivo de resultados do cocktail
	
	for(int i = 0; i < array_size; i++) {
		
		long double iteractive_bubble_average_time = 0.0;
		int tamanho_vetor = sizes[i]; // pega o tamanho do vetor para esta i
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma seed diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int seed = 0; seed < 5; seed++) {	
			string nome_arquivo = "dados/random"+to_string(i)+"_"+to_string(seed)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// CocktailSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = chrono::high_resolution_clock::now();
		
			CocktailSort(tamanho_vetor, vetor); // ordena o vetor usando o CocktailSort
		
			// obtendo o tempo final
			auto fim = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_cocktail = chrono::duration_cast<chrono::microseconds>(fim - ini).count();
			
			duracao_media_cocktail += duracao_cocktail;
			
		}
		
		duracao_media_cocktail = duracao_media_cocktail / 5.0;
		cout << "[Cocktail] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_cocktail << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media_cocktail << "\n"; // grava no arquivo de resultados do cocktail
	}
	
	ofs.close(); // fecha arquivo de resultados do CockTail Sort
	// ------------------------------------------------------------
	
	
	// ------------------------------------------------------------
	// Etapa 3 - Execução do BubbleSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs2("resultados/resultadoBubble.txt", ofstream::out ); // abre arquivo de resultados do bubblesort
	
	for(int i = 0; i < array_size; i++) {
		
		long double duracao_media_bubble = 0.0;
		int tamanho_vetor = sizes[i]; // pega o tamanho do vetor para esta i
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma seed diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int seed = 0; seed < 5; seed++) {	
			string nome_arquivo = "dados/random"+to_string(i)+"_"+to_string(seed)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// BubbleSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			BubbleSort(tamanho_vetor, vetor); // ordena o vetor usando o CocktailSort
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubble = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_bubble += duracao_bubble;			
		}	
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		cout << "[Bubble] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
		ofs2 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs2.close(); // fecha arquivo de resultados do Bubble Sort
	// ------------------------------------------------------------
	
	return 0;
}
