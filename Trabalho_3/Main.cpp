#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "ordenacaoVetor.h"
#include "ordenacaoLista.h"
using namespace std;

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

int main() {
	
	int sizes[] = {1000, 5000, 10000, 50000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};
	int size_array_size = 11;
	
	random_data_file_generator(size_array_size, sizes);
	
	cout << "Vetor:" << endl;

	//Bubble Sort iterativo em vetor
	ofstream output_file_1("outputs/array/iterativeBubble.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iterative_bubble_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iterativeBubbleSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iterative_bubble_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iterative_bubble_average_time += iterative_bubble_duration;
		}
		
		iterative_bubble_average_time /= 5.0;
		cout << "[Iterative Bubble] " << array_size << ", [Average Runtime] = " << iterative_bubble_average_time << " microseconds" << endl;
		output_file_1 << array_size << " " << iterative_bubble_average_time << endl;
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
		cout << "[Recursive Bubble] " << array_size << ", [Average Runtime] = " << recursive_bubble_average_time << " microseconds" << endl;
		output_file_2 << array_size << " " << recursive_bubble_average_time << endl;
	}
	output_file_2.close();

	//Insertion Sort iterativo em vetor
	ofstream output_file_3("outputs/array/iterativeInsertion.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iterative_insertion_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iterativeInsertionSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iterative_insertion_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iterative_insertion_average_time += iterative_insertion_duration;
		}
		
		iterative_insertion_average_time /= 5.0;
		cout << "[Iterative Insertion] " << array_size << ", [Average Runtime] = " << iterative_insertion_average_time << " microseconds" << endl;
		output_file_3 << array_size << " " << iterative_insertion_average_time << endl;
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
		cout << "[Recursive Insertion] " << array_size << ", [Average Runtime] = " << recursive_insertion_average_time << " microseconds" << endl;
		output_file_4 << array_size << " " << recursive_insertion_average_time << endl;
	}
	output_file_4.close();

	//Selection Sort iterativo em vetor
	ofstream output_file_5("outputs/array/iterativeSelection.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iterative_selection_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iterativeSelectionSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iterative_selection_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iterative_selection_average_time += iterative_selection_duration;
		}
		
		iterative_selection_average_time /= 5.0;
		cout << "[Iterative Selection] " << array_size << ", [Average Runtime] = " << iterative_selection_average_time << " microseconds" << endl;
		output_file_5 << array_size << " " << iterative_selection_average_time << endl;
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
		cout << "[Recursive Selection] " << array_size << ", [Average Runtime] = " << recursive_selection_average_time << " microseconds" << endl;
		output_file_6 << array_size << " " << recursive_selection_average_time << endl;
	}
	output_file_6.close();

	//Merge Sort iterativo em vetor
	ofstream output_file_7("outputs/array/iterativeMerge.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iterative_merge_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iterativeMergeSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iterative_merge_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iterative_merge_average_time += iterative_merge_duration;
		}
		
		iterative_merge_average_time /= 5.0;
		cout << "[Iterative Merge] " << array_size << ", [Average Runtime] = " << iterative_merge_average_time << " microseconds" << endl;
		output_file_7 << array_size << " " << iterative_merge_average_time << endl;
	}
	output_file_7.close();

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
		
			auto recursive_merge_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			recursive_merge_average_time += recursive_merge_duration;
		}
		
		recursive_merge_average_time /= 5.0;
		cout << "[Recursive Merge] " << array_size << ", [Average Runtime] = " << recursive_merge_average_time << " microseconds" << endl;
		output_file_8 << array_size << " " << recursive_merge_average_time << endl;
	}
	output_file_8.close();

	//Heap Sort iterativo em vetor
	ofstream output_file_9("outputs/array/iterativeHeap.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iterative_heap_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iterativeHeapSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iterative_heap_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iterative_heap_average_time += iterative_heap_duration;
		}
		
		iterative_heap_average_time /= 5.0;
		cout << "[Iterative Heap] " << array_size << ", [Average Runtime] = " << iterative_heap_average_time << " microseconds" << endl;
		output_file_9 << array_size << " " << iterative_heap_average_time << endl;
	}
	output_file_9.close();

	//Heap Sort recursivo em vetor
	ofstream output_file_10("outputs/array/recursiveHeap.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double recursive_heap_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			recursiveHeapSort(array, array_size);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto recursive_heap_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			recursive_heap_average_time += recursive_heap_duration;
		}
		
		recursive_heap_average_time /= 5.0;
		cout << "[Recursive Heap] " << array_size << ", [Average Runtime] = " << recursive_heap_average_time << " microseconds" << endl;
		output_file_10 << array_size << " " << recursive_heap_average_time << endl;
	}
	output_file_10.close();

	//Quick Sort iterativo em vetor
	ofstream output_file_11("outputs/array/iterativeQuick.txt", ofstream::out );
	for(int i = 0; i < size_array_size; i++) {
		
		long double iterative_quick_average_time = 0.0;
		int array_size = sizes[i];
		int array[array_size];
	
		for(int seed = 0; seed < 5; seed++) {	
			string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
		
			data_file_read(array_size, array, data_file_name.c_str());
			
			auto inicial_clock = chrono::high_resolution_clock::now();

			iterativeQuickSort(array, 0, array_size-1);
		
			auto final_clock = chrono::high_resolution_clock::now();
		
			auto iterative_quick_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
			
			iterative_quick_average_time += iterative_quick_duration;
		}
		
		iterative_quick_average_time /= 5.0;
		cout << "[Iterative Quick] " << array_size << ", [Average Runtime] = " << iterative_quick_average_time << " microseconds" << endl;
		output_file_11 << array_size << " " << iterative_quick_average_time << endl;
	}
	output_file_11.close();

	//Quick Sort recursivo em vetor
	ofstream output_file_12("outputs/array/recursiveQuick.txt", ofstream::out );
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
		cout << "[Recursive Quick] " << array_size << ", [Average Runtime] = " << recursive_quick_average_time << " microseconds" << endl;
		output_file_12 << array_size << " " << recursive_quick_average_time << endl;
	}
	output_file_12.close();

	cout << endl << "Lista:" << endl;

	//BubbleSort Iterativo em lista
    ofstream output_file_13("outputs/list/iterativeBubble.txt", ofstream::out );
    for(int i = 0; i < size_array_size; i++) {
        
        long double iterative_bubble_average_time = 0.0;
        int array_size = sizes[i];
        int array[array_size];
        
        List *list = new List();
        
        for(int seed = 0; seed < 5; seed++) {   
            string data_file_name = "inputs/file-"+to_string(array[i])+"-"+to_string(seed)+".dat";
        
            list->data_file_read_list(array_size, array, data_file_name.c_str());
            
            auto inicial_clock = chrono::high_resolution_clock::now();
            
            list->bubbleSort();
			
            auto final_clock = chrono::high_resolution_clock::now();
        
            auto iterative_bubble_duration = chrono::duration_cast <chrono::microseconds> (final_clock - inicial_clock).count();
            
            iterative_bubble_average_time += iterative_bubble_duration;
        }
        iterative_bubble_average_time /= 5.0;
        cout << "[Iterative Bubble] " << array_size << ", [Average Runtime] = " << iterative_bubble_average_time << " microseconds" << endl;
        output_file_13 << array_size << " " << iterative_bubble_average_time << endl;
		list->~List();
	}
        output_file_13.close();
}
