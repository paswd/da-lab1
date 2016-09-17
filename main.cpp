#include <stdio.h>
#include "vector.h"
#include "queue.h"

//using namespace std;

/*int main()
{
	TVector *arr = new TVector;
	arr->resize(2);
	arr->values[0] = 3;
	arr->values[1] = 2;
	arr->print();
	cout << arr->size() << endl;
	arr->resize(4);
	arr->values[2] = 1;
	arr->values[3] = 6;
	arr->print();
	cout << arr->size() << endl;
	arr->resize(2);
	arr->print();
	cout << arr->size() << endl;
	delete arr;
	return 0;
}*/

int main() {
	const Item queue_empty = -9000000000000000000;
	/*Queue *queue = queue_create();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Item tmp;
		scanf("%lld", &tmp);
		queue_push(queue, tmp);
	}
	queue_sort(queue);
	queue_print(queue);
	queue_destroy(&queue);*/
	TQueue *queue = new TQueue;
	printf("-------------------------------------------\n");
	printf("Commands:\n");
	printf("a <value> - push to queue\n");
	printf("d - pop from queue and print popped item\n");
	printf("s - sort queue\n");
	printf("p - print queue\n");
	printf("q - exit\n");
	printf("-------------------------------------------\n");
	//int cnt = 0;
	while (true) {
		//printf("%d\n", cnt);
		//cnt++;
		char cmd;
		Item value = 0;
		bool is_finished = false;
		scanf("%c", &cmd);
		long long tmp;
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 'a':
				scanf("%lld", &value);
				queue->Push(value);
				break;
			case 'd':
				tmp = (long long) queue->Pop();
				if (tmp != queue_empty)
					printf("%lld\n", tmp);
				break;
			case 'p':
				queue->Print();
				break;
			/*case 'c':
				queue_prinTcorrect(queue);
				break;
			case 'f':
				printf("%lld\n", queue_first(queue));
				break;*/
			case '\n':
				break;
			default:
				printf("Invalid command `%c`\n", cmd);
				break;
		}
		if (is_finished) break;
	}
	printf("Goodbye!\n");

	delete queue;
	return 0;
}
