
import java.util.*;

class Node {
    Node prev, next;
    String name;
    
    Node(String customerName) {
        this.prev = null;
        this.next = null;
        this.name = customerName;
    }
}

class DoublyLinkedList {
    
    Node head=null, tail=null;

    void insertRear(Node node) {
        if(head!=null && tail!=null) {
            tail.next = node;
            node.prev = tail;
            tail = node;
        } else {
            head = tail = node;
        }
        
    }
    
    void removeFront() {
        head = head.next;
        if(head!=null) {
        head.prev = null;}
    }
    
    void remove(Node nd) {
        Node prev = nd.prev;
        Node nxt = nd.next;
        if(nxt==null && prev==null) {
            head = tail = null;
        }
        else if(nd.next==null) {
            tail = tail.prev;
            tail.next = null;
        } else if(nd.prev==null) {
            head = head.next;
            head.prev = null;
        } else {
            
            prev.next = nxt;
            nxt.prev = prev;
        }
    }
    
}

class RestaurantWaitList {
    // {Bob: (5, Addr1), Tim: (4, Addr2), Jim: (4, Addr3)}
    Map<String, Map<Integer, Node>> customerMp;
    // {5: [Bob], 4: [Tim, Jim]}
    HashMap<Integer, DoublyLinkedList> tableGroupMp;
    
    RestaurantWaitList() {
        customerMp = new HashMap<>();
        tableGroupMp = new HashMap<>();
    }
    
    void addGroup(String name, int tableSize) {
        Node newNode = new Node(name);
        if(!tableGroupMp.containsKey(tableSize)) {
            DoublyLinkedList dbLinkedList = new DoublyLinkedList();
            tableGroupMp.put(tableSize, dbLinkedList);
            dbLinkedList.insertRear(newNode);
        } 
        else {
            tableGroupMp.get(tableSize).insertRear(newNode);
        }
        Map<Integer, Node> mp = new HashMap<>();
        mp.put(tableSize, newNode);
        customerMp.put(name, mp);
    }
    
    void allotTable(int tableSize) {
        Node frontNode = tableGroupMp.get(tableSize).head;
        if(frontNode!=null) {
            System.out.println(frontNode.name + " is alloted the table");
            customerMp.remove(frontNode.name);
            tableGroupMp.get(tableSize).removeFront();
        }
    }
    
    void remove(String customer) {
        Node nd = null;
        // int size ;
        for(Integer key: customerMp.get(customer).keySet()) {
            // size = key;
            nd = customerMp.get(customer).get(key);
            tableGroupMp.get(key).remove(nd);
            
        }
        customerMp.remove(customer);
    }
    
    void printValues() {
        for (String key: customerMp.keySet()) {
            for(Integer size: customerMp.get(key).keySet()) {
                System.out.println(key + ":" + size );   
            }
        }
        
        for(Integer key: tableGroupMp.keySet()) {
            System.out.print(key + ": ");
            Node hd = tableGroupMp.get(key).head; 
            while(hd!=null) {
                System.out.print(hd.name+ ", ");
                hd=hd.next;
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        
        RestaurantWaitList waitList = new RestaurantWaitList();

        waitList.addGroup("Bob", 5);
        waitList.addGroup("Tim", 4);
        waitList.addGroup("Jim", 4);
        waitList.addGroup("Jack", 4);
        waitList.printValues();
        // waitList.allotTable(4);
        // waitList.printValues();
        // waitList.allotTable(4);
        // waitList.printValues();
        System.out.println("Removing customer");
        waitList.remove("Bob");
        // waitList.remove("Jack");
        waitList.remove("Jim");
        waitList.remove("Tim");
        waitList.printValues();
        
    }
}
