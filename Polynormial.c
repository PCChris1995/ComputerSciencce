#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
	ElementType coefficient;
	ElementType index;
	PtrToNode Next;

};

typedef PtrToNode List;

List Read();
List Calculate(List L1,List L2);
void Print(List L);

int main() {
	List L1, L2, L;	
	L1 = Read();
	L2 = Read();
	L = Calculate( L1, L2);
	Print(L1);
	Print(L2);
	Print(L);

	return 0;
}

List Read() {
	List L = (List)malloc( sizeof(List) );
	L->Next = NULL;	
	List Last = L;
	int n;
	printf("Please input a List:");
	scanf("%d",&n);
	while (n--) {
		if (L->Next == NULL) {
			List temp = (List)malloc(sizeof(List));
			temp->Next = NULL;
			scanf("%d", &temp->coefficient);
			scanf("%d",&temp->index);
			L->Next = temp;
			L = L->Next;
		}
	}
	return Last->Next;

}

List Calculate(List L1, List L2) {
	List T1 = L1;
	List T2 = L2;
	List S2 = L2;
	List temp = (List)malloc( sizeof(List) );
	temp->Next = NULL;
	List L = temp;
	while (T1 != NULL) {
		while (T2 != NULL)
		{
			temp->coefficient = T1->coefficient * S2->coefficient;
			temp->index = T1->index + S2->index;
			temp->Next = T2->Next;
			temp = temp->Next;
			T2 = T2->Next;
			S2 = S2->Next;		
		}
		S2 = L2;
		T2 = L2;
		T1 = T1->Next;
	}
	return L->Next;
}
void Print(List L) {
	while (L->Next != NULL) {
		printf("%d",L->coefficient);
		printf(" ");
		printf("%d",L->index);
		L = L->Next;
	}
	if (L->Next == NULL && L != NULL) {
		printf(" ");
		printf("%d", L->coefficient);
		printf(" ");
		printf("%d", L->index);
		L = L->Next;
	}
	else if(L == NULL)
		printf("the input is NULL!");
	printf("\n");
}