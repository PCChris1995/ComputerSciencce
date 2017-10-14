#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;

struct Node {
	ElementType Data;
	PtrToNode Next;
};

typedef PtrToNode List;

List Read();
void Print(List L);
List Merge(List L1, List L2);

int main() {
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

List Merge(List L1, List L2) {

	List merge = (List)malloc(sizeof(List));
	merge->Next = NULL;
	List temp = merge;
	while ((L1 != NULL) && (L2 != NULL)) {
		if (L1->Data <= L2->Data) {
			temp->Next = L1;
			L1 = L1->Next;
			temp = temp->Next;
		}
		else if (L1->Data > L2->Data) {
			temp->Next = L2;
			L2 = L2->Next;
			temp = temp->Next;
		}
	}
	while (L1 == NULL && L2 != NULL) {
		temp->Next = L2;
		L2 = L2->Next;
		temp = temp->Next;
	}
	while (L2 == NULL && L1 != NULL) {
		temp->Next = L1;
		L1 = L1->Next;
		temp = temp->Next;
	}

	return merge->Next;

}

List Read() {

	int len;
	printf("Please input a number:");
	scanf("%d", &len);
	/*if (!len) {
	return NULL;
	}*/
	List First = (List)malloc(len * sizeof(List));
	First->Next = NULL;
	List Last = First;
	while (len--) {
		if (First->Next == NULL) {
			List temp = (List)malloc(sizeof(List));
			temp->Next = NULL;
			scanf("%d", &temp->Data);
			First->Next = temp;
			First = First->Next;
		}

	}
	return Last->Next;

}

void Print(List L) {
	if (L->Next == NULL && L != NULL) {
		printf("%d", L->Data);
		/*else
		{
		printf("Input is NULL!\n");
		}*/

	}
	while (L != NULL) {
		printf("%d ", L->Data);
		L = L->Next;
	}
}

