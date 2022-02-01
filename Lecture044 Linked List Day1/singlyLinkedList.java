class Node{
  int data;
  Node next;
  
  Node(int data){
    this.data = data;
    this.next = null;
  }
}

public void print(Node head){
  Node curr = head;
  
  while(curr.next!=null){
    System.out.print(curr.data+" ");
    curr = curr.next;
  }
  
  System.out.print(curr.data+" ");
  System.out.println();
}

public Node insertAtHead(Node ptr,int data){
  Node newNode = new Node(data);
  
  newNode.next = ptr;
  
  ptr = newNode;
  
  return ptr;
}

public Node insertAtTail(Node ptr,int data){
  Node newNode = new Node(data);
  
  newNode.next = null;
  
  ptr.next = newNode;
  
  ptr = newNode;
  
  return ptr
}

public void insertAtPosition(Node tail,Node head,int pos,int value){
  Node curr = head,prev = null;
  
  if(pos==1){
    insertAtHead(head,value);
    return;
  }
  
  int i = 1;
  
  while(i<pos){
    prev = curr;
    curr = curr.next;
    i++;
  }
  
  Node newNode = new Node(value);
  
  newNode.next = prev.next;
  
  prev.next = newNode;
}

public void deleteNode(int pos,Node head){
  Node curr = head,prev = null;
  
  if(curr.next == null){
    head = null;
    return;
  }
  int i = 1;
  
  while(i<pos){
    prev = curr;
    curr = curr.next;
    i++;
  }
  
  prev.next = curr.next;
}

public static void main(String[] args) {
    
    //created a new node
    Node node1 = new Node(10);
 
    
    //head pointed to node1
    Node head = node1; 
    Node tail = node1;
    print(head);

    tail = insertAtTail(tail, 12);

    print(head);

    head = insertAtHead(head, 12);
    print(head);
  
    insertAtPosition(tail,head, 4, 22);
    print(head);    

    deleteNode(4, head);
    print(head);

}