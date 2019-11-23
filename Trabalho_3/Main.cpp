#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "ordenacaoVetor.h"
#include "ordenacaoLista.h"
using namespace std;

struct Node {
    int key;
    Node *next;
    Node *prev;
};


void random_data_file_generator(int size_array_size, int *array) {
	for(int i = 0; i < size_array_size; i++) {
		for(int seed = 0; seed < 5; seed++) {
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
			ofstream out_file(data_file_name.c_str(), ios::binary);
			srand(time(NULL));

			for(int j = 0; j < array[i]; j++) {
				int random_number = rand()%1000000;
				out_file.write((char*)&random_number, sizeof(random_number));
			}
			out_file.close();
		}
	}
}




void data_file_read(int array_size, int *array, const char *data_file_name) {	
	ifstream in_file(data_file_name, ios::binary);

	for (int i = 0; i < array_size; i++)
		in_file.read((char*)&array[i], sizeof(int));

	in_file.close();
}

/*void data_file_read_list(int array_size, Node* list , const char *data_file_name){	
	ifstream in_file(data_file_name, ios::binary);

	for (int i = 0; i < array_size; i++)
		in_file.read((char*)&array[i], sizeof(int));
		(list->next)->;
	in_file.close();
}
*/
int main() {
	
	int sizes[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
	int size_array_size = 7;
	
	random_data_file_generator(size_array_size, sizes);

	//Bubble Sort iterativo em vetor
	ofstream output_file_1("outputs/array/iteractiveBubble.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iteractive_bubble_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iteractiveBubbleSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iteractive_bubble_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iteractive_bubble_average_time += iteractive_bubble_duration;
		}
		
		iteractive_bubble_average_time /= 5.0;
		cout << "[Iteractive Bubble] " << array_size << ", Average Runtime = " << iteractive_bubble_average_time << " microseconds" << endl;
		output_file_1 << array_size << " " << iteractive_bubble_average_time << endl;
	}
	output_file_1.close();

	//Bubble Sort recursivo em vetor
	ofstream output_file_2("outputs/array/recursiveBubble.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double recursive_bubble_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			recursiveBubbleSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto recursive_bubble_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			recursive_bubble_average_time += recursive_bubble_duration;
		}
		
		recursive_bubble_average_time /= 5.0;
		cout << "[Recursive Bubble] " << array_size << ", Average Runtime = " << recursive_bubble_average_time << " microseconds" << endl;
		output_file_2 << array_size << " " << recursive_bubble_average_time << endl;
	}
	output_file_2.close();

	//Insertion Sort iterativo em vetor
	ofstream output_file_3("outputs/array/iteractiveInsertion.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iteractive_insertion_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iteractiveInsertionSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iteractive_insertion_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iteractive_insertion_average_time += iteractive_insertion_duration;
		}
		
		iteractive_insertion_average_time /= 5.0;
		cout << "[Iteractive Insertion] " << array_size << ", Average Runtime = " << iteractive_insertion_average_time << " microseconds" << endl;
		output_file_3 << array_size << " " << iteractive_insertion_average_time << endl;
	}
	output_file_3.close();
	
	//Insertion Sort recursivo em vetor
	ofstream output_file_4("outputs/array/recursiveInsertion.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double recursive_insertion_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			recursiveInsertionSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto recursive_insertion_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			recursive_insertion_average_time += recursive_insertion_duration;
		}
		
		recursive_insertion_average_time /= 5.0;
		cout << "[Recursive Insertion] " << array_size << ", Average Runtime = " << recursive_insertion_average_time << " microseconds" << endl;
		output_file_4 << array_size << " " << recursive_insertion_average_time << endl;
	}
	output_file_4.close();

	//Selection Sort iterativo em vetor
	ofstream output_file_5("outputs/array/iteractiveSelection.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iteractive_selection_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iteractiveSelectionSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iteractive_selection_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iteractive_selection_average_time += iteractive_selection_duration;
		}
		
		iteractive_selection_average_time /= 5.0;
		cout << "[Iteractive Selection] " << array_size << ", Average Runtime = " << iteractive_selection_average_time << " microseconds" << endl;
		output_file_5 << array_size << " " << iteractive_selection_average_time << endl;
	}
	output_file_5.close();

	//Selection Sort recursivo em vetor
	ofstream output_file_6("outputs/array/recursiveSelection.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double recursive_selection_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			recursiveSelectionSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto recursive_selection_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			recursive_selection_average_time += recursive_selection_duration;
		}
		
		recursive_selection_average_time /= 5.0;
		cout << "[Recursive Selection] " << array_size << ", Average Runtime = " << recursive_selection_average_time << " microseconds" << endl;
		output_file_6 << array_size << " " << recursive_selection_average_time << endl;
	}
	output_file_6.close();

	//Merge Sort recursivo em vetor
	ofstream output_file_8("outputs/array/recursiveMerge.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double recursive_merge_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			recursiveMergeSort(array, 0, array_size-1);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto recursive_merge_duration = chrono::duration_cast <chrono::milliseconds> (final_clock - inicial_clock).count();
			
			recursive_merge_average_time += recursive_merge_duration;
		}
		
		recursive_merge_average_time /= 5.0;
		cout << "[Recursive Merge] " << array_size << ", Average Runtime = " << recursive_merge_average_time << " milliseconds" << endl;
		output_file_8 << array_size << " " << recursive_merge_average_time << endl;
	}
	output_file_8.close();

	//HeapSort Iterativo em vetor
	ofstream output_file_9("outputs/array/iteractiveBubble.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iteractive_bubble_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iteractiveHeapSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iteractive_bubble_duration = chrono::duration_cast <chrono::milliseconds> (final_clock - inicial_clock).count();
			
			iteractive_bubble_average_time += iteractive_bubble_duration;
		}
		
		iteractive_bubble_average_time /= 5.0;
		cout << "[Iteractive HeapSort] " << array_size << ", Average Runtime = " << iteractive_bubble_average_time << " milliseconds" << endl;
		output_file_9 << array_size << " " << iteractive_bubble_average_time << endl;
	}
	output_file_9.close();


	//Quick Sort recursivo em vetor
	ofstream output_file_10("outputs/array/recursiveQuick.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double recursive_quick_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			recursiveQuickSort(array, 0, array_size-1);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto recursive_quick_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			recursive_quick_average_time += recursive_quick_duration;
		}
		
		recursive_quick_average_time /= 5.0;
		cout << "[Recursive Quick] " << array_size << ", Average Runtime = " << recursive_quick_average_time << " microseconds" << endl;
		output_file_10 << array_size << " " << recursive_quick_average_time << endl;
	}
	output_file_10.close();

/*
//BubbleSort Iterativo em lista
	ofstream output_file_13("outputs/array/iteractiveBubble.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iteractive_bubble_list_average_time = 0.0;
		int array_size = sizes[i];
		
        List *list = new List();
		
        for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iteractiveBubbleSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iteractive_bubble_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iteractive_bubble_list_average_time += iteractive_bubble_duration;
		}
		
		iteractive_bubble_list_average_time /= 5.0;
	
		list->~List(); // deleta a lista
	}

    output_file_13.close();
*/



	return 0;
}

