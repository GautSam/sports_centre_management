#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 4
#include "queueoperations.h"

struct member {
	struct member *next;
	struct member *prev;
	char name[30];
	int age;
	char intrestedsport[30];
	char phoneNo[11];
};
struct member *head;

//this fucntion is to add some data beforehand
void insertNode(char mname[30],int mage,char mintrestedsport[30],char phoneNo[11]) {
	struct member *ptr =(struct member *)malloc(sizeof(struct member));
	struct member *temp;
	strcpy(ptr->name,mname);
	ptr->age=mage;
	strcpy(ptr->intrestedsport,mintrestedsport);
	strcpy(ptr->phoneNo, phoneNo);
	if(head==NULL) {
		ptr->next=NULL;
		ptr->prev=NULL;
		head = ptr;
	} else {
		temp = head;
		while(temp->next!=NULL) {
			temp = temp->next;
		}
		temp->next = ptr;
		ptr ->prev=temp;
		ptr->next = NULL;
	}
	node_count++;

}


//new user entered memeber will be added at the end of the list
void addmember() {
	char name[30];
	int age;
	char intrestedsport[30];
	char phoneNo[11];

	printf("\n\n");
	printf(" \t-----------------------------------------\n");
	printf("\t|\t \tREGISTRATION             |\n");
	printf(" \t-----------------------------------------\n");
	printf(" \t-----------------------------------------------------");
	printf("\n\t|  \tENTER FULL NAME :    ");
	scanf(" %[^\n]s",name);
	printf("\n\t|  \tENTER AGE :    ");
	scanf("%d",&age);
	printf("\n\t|  \tONE SPORT YOU ARE INTRESTED IN :    ");
	scanf(" %[^\n]s",intrestedsport);
	printf("\n\t|  \tEnter PHONE NUMBER :    ");
	scanf(" %[^\n]s",phoneNo);
	printf(" \t-----------------------------------------------------");

	struct member *ptr =(struct member *)malloc(sizeof(struct member));
	struct member *temp;

	if (ptr==0) {
		printf("Overflow");
	} else {
		//mobile number should be checked if it is 10 digit before entering into database
		if(strlen(phoneNo)!=10) {
			printf("\n\nMOBILE NUMBER ENTERED IS NOT VALID.....please verify the mobile number and refill the form\n");
			printf("ENTERED MOBILE NUMBER IS : %s\n", phoneNo);
			printf("--------------------RE-FILL---------------------\n");
			printf("\n");
			addmember();
		} else {
			strcpy(ptr->name,name);
			ptr->age=age;
			strcpy(ptr->intrestedsport,intrestedsport);
			strcpy(ptr->phoneNo, phoneNo);
			if(head==NULL) {
			ptr->next=NULL;
			ptr->prev=NULL;
			head = ptr;
			} else {
				temp = head;
				while(temp->next!=NULL) {
					temp = temp->next;
				}
				temp->next = ptr;
				ptr ->prev=temp;
				ptr->next = NULL;
			}
			node_count++;
			printf("\n\n\t------MEMBER ADDED SUCCESSFULLY-------\n\n\n");
			}
		
	}

}


//search member
void searchMember(int choice) {
	char name[30],intrestedsport[30];
	printf("\n..............................................................................................\n");
	if(choice==1) {
		printf("\n\t\tENTER SPORT NAME YOU WANT TO SEARCH : ");
		scanf(" %[^\n]s",intrestedsport);
		struct member *temp=head;
		struct member *result = NULL;
		printf("\t      ---------------------------------------------------------------------\n");
		printf("\n        \t[NAME]\t\t");
		printf("\t[SPORT INTREST]\t       ");
		printf("\t[PHONE NO]\t\t");
		printf("\n");
		while(temp!=NULL) {
			if(!strcasecmp(intrestedsport, temp->intrestedsport)) {

				printf("\n\t\t %s      \t\t%s       \t\t %s\n",temp->name,temp->intrestedsport, temp->phoneNo);
			}
			temp=temp->next;
		}
		printf("\t      ---------------------------------------------------------------------\n");
		printf("\n");


	} else if(choice==2) {
		printf("\n\t\tENTER FULL NAME YOU WANT TO SEARCH : ");
		scanf(" %[^\n]s",name);

		struct member *temp=head;
		struct member *result = NULL;

		while(temp!=NULL) {
			if(!strcasecmp(name, temp->name)) {
				result = temp;
			}
			temp=temp->next;
		}
		printf("\n\t      ---------------------------------------------------------------------\n");
		printf("\n        \t[NAME]\t\t");
		printf("\t[SPORT INTREST]\t       ");
		printf("\t[PHONE NO]\t\t");
		printf("\n");
		if(result) {
			printf("\n\t\t %s      \t\t%s       \t\t %s\n",result->name,result->intrestedsport, result->phoneNo);
			printf("\n\t      ---------------------------------------------------------------------\n");
			printf("\n");
		} else {
			printf("MEMBER NOT FOUND!!!");
		}
	}

printf("\n..............................................................................................\n");
printf("\n");

}


