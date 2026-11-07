SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
    SinglyLinkedListNode* added = new SinglyLinkedListNode(data);

    if (position == 0)
    {
        added->next = llist;
        return added;
    }

    SinglyLinkedListNode* temp = llist;

    for (int step = 1; step < position; step++)
    {
        temp = temp->next;
    }

    added->next = temp->next;
    temp->next = added;

    return llist;
}