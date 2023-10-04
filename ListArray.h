#include "List.h"
#include <ostream>

using namespace std;

template <typename T> class ListArray : public List<T>{
	private:
		T *arr;
		int max;
		int n;
		static const int MINSIZE = 2;
	public:
		ListArray(){
			arr = new T[MINSIZE];
			n = 0;
			max = 2;
		}

		~ListArray(){
			delete[] arr;
		}

		T operator[](int pos){
			if(pos < 0 || pos > max) throw out_of_range("Posicion del array no valida\n");
			else{
				return arr[pos];		
			}
		}

		friend ostream& operator <<(ostream &out, const ListArray<T> &list){
			for(int i = 0; i<max; i++){
				out << list[i] << " ";
			}
			return out;
		}

		void resize(int new_size){
			T *nuevo = new T[new_size];
			for(int i = 0; i<max; i++){
				nuevo[i] = arr[i];
			}
			delete[] arr;
			arr = nuevo;
			max = new_size;
		}

		void insert(int pos, T e) override{
			n++;
				
			T *nuevo = new T[max];

			for(int i = 0; i<pos; i++){
				nuevo[i] = max[i]; 
			}

			nuevo[pos] = e;

			for(int i = pos+1; i<n; i++){
				nuevo[i] = arr[i-1];
			}

			delete[] arr;
			arr = nuevo;

		}

		void append(T e) override{
			insert(n, e);
		}

		void prepend(T e) override{
			insert(0, e);
		}

		T remove(int pos) override{

			if(pos < 0 || pos >= n) throw out_of_range("Posición no válida del array\n");

			T removed = arr[pos];
			T* nuevo = new T[max];

			for(int i = 0; i<pos; i++){
				nuevo[i] = arr[i];
			}	
			
			for(int i = pos+1; i<n; i++){
				nuevo[i] = arr[i];
			}
			
			delete[] arr;
			n--;
			arr = nuevo;
		}

		T get(int pos) override{
			
		}


};
