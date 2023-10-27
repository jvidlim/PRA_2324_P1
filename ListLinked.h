#include <ostream>
#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T> class ListLinked : public List<T>{

private:
	Node<T>* first;
	int n;

public:
	ListLinked(){
		first = nullptr;
		n = 0;
	}

	~ListLinked(){
    		Node<T>* aux = nullptr;
    		while(first !=  nullptr){
        		aux = first->next;
        		delete first;
        		first = aux;
    		}
	}

	T operator[](int pos){
		if(pos < 0 || pos >= n){
			throw out_of_range("Posición no válida");
		}
		int i = 0;
		Node<T>* aux = first;
		while(i != pos){
			i++;
			aux = aux->next;
		}

		return aux->data;
	}

	friend ostream&operator<<(ostream &out, const ListLinked<T> &list){
		Node<T>* aux = list.first;
		out << "List => [\n";
		while(aux != nullptr){
			out << " " << aux->data << "\n";
			aux = aux->next;
		}
		out << "]\n";
		return out;
	}

	void insert(int pos, T e) override{

		//cout << "Insert: " << pos << ": " << e << endl;

		if(pos < 0 || pos > n){
			throw out_of_range("Posición no válida");
		}
		
		if(pos == 0){
			Node<T>* nuevo = new Node<T>(e, first);
			first = nuevo;
		}else if(pos == n){
			Node<T>* aux = first;
			while(aux->next != nullptr){
				aux = aux->next;
			}
			Node<T>* nuevo = new Node<T>(e, nullptr);
			aux->next = nuevo;

		}else{
			Node<T>* act = first->next;
			Node<T>* prev = first;
			int i = 1;

			while(i != pos){
				prev = act;
				act = act->next;
				i++;
			}
			Node<T>* nuevo = new Node(e, act);
			prev->next = nuevo;
		}
		n++;
	}

	void append(T e) override{
		insert(n, e);
	}	

	void prepend(T e) override{
		insert(0, e);
	}

	T remove(int pos) override{
		if(pos < 0 || pos >= n){
			throw out_of_range("Posicion no valida");
		}
	
		if(pos == 0){
			T devolver = first->data;
			Node<T>* aux = first->next;
			delete first;
			first = aux;
			n--;
			return devolver;
		}else if(pos == n-1){
			Node<T>* act = first->next;
			Node<T>* prev = first;
			while(act->next != nullptr){
				prev = act;
				act = act->next;	
			}
			T devolver = act->data;
			delete act;
			prev->next = nullptr;
			n--;
			return devolver;
		}else{

			int i = 1;
			Node<T>* prev = first;
			Node<T>* act = prev->next;
			while(i != pos){
				//cout << "(" << i << " " << act->data <<")\n";
				prev = act;
				act = act->next;
				i++;
			}
			T devolver = act->data;
			prev->next = act->next;
			delete act;
			n--;
			return devolver;
		}
	}

	T get(int pos) override{
		if(pos < 0 || pos >= n){
			throw out_of_range("Posicion no valida");
		}
		int i = 0;
		Node<T>* aux = first;
		
		while(i !=  pos){
			aux = aux->next;
			i++;
		}
		return aux->data;
	}

	int search(T e) override{
		int i = 0;
		Node<T>* aux = first;

		while(aux != nullptr){
			if(aux->data == e) return i;
			else{
				aux = aux->next;
				i++;
			}
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
