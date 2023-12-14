#include <iostream>
#include <memory>

using namespace std;

struct node {
    int data;
    std::unique_ptr<node> next, prev;
};

void showList(node* head, node* tail)
{
    node* temp = head;
    int i = 1;
    while (temp)
    {
        cout << i << ".  " << temp->data << endl;
        temp = temp->prev.get();
        if (temp == head)
            temp = null;
        i++;
    }
}

void addLastList(std::unique_ptr<node>& head, node* tail, int data)
{
    auto temp = make_unique<node>();
    temp->data = data;

    if (!head)
    {
        temp->next = temp->prev = temp.get();
        head = std::move(temp);
    }
    else
    {
        temp->data = data;
        tail->prev = temp.get();  temp->next = tail;
        head->next = std::move(temp);  temp->prev = head.get();
    }
}

void searchAmountOfZero(std::unique_ptr<node>& head, node* tail, int i, int j)
{
    node* temp = head.get();
    int iterator = 1;
    int amount = 1;
    while (temp)
    {
        if (temp->data != 0) {
            temp = temp->prev.get();
            iterator++;
        }
        if (temp->data == 0) {
            cout << "(" << iterator << ", " << temp->data << ")" << endl;
            temp = temp->prev.get();
            iterator++;
            if (i < iterator && iterator < j) {
                amount++;
            }

        }
        if (temp == head.get())
            temp = null;
    }
    cout << endl;
    cout << "Amount of zero between i(" << i << ") and j(" << j << "): " << amount;
}

int main() {
    int i;
    int j;
    std::unique_ptr<node> head, tail;

    addLastList(head, tail.get(), 0);
    addLastList(head, tail.get(), 0);
    addLastList(head, tail.get(), 1);
    addLastList(head, tail.get(), 0);
    addLastList(head, tail.get(), 3);
    addLastList(head, tail.get(), 0);
    addLastList(head, tail.get(), 0);
    addLastList(head, tail.get(), 4);
    addLastList(head, tail.get(), 0);

    showList(head.get(), tail.get());
    cout << "All zero: " << endl;

    searchAmountOfZero(head, tail.get(), 1, 8);

    return 0;
}
