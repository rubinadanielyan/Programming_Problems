bool has_cycle(Node* head)
{
    Node* first = head;
    Node* second = head;

    while (second != nullptr && second->next != nullptr)
    {
        first = first->next;
        second = second->next->next;

        if (first == second)
            return true;
    }

    return false;
}