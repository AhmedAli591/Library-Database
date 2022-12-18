#include "main.h"


void main(void)
{
	u32 Select = 0;
	ErrorState Test = NOK;
	List_t *Mylist;
	
	Test = Newlist (&Mylist);
	
	if (NOK == Test)
	{
		printf ("ERROR!, Please Try again \n");
	}
	else 
	{	
		printf ("--------------- WELCOME TO THE LIBRARY APP ---------------\n");
		while (Select != 5)
		{
			printf ("----------------------------------------------------------\n");
			printf ("Choose one of the following options: \n");
			printf ("To view all books               Enter '1' \n");
			printf ("To add a New book               Enter '2' \n");
			printf ("To Delete a book                Enter '3' \n");
			printf ("To view No. of available books  Enter '4' \n");
			printf ("To Exist the Library App        Enter '5' \n");
			printf ("----------------------------------------------------------\n");
			printf ("---> You Choice is : ");
		
			scanf  ("%d",&Select);		//the user selection
			fflush(stdin);
			
			switch (Select)
			{
				
			case 1:
					Test = DisplayBook(Mylist);
					if (NOK == Test)
					{
						printf ("ERROR!, Please Try again \n");
					}
					else {}
					break;
			
			case 2:
					Test = AddNewBook(Mylist);
					if (NOK == Test)
					{
						printf ("ERROR!, Please Try again \n");
					}
					else 
					{
						printf ("The Book has been added succefully :)\n");
					}
					break;
					
			case 3:
					Test = DeletBook(Mylist);
					if (NOK == Test)
					{
						printf ("ERROR!, Please Try again \n");
					}
					else {}
					break;
					
			case 4:
					if (IsEmpty (Mylist) == Empty)
					{
						printf ("Empty List, Please add some Book first! \n");
					}
					else
					{
						printf("The Number of available Books is --> %d \n",Mylist->Size);
					}
					break;
					
			case 5:
					break;
					
			default:
					printf ("You entered a wrong input, please try again ! \n");
					
			}

		}
	}
}
