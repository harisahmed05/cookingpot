#include <stdio.h>
#include <stdlib.h>

typedef struct pizzeria Pizzeria;
typedef struct node Node;

struct pizzeria {
    int time;
    double price;
    char* customer;
    char* pizza;
};

struct node {
    Pizzeria* data;
    Node* next;
};

Node* create_pizzeria(char* customer, char* pizza, double price, int time)
{
    Pizzeria* new_pizzeria = (Pizzeria *) malloc(sizeof(Pizzeria));
    if (new_pizzeria == NULL) {
        printf("Error! Could Not Create A New Pizzeria\n");
        exit(1);
    }
    new_pizzeria->time = time;
    new_pizzeria->price = price;
    new_pizzeria->customer = customer;
    new_pizzeria->pizza = pizza;

    return new_pizzeria;
}

Node* create_node(Pizzeria* item, Node* next)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error! Could Not Create A New Node\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node* head, Pizzeria* item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}

Node *append(Node* head, Pizzeria* item)
{
    Node* new_node = create_node(item, NULL);
    if (head == NULL) {
        return new_node;
    }

    Node* current_node = head;

    while(current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

void print_pizzeria(Pizzeria* item)
{
    printf("Customer: %s\n", item->customer);
    printf("Pizza: %s\n", item->pizza);
    printf("Price: %lf\n", item->price);
    printf("Time: %d\n", item->time);
    printf("\n");
}

void print_linked_list(Node *head)
{
    Node* current_node = head;
    while (current_node != NULL) {
        print_pizzeria(current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() 
{
    Pizzeria *a, *b, *c;
    Node *n1, *head;

    a = create_pizzeria("Tony", "Pepperoni", 20.99, 40);
    b = create_pizzeria("Sophia", "Hawaiian", 18.49, 20);
    c = create_pizzeria("Joe", "Supreme", 19.99, 10);

    n1 = create_node(a, NULL);
    head = n1;
    print_linked_list(head);

    head = prepend(head, b);
    print_linked_list(head);

    head = append(head, c);
    print_linked_list(head);

    return 0;
    
}
