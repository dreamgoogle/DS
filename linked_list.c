#include<stdio.h>
#include"types.h"
#include<stdlib.h>

struct nodee {
	int data;
	struct nodee *link;
};

typedef struct nodee node;
node *f_elem = NULL;
node *l_elem = NULL;
u8 len_of_list;

u8 append_at_begin()
{
	u8 ret = TRUE;
	u32 data;
	node *tmp_n;
	printf("Inside append_at_begin\n");
	printf("Enter the data to append : ");
	scanf_s("%u",&data);
	tmp_n = malloc(sizeof(node));
	if (tmp_n == NULL)
	{
		printf("Memory not allocated\n");
		ret = FALSE;
	}
	else
	{
		tmp_n->data = data;
		tmp_n->link = f_elem;
		f_elem = tmp_n;
		if (tmp_n->link == NULL)
		{
			l_elem = tmp_n;
		}
		len_of_list++;
	}
	return ret;
}

u8 append_after()
{
	u32 after, data;
	u8 ret = TRUE,data_found = TRUE;
	node *tmp_n1,*tmp_n2;
	printf("Inside append_after\n");
	printf("Enter you input in form of x,y\n");
	printf("x = After which data, y = Data\n");
	scanf_s("%d%*c%d", &after, &data);
	do {
		if (f_elem == NULL)
		{
			printf("There are no elements in the list\nChoose a different option : ");
			ret = FALSE;
		}
		else
		{
			tmp_n1 = f_elem;
			while ((tmp_n1->link != NULL) && (tmp_n1->data != after))
			{
				tmp_n1 = tmp_n1->link;
			}
			//Either tmp_n1 node contains required data or it points to the last data
			if (tmp_n1->data != after)
			{
				data_found = FALSE;
				printf("'After which data' does not exist in the list\n");
				printf("Choose 'After which data' again : ");
				scanf_s("%u",&after);

			}
			else
			{
				data_found = TRUE;
				tmp_n2 = malloc(sizeof(node));
				if (tmp_n2 == NULL)
				{
					printf("Memory not allocated\n");
				}
				else
				{
					tmp_n2->link = tmp_n1->link;
					tmp_n1->link = tmp_n2;
					tmp_n2->data = data;
				}
				len_of_list++;
			}
		}
	} while (!data_found);
	return ret;
}

u8 append_at_last()
{
	printf("Inside append_at_last\n");
	node *tmp_n;
	u8 ret = TRUE;
	u32 data;
	printf("Enter the data to append : ");
	scanf_s("%u", &data);
	tmp_n = malloc(sizeof(node));
	if (tmp_n == NULL)
	{
		printf("Memory not allocated\n");
		ret = FALSE;
	}
	else
	{
		tmp_n->link = NULL;
		tmp_n->data = data;
		if (f_elem == NULL) // If there are no elements in the list
		{
			f_elem = tmp_n;
			l_elem = tmp_n;
		}
		else
		{
			l_elem->link = tmp_n;
			l_elem = tmp_n;
		}
		len_of_list++;
	}
	return ret;
}

u8 append_at_posn()
{
	printf("Inside append_at_posn\n");
	u8 ret = TRUE;
	if (f_elem == NULL)
	{
		printf("List is empty. Choose different option:");
		ret = FALSE;
	}
	else 
	{
		u32 posn,data;
		u8 len = 0,pos_cor,i;
		node *tmp_n,*tmp_n1;
		tmp_n = f_elem;
		while (tmp_n != NULL)
		{
			tmp_n = tmp_n->link;
			len++;
		}
		printf("Enter the position and Data in form of posn,data: ");
		scanf_s("%u%*c%u",&posn,&data);
		do {
			if (posn <= ((u32)len + 1))
			{
				pos_cor = TRUE;
				if (posn > 1)
				{
					i = 1;
					tmp_n = f_elem;
					while (posn - i > 1)
					{
						tmp_n = tmp_n->link;
						i++;
					}
					tmp_n1 = malloc(sizeof(node));
					if (tmp_n1 == NULL)
					{
						printf("Memory not allocated\n");
					}
					else
					{
						tmp_n1->link = tmp_n->link;
						tmp_n1->data = data;
						tmp_n->link = tmp_n1;
						len_of_list++;
					}
				}
				else
				{
					printf("To fill position 1 use option 'Append at beginning'");
					ret = FALSE;
				}
			}
			else
			{
				printf("Position seeked cannot be filled\nChoose a different position : ");
				scanf_s("%u", &posn);
				pos_cor = FALSE;
			}
		} while (!pos_cor);
	}
	return ret;
}

