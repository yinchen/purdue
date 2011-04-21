#include "my_scheduler.h"

int a = 5, b = 2;
char s[10] = "HELLO";

/* Tasks to schedule */
void task1() {
	int c;
	++a;
	--b;
	sleep(1);
	printf("\nTASK 1: %d/%d\n",a,b);
	c = a/b;
//	printf("%d\n",c);
}

void task2() {
	int c;
	++a;
	--b;
	sleep(1);
	printf("\nTASK 2: %d mod %d\n",a,b);
	c = a % b;
//	printf("%d\n",c);
}

void task3() {
	sleep(1);
	printf("\nTASK 3: String concatenation - ");
	strcat(s,"!!");
	printf("%s\n",s);
}

void task4() {
	sleep(1);
	printf("\nTASK 4: Null strcat\n");
	char *s1;
	strcat(s1,"!");
	printf("\n%s\n",s1);
}

void task5() {
	alarm(4);
	printf("\nTASK 5: Alarm\n");
	printf("Waiting for alarm...\n");
	for(;;);
}

/* Main function */
int main() {
	void (*func[5]) (void);
	func[0] = task1;
	func[1] = task2;
	func[2] = task3;
	func[3] = task4;
	func[4] = task5;

	initHandlers();
	scheduler(func, 5);
}

