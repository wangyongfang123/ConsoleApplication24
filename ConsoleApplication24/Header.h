#pragma once
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdbool>

typedef struct _Node
{
	int number;
	char firstname[10];
	char lastname[10];
	double  balance;
	struct _Node* next;
	//struct _Node* prev;

} Node, *NodePtr;

NodePtr new_node(NodePtr *node)
{
	NodePtr ptr = (NodePtr)malloc(sizeof(Node));
	memset(ptr, 0, sizeof(Node));

	if (node != 0)
	{
		*node = ptr;
	}
	return ptr;//*node	
}

void free_node(NodePtr *node)
{
	free(*node);

	*node = 0;
}


void processList(NodePtr list)
{
	//�����������������
	Node* pNode = list;
	int row = 1;
	while (pNode != 0)
	{
		printf(":%d\t%s\t%s\t%d\n", row, pNode->firstname, pNode->lastname, pNode->balance);
		pNode = pNode->next;
		row++;
	}

	fputs("\n", stdout);
}

bool isEmpty(NodePtr list)
{
	return list == 0;
}

int insertData(NodePtr *ppNode, const void* data)
{
	NodePtr pCurNode = *ppNode;

	if (pCurNode == 0)			//��Ϊ�յ����������ڵ�λ��Ϊ�գ�
	{
		NodePtr ptr = (NodePtr)malloc(sizeof(Node));
		memset(ptr, 0, sizeof(Node));

		pCurNode = *ppNode;
	}
	else
	{
		//1. ������Node
		Node* pNewNode = new_node(0);
		//2. ���²���λ�ýڵ��ԭ�¸��ڵ����½ڵ�Ĺ�ϵ
		//pCurNode->next->prev = pNewNode;
		pNewNode->next = pCurNode->next;
		//3. ���²���λ�ýڵ����½ڵ�Ĺ�ϵ
		pCurNode->next = pNewNode;
		//pNewNode->prev = pCurNode;

		pCurNode = pNewNode;		//���µ�ǰ���
	}
	//�������ݣ����ڵ����ݸ�ֵ��
	strcpy(pCurNode->firstname, data);

	return 0;
}

int appendData(NodePtr *ppNode, const void *data)
{
	if (*ppNode == 0)
	{
		return insertData(ppNode, data);
	}

	NodePtr pOrgTailNode = *ppNode;

	while (pOrgTailNode->next != 0)
	{
		pOrgTailNode = pOrgTailNode->next;
	}


	Node* pNewTailNode = new_node(0);

	pOrgTailNode->next = pNewTailNode;

	return 0;

}

// Node ��ͷ���
int deleteData(NodePtr *ppNode, const void* data)
{
	if (ppNode == 0 || *ppNode == 0)
	{
		return -1;
	}
	NodePtr pNode = *ppNode;
	NodePtr preNode = 0;
	while (pNode != 0)
	{
		if (strcmp(pNode->name, data) == 0)
		{
			if (pNode->next != 0)
			{
				pNode->next = pNode;
			}

			if (pNode != 0)
			{
				pNode->prev->next = pNode->next;
			}

			if (preNode == 0)//�����ͷ��㣬�͸����б�ͷָ��,��Ϊ����ppNode�Ǳ�ͷ
			{
				*ppNode = (*ppNode)->next;
			}

			//2. �ͷ�Ҫɾ���ڵ�ռ�õ��ڴ�
			free_node(&pNode);
			break;
		}
		preNode = pNode;
		pNode = pNode->next;
	}
}


NodePtr findData(NodePtr list, const char* name)
{
	if (list == 0)
	{
		return NULL;
	}
	NodePtr pNode = list;
	while (pNode != 0)
	{
		if (strcmp(pNode->name, name) == 0)
		{
			printf("%s\t%s\t%d\n", pNode->firstname, pNode->lastname, pNode->balance);
			break;
		}
		else
		{
			pNode = pNode->next;
		}
	}

	return 0;
}

