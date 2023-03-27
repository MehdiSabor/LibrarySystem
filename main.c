#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


 
typedef struct node{
 char name[30];
 char ISBN[30];
 char borrow[30];
 char client[30];
 char date[30];
 char field[30];
 struct node* next,*prev;
}book;
 
book *head=NULL;

 
book *Create(char name[],char ISBN[],char borrow[],char client[],char date[],char field[]){
 book* D;
 D=(book*)malloc(sizeof(book));
 
strcpy(D->name,name);
strcpy(D->client,client);
strcpy(D->date,date);
strcpy(D->field,field);
strcpy(D->ISBN,ISBN);
strcpy(D->borrow,borrow);
D->next=NULL;
return D;
}
void Insert(book* newNode) {
  char flag;
 if(newNode->name[0]>=97)
  {
    newNode->name[0]=newNode->name[0]-32;
  }
    // insert in a empty list
    if (head == NULL)
        head = newNode;
 
    // insert at the beginning
    else if (head->name[0] >= newNode->name[0]) {
        newNode->next = head;
        newNode->next->prev = newNode;
        head = newNode;
    }
 
    else {
        book *tmp = head;
 
  
        // insert by alphabetical order
        while (tmp->next != NULL &&
               tmp->next->name[0] < newNode->name[0])
            tmp = tmp->next;

 
        newNode->next = tmp->next;

        // insert at the end
        if (tmp->next != NULL)
            newNode->next->prev = newNode;
 
        tmp->next = newNode;
        newNode->prev = tmp;
    }
}



 
void printnodes(){
book *w=head;
printf("Book Info:\n");
while(w!=NULL){
  
  printf("name:%s ISBN:%s borrow:%s client:%s date:%s field:%s ",w->name,w->ISBN,w->borrow,w->client,w->date,w->field);
  printf("\n");
  

   w=w->next;
}
}


void delete(char ISBN[]){
  book *temp=head;
  book *temp2;
  while(strcmp(temp->ISBN,ISBN)!=0)
{    temp=temp->next;
}
//delete one node
if(temp->next==NULL && temp==head){
      head=NULL;
      free(head);
      printf("Successfully Deleted");
        return;
    }
    //delete node at the beginning
  if(temp  == head && temp->next!=NULL)  
    {  head = head->next;
    free(head->prev);   
    head->prev=NULL;
    printf("Successfully Deleted");
return;   
    }  
    //delete node at the end
  if(temp->next == NULL && temp!=head)  
    {  
        temp2=temp->prev;
        temp2->next=NULL;
        free(temp);
        printf("Successfully Deleted");
        return;
    }  

    //delete node at the middle
  else {
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
        printf("Successfully Deleted");
        return;
  }





printf("Invalid Enter Another ISBN\n");
} 






void Update(char ISBN[]){
  book *temp=head;
  char newdate[30];
  char newclient[30];
  char borrow[30];
  int borro;
  while( temp != NULL){
   
    if(strcmp(temp->ISBN,ISBN)==0)
{printf("Change the status: ");
  scanf("%s",borrow);
    if(strcmp(borrow,"1")==0){
  printf("Change the date: ");
  scanf("%s",newdate);
  printf("Enter the name of the new client: ");
scanf("%s",newclient);
  strcpy(temp->date,newdate);
  strcpy(temp->borrow,borrow);
  strcpy(temp->client,newclient);}
  else {
    strcpy(temp->date,"None");
  strcpy(temp->borrow,borrow);
  strcpy(temp->client,"None");}
  printf("Successfully updated");
  return;
  }
  temp=temp->next;
  }



printf("Book Not Found\n");
}

void Write(char file[]){
FILE *out;
out=fopen(file,"w");
if(out==NULL)printf("Couldn't Access the File.");
book *w=head;
while(w!=NULL){
 
  fprintf(out,"%s\n%s\n%s\n%s\n%s\n%s\n",w->name,w->ISBN,w->borrow,w->client,w->date,w->field);

   w=w->next;
}
fclose(out);
}



int getlines(char file[]){
  FILE *fp;
  char c;
  int count=1;
   fp = fopen(file, "r");

    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') 
            count++;
    fclose(fp);
    return count;
}
int Read(char file[]){
FILE *in;
in=fopen(file,"r");
book *tmp;
  char ch;
char name[30];
char ISBN[30];
char borrow[30];
char client[30];
char date[30];
char field[30];
int l;
l=(getlines(file)/6);
if(in==NULL)
{printf("Couldn't Access the File");
return 0;
}
  
else 
{
  for(int i=0;i<l;i++){

fgets(name,30,in);
name[strcspn(name, "\n")] = 0;
fgets(ISBN,30,in);
ISBN[strcspn(ISBN, "\n")] = 0;
fgets(borrow,30,in);
borrow[strcspn(borrow, "\n")] = 0;
fgets(client,sizeof(client),in);
client[strcspn(client, "\n")] = 0;
fgets(date,sizeof(date),in);
date[strcspn(date, "\n")] = 0;
fgets(field,sizeof(field),in);
field[strcspn(field, "\n")] = 0;

tmp=Create(name,ISBN,borrow,client,date,field);
Insert(tmp);
printf("Book Successfully inserted!");
}
fclose(in);
return 1;
}



}



