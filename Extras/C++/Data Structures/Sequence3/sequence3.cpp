#include "sequence3.h"

using namespace main_savitch_5;

sequence::sequence()
{
	head_ptr = NULL;
	tail_ptr = NULL;
	cursor = NULL;
	precursor = NULL;
	many_nodes = 0;
}

sequence::sequence(const sequence& source)
{
	if (source.cursor == 0)
	{
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = NULL;
		precursor = NULL;
	}
	else if (source.head_ptr == source.cursor)
	{
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = head_ptr;
		precursor = NULL;
	}
	else
	{
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		size_type index = 1;
		node *new_cursor = source.head_ptr;
		while (new_cursor != source.precursor)
		{
			new_cursor = new_cursor->link();
			index++;
		}
		precursor = list_locate(head_ptr, index);
		cursor = precursor->link();
	}
	many_nodes = source.many_nodes;
}

sequence::~sequence()
{
	list_clear(head_ptr);

}

void sequence::start()
{
	cursor = head_ptr;
	precursor = NULL;
}
void sequence::advance()
{
	if (is_item())
	{
		precursor = cursor;
		cursor = cursor->link();
	}
	else
		start();
}
void sequence::insert(const value_type& entry)
{
	if (is_item())
	{
		if (precursor != NULL)
		{
			list_insert(precursor, entry);
			cursor = precursor->link();
		}
		else
		{
			list_head_insert(head_ptr, entry);
			precursor = NULL;
			cursor = head_ptr;
		}
	}
	else
	{
		if (many_nodes == 0)
		{
			list_head_insert(head_ptr, entry);
			precursor = NULL;
			cursor = head_ptr;
			tail_ptr = head_ptr;
		}
		else
		{
			list_head_insert(head_ptr, entry);
			precursor = NULL;
			cursor = head_ptr;
		}
	}
	many_nodes++;
}

void sequence::attach(const value_type& entry)
{
	if (is_item())
	{
		if (cursor->link() == NULL)
		{
			list_insert(cursor, entry);
			precursor = cursor;
			cursor = cursor->link();
			tail_ptr = cursor;
		}
		else
		{
			list_insert(cursor, entry);
			precursor = cursor;
			cursor = cursor->link();
		}

	}
	else
	{
		if (many_nodes == 0)	//If there is nothing in the list
		{
			list_head_insert(head_ptr, entry); //Insert a head
			precursor = NULL;	//PreCursor is null
			cursor = head_ptr;	//Cursor is now the head
			tail_ptr = head_ptr; //Head is now also the tail
		}
		else //Means the cursor is not on the list
		{
			precursor = tail_ptr; //Tail ptr is now the precursor
			list_insert(tail_ptr, entry); //insert an entry after the tail ptr
			tail_ptr = tail_ptr->link(); // tail ptr is now next node
			cursor = tail_ptr; //cursor is on tail ptr

		}
	}
	many_nodes++;
}
void sequence::operator =(const sequence& source)
{
	many_nodes = source.many_nodes;
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	node* index_src;
	index_src = source.head_ptr;
	precursor = head_ptr;
	if (source.cursor == NULL)
	{
		if (source.precursor == NULL)
		{
			cursor = NULL;
			precursor = NULL;
		}
		else
		{
			precursor = tail_ptr;
			cursor = NULL;
		}
	}
	else
	{
		if (source.precursor == NULL)
		{
			cursor = head_ptr;
			precursor = NULL;
		}
		else
		{

			while (index_src != source.precursor)
			{
				index_src = index_src->link();
				precursor = precursor->link();
			}
			cursor = precursor->link();
		}
	}
}

void sequence::remove_current()
{
	if (is_item())
	{
		many_nodes--;
		if (precursor == NULL)
		{
			list_head_remove(head_ptr);
			cursor = head_ptr;
		}
		else
		{
			cursor = cursor->link();
			list_remove(precursor);
		}
	}
}


sequence::value_type sequence::current() const
{
	return cursor->data();
}