void printNodeInfo(const NodePtr pNode)
{
	NodePtr pInfo = (NodePtr)pNode->name;
	printf("firstname:%s\t lastname:%s\t balance:%d\n", pNode->firstname, pNode->lastname, pNode->balance);

}


int enterChoice(void)
{
	int menuChoice;

	printf("\nEnter your choice\n"
		"1 - add a new account\n"
		"2 - delete an account\n"
		"3 - print account info\n"
		"4 - print list contents\n"
		"5 - end program\n? ");
	scanf("%d", &menuChoice);
	return menuChoice;
}

int main()
{
	NodePtr header = 0;
	Node* pCurNode = header;
	//char name[256];
	while (1)
	{
		int choice = enterChoice();

		switch (choice)
		{
		case 1:
		{
			fputs("input format:\n"
				"[number] [firstname] [listname] [balance]\n", stdout);
			NodePtr ptr = (NodePtr)malloc(sizeof(Node));
			memset(ptr, 0, sizeof(Node));
			scanf("%d%s%s%d", &ptr->number, ptr->firstname, ptr->lastname, &ptr->balance);
			appendData(&header, ptr);
		}
		break;
		case 2:
		{
			fputs("input the name(delete):\n", stdout);
			NodePtr ptr = (NodePtr)malloc(sizeof(Node));
			memset(ptr, 0, sizeof(Node));
			scanf("%d", &ptr->number);
			deleteData(&header, ptr);

		}
		break;
		case 3:
		{
			fputs("input the name to find:\n", stdout);
			NodePtr ptr = (NodePtr)malloc(sizeof(Node));
			memset(ptr, 0, sizeof(Node));
			scanf("%d", &number);
			NodePtr pNode = findData(header, name);
			if (pNode != 0)
			{
				printNodeInfo(pNode);
			}
			else
			{
				printf("[%s] not find!\n");
			}
		}
		break;
		case 4:
		{
			fputs("list contents:\n", stdout);
			processList(header);
		}
		break;
		default:
			return 0;
		}

	}

	return 0;
}

#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdbool>

typedef struct _Node
{
	int number;
	char firstname[10];
	char lastname[10];
	double  balance;
	struct _Node* next;
	//struct _Node* prev;

} Node, *NodePtr;

NodePtr new_node(NodePtr *node)
{
	NodePtr ptr = (NodePtr)malloc(sizeof(Node));
	memset(ptr, 0, sizeof(Node));

	if (node != 0)
	{
		*node = ptr;
	}
	return ptr;//*node	
}

void free_node(NodePtr *node)
{
	free(*node);

	*node = 0;
}


void processList(NodePtr list)
{
	//�����������������
	Node* pNode = list;
	int row = 1;
	while (pNode != 0)
	{
		printf(":%d\t%s\t%s\t%d\n", row, pNode->firstname, pNode->lastname, pNode->balance);
		pNode = pNode->next;
		row++;
	}

	fputs("\n", stdout);
}

bool isEmpty(NodePtr list)
{
	return list == 0;
}

int insertData(NodePtr *ppNode, const void* data)
{
	NodePtr pCurNode = *ppNode;

	if (pCurNode == 0)			//��Ϊ�յ����������ڵ�λ��Ϊ�գ�
	{
		NodePtr ptr = (NodePtr)malloc(sizeof(Node));
		memset(ptr, 0, sizeof(Node));

		pCurNode = *ppNode;
	}
	else
	{
		//1. ������Node
		Node* pNewNode = new_node(0);
		//2. ���²���λ�ýڵ��ԭ�¸��ڵ����½ڵ�Ĺ�ϵ
		//pCurNode->next->prev = pNewNode;
		pNewNode->next = pCurNode->next;
		//3. ���²���λ�ýڵ����½ڵ�Ĺ�ϵ
		pCurNode->next = pNewNode;
		//pNewNode->prev = pCurNode;

		pCurNode = pNewNode;		//���µ�ǰ���
	}
	//�������ݣ����ڵ����ݸ�ֵ��
	strcpy(pCurNode->firstname, data);

	return 0;
}

