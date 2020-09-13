public class SingleLinkedList<V> {
    static class Node<V> {
        private V data;
        private Node<V> next;

        Node(V data, Node<V> next) {
            this.data = data;
            this.next = next;
        }

        public V getData() {
            return data;
        }

        public Node<V> getNext() {
            return next;
        }

        public void setNext(Node<V> next) {
            this.next = next;
        }
    }

    private Node<V> head;
    private Node<V> tail;
    private int size;


    SingleLinkedList() {
        this.head = this.tail = null;
        this.size = 0;
    }

    void addHEAD(V value) {
        Node<V> node = new Node<>(value, null);
        if (this.head == null) {
            this.head = this.tail = node;
        } else {
            node.setNext(this.head);
            this.head = node;
        }
        size++;
    }

    void addTAIL(V value) {
        Node<V> node = new Node<>(value, null);
        if (this.head == null) {
            this.head = this.tail = node;
        } else {
            this.tail.setNext(node);
            this.tail = node;
        }
        size++;
    }

    public int getSize() {
        return size;
    }


    void printSingleLinkedList() {
        Node<V> node = this.head;
        while (node != null) {
            System.out.print(node.getData() + "   ");
            node = node.getNext();
        }
    }

    public static void main(String[] args) {
//        SingleLinkedList<Integer> singleLinkedList = new SingleLinkedList<>();
//        singleLinkedList.addTAIL(1);
//        singleLinkedList.addTAIL(2);
//        singleLinkedList.addTAIL(3);
//        singleLinkedList.addTAIL(4);
//        singleLinkedList.addTAIL(5);
//        singleLinkedList.addTAIL(6);
//        singleLinkedList.addHEAD(11);
//        singleLinkedList.addHEAD(99);
//        singleLinkedList.addTAIL(100);
//        singleLinkedList.printSingleLinkedList();
//        System.out.println();
//        System.out.print(singleLinkedList.getSize());
        SingleLinkedList<String> singleLinkedList = new SingleLinkedList<>();
        singleLinkedList.addTAIL("a");
        singleLinkedList.addTAIL("b");
        singleLinkedList.addTAIL("c");
        singleLinkedList.addTAIL("d");
        singleLinkedList.addTAIL("e");
        singleLinkedList.addHEAD("avp");
        singleLinkedList.printSingleLinkedList();
        System.out.println();
        System.out.print(singleLinkedList.getSize());
    }
}