//deleting node beginning-middle-end
void removeMember() {
	char name[30];

	printf("\n\n");
	printf(" \t\t-----------------------------------------\n");
	printf("\t\t|\t \tREMOVAL                 |\n");
	printf(" \t\t-----------------------------------------\n");
	printf(" \t----------------------------------------------------------\n");
	printf("\n\tENTER FULL NAME YOU WANT TO DELETE : ");
	scanf(" %[^\n]s",name);

	struct member *temp=head;
	struct member *result = NULL;

	while(temp!=NULL) {
		if(!strcasecmp(name, temp->name)) {
			result = temp;
		}
		temp=temp->next;
	}

	if(result) {
		if (head == result)
			head = result->next;

		if (result->next != NULL)
			result->next->prev = result->prev;

		if (result->prev != NULL)
			result->prev->next = result->next;

		printf("\n\t\tMEMBER SUCCESSFULLY REMOVED!!!!\n\n");
	} else {
		printf("\n\t\tMEMBER NOT FOUND!!!\n");
	}
	printf(" \t----------------------------------------------------------\n");
}

//display all members list
void displaymembers() {
	struct member *temp=head;
	if(temp==NULL) {
		printf("\t \tOOPS...NO MEMBER AS OF NOW........\n");
	} else {


		printf("\n\t      ------------------------------------------------------------------------------------------------\n");
		printf("\n        \t[NAME]\t\t");
		printf("\t[AGE]\t\t     ");
		printf("\t[SPORT INTREST]\t       ");
		printf("\t[PHONE NO]\t\t");

		while(temp!=NULL) {
			printf("\n\t%15s           ",temp->name);
			printf("\t%2d      ",temp->age);
			printf("\t%15s              ",temp->intrestedsport);
			printf("\t%10s              ", temp->phoneNo);
			temp=temp->next;
		}
		printf("\n\n");
		printf("\n\t     --------------------------------------------------------------------------------------------------\n");
	}
}





//sort the data by age
/*
	void sortbyage(int request) {
	if(request==1) {
		//ascending order by age
		struct member *ptr1, *ptr2;
		int i, j, tempage;
		char tempintrestedsport[30],tempname[30],tempphoneNo[10];
		ptr1 = ptr2 = head;

		for (i = 0; i < node_count; i++) {
			tempage = ptr1->age;
			strcpy(tempintrestedsport,ptr1->intrestedsport);
			strcpy(tempname,ptr1->name);
			strcpy(tempphoneNo,ptr1->phoneNo);

			for (j = 0; j < i; j++)
				ptr2 = ptr2->next;
			for (j = i; j > 0 && ptr2->prev->age > tempage; j--) {
				ptr2->age = ptr2->prev->age;
				strcpy(ptr2->intrestedsport,ptr2->prev->intrestedsport);
				strcpy(ptr2->name,ptr2->prev->name);
				strcpy(ptr2->phoneNo,ptr2->prev->phoneNo);
				ptr2 = ptr2->prev;
			}
			ptr2->age = tempage;
			strcpy(ptr2->intrestedsport,tempintrestedsport);
			strcpy(ptr2->name,tempname);
			strcpy(ptr2->phoneNo,tempphoneNo);
			ptr2 = head;
			ptr1 = ptr1->next;
		}
		displaymembers();
	} else if(request==2) {
		//descending order by age
		
	}
}
*/


