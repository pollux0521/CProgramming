#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 32

typedef struct student {
	char _name[SIZE];
	struct student* _next;
	struct student* _prev;
} Student;

Student* new_student(char* name) {
	Student* s = NULL;
	s = (Student*)malloc(sizeof(Student));
	if(s!=NULL) {
		strncpy(s->_name, name, strlen(name)+1);
		s->_next = NULL;
		s->_prev = NULL;
	}

	return s;
}

int add_student(Student** head, Student* student) {
	if(*head == NULL) { *head = student; }
	else {
		Student* ptr = NULL;
		ptr = *head;
		while(ptr->_next != NULL) ptr = ptr->_next;	

		ptr->_next = student;
		student->_prev = ptr;
	}

	return 0;
}

Student* search_student(Student* head, char* name) {
	Student* ptr = NULL;
	if(head != NULL) {
		ptr = head;
		/* TODO search student with name using strstr or strcmp */

	}
	return ptr; 
}

int del_student(Student* head, char* name) {
	Student* ptr = NULL;
	if(head != NULL) {
		ptr = head;
		/* TODO delete student with name using strstr or strcmp */

	}

	return 0;	
}

int print_students(Student* head) {
	if(head != NULL) {
		Student* ptr = NULL;
		ptr = head;
		while(ptr!=NULL) {
			printf("%s\n", ptr->_name);
			ptr = ptr->_next;
		}
	}

	return 0;
}

int print_students_reverse(Student* head) {
	if(head != NULL) {
		Student* ptr = NULL;
		ptr = head;
		while(ptr->_next != NULL) { ptr = ptr->_next;	}
		
		while(ptr!=NULL) {
			printf("%s\n", ptr->_name);
			ptr = ptr->_prev;
		
		}
	}

	return 0;
}

int main() {
	Student* head = NULL;
	head->_prev = NULL;
	Student* s = NULL;

	s = new_student("Incheol Shin");
	add_student(&head, s);

	s = new_student("Wooseong Jeong");
	add_student(&head, s);

	s = new_student("Jeongjae lee");
	add_student(&head, s);

	s = new_student("Bin Hyun");
	add_student(&head, s);

	print_students_reverse(head);

	return 0;
}
