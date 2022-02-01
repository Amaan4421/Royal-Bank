/*
		AUTHOR:AMAAN SAJINA
		DOC:19/01/2022
		OBJECTIVE:BANK APPLICATION WITH POINTERS,FILE AND STRUCTURE
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
struct Bank
{
	int cid;
	char cName[30];
	char uName[30];
	char password [30];
	float balance;
	int transactionCounter;
	struct Bank *next;
	int flag;
}*Head=NULL;
void createAccount();
void displayAll();
void displayParticular();
void checkBalance(struct Bank *temp1);
void withdraw(struct Bank *temp1);
void deposit(struct  Bank *temp1);
struct Bank* login(char user[],char pass[]);
void del(int id);
void main()
{
	int choice, adminChoice,choiceCustomer;
	char user[30];
	char pass[30];
	int id;
	struct Bank *temp1;
//	textbackground(WHITE);
	while(1)
	{
		textbackground(WHITE);
		main:
		clrscr();
		textcolor(RED);
		gotoxy(30,4);
		cprintf("--------------------------");
		gotoxy(29,5);
		cprintf("|");
		gotoxy(29,6);
		cprintf("|");
		gotoxy(29,7);
		cprintf("|");
		gotoxy(56,5);
		cprintf("|");
		gotoxy(56,6);
		cprintf("|");
		gotoxy(56,7);
		cprintf("|");
		gotoxy(32,6);
		cprintf("WELCOME TO ROYAL BANK");
		gotoxy(30,8);
		cprintf("--------------------------");
		sound(1000);
		delay(200);
		nosound();
		textcolor(BLUE);
		gotoxy(25,7);
		cprintf("\n\n\n-------------Home Page--------------");
		textcolor(BLACK);
		gotoxy(25,13);
		cprintf("1---Admin");
		gotoxy(25,14);
		cprintf("2---Customer");
		gotoxy(25,15);
		cprintf("3---Exit");
		gotoxy(25,17);
		cprintf("Enter your choice:");
		cscanf("%d",&choice);

		switch(choice)
		{
			case 1: sound(500);
				delay(200);
				nosound();

				start1:
				clrscr();
				textcolor(BLUE);
				gotoxy(28,3);
				cprintf("Welcome to Admin Panel!!");
					textcolor(BLACK);
					gotoxy(28,5);
					cprintf("Enter username:");
					fflush(stdin);
					gets(user);
					sound(300);
					delay(200);
					nosound();
					gotoxy(28,7);
					cprintf("Enter password:");
					gets(pass);
					if(strcmp(user,"admin")==0 && strcmp(pass,"admin")==0)
					{
						while(1)
						{
							clrscr();
							sound(1000);
							delay(200);
							nosound();
							textcolor(BLUE);
							gotoxy(28,3);
							cprintf("Login successfully done!!");

							textcolor(BLACK);
							printf("\n\n\t\t1---Create Account");
							printf("\n\t\t2---Delete Account");
							printf("\n\t\t3---Display All");
							printf("\n\t\t4---Display Particular");
							printf("\n\t\t5---Log out");

							printf("\n\n\t\tEnter your choice:");
							scanf("%d",&adminChoice);
							switch(adminChoice)
							{
									case 1: sound(300);
											delay(200);
											nosound();

											createAccount();
											printf("\n\nSuccessfully created account!!");								
											sound(4000);
											delay(200);
											nosound();
											getch();
											break;

									case 2: sound(300);
											delay(200);
											nosound();

											printf("\nEnter the id you want to delete:");
											scanf("%d",&id);
											del(id);
											break;

									case 3: sound(300);
											delay(200);
											nosound();
											displayAll();
											getch();
											break;

								   /*		case 4: sound(3000);
													delay(200);
													nosound();

													printf("\nEnter the id you want to display:");
													scanf("%d",&id);
													displayparticular(id);
												break;
								 */
									case 5: goto main;

									default:printf("\nInvalid Choice!!");
											sound(2000);
											delay(400);
											nosound();
											getch();


							}//end of admin choice
						}//end of while
					}//end of if
					else
					{
						clrscr();
						printf("\nInvalid Username or Password!!");
						sound(2000);
						delay(400);
						nosound();
						getch();
						goto start1;

					}//end of else

			break;


			case 2: start:
					sound(500);
					delay(200);
					nosound();
					clrscr();
					textcolor(BLUE);
					gotoxy(24,3);
					cprintf("We are thankful to you for choosing our bank!!!");
					textcolor(BLACK);
					printf("\n\n\t\t\tPlease enter your username:");
					fflush(stdin);
					gets(user);
						printf("\n\n\t\t\tEnter your password:");
						gets(pass);
						temp1=login(user, pass);
						while(1)
						{
							clrscr();
							if(temp1!=NULL)
							{
								textcolor(BLUE);
								gotoxy(28,4);
								cprintf("Succefully login");
								textcolor(BLACK);
								printf("\n\n1----Check balance");
								printf("\n2----Deposit");
								printf("\n3---Withdraw");
								printf("\n4----Logout");

								printf("\n\nEnter the choice:");
								scanf("%d",&choiceCustomer);
								switch(choiceCustomer)
								{
									case 1: sound(300);
											delay(200);
											nosound();
											checkBalance(temp1);
									break;

									case 2: sound(300);
											delay(200);
											nosound();
											deposit(temp1);
									break;

									case 3: sound(300);
											delay(200);
											nosound();
											withdraw(temp1);
										break;

									case 4: goto main;


									default:printf("\nInvalid Choice!!");
											sound(2000);
											delay(400);
											nosound();
											getch();
								}//end of switch of customer

							}//end of if
							else
							{
								clrscr();
								printf("\nUsername and Password are Incorrect!!");
								sound(2000);
								delay(300);
								nosound();
								getch();
								goto start;
							}//end of else
						}//end of  while
			break;

			case 3: sound(500);
					delay(200);
					nosound();
					exit(0);


			default:printf("\nInvalid choice!!");
					sound(2000);
					delay(300);
					nosound();
					getch();

		}//end of switch
       goto main;
	}//end of while
}//end of main

