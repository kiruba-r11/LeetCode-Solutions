class MyLinkedList {
private:
    
    // Linked List Node
    class node {
    public:
        int data;
        node *next;
        
        // Constructor
        node(int data) {
            this->data = data;
            next = NULL;
        }
    };
    
    node *head , *tail;
    int length;
    
public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    int get(int index) {
        
        node *temp = head;
        
        if(index >= length) return -1;
        
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        
        return temp->data;
    }
    
    void addAtHead(int val) {
        
        node *newnode = new node(val);
        
        if(head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
        
        length++;
    }
    
    void addAtTail(int val) {
        
        node *newnode = new node(val);
        
        if(tail == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        
        length++;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index > length) return;
        
        if(index == 0) {
            addAtHead(val);
            return;
        }
        
        if(index == length) {
            addAtTail(val);
            return;
        }
        
        node *cur = head , *prev = NULL;

        for(int i = 0; i < index; i++) {
            prev = cur;
            cur = cur->next;
        }

        node *newnode = new node(val);
        prev->next = newnode;
        newnode->next = cur;
        
        length++;
    }
    
    void deleteAtIndex(int index) {
        
        if(index >= length) return;
        
        node *cur = head , *prev = NULL;
        
        for(int i = 0; i < index; i++) {
            prev = cur;
            cur = cur->next;
        }
        
        if(prev) {            
            prev->next = cur->next;
            
            // If last node has to be deleted, then tail should be updated
            if(cur->next == NULL) tail = prev;
        }
        else {
            
            // If first node has to be deleted, then head should be updated
            head = cur;
            head = head->next;
        }
        
        length--;
        
        delete cur;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */