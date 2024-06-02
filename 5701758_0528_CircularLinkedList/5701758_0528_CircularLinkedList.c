#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

//ListNode* init_list()

ListNode* insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}

void print_list(ListNode* tail) {
	ListNode* p;

	if (tail == NULL) return;
	p = tail->link;
	do {
		printf("[%2d] ", p->data);
		p = p->link;
	} while (p != tail->link);
}
ListNode* insert_last(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (tail == NULL) {
		tail = node;
		node->link = node;
	}
	else {
		node->link = tail->link;
		tail->link = node;
		tail = node;
	}
}
ListNode* delete_first(ListNode* tail) {
	if (tail == NULL) return NULL;
	ListNode* head = tail->link;
	if (head == tail) {
		free(head);
		return NULL;
	}
	tail->link = head->link;
	free(head);
	return tail;
}
ListNode* delete_last(ListNode* tail) {
	if (tail == NULL)return NULL;
	ListNode* head;
	head = tail->link;
	tail->link = head->link;
	free(head);
	return tail;
}

int main() {
	ListNode* tail = NULL;

	int choice = 0;
	int n1, n2;
	while (1) {
		printf("\n메뉴\n");
		printf("1. 리스트 처음에 추가\n");
		printf("2. 리스트 마지막에 추가\n");
		printf("3. 리스트 처음 노드 삭제\n");
		printf("4. 리스트 마지막 노드 삭제\n");
		printf("5. 리스트 프린트\n");
		printf("6. 프로그램 종료\n");
		printf("선택 : ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("리스트 처음에 추가할 숫자를 입력하시오 : ");
			scanf_s("%d", &n1);
			tail = insert_first(tail, n1);
			break;
		case 2:
			printf("리스트 마지막에 추가할 숫자를 입력하시오 : ");
			scanf_s("%d", &n2);
			tail = insert_last(tail, n2);
			break;
		case 3:
			printf("리스트 처음 노드를 삭제합니다.");
			tail = delete_first(tail);
			break;
		case 4:
			printf("리스트 마지막 노드를 삭제합니다.");
			tail = delete_last(tail);
			break;
		case 5:
			printf("리스트를 출력합니다.");
			print_list(tail);
			break;
		case 6:
			printf("프로그램을 종료합니다.");
			exit(0);
		default:
			printf("잘못된 선택입니다.\n");
			break;
		}
	}

	return 0;
	/*tail = insert_first(tail, 30);
	tail = insert_first(tail, 20);
	tail = insert_first(tail, 10);

	tail = insert_last(tail, 40);
	tail = insert_last(tail, 50);
	tail = insert_last(tail, 60);
	print_list(tail);*/
}