void createAccount()
{
	FILE *fp;
	struct Bank *temp=Head, *temp1;
	if(Head==NULL)
	{
		fp=fopen("royalbank.txt","w");
		Head=(struct Bank *) malloc(sizeof(struct Bank));
		printf("\nEnter the cid:");
		scanf("%d",&Head->cid);
		printf("\n\nEnter the customer name:");
		fflush(stdin);
		scanf("%s",Head->cName);
		printf("\n\nEnter the customerUser name:");
		fflush(stdin);
		scanf("%s",Head->uName);
		printf("\n\nEnter the customer password:");
		fflush(stdin);
		scanf("%s",Head->password);
		Head->balance=10000;
		Head->transactionCounter=0;
		Head->flag=1;
		fwrite(&Head,sizeof(Head),1,fp);
		fclose(fp);
	}//end of if
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}//end of while
		fp=fopen("royalbank.txt","a");
		temp1=(struct Bank *) malloc(sizeof(struct Bank));
		printf("\nEnter the cid:");
		scanf("%d",&temp1->cid);
		printf("\nEnter the customer name:");
		fflush(stdin);
		scanf("%s",temp1->cName);
		printf("\nEnter the customerUser name:");
		fflush(stdin);
		scanf("%s",temp1->uName);
		printf("\nEnter the customer password:");
		fflush(stdin);
		scanf("%s",temp1->password);
		temp1->balance=10000;
		temp1->transactionCounter=0;
		temp1->flag=0;
		fwrite(&temp1,sizeof(temp1),1,fp);
		fclose(fp);
		temp->next=temp1;
		temp1->next=NULL;
	} //end of else

}//end of create

