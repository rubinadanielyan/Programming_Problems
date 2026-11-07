int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    int length1 = 0;
    int length2 = 0;

    SinglyLinkedListNode* temp = head1;

    while (temp != nullptr)
    {
        length1++;
        temp = temp->next;
    }

    temp = head2;

    while (temp != nullptr)
    {
        length2++;
        temp = temp->next;
    }

    SinglyLinkedListNode* first = head1;
    SinglyLinkedListNode* second = head2;

    while (length1 > length2)
    {
        first = first->next;
        length1--;
    }

    while (length2 > length1)
    {
        second = second->next;
        length2--;
    }

    while (first != second)
    {
        first = first->next;
        second = second->next;
    }

    return first->data;
}