int appendData(NodePtr *ppNode, const void *data)
{
	if (*ppNode == 0)
	{
		return insertData(ppNode, data);
	}

	NodePtr pOrgTailNode = *ppNode;

	while (pOrgTailNode->next != 0)
	{
		pOrgTailNode = pOrgTailNode->next;
	}


	Node* pNewTailNode = new_node(0);

	pOrgTailNode->next = pNewTailNode;

	return 0;

}

// Node ��ͷ���
int deleteData(NodePtr *ppNode, const void* data)
{
	if (ppNode == 0 || *ppNode == 0)
	{
		return -1;
	}
	NodePtr pNode = *ppNode;
	NodePtr preNode = 0;
	while (pNode != 0)
	{
		if (strcmp(pNode->name, data) == 0)
		{
			if (pNode->next != 0)
			{
				pNode->next = pNode;
			}

			if (pNode != 0)
			{
				pNode->prev->next = pNode->next;
			}

			if (preNode == 0)//�����ͷ��㣬�͸����б�ͷָ��,��Ϊ����ppNode�Ǳ�ͷ
			{
				*ppNode = (*ppNode)->next;
			}

			//2. �ͷ�Ҫɾ���ڵ�ռ�õ��ڴ�
			free_node(&pNode);
			break;
		}
		preNode = pNode;
		pNode = pNode->next;
	}
}


NodePtr findData(NodePtr list, const char* name)
{
	if (list == 0)
	{
		return NULL;
	}
	NodePtr pNode = list;
	while (pNode != 0)
	{
		if (strcmp(pNode->name, name) == 0)
		{
			printf("%s\t%s\t%d\n", pNode->firstname, pNode->lastname, pNode->balance);
			break;
		}
		else
		{
			pNode = pNode->next;
		}
	}

	return 0;
}

void printNodeInfo(const NodePtr pNode)
{
	NodePtr pInfo = (NodePtr)pNode->name;
	printf("firstname:%s\t lastname:%s\t balance:%d\n", pNode->firstname, pNode->lastname, pNode->balance);

}


int enterChoice(void)
{
	int menuChoice;

	printf("\nEnter your choice\n"
		"1 - add a new account\n"
		"2 - delete an account\n"
		"3 - print account info\n"
		"4 - print list contents\n"
		"5 - end program\n? ");
	scanf("%d", &menuChoice);
	return menuChoice;
}

int main()
{
	NodePtr header = 0;
	Node* pCurNode = header;
	//char name[256];
	while (1)
	{
		int choice = enterChoice();

		switch (choice)
		{
		case 1:
		{
			fputs("input format:\n"
				"[number] [firstname] [listname] [balance]\n", stdout);
			NodePtr ptr = (NodePtr)malloc(sizeof(Node));
			memset(ptr, 0, sizeof(Node));
			scanf("%d%s%s%d", &ptr->number, ptr->firstname, ptr->lastname, &ptr->balance);
			appendData(&header, ptr);
		}
		break;
		case 2:
		{
			fputs("input the name(delete):\n", stdout);
			NodePtr ptr = (NodePtr)malloc(sizeof(Node));
			memset(ptr, 0, sizeof(Node));
			scanf("%d", &ptr->number);
			deleteData(&header, ptr);

		}
		break;
		case 3:
		{
			fputs("input the name to find:\n", stdout);
			NodePtr ptr = (NodePtr)malloc(sizeof(Node));
			memset(ptr, 0, sizeof(Node));
			scanf("%d", &number);
			NodePtr pNode = findData(header, name);
			if (pNode != 0)
			{
				printNodeInfo(pNode);
			}
			else
			{
				printf("[%s] not find!\n");
			}
		}
		break;
		case 4:
		{
			fputs("list contents:\n", stdout);
			processList(header);
		}
		break;
		default:
			return 0;
		}

	}

	return 0;
}

