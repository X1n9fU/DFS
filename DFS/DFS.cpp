#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // ������ �ִ� ũ��
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef int element; // �������� �ڷ���
element stack[MAX_STACK_SIZE]; // 1���� �迭
int top = -1;

// ���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
// ���� �Լ�
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES] = { 0 };

void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;
		}
	}
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs_iterate(GraphType *g, int v) {

	int w;
	push(v);
	while (!is_empty()) { //������� ������
		v = pop();
		if (visited[v] == FALSE) {
			visited[v] = TRUE;
			printf("����%d ", v);
		}
		for (w = 0; w < g->n; w++) {
			if (g->adj_mat[v][w] && !visited[w])//�ȹ湮������ 
				push(w);
		}
	}


}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	//insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 3);
	//insert_edge(g, 2, 3);

	printf("���� �켱 Ž��\n");
	dfs_iterate(g, 0);
	printf("\n");
	free(g);
	return 0;
}