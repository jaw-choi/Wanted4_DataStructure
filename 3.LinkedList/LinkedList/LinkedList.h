#pragma once

#include "Node.h"
#include <iostream>

// ¸Ş¸ğ¸® ·¹ÀÌ¾Æ¿ô.
//class Test
//{
//	int value;
//	int* test;
//};

// ´ÜÀÏ ¿¬°á ¸®½ºÆ® Å¬·¡½º.
// Node¸¦ ³»ºÎ¿¡¼­ °ü¸®.
// Á¤·Ä ±â¹İÀ¸·Î ³ëµå Ãß°¡ (ÀüÁ¦: ºñ±³°¡ °¡´ÉÇØ¾ß ÇÔ).
template<typename T>
class LinkedList
{
	// Å¸ÀÔ ¾Ë¸®¾Æ½Ì ÁöÁ¤.
	using NodeType = Node<T>*;

public:
<<<<<<< Updated upstream
    LinkedList()
	: head(nullptr), count(0)
    {
    }
    ~LinkedList()
    {
	// Todo: ë©”ëª¨ë¦¬ ì •ë¦¬.
    }

    // ë…¸ë“œ ì¶”ê°€ í•¨ìˆ˜.
    void Insert(const T& data)
    {
	// ìƒˆë…¸ë“œ ìƒì„±.
	NodeType newNode = new Node<T>(data);

	// ë…¸ë“œë¥¼ ì‚½ì…í•  ìœ„ì¹˜ í™•ì¸.

	// í—¤ë“œê°€ ë¹ˆ ìƒíƒœì¸ì§€ í™•ì¸.
	if (!head)
=======
	LinkedList()
		: head(nullptr), count(0)
	{
	}
	
	~LinkedList()
>>>>>>> Stashed changes
	{
		// ¸Ş¸ğ¸® Á¤¸®.
		NodeType current = head;
		NodeType next = nullptr;

		// ¼øÈ¸ÇÏ¸é¼­ ¸Ş¸ğ¸® ÇØÁ¦.
		while (current)
		{
			// »èÁ¦ÇÏ±â Àü¿¡ ´ÙÀ½ ³ëµå ¹Ì¸® ÀúÀå.
			next = current->next;

			// »èÁ¦.
			delete current;

			// ´ÙÀ½ ³ëµå·Î ÀÌµ¿.
			current = next;
		}

		// Á¤¸®.
		head = nullptr;
		count = 0;
	}

	// ³ëµå Ãß°¡ ÇÔ¼ö.
	void Insert(const T& data)
	{
		// »õ³ëµå »ı¼º.
		NodeType newNode = new Node<T>(data);

		// ³ëµå¸¦ »ğÀÔÇÒ À§Ä¡ È®ÀÎ.

		// Çìµå°¡ ºó »óÅÂÀÎÁö È®ÀÎ.
		if (!head)
		{
			// Çìµå ³ëµå¸¦ »õ ³ëµå·Î ÁöÁ¤.
			head = newNode;
		}

		// Çìµå°¡ ÀÖÀ¸¸é Ãß°¡ÇÒ À§Ä¡ °Ë»ö ÈÄ Ãß°¡.
		else
		{
			// ÀÚ¸® °Ë»öÀ» À§ÇÑ º¯¼ö.
			NodeType current = head;
			NodeType trail = nullptr;

			// ÀÚ¸® °Ë»ö.
			while (current)
			{
				// °ª ºñ±³.
				if (current->data >= data)
				{
					break;
				}

				// ´ÙÀ½ ³ëµå·Î °Ë»ö ÀÌ¾î°¡±â.
				trail = current;
				current = current->next;
			}

			// °Ë»öÇÑ À§Ä¡°¡ ÇìµåÀÎ °æ¿ì.
			if (current == head)
			{
				// newNode¸¦ Çìµå·Î ÀüÈ¯.
				newNode->next = head;
				head = newNode;
			}

			// Çìµå°¡ ¾Æ´Ñ °æ¿ì.
			else
			{
				// »ğÀÔÇÒ À§Ä¡¿¡¼­ Æ÷ÀÎÅÍ Á¤¸®.
				newNode->next = current;
				trail->next = newNode;
			}
		}

		// ÀúÀå °³¼ö Áõ°¡.
		++count;
	}

	// ³ëµå Á¦°Å ÇÔ¼ö.
	void Delete(const T& data)
	{
		// ¿¹¿Ü Ã³¸® (ºó ¸®½ºÆ®´Â Áö¿ï°Ô ¾øÀ½).
		if (!head)
		{
			std::cout << "List is empty.\n";
			return;
		}

		// »èÁ¦ÇÒ ³ëµå °Ë»ö.
		NodeType current = head;
		NodeType trail = nullptr;

		while (current)
		{
			// °ª ºñ±³.
			if (current->data == data)
			{
				break;
			}

			// ´ÙÀ½ ³ëµå·Î °Ë»ö ÀÌ¾î°¡±â.
			trail = current;
			current = current->next;
		}

		// ¿¹¿ÜÃ³¸®.
		if (!current)
		{
			// °Ë»ö ½ÇÆĞÇÑ °æ¿ì.
			std::cout << "Failed to find the node.\n";
			return;
		}

		// »èÁ¦ÇÒ ³ëµå°¡ ÇìµåÀÎ °æ¿ì.
		if (head == current)
		{
			// ±âÁ¸ ÇìµåÀÇ ´ÙÀ½ ³ëµå¸¦ »õ Çìµå·Î ¼³Á¤.
			head = head->next;
		}

		// Çìµå°¡ ¾Æ´Ñ °æ¿ì.
		else
		{
			// Æ÷ÀÎÅÍ Á¤¸®.
			trail->next = current->next;
		}

		// ¸Ş¸ğ¸® ÇØÁ¦.
		delete current;

		// Á¦°Å Ã³¸®.
		--count;
	}

	// Ãâ·Â ÇÔ¼ö.
	void Print()
	{
		// Ã³À½ºÎÅÍ ¼øÈ¸ÇÏ¸é¼­ °ª Ãâ·Â.
		NodeType current = head;

		// ¼øÈ¸.
		while (current)
		{
			// ÇöÀç ³ëµåÀÇ °ª Ãâ·Â.
			std::cout << "Data: " << current->data << "\n";

			// ´ÙÀ½ ³ëµå·Î ÀÌµ¿.
			current = current->next;
		}
	}

private:
	// Çìµå(¸Ó¸®) ³ëµå.
	//Node<T>* head = nullptr;
	NodeType head = nullptr;

	// ¿¬°á ¸®½ºÆ®¿¡ ÀúÀåµÈ Ç×¸ñÀÇ ¼ö.
	int count = 0;
};