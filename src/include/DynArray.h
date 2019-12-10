#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_
//a DynArray stores data in an ordered random access structure with
//no delete operations. Items are added with append.

template <class T> class DynArray{
public :
	DynArray();
	DynArray(int);
	~DynArray();

	bool append(T item);		//always added to end
	bool truncate();			//make arraySize = nData
	void clear() {nData = 0;}
	int length() const {return nData;}
	bool empty() const {return nData == 0;}
	const T &operator[] (int i) const{return data[i];}

	T *data;
	int nData;
	int arraySize;
};

template <class T> DynArray<T>::DynArray() {
	nData = 0;
	arraySize = 4;
	data = new T[arraySize];
}

template <class T> DynArray<T>::DynArray(int a){
	nData = 0;
	arraySize = a;
	data = new T[arraySize];
}

template <class T> DynArray<T>::~DynArray() {
	nData = 0;
	delete [] data;
}

template <class T> bool DynArray<T>::truncate(){
	if (nData != arraySize){
		T *temp = data;
		arraySize = nData;

		if (!(data = new T[arraySize])) {
			return false;
		}

		for (int i = 0; i < nData; i++){
			data[i] = temp[i];
		}

		delete[] temp;
	}

	return true;
}

template <class T> bool DynArray<T>::append(T item){
	if (nData == arraySize){
		arraySize *= 2;
		T *temp = data;

		if (!(data = new T[arraySize])) return false;

		for (int i = 0; i < nData; i++)
			data[i] = temp[i];

		delete [] temp;
	}
	data[nData++] = item;
	return true;
}
#endif //_DYN_ARRAY_H_
