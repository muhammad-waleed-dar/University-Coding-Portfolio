void remove(int value)
{
    if (head == nullptr)
        return;

    Node* current = head;
    Node* prev = nullptr;

    do
    {
        if (current->info == value)
        {
            // Only one node
            if (current->next == current)
            {
                delete current;
                head = nullptr;
                return;
            }

            // If removing head
            if (current == head)
            {
                Node* last = head;
                while (last->next != head)
                    last = last->next;

                head = head->next;
                last->next = head;
            }
            else
            {
                prev->next = current->next;
            }

            delete current;
            return;
        }

        prev = current;
        current = current->next;

    } while (current != head);
}