void displayAll()
{
	FILE *fp;
	struct Bank *temp;
	fp=fopen("royalbank.txt","r");
	printf("\ncid\t\tcname\t\t\tbalance\n");
	temp=(struct Bank *) malloc(sizeof(struct Bank));
	while(fread(&temp,sizeof(temp),1,fp))
	{
		printf("\n%d\t\t%s\t\t\t%.2f",temp->cid,temp->cName,temp->balance);
	}//end of while
}//end of display

void checkBalance(struct Bank *temp1)
{
	printf("\nWelcome Mr.%s",temp1->cName);
	printf("\nYour Balance is %f",temp1->balance);
	return;
}//end of checking

void withdraw(struct Bank *temp1)
{
	float with,tempBalance;
	FILE *fp;
	fp=fopen("royalbank.txt","a");
	printf("\nEnter the amount you want to withdraw:");
	scanf("%f",&with);
	tempBalance=temp1->balance-with;
	if(tempBalance<=10000)
	{
		printf("\nInsufficiant Balance!!");
		getch();
		return;
	}//end of if
	temp1->balance=tempBalance;
	fseek(fp,temp1->flag,SEEK_SET);
	fwrite(&temp1,sizeof(temp1),1,fp);
	fclose(fp);
}//end of withdraw


void del(int id)
{
	struct Bank *temp,*temp1;
	FILE *fp;
	fp=fopen("royalbank.txt","a");
	while(fread(&temp,sizeof(temp),1,fp))
	{
		if(Head==NULL)
		{
			Head=(struct Bank *)malloc(sizeof(struct Bank));
			Head=temp;
			Head->next=NULL;
		}
		//end of if
		else
		{
			temp1=Head;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}//end of while
			temp1->next=temp;
		}//end of else
	}//end of outer while

	if(Head->next==NULL)
	{
		temp=Head;
		Head=NULL;
		free(temp);
		return;
	}//end of if
	temp=Head;
	while(temp->next->cid!=id || temp==NULL)
	{
		temp=temp->next;
	}//end of while

	if(temp==NULL)
	{
		printf("\nThe id you entered does not exists!!");
		return;
	}//end of if
	else
	{
		if(temp->next->next==NULL)
		{
			temp1=temp->next;
			temp->next=NULL;
			free(temp1);
		}//end of if
		else
		{
			temp1=temp->next;
			temp->next=temp1->next;
			temp1->next=NULL;
			free(temp1);
		}//end of else
	}//end of outer else

	temp1=Head;
	while(temp1!=NULL)
	{
		printf("%d->%s",temp1->cid,temp1->cName);
		temp1=temp1->next;
		getch();
	}//end of while
	getch();
	fclose(fp);
}//end of delete


void deposit(struct Bank *temp1)
{
	float dep;
	FILE *fp;
	fp=fopen("royalbank.txt","a");
	printf("\nEnter the amount you want to deposit:");
	scanf("%f",&dep);
	if(dep>0)
	{
		temp1->balance=temp1->balance+dep;
		fseek(fp,temp1->flag,SEEK_SET);
		fwrite(&temp1,sizeof(temp1),1,fp);
		fclose(fp);
	}//end of if
	else
	{
		printf("Deposit not possible!!");
		getch();
		return;
	}//end of else
}//end of deposit

struct Bank* login(char user[],char pass[])
{
	struct Bank *temp;
	FILE *fp;
	int pos;
	fp=fopen("royalbank.txt","r");
	while((fread(&temp,sizeof(temp),1,fp)))
	{
		if(strcmp(temp->uName,user)==0 && strcmp(temp->password,pass)==0)
		{
			pos=ftell(fp);
			printf("\nThe location of this structure is %d",pos);
			temp->flag=pos-1;
			getch();
			return temp;
		}//end of if
	}//end of while login
	return NULL;
}//end of login






























































