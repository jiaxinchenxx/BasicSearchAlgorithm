#include <iostream>
#include <string>

using namespace std;


int SeqSearch(int *arr, int target, int len) {

	for (int i = 0; i < len; i++)
		if (arr[i] == target)
			return i + 1;

	return -1;
}

int BinarySearch(int *arr, int target, int len) {

	int left = 0, right = len - 1;
	int mid = (left + right) / 2;

	while (right > left) {

		if (arr[mid] == target)
			return mid + 1;

		else if (arr[mid] < target) {
			left = mid + 1;
			mid = (left + right) / 2;
		}

		else {
			right = mid - 1;
			mid = (left + right) / 2;
		}
	}

	return -1;

}



class BiLinkedNode {

public:

	int inx;
	int value;

	BiLinkedNode* next;
	BiLinkedNode* prev;

	BiLinkedNode() {
		inx = -1;
		value = -1;
		next = NULL;
		prev = NULL;
	}

};

class BiLinkedList {

public:

	BiLinkedNode* HEAD;
	BiLinkedNode* TAIL;
	BiLinkedNode* MID;

	BiLinkedList() { HEAD = TAIL = MID = NULL; }

	void BuildIndex(int *arr, int len);
	void Insert(int x, int inx);
	void ShowList();


};

void BiLinkedList::ShowList() {
	BiLinkedNode* p = HEAD;
	while (p) {
		cout << "VAL: " << p->value << ' ' << "INX: " << p->inx << ' ';
		p = p->next;
	}
	cout << endl;
}

void BiLinkedList::BuildIndex(int *arr, int len) {
	for (int i = 0; i < len; i++)
		Insert(arr[i], i);

}

void BiLinkedList::Insert(int x, int inx) {

	if (!HEAD) {
		this->MID = new BiLinkedNode();
		MID->inx = inx;
		MID->value = x;
		MID->prev = MID->next = NULL;
		HEAD = MID;
		TAIL = MID;
		return;
	}

	BiLinkedNode *htmp = HEAD, *ttmp = TAIL;

	BiLinkedNode *node = new BiLinkedNode();
	node->inx = inx;
	node->value = x;

	if (x <= MID->value) {
		BiLinkedNode* tmp = HEAD;
		while (x > tmp->value && tmp != MID)
			tmp = tmp->next;

		if (!tmp->prev) {
			node->prev = NULL;
			node->next = tmp;
			HEAD = node;
		}
		else {
			tmp->prev->next = node;
			node->prev = tmp->prev;
			node->next = tmp;
			tmp->prev = node;
		}
	}

	else {
		BiLinkedNode* tmp = TAIL, *t;
		while (x < tmp->value && tmp != MID)
			tmp = tmp->prev;

		if (!tmp->next) {
			tmp->next = node;
			node->prev = tmp;
			node->next = NULL;
			TAIL = node;
		}

		else {
			t = tmp->next;
			tmp->next = node;
			node->prev = tmp;
			node->next = t;
		}
	}
}





class LinkedNode {

public:

	int * arr;
	int curInx;
	LinkedNode * next;
	int resPos;

	LinkedNode() {
		arr = new int[5];
		for (int i = 0; i < 5; i++)
			arr[i] = 0;
		curInx = 0;
		this->next = NULL;
		resPos = -1;
	}


	~LinkedNode(){}
};

class LinkedList {

public:

	LinkedNode * HEAD;

	LinkedList() {this->HEAD = new LinkedNode();}
	~LinkedList() {
		LinkedNode *p, *q;
		p = this->HEAD;
		while (p) {
			q = p->next;
			delete p;
			p = q;
		}
	}

	void Insert2Tail(int x);
	void ShowList();
	LinkedNode* Search(int target);
};

LinkedNode* LinkedList::Search(int target) {

	LinkedNode * tmp = this->HEAD->next;
	if (!tmp)
		return NULL;

	bool isFound = false;

	while (tmp) {
		for(int i=0;i<tmp->curInx;i++)
			if (tmp->arr[i] == target) {
				isFound = true;
				tmp->resPos = i + 1;
				break;
			}

		if (isFound)
			break;
		tmp = tmp->next;
	}
	return tmp;
}


void LinkedList::ShowList() {

	LinkedNode *tmp = this->HEAD->next;

	while (tmp) {
		for (int i = 0; i < tmp->curInx; i++)
			cout << tmp->arr[i]<<' ';
		tmp = tmp->next;
		cout << endl;
	}

}

void LinkedList::Insert2Tail(int x) {

	LinkedNode * tmp = this->HEAD;
	if (!HEAD->next) {
		LinkedNode * node = new LinkedNode();
		node->arr[node->curInx++] = x;
		HEAD->next = node;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	if (tmp->curInx < 5)
		tmp->arr[tmp->curInx++] = x;
	else {
		LinkedNode * node = new LinkedNode();
		tmp->next = node;
		node->arr[node->curInx++] = x;
		return;
	}
}



void main() {

	int arr[11] = { 10, 13, 17, 23, 38, 46, 54, 65, 82, 89, 92 };

	//cout << SeqSearch(arr, 82, 11)<<endl;
	//cout << BinarySearch(arr, 82, 11) << endl;

	LinkedList l1;
	for (int i = 0; i < 36; i++)
		l1.Insert2Tail(i);

	l1.ShowList();

	LinkedNode* tmp = l1.Search(27);
	if (tmp)
		cout << tmp->resPos << endl;


	BiLinkedList l2;
	int arr1[4] = { 3,2,7,8 };
	l2.BuildIndex(arr1, 4);

	l2.ShowList();


	system("pause");


}