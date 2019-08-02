#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int count(SinglyLinkedListNode* temp){
    int ans = 0;
    while(temp != NULL){
        temp = temp->next;
        ans++;
    }
    return ans;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int n1 = count(head1);
    int n2 = count(head2);

    if(n1 > n2){
        int t = n1 - n2;
        while(t--){
            head1 = head1->next;
        }
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        return(head1->data);
    }
    else{
        int t = n2 - n1;
           while(t--){
            head2 = head2->next;
        }
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        return(head1->data);
    }
}

int main()
