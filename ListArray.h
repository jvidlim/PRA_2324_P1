#include "List.h"
#include <ostream>

using namespace std;

template <typename T> class ListArray : public List<T>{
	private:
		T *arr;
		int max;
		int n;
		static const int MINSIZE = 2;

		void resize(int new_size){
			T *nuevo = new T[new_size];
			for(int i = 0; i<max; i++){
				nuevo[i] = arr[i];
			}
			delete[] arr;
			arr = nuevo;
			max = new_size;
		}

	public:
		ListArray(){
			arr = new T[MINSIZE];
			n = 0;
			max = MINSIZE;
		}

		~ListArray(){
			delete[] arr;
		}

		T operator[](int pos){
			if(pos < 0 || pos >= n) throw out_of_range("Posicion del array no valida");
			else{
				return arr[pos];		
			}
		}

		friend ostream& operator <<(ostream &out, const ListArray<T> &list){
			
			out << "List => [\n";
			
			for(int i = 0; i<list.n; i++){
				out << list.arr[i] << "\n";
			}

			out << "]";
			
			return out;
		}

		void insert(int pos, T e) override{
			if(pos < 0 || pos > max) throw out_of_range("Posicion del array no valida");
			n++;
			if(n > max) resize(n);

			for(int i = n-1; i>pos; i--){
				arr[i] = arr[i-1];
			}

			arr[pos] = e;

		}

		void append(T e) override{
			insert(n, e);
		}

		void prepend(T e) override{
			insert(0, e);
		}

		T remove(int pos) override{

			if(pos < 0 || pos >= n) throw out_of_range("Posicion del array no valida");
			
			max--;

			T removed = arr[pos];
			T* nuevo = new T[max];

			for(int i = 0; i<n-1; i++){
				if(i < pos) nuevo[i] = arr[i];
				else nuevo[i] = arr[i+1];
			}	

			delete[] arr;
			n--;
			arr = nuevo;

			return removed;
		}

		T get(int pos) override{
			if(pos < 0 || pos>=n) throw out_of_range("Posición no válida del array");
			return arr[pos];
		}

		int search(int k) override{
			for(int i = 0; i<n;++i){
				if(arr[i] == k) return i;
			}
			return -1;
		}

		bool empty() override{
			if(n == 0) return true;
			else return false;
		}

		int size() override{
			return n;
		}


};
