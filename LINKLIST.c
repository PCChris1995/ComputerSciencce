
//this is my first project

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); 
void Print(List L); 

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	Print(L1);
	Print(L2);
	return 0;
}

/* 你的代码将被嵌在这里 */
List Read() {
	int n;
	scanf("%d", &n);
	List L = (struct Node *)malloc(sizeof(struct Node));
	L->Next = NULL;
	List ans = L;
	while (n--) {
		if (L->Next == NULL) {
			List temp = (struct Node *)malloc(sizeof(struct Node));
			temp->Next = NULL;
			scanf("%d", &temp->Data);
			L->Next = temp;
			L = L->Next;
		}
		
	}
	return L;
}
void Print(List L) {
	/*if (L->Next == NULL) {
		printf("NULL\n");
		return;
	}*/
	List temp = L;
	while (temp->Next) {
		printf("%d ", temp->Data);
		temp = temp->Next;
	}
	printf("%d", temp->Data);
	printf("\n");
}