void append()
{
	u32 option;
	u8 ret = TRUE;
	printf("Appending options\n1) Append at beginning \n2) Append after some data x\n3) Append at last\n4) Append at a position\n");
	printf("How do you want to append :");
	do {
		scanf_s("%d", &option);
		switch (option)
		{
		case 1: ret = append_at_begin();
				break;
		case 2: ret = append_after();
				break;
		case 3: ret = append_at_last();
				break;
		case 4: ret = append_at_posn();
				break;
		default:option = 0;
				printf("Wrong choice!! Choose correct option : ");
				break;
		}
	} while (!option || !ret);
}

u8 delete_at_begin()
{
	printf("Inside delete_at_begin\n");
	u8 ret = TRUE;
	node *tmp_n;
	if (f_elem == NULL)
	{
		printf("Nothing to delete!! List is empty\n");
		ret = FALSE;
	}
	else
	{
		tmp_n = f_elem;
		if (f_elem == l_elem)
		{
			// In case there is only 1 elem in the list then last elem should also be updated
			l_elem = f_elem->link;
		}
		f_elem = f_elem->link;
		if (f_elem->link == NULL)
		{
			// In case there were only 2 elements in the list then after deleting first elem, 2nd becomes first & last both
			l_elem = f_elem;
		}
		len_of_list--;
		free(tmp_n);
	}
	return ret;
}

node* return_node_from_last(u8 posn)
{
	printf("Inside return_node_from_last\n");
	node *tmp_n = NULL;
	u8 success = TRUE;
	u32 position = posn;
	do {
		if (position <= len_of_list)
		{
			u8 count;
			count = len_of_list - position;
			tmp_n = f_elem;
			while (count>0)
			{
				tmp_n = tmp_n->link;
				count--;
			}
			success = TRUE;
		}
		else
		{
			printf("Position does not exists in the list\nTry new position : ");
			scanf_s("%u", &position);
			success = FALSE;
		}
	} while (!success);
	return tmp_n;
}

u8 delete_at_last()
{
	printf("Inside delete_at_last\n");
	u8 ret = TRUE;
	node *tmp_n,*tmp_n1;
	if (f_elem == NULL)
	{
		printf("Nothing to delete. List is empty!! \n");
		ret = FALSE;
	}
	else
	{
		if (f_elem == l_elem) // If there is only 1 element in the list
		{
			tmp_n = f_elem;
			f_elem = NULL;
			l_elem = NULL;
		}
		else
		{
			if (f_elem->link == l_elem) // If there are only 2 elements in the list
			{
				f_elem->link = NULL;
				tmp_n = l_elem;
				l_elem = f_elem;
			}
			else
			{
				tmp_n1 = return_node_from_last(2); printf("correctly returned\n");
				tmp_n1->link = NULL;
				tmp_n = l_elem;
				l_elem = tmp_n1;
			}
		}
		len_of_list--;
		free(tmp_n);
	}
	return ret;
}

