#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAUSE system("read -rsp $'Press any key to continue ...\n' -n1")
#define TODO_SIZE 100

typedef struct todo { 
	char buffer[TODO_SIZE];
	struct todo* next;
	int count;
} todo;

/******* FUNCTIONS ********/
void interface();
void showTodo();
void createTodo();
void deleteTodo();
void adjustCount();
void freeList(todo* head); // resurcively free memory

todo* start = NULL;
todo *add1, *add2; // create temp note for createTodo()

int main()
{
	int choice;
	interface();

	while(1) {
		system("clear");

		printf("1. show TODO list\n");
		printf("2. create new TODO\n");
		printf("3. delete your TODO\n");
		printf("4. Exit");
		printf("\n\n\nEnter your choice\t:\t");

		scanf("%d", &choice);

		switch(choice) {
			case 1:
				showTodo();
				break;
			case 2:
				getchar(); // workaround buffer
				createTodo();
				break;
			case 3:
				deleteTodo();
				break;
			case 4:
				freeList(start);
				puts("bye bye!");
				exit(0);
				break;
			default:
				printf("\nInvalid choice!\n");
				PAUSE;
		}
	}


	return 0;
}

void interface()
{
	printf("\n\n\n\n");
	printf("\t~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~\n");
	printf("\t~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~\n\n");
	printf("\t} : } : } : } : } : } "
			": } : } : } :"
			"the TODO app"
			": { : { : { : { : { "
			": { : { : { : {\n\n");
	printf("\t~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~\n");
	printf("\t~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~~~~~~~~~~~~"
			"~~~~~~~~\n\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t@tiendz\n\n\n\n\n\n\n");

	PAUSE;
}

void showTodo()
{
	system("clear");
	todo* temp;
	temp = start;

	if(start == NULL)
		printf("\n\nEmpty TODO \n\n");

	while(temp != NULL)
	{
		printf("%d.)", temp->count);
		puts(temp->buffer);
		temp = temp->next;
	}
	printf("\n\n\n");
	PAUSE;
}

void createTodo()
{
	/* recursively ask to continue */
	char c = 'n';
	char buf[TODO_SIZE - 1];

	// base
	system("clear");
	printf("continue? y/n\t");
	fgets(buf, sizeof buf, stdin);
	// get the first character in what user type in
	sscanf(buf, "%c", &c);
	if(c == 'n')
		return;

	// the programm
	if(start == NULL)
	{
		add1 = (todo*)malloc(sizeof(todo));
		printf("\ntype in...\n");
		fflush(stdout);
		fgets(add1->buffer, TODO_SIZE, stdin);

		start = add1;
		add1->count = 1;
		add1->next = NULL;
	}
	else
	{
		add2 = (todo*)malloc(sizeof(todo));
		printf("\ntype in...\n");
		fflush(stdout);
		fgets(add2->buffer, TODO_SIZE, stdin);

		add2->next = NULL;
		add1->next = add2;
		add1 = add2;
		adjustCount();
	}
	createTodo();
}

void deleteTodo()
{
	system("clear");
	int x;

	if(start == NULL)
		printf("\n\nThere is no TODO for today :-)\n\n\n");
	else {
		printf("\nEnter the TODO's number that u want to remove.\n\t\t");
		scanf("%d", &x);

		todo *del, *temp;
		del = start;
		temp = start->next;
		while(1) 
		{
			if(del->count == x){
				start = start->next;
				free(del);
				adjustCount();
				break;
			}
			if (temp->count == x) {
				del->next = temp->next;
				free(temp);
				adjustCount();
				break;
			}
			else {
				del = temp;
				temp = temp->next;
			}
		}
	}
	PAUSE;
}

void adjustCount()
{
	todo* temp;
	int i = 1;
	temp = start;

	while(temp != NULL) {
		temp->count = i;
		i++;
		temp = temp->next;
	}
}

void freeList(todo* head)
{
	// recursively free memory
	if(head == NULL)
		return;

	todo* tmp = head->next;
	freeList(tmp);
	free(tmp);
}
