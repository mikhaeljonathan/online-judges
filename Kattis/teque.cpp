#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct dequeue{
	int sizeDequeue;
	int *arr;
	int head;
	int tail;
	int nsize;
	
	dequeue(){ //constructor
		sizeDequeue = 0;
		arr = NULL;
		head = tail = nsize = 0;
	}
	
	~dequeue(){ //destructor
		free(arr);
	}
	
	void checkResize(){
		if (nsize >= (sizeDequeue - 1) || head < 1 || tail >= sizeDequeue){
			int newSize = sizeDequeue * 2;
			if (newSize == 0) newSize = 1;
			
			int *tempArr = (int *)realloc(arr, newSize * sizeof(int));
			
			arr = tempArr;
			
			int halfData = nsize / 2 + 1;
			
			int newMiddle = newSize / 2;
			int lastDataPlace = newMiddle + halfData;
			
			for (int i = tail; i >= head; i--){
				arr[lastDataPlace] = arr[i];
				lastDataPlace--;
			}
			
			head = lastDataPlace + 1;
			tail = newMiddle + halfData;
			sizeDequeue = newSize;
			nsize = tail - head;
		}
	}
	
	void pushFront(int x){
		checkResize();
		head--;
		arr[head] = x;
		nsize++;
	}
	
	void pushBack(int x){
		checkResize();
		arr[tail] = x;
		tail++;
		nsize++;
	}
	
	void popFront(){
		if (head == tail) return;
		head++;
		nsize--;
	}
	
	void popBack(){
		if (head == tail) return;
		tail--;
		nsize--;
	}
	
	int getFront(){
		return arr[head];
	}
	
	int getBack(){
		return arr[tail - 1];
	}
	
	int getIndex(int idx){
		return arr[head + idx];
	}
	
	int getSize(){
		return nsize;
	}
};

int main(){
//	dequeue x;
//	x.pushBack(1);
//	x.pushBack(2);
//	x.pushFront(3);
//	x.pushFront(4);
//	for (int i = 0; i < x.getSize(); i++){
//		printf("%d ", x.getIndex(i));
//	}
//	puts ("");
	
	dequeue leftElement;
	dequeue rightElement;
	
	int tcase, number;
	char command[20];
	
	scanf ("%d", &tcase);
	for (int t = 1; t <= tcase; t++){
		scanf ("%s %d", command, &number);
		
		if (strcmp(command, "push_front") == 0){
			leftElement.pushFront(number);
			
			if (leftElement.getSize() > rightElement.getSize()){
				rightElement.pushFront(leftElement.getBack());
				leftElement.popBack();
			}
		}
		else if (strcmp(command, "push_back") == 0){
			rightElement.pushBack(number);
			if (rightElement.getSize() > leftElement.getSize()){
				leftElement.pushBack(rightElement.getFront());
				rightElement.popFront();
			}
		}
		else if (strcmp(command, "push_middle") == 0){
			if (leftElement.getSize() < rightElement.getSize()){
				leftElement.pushBack(rightElement.getFront());
				rightElement.popFront(); 
			}
			rightElement.pushFront(number);
		}
		else{
			if (number < leftElement.getSize()){
				printf("%d\n", leftElement.getIndex(number));
			}
			else{
				printf("%d\n", rightElement.getIndex(number - leftElement.getSize()));
			}
		}
		
//		for (int i = 0; i < leftElement.getSize(); i++){
//			printf("%d ", leftElement.getIndex(i));
//		}
//		for (int i = 0; i < rightElement.getSize(); i++){
//			printf("%d ", rightElement.getIndex(i));
//		}
//		puts ("");
	}
	return 0;
}