u8 delete_at_posn()
{
	printf("Inside delete_at_posn\n");
	u8 ret = FALSE, success = TRUE, i;
	u32 position;
	node *tmp_n,*tmp_n1;
	printf("Which position you want to delete(1..n) : ");
	do {
		scanf_s("%u", &position);
		if(position <= len_of_list)
		{
			success = TRUE;
			if(position < 1)
			{
				success = FALSE;
				printf("Position does not exist in the list. Choose position again(1..n) : ");
			    scanf_s("%u",&position);
			}
			else if(position == 1)
			{
				tmp_n = f_elem;
				f_elem = f_elem->link;
				if (position == len_of_list)
				{
					l_elem = f_elem;
				}
				free(tmp_n);
				len_of_list--;
				ret = TRUE;
			}
			else if (position > 1)
			{
				tmp_n = f_elem;
				i = 2;
				while(position-i)
				{
					tmp_n = tmp_n->link;
					i++;
				}
				tmp_n1 = tmp_n->link;
				tmp_n->link = tmp_n->link->link;
				if (position == len_of_list)
				{
					l_elem = tmp_n;
				}
				free(tmp_n1);
				len_of_list--;
				ret = TRUE;
			}
		}
		else
		{
			success = FALSE;
			printf("Position does not exist in the list. Choose position again(1..n) : ");
			scanf_s("%u",&position);
		}
	}while(!success);
	return ret;
}

u8 delete_a_data()
{
	printf("Inside delete_a_data\n");
	u8 ret = TRUE,found;
	u32 data;
	node *tmp_n,*tmp_n1;
	if (f_elem == NULL)
	{
		printf("Nothing to delete. List is empty !!\n");
		ret = FALSE;
	}
	else
	{
		printf("Enter the data to be deleted : ");
		do {
			found = FALSE;
			scanf_s("%u",&data);
			if (f_elem->data == data)
			{
				tmp_n = f_elem;
				f_elem = f_elem->link;
				if (tmp_n == l_elem)
				{
					l_elem = NULL;
				}
				found = TRUE;
				free(tmp_n);
				len_of_list--;
			}
			else
			{
				tmp_n = f_elem;
				while ((tmp_n->link != NULL) && (!found))
				{
					if (tmp_n->link->data != data)
					{
						tmp_n = tmp_n->link;
					}
					else
					{
						found = TRUE;
					}
				}
				if (found)
				{
					if (tmp_n->link == l_elem) // If last node is deleted than update l_elem also
					{
						l_elem = tmp_n;
					}
					tmp_n1 = tmp_n->link;
					tmp_n->link = tmp_n->link->link;
					free(tmp_n1);
					len_of_list--;
				}
				else
				{
					printf("Data not found in the list. Choose a different data : ");
					scanf_s("%u", &data);
				}
			}
		} while (!found);
	}
	return ret;
}

void delete()
{
	printf("Inside Delete\n");
	u32 option;
	u8 ret = TRUE;
	printf("Deleting options\n1) Delete at beginning \n2) Delete at last\n3) Delete at a position\n4) Delete a data\n");
	printf("How do you want to delete :");
	do {
		scanf_s("%d", &option);
		switch (option)
		{
		case 1: ret = delete_at_begin();
				break;
		case 2: ret = delete_at_last();
				break;
		case 3: ret = delete_at_posn();
				break;
		case 4: ret = delete_a_data();
				break;
		default:option = 0;
				printf("Wrong choice!! Choose correct option : ");
				break;
		}
	} while (!option || !ret);
}

void display()
{
	printf("Inside Display\n");
	node *tmp_n;
	tmp_n = f_elem;
	while (tmp_n != NULL)
	{
		printf("%d ",tmp_n->data);
		tmp_n = tmp_n->link;
	}
	putchar('\n');
}

void main()
{
	u32 wtc;
	printf("Welcome to linked list programe\n");
	do {
		printf("Available options :\n");
		printf("1) Add a member\n");
		printf("2) Remove a member\n");
		printf("3) Display the list\n");
		printf("4) Exit\n");
		printf("Please choose an option : ");
		scanf_s("%u",&wtc);

		switch (wtc)
		{
		case 1:
		{
			append();
			break;
		}
		case 2:
		{
			delete();
			break;
		}
		case 3:
		{
			display();
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			wtc = 0; /* Loop around */
			printf("Wrong choice. Choose again \n");
			break;
		}
		}
	} while (!(wtc==4));
}