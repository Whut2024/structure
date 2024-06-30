package lru;

import java.util.HashMap;
import java.util.Map;

/**
 * LRU（Least Recently Used）缓存策略实现类
 *
 * @param <K> 缓存键的类型
 * @param <V> 缓存值的类型
 */
public class LRU<K, V> {

    /**
     * LRU链表节点类
     *
     * @param <K> 节点键的类型
     * @param <V> 节点值的类型
     */
    private static class Node<K, V> {

        /**
         * 前一个节点
         */
        public Node<K, V> pre;

        /**
         * 后一个节点
         */
        public Node<K, V> next;

        /**
         * 节点值
         */
        public V value;

        /**
         * 节点键
         */
        public K key;

        public Node(K key, V value, Node<K, V> next, Node<K, V> pre) {
            this.value = value;
            this.next = next;
            this.pre = pre;
            this.key = key;
        }

        public Node(K key, V value) {
            this.value = value;
            this.key = key;
        }

        public Node() {
        }
    }

    /**
     * LRU链表的头节点
     */
    private Node<K, V> head;

    /**
     * LRU链表的尾节点
     */
    private Node<K, V> tail;

    /**
     * 虚拟头节点，用于简化操作
     */
    private final Node<K, V> dummy = new Node<>();

    /**
     * 哈希表，用于存储键值对到LRU链表的映射
     */
    private final Map<K, Node<K, V>> hash = new HashMap<>();


    private final int CAPACITY;

    private int size;

    public LRU(int capacity) {
        if (capacity < 1) throw new IllegalArgumentException();
        this.CAPACITY = capacity;
    }

    public V get(K key) {
        if (!hash.containsKey(key)) return null;

        Node<K, V> node = hash.get(key);

        // head
        if (node == head) return node.value;

        if (node == tail) {
            Node<K, V> tailPreNode = node.pre;

            // head-----tail
            if (tailPreNode == head) {
                dummy.next = tail;
                tail.pre = dummy;

                tail.next = head;
                head.pre = tail;
                head.next = null;

                head = tail;
                tail = tailPreNode;

                return node.value;
            }

            // head-----xxx-----tail

            node.next = head;
            head.pre = node;
            node.pre = dummy;
            dummy.next = node;

            tailPreNode.next = null;

            head = node;
            tail = tailPreNode;

            return node.value;
        }

        // head---xxx----target----yyy---tail
        Node<K, V> preNode = node.pre;
        Node<K, V> nextNode = node.next;

        node.next = head;
        head.pre = node;
        node.pre = dummy;
        dummy.next = node;

        preNode.next = nextNode;
        nextNode.pre = preNode;

        head = node;

        return node.value;
    }

    public V remove(K key) {
        if (!hash.containsKey(key)) return null;

        Node<K, V> removeNode = hash.get(key);

        if (removeNode == head) {
            if (tail == head) {
                dummy.next = null;
                head = tail = null;

                size--;
                return removeNode.value;
            }

            Node<K, V> nextNode = head.next;

            // help gc
            removeNode.pre = null;
            removeNode.next = null;

            dummy.next = nextNode;
            nextNode.pre = dummy;

            head = nextNode;

            size--;
            return removeNode.value;
        }

        if (removeNode == tail) {
            Node<K, V> preNode = tail.pre;

            // help gc
            tail.pre = null;
            preNode.next = null;

            tail = preNode;

            return removeNode.value;
        }

        Node<K, V> preNode = removeNode.pre;
        Node<K, V> nextNode = removeNode.next;

        // help gc
        removeNode.pre = null;
        removeNode.next = null;

        preNode.next = nextNode;
        nextNode.pre = preNode;

        size--;
        return removeNode.value;
    }

    public void put(K key, V value) {
        if (hash.containsKey(key)) {
            // flush value and site
            remove(key);
            put(key, value);
            return;
        }


        Node<K, V> newNode = new Node<>(key, value);
        if (head == null) {
            head = newNode;

            dummy.next = head;
            head.pre = dummy;

            tail = head;

            size++;
        } else {
            if (CAPACITY == size) {
                Node<K, V> preNode = tail.pre;

                preNode.next = newNode;
                newNode.pre = preNode;

                // help gc
                tail.pre = null;
            } else {
                tail.next = newNode;
                newNode.pre = tail;

                size++;
            }
            tail = newNode;
        }

        hash.put(key, tail);
    }

    public int size() {
        return this.size;
    }
}
