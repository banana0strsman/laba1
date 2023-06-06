#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* PNode;

PNode add(PNode s, int inf);
PNode del(PNode s);
PNode add(PNode s);
void print(PNode s);
PNode delMinNumber(PNode node);

int main()
{
    setlocale(0, "rus");
    int choice = -1;

    Node* stack;
    Node* new_stack;
    stack = NULL;
    new_stack = NULL;

    while (choice != 0)
    {
        system("cls");


        cout << "МЕНЮ" << endl << endl
            << "1|\tсоздать/добавить" << endl
            << "2|\tудалить" << endl
            << "3|\tпросмотреть" << endl
            << "4|\tдоп. задание" << endl << endl
            << "0| ВЫХОД" << endl
            << "Ваш выбор: " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1: stack = add(stack); break;
        case 2: stack = del(stack); break;
        case 3: print(stack); system("pause"); break;
        case 4: stack = del(stack); new_stack = delMinNumber(stack); print(new_stack);  system("pause"); break;
        default:
            cout << "!!!ERROR!!!"; break;
        }

    }

    return 0;
}

PNode add(PNode node, int inf) {

    PNode node_new = node;
    node = new Node;

    if (node == NULL) {
        cout << "Memory is full\n";
        system("pause");
        return 0;
    }

    node->data = inf;
    node->next = node_new;
    return node;
}

PNode del(PNode s)
{
    PNode s1;
    if (s == NULL) {
        cout << "ERROR" << endl;
        return 0;
    }

    s1 = s;
    s = s->next;
    delete(s1);
    cout << "Последний элемент стека удален" << endl;
    return (s);
}

PNode add(PNode s)
{
    PNode s1;
    s1 = s;
    s = new Node;

    if (s == NULL) {
        cout << "ERROR MEMORY" << endl;
        return 0;
    }

    cout << "Введите информацию в поле data:" << endl;
    cin >> s->data;
    s->next = s1;

    return s;
}

void print(PNode s)
{
    PNode s1;
    s1 = s;

    if (s == NULL) {
        cout << "ERROR" << endl;
        return;
    }

    do {
        cout << s1->data << endl;
        s1 = s1->next;
    } while (s1 != NULL);

    cout << "Конец стека" << endl;
}

int size(PNode node) {
    PNode node_new = node;
    int count = 0;
    if (node == NULL) {
        cout << "Stack not found/n";
        system("pause");
        return -1;
    }
    do {
        count++;
        node_new = node_new->next;
    } while (node_new != NULL);

    return count;
}


PNode delMinNumber(PNode node) {
    PNode node_new = node;
    Node* result = NULL;

    if (node == NULL) {
        cout << "Stack not found/n";
        system("pause");
        return 0;
    }

    int count = size(node);


    vector<int> arr;
    vector<int> new_arr;

    for (int i = 0; i < count; i++)
    {
        arr.push_back(node_new->data);
        node_new = node_new->next;
    }

    int min = arr[0];

    for (int i = 0; i < count; i++)
    {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != min) {
            new_arr.push_back(arr[i]);
        }

    }


    for (int i = 0; i < new_arr.size(); i++)
    {
        result = add(result, new_arr[i]);
    }
    return result;
}
