DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data)
{
    DoublyLinkedListNode* added = new DoublyLinkedListNode(data);

    DoublyLinkedListNode* previous = nullptr;
    DoublyLinkedListNode* current = llist;

    while (current != nullptr && current->data <= data)
    {
        previous = current;
        current = current->next;
    }

    added->next = current;
    added->prev = previous;

    if (previous != nullptr)
        previous->next = added;
    else
        llist = added;

    if (current != nullptr)
        current->prev = added;

    return llist;
}