void Ask(){
  char name[30],client[30],date[30],field[30];
 char ISBN[30];
 char borrowed[30];
 char borr[30];
for(int i=0;i<1;i++){
 book *tmp;
 book *w=head;
 char c;
 printf("Please Enter the ISBN: ");
 scanf(" %254[^\n]",ISBN);
 while(w!=NULL){
  if(strcmp(w->ISBN,ISBN)==0){printf("Error ISBN already existing");
  printf("\n");
  return;
  }else
  w=w->next; 
  }
 printf("Please Enter the book name: ");

 scanf(" %254[^\n]",name);
  
 printf("Is it borrowed or not: ");
scanf(" %254[^\n]",borr);
 if(strcmp(borr,"1")==0){
 printf("Please Enter the client name: ");
 scanf(" %254[^\n]",client);
 printf("Please Enter the date: ");
scanf(" %254[^\n]",date);}
 else {strcpy(client,"None");
 strcpy(date,"None");}
 printf("Please Enter the field: ");
 scanf(" %254[^\n]",field);


 
 tmp=Create(name,ISBN,borr,client,date,field);
 Insert(tmp);
}
}

void SearchISBN(){
  
  char ISBN[30];

printf("\nEnter an ISBN: ");
scanf("%s",ISBN);

  book *w=head;


  while(w!=NULL){
  if(strcmp(w->ISBN,ISBN)==0)
  {printf("name:%s ISBN:%s client:%s borrow:%s date:%s field:%s ",w->name,w->ISBN,w->client,w->borrow,w->date,w->field);
  printf("\n");
  return;
  }
  else
  w=w->next;
  
    
  }
printf("ISBN not found\n");
SearchISBN();
}


int stringCmpi (char *s1,char *s2)
{
    int i=0;
    for(i=0; s1[i]!='\0'; i++)
    {
        if( toupper(s1[i])!=toupper(s2[i]) )
            return 1;           
    }
    return 0;
}
void SearchName(){
  
  char name[30], c;

printf("Enter a Book Name:\n ");
scanf(" %254[^\n]",name);
int flag=0;
  book *w=head;


  while(w!=NULL){
   
  if(stringCmpi(w->name,name)==0){printf("name:%s ISBN:%s client:%s borrow:%s date:%s field:%s ",w->name,w->ISBN,w->client,w->borrow,w->date,w->field);
  printf("\n");
  w=w->next;
  flag=1;
  }
  else
  w=w->next;
  }

if (flag!=1){printf("Book Name not found\n");
SearchName();}


}
void SearchClient(){
  
  char client[30], c;

printf("Enter the Client's name:\n ");
scanf(" %254[^\n]",client);
int flag=0;
  book *w=head;


  while(w!=NULL){
   
  if(stringCmpi(w->client,client)==0){printf("name:%s ISBN:%s client:%s borrow:%s date:%s field:%s ",w->name,w->ISBN,w->client,w->borrow,w->date,w->field);
  printf("\n");
  w=w->next;
  flag=1;
  }
  else
  w=w->next;

  
    
  }
if (flag!=1){printf("Client Name not found\n");
SearchClient();}}

void SearchField(){
  
  char field[30], c;

printf("Enter a Field:\n ");
scanf(" %254[^\n]",field);
int flag=0;
  book *w=head;
  while(w!=NULL){
  if(stringCmpi(w->field,field)==0){printf("name:%s ISBN:%s client:%s borrow:%s date:%s field:%s ",w->name,w->ISBN,w->client,w->borrow,w->date,w->field);
  printf("\n");
  w=w->next;
  flag=1;
  }
  else
  w=w->next;
  }
if (flag!=1){printf("Field not found\n");
SearchField();}}

void Menu(){
		printf("\n\n\t------------- Menu To Use -------------\n");
  printf("\n\t1.Display\n");
  printf("\n\t2.Insert a New Book\n");
  printf("\n\t3.Update a New Book by ISBN\n");
  printf("\n\t4.Delete a Book by ISBN\n");
  printf("\n\t5.Search\n");
  printf("\n\t6.Exit\n");
printf("\n\tEnter your choice: ");
}

void sMenu(){
printf("\n\t5.1.Search by ISBN\n");
  printf("\n\t5.2.Search by field\n");
  printf("\n\t5.3.Search by book name\n");
  printf("\n\t5.4.Search by borrower name\n");
  printf("\n\tEnter your choice: ");
}


int main(void) {
char file[30];
int flag, f=0;
FILE *in;
char uISBN[30];
char dISBN[30];
while(f!=1){
printf("Enter the file name: ");
scanf("%s",file);
Read(file);
}
Write(file);
int choice,schoice;
do{
 Menu();
 scanf("%d",&choice);
 printf("\n");
switch(choice){
  case 1:
    printnodes();
    break;
  case 2:
    Ask();
    Write(file);
    break;
  case 3:
    printf("Enter the ISBN you want to update: ");
    scanf("%s",uISBN);
    Update(uISBN);
    Write(file);
    break;
  case 4:
    printf("Enter the ISBN you want to delete: ");
    scanf("%s",dISBN);
    delete(dISBN);
    Write(file);
    break;
  case 5:
  sMenu();
  scanf("%d",&schoice);
  switch(schoice){
    case 1:
    SearchISBN();
    break;
    case 2:
    SearchField();
    break;
    case 3:
    SearchName();
    break;
    case 4:
    SearchClient();
    break;
    default:
    printf("Invalid");
    break;

  }
  break;
   case 6:
   printf("BYE!");
   break;
 default:
    printf("Invalid Choice");
    
}
}while(choice!=6);

Write(file);
 return 0;

}