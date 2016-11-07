#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

int hash_key(char* name){

	printf("Calculating hash_key for %s\n", name);
	int i,sum;
	for (int i = 0; name[i]!='\0'; ++i)
	{
		sum += name[i];
	}
return sum % size;
}


char *hash_table[100];

void insert_book(){
	char book[50];
	int hash,i=1;
	printf("enter 0 to exit");
	while(i){
	scanf("%d",&i);
	printf("Enter string to generate hash key\n");
	scanf("%s",book);
	hash = hash_key(book);
	hash_table[hash] = book; 
	printf("\n hash key of %s is \n %d",book,hash);
	}

}



int book_availability(char *name){
	int hash;
	hash = hash_key(name);
	printf("\n hash key of %s is \n %d",name,hash);
	return strcmp(name , hash_table[hash]);
}


void main(){
	char name[100];
	int b_avail = 0;

	insert_book();

	printf("Enter name of book to be checked \n");
	scanf("%s",name);
	printf("Now searching for %s\n", name );
	b_avail = book_availability(name);

	if(b_avail == 0){
		printf("book is available\n");
			b_avail = 1;
	}
	else
	printf("NOT available");
}