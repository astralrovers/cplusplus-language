#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;

using thread_func = void *(*)(void *);

class CreateTask;

void *task_run(CreateTask *taskObj);

class CreateTask {
public:
	CreateTask() {}

	void task_create(thread_func func) {
		this->func = func;

		pthread_t tid;
		pthread_create(&tid, NULL, (thread_func)task_run, this);
	}

	friend void *task_run(CreateTask *taskObj);

	thread_func func;
};

void *task_run(CreateTask *taskObj) {
	cout << pthread_self() << endl;
	taskObj->func(NULL);

	return (void *)0;
}


void *_func(void *name)
{
	if (name) {
		cout << (char *)name << endl;
	}

	cout << pthread_self() << endl;

	while (1);
}


int main(void)
{
	CreateTask tasks;

	tasks.task_create(_func);
	while(1);

	return 0;
}