int main() {

	int input,flag,choice,req,bookinp,flagb,gameinp,flagbt,gamerminp;
	insertNode("Gautami",21,"Chess","9168218747");
	insertNode("Aniket",20,"Cricket","9370068729");
	insertNode("Laxita",22,"Swimming","9812673456");
	insertNode("Gandhar",21,"Cricket","9827452819");


	printf("\t\t *** GYMKHANA (SPORTS CENTER) REGISTRATION SYSTEM ****");
	printf("\n\n");

	while(1) {
		printf(" ###################-----------------------------------######################\n");
		printf("|\t\t SERVICES AVAILABLE IN THIS APPLICATION         	    |\n");
		printf("|\t\t [1] \t DISPLAY ALL MEMEBER OF SPORTS CENTER    	    |\n");
		printf("|\t\t [2] \t ADD MEMEBER TO SPORTS CENTER            	    |\n");
		printf("|\t\t [3] \t REMOVE MEMEBER FROM SPORTS CENTER       	    |\n");
		printf("|\t\t [4] \t SEARCH MEMEBER DETAILS                  	    |\n");
		printf("|\t\t [5] \t BOOK GAMES IN SPORTS CENTER             	    |\n");
		//printf("|\t\t [6] \t SORT THE DATA DISPLAY                   	    |\n");
		printf("|\t\t [6] \t HOW MANY MEMBERS ARE THERE?              	    |\n");
		printf("|\t\t [0] \t to exit registration window             	    |\n");
		printf(" ----------------------------------------------------------------------------\n");
		printf("YOUR PREFERENCE:   ");
		scanf("%d",&input);

		switch(input) {
			case 0:
				printf("THANK YOU FOR USING THIS SOFTWARE.........");
				exit(0);
				break;
			case 1:
				//show current memebers in gymkhana
				printf("\n");
				printf(" \t\t\t\t-----------------------------------------\n");
				printf("\t\t\t\t|\t   MEMBERS OF GYMKHANA          |\n");
				printf(" \t\t\t\t-----------------------------------------\n");
				displaymembers();
				printf("\n");
				break;

			case 2:
				//add new member to gymkhana
				
				addmember();
				break;

			case 3:
				//remove name of member from the list
				removeMember();
				printf("\n\n");
				break;

			case 4:
				//search member in the list
				printf("\n\n");                          
				printf(" \t   -------------------------------------------------------\n");
				printf("\t  |\t \t          SEARCHING                       |\n");
				printf(" \t   -------------------------------------------------------\n");
				flag=0;
				while(flag!=1) {
					printf("             ==================================================\n");
					printf("\n              -----YOU HAVE TWO OPTIONS FOR SEARCHING-----\n");
					printf("            \t1. SEARCH BY SPORTS INTRESTED IN...\n");
					printf("            \t2. SEARCH BY NAME\n");
					printf("            \t0. [exit]\n");
					printf("\n");
					printf("             ==================================================\n");
					printf("\t     YOUR CHOICE FOR SEARCHING RECORD :     ");
					scanf("%d",&choice);
					printf("\n\n"); 
					searchMember(choice);
					
					flag=1;
				}
				break;


			case 5:
				//asumming 4 games booking in sports centre --- chess, carrom, table-tennis, cricket
				printf("\n\n");
				printf(" \t-----------------------------------------\n");
				printf("\t|\t \tBOOKING                  |\n");
				printf(" \t-----------------------------------------\n");
				flagb=flagbt=0;
				while(flagb!=1) {
					printf("         =======================================\n");
					printf("\t     1. BOOK GAME FOR TOMORROW\n");
					printf("\t     2. CANCEL BOOKING\n");
					printf("\t     3. DISPLAY CURRENT BOOKINGS\n");
					printf("\t     0. [exit booking window]\n");
					printf("         =======================================\n");
					printf("\t    YOUR CHOICE : ");
					scanf("%d",&bookinp);
					printf("\n");
					switch(bookinp) {
							case 0:
								flagb=1;
								break;
							case 1:
								printf("\n\n");                              
								printf(" \t\t\t\t-----------------------------------------\n");
								printf("\t\t\t\t|\t \tFOR WHICH GAME ?         |\n");
								printf(" \t\t\t\t-----------------------------------------\n");

								printf("\t\t\t\t------------------------------------------------\n");
								printf("\t\t\t\t\t1. WANT TO PLAY CHESS TOMORROW\n");
								printf("\t\t\t\t\t2. WANT TO PLAY CRICKET TOMORROW\n");
								printf("\t\t\t\t\t3. WANT TO PLAY CARROM TOMORROW\n");
								printf("\t\t\t\t\t4. WANT TO PLAY TABLE-TENNIS TOMORROW\n");
								printf("\t\t\t\t------------------------------------------------\n");
								printf("\t\t\t\tYOUR CHOICE : ");
								scanf("%d",&gameinp);
								switch(gameinp) {
									case 1:
										enqueuechess();
										break;
									case 2:
										enqueuecricket();
										break;
									case 3:
										enqueuecarrom();
										break;
									case 4:
										enqueuetennis();
										break;
										
									default:
										printf("\t\t\t\tINVALID CHOICE !!!\n");
										break;

								}

								break;
							case 2:
								printf("\n\n");                              
								printf(" \t\t\t\t-----------------------------------------\n");
								printf("\t\t\t\t|\t \tFOR WHICH GAME ?         |\n");
								printf(" \t\t\t\t-----------------------------------------\n");
								printf("\t\t\t\t------------------------------------------------\n");
								printf("\t\t\t\t1. WANT TO REMOVE BOOKING FOR CHESS TOMORROW\n");
								printf("\t\t\t\t2. WANT TO REMOVE BOOKING FOR PLAY CRICKET TOMORROW\n");
								printf("\t\t\t\t3. WANT TO REMOVE BOOKING FOR PLAY CARROM TOMORROW\n");
								printf("\t\t\t\t4. WANT TO REMOVE BOOKING FOR PLAY TABLE-TENNIS TOMORROW\n");
								printf("\t\t\t\t------------------------------------------------\n");
								printf("\t\t\t\tYOUR CHOICE : ");
								scanf("%d",&gamerminp);
								switch(gamerminp) {
									case 1:
										dequeuechess();
										break;
									case 2:
										dequeuecricket();
										break;
									case 3:
										dequeuecarrom();
										break;
									case 4:
										dequeuetennis();
										break;
									default:
										printf("\t\t\t\tINVALID CHOICE !!!\n");
										break;

								}
								break;
							case 3:
								printf("\n\n");
								printf(" \t\t\t--------------------------------------------\n");
								printf("\t\t\t|\t \tLIST OF BOOKINGS            |\n");
								printf(" \t\t\t--------------------------------------------\n");
								printf(" \t\t   ----------------------------------------------------------\n");
								printf(" \t\t\t-----------------------------------------\n");
								printf(" \t\t\t|\t \tCHESS                     |\n");
								printf(" \t\t\t-----------------------------------------\n");
								displaychess();
								printf(" \t\t\t-----------------------------------------\n");
								printf(" \t\t\t|\t \tCARROM                    |\n");
								printf(" \t\t\t-----------------------------------------\n");
								displaycarrom();
								printf(" \t\t\t-----------------------------------------\n");
								printf(" \t\t\t|\t \tCRICKET                   |\n");
								printf(" \t\t\t-----------------------------------------\n");
								displaycricket();
								printf(" \t\t\t-----------------------------------------\n");
								printf(" \t\t\t|\t \tTABLE TENNIS              |\n");
								printf(" \t\t\t-----------------------------------------\n");
								displaytennis();
								printf("\t.............................................................................\n");
								printf("\n\n");
								break;
							default:
								printf(" \t\t\tINVALID CHOICE!!\n");

							}
					}
				break;
				
			/*
			case 6:
				printf("-----------------------------------------\n");
				printf("|\t \tSORTING                 |\n");
				printf("-----------------------------------------\n");
				flag=0;
				while(flag!=1) {
					printf("\n---YOU HAVE TWO OPTIONS FOR SORTING---\n");
					printf("1. SORT BY SPORTS INTRESTED IN...\n");
					printf("2. SORT BY AGE\n");
					printf("0. [exit]\n");
					printf("\n");
					printf("YOUR CHOICE FOR SORTING :     ");
					scanf("%d",&choice);
					switch(choice) {
						case 0:
							flag=1;
							break;
						case 1:
							//sortbyintrest();
							break;
						case 2:
							//sort by age
							printf("...............HOW YOU WANT TO SORT DATA................\n");
							printf("1. ascending order of age\n");
							printf("2. descending order of age\n");
							scanf("%d",&req);
							sortbyage(req);
							break;
						default :
							printf("Invalid Input Try again!");
							break;

					}


				}
				break;
			*/
			case 6:
				printf("\n\n");
				printf("\t\t---------------------------------\n");
				printf("\t\t|      CURRENT MEMBER COUNT      |\n");
				printf("\t\t---------------------------------\n");
				printf("\n\t\t\t      %d\n",node_count);
				printf("\n\n");
				break;
			default :
				printf("Invalid Input Try again!");
				break;
		}
	}

}

