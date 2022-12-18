#include "LibraryFile.h"


ErrorState Newlist (List_t **S)			//make a new List
{
	ErrorState Ret = NOK;
	List_t *ptr = (List_t *)malloc (sizeof (List_t) );
	if (NULL == S)
	{
		Ret = NULL_PTR;
	}
	else if (NULL == ptr)
	{
		printf ("Malloc faild to create a list! \n");
		Ret = NULL_PTR;
	}
	else
	{
		ptr->Size = 0;
		ptr->Head = NULL;
		ptr->Tail = NULL;
		*S = ptr;
		Ret = OK;
	}
	return Ret;
}

ErrorState IsEmpty (List_t *S)
{
	ErrorState Ret = NOK;
	if (NULL == S)
	{
		Ret = NULL_PTR;
	}
	else if (NULL == S->Head && NULL == S->Tail)
	{
		Ret = Empty;
	}
	else
	{
		Ret = NEmpty;
	}
	return Ret;
}

ErrorState AddNewBook (List_t *S)
{
	ErrorState Ret = NOK;
	NODE_t *ptr;
	if (NULL == S)
	{
		Ret = NULL_PTR;
	}
	else if (IsEmpty (S) == Empty)			//add Boke in an Empty List
	{
		ptr = (NODE_t *) malloc (sizeof (NODE_t) );
		ptr->Next = NULL;
		ptr->Prevouse = NULL;
		
		printf("Enter the Name of the Book : ");
		gets (ptr->BookName);
		fflush (stdin);
		
		printf("Enter the Name of the Author : ");
		gets (ptr->BookAuthor);
		fflush (stdin);
		
		printf("Enter the Price of the Book : ");
		scanf ("%d",&ptr->Price);
		fflush (stdin);
		
		S->Head = ptr;
		S->Tail = ptr;
		S->Size++ ;
		Ret = OK;
	}
	else					//add Book in the last of a List full with element
	{
		ptr = (NODE_t *) malloc (sizeof (NODE_t) );
		ptr->Next = NULL;
		ptr->Prevouse = S->Tail;
		
		printf("Enter the Name of the Book : ");
		gets (ptr->BookName);
		fflush (stdin);
		
		printf("Enter the Name of the Author : ");
		gets (ptr->BookAuthor);
		fflush (stdin);
		
		printf("Enter the Price of the Book : ");
		scanf ("%d",&ptr->Price);
		fflush (stdin);
		
		S->Tail->Next = ptr;
		S->Tail = ptr;
		S->Size++ ;
		Ret = OK;
	}
	return Ret;
}

ErrorState DisplayBook(List_t *S)
{
	ErrorState Ret = NOK;
	NODE_t *ptr;
	u32 i = 1;
	if (NULL == S)
	{
		Ret = NULL_PTR;
	}
	else if (IsEmpty(S) == Empty)
	{
		printf ("Empty List, Please add some Book first! \n");
		Ret = OK;
	}
	else
	{
		ptr = S->Head;
		printf ("------------------ The Available Books -------------------\n");
		while (NULL != ptr)
		{
			printf ("Book NO. %d \n",i);
			printf ("The Name of the Book : %s \n",ptr->BookName);
			printf ("The Name of the Author : %s \n",ptr->BookAuthor);
			printf ("The Price of the Book : %d \n",ptr->Price);
			ptr = ptr->Next;
			printf ("----------------------------------------------------------\n");
			i++;
		}
		Ret = OK;
	}
	return Ret;
}

ErrorState DeletBook (List_t *S)
{
	u32 Order = 0;
	ErrorState Ret = NOK;
	NODE_t *ptr = NULL;
	if (NULL == S)
	{
		Ret = NULL_PTR;
	}
	else if (IsEmpty(S) == Empty)
	{
		printf ("Empty List, Please add some Book first! \n");
		Ret = Empty;
	}
	else
	{
		printf ("Please enter the order of book you want to delet (from 1 to %d ) --> ",S->Size);
		scanf ("%d",&Order);
		if (Order > S->Size || Order < 0)
		{
			printf ("Error!, Enter not allowed number \n");
			Ret = OK;
		}
		else if (1 == S->Size)		//if there is only one book in the List
		{
			ptr = S->Head;
			free (ptr);
			S->Size--;
			S->Head = NULL;
			S->Tail = NULL;
			Ret = OK;
			printf ("The Book has been deleted succefully :)\n");
		}
		else if (1 == Order)	// Delet a Book from the begane of the List
		{
			ptr = S->Head;
			S->Head = S->Head->Next;
			S->Head->Prevouse = NULL;
			free (ptr);
			S->Size--;
			Ret = OK;
			printf ("The Book has been deleted succefully :)\n");
		}
		else if (Order == S->Size)	//Delet a Book from the last of the List 
		{
			ptr = S->Tail;
			S->Tail = S->Tail->Prevouse;
			S->Tail->Next = NULL;
			free (ptr);
			S->Size--;
			Ret = OK;
			printf ("The Book has been deleted succefully :)\n");
		}
		else		//Delet from the Medil of the List
		{
			u32 i = 1;
			ptr = S->Head;
			while (i++ != Order)
			{
				ptr = ptr->Next;
			}
			ptr->Prevouse->Next = ptr->Next;
			ptr->Next->Prevouse = ptr->Prevouse;
			free(ptr);
			S->Size--;
			Ret = OK;
			printf ("The Book has been deleted succefully :)\n");
		}
	}
	return Ret;
}