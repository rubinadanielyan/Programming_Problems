DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist)
{
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* newHead = nullptr;

    while (current != nullptr)
    {
        DoublyLinkedListNode* nextNode = current->next;

        current->next = current->prev;
        current->prev = nextNode;

        newHead = current;
        current = nextNode;
    }

    return newHead;
}