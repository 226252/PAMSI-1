#ifndef mergesort_HPP
#define mergesort_HPP
using namespace std;
#include "../array.hpp"
#include "../Interfaces/irunnable.hpp"
#include "../Interfaces/imergesortable.hpp"


/* Scalanie dwoch posortowanych ciagow
tab[pocz...sr] i tab[sr+1...kon] i
wynik zapisuje w tab[pocz...kon] */
class Mergesort :public stru::irunnable
{
	imergesortable<int>& object;
public:

	Mergesort(imergesortable<int>& starter)
		:object(starter){}
	~Mergesort(){}




	void merge(int begin, int middle, int end){
		stru::array<int> tmp; 
		// utworzenie tablicy pomocniczej
		int i = begin;
		int j = middle+1;
		int k = 0; 
		// zmienne pomocnicze
		 
		while (i <= middle && j <= end){
			if (object[j] < object[i]){
				tmp.add(object[j]);
				j++;
			}else{	
				tmp.add(object[i]);
				i++;
			}
			k++;
		}
		 
		if (i <= middle){
			while (i <= middle){
				tmp.add(object[i]);
				i++;
				k++;
			}
		}else{
			while (j <= end){
				tmp.add(object[j]);
				j++;
				k++;
			}
		}
		 
		for (i = 0; i <= end-begin; i++){
			object[begin+i] = tmp[i];
		}  
	}

 
	/* Procedura sortowania tab[pocz...kon] */
	void sort(int begin, int end){
		int middle;
		if (begin<end){
			middle=(begin+end)/2;
			sort(begin, middle);    // Dzielenie lewej części
			sort(middle+1, end);   // Dzielenie prawej części
			merge(begin, middle, end);   // Łączenie części lewej i prawej
		}
	}

	bool is_sorted(){
	  int first;
	  int second;
	  
	  for (int i=0;i<object.get_last_index()-1;i++){

	    first=object[i];
	    second=object[i+1];
	    
	    if(first>second){
	      return false;
	    }
	  }
	  
	  return true;
	  
	}
	virtual void prepare(unsigned int size,char option){

	  //Options: r- fill with random numbers
	  //         i- prepare with increasing array
	  //         d- prepare with decreasing array

	  switch(option){

	  case 'r':
	    fill_random(size);
	    break;

	  case'i':
	    fill_random(size);
	    sort(0,size-1);
	    break;

	  case'd':
	    fill_random(size);
	    sort(0,size-1);
	    for (unsigned int i=0;i<(size-1)/2;i++){
	      swap(i,(size-1)-i);
	    }
	    break;

	  default:
	    fill_random(size);
	    break;

	  }
	 }
	virtual void perform_run(unsigned int size, char option){
	  sort(0,object.get_last_index());
	  if(!is_sorted()){
	    std::cerr<< "ERR: NOT  SORTED AFTER SORT!\n";
	  }  
	}

	void reset(){

	  object.reset();  
	}

	virtual void fill_random(unsigned int howmany){
	  
	  for(unsigned int i=0;i<howmany;i++){
	    int random_number=(std::rand()%howmany)+0;
	    object.set_element(random_number);
	  }
	}

	inline void swap(int index_1, int index_2){

	  int temp=object[index_1];
	  object[index_1]=object[index_2];
	  object[index_2]=temp;	  
	}

};



#endif