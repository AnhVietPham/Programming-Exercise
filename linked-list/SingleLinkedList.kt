package com.avp.basic.kotlin

class SingleLinkedList<V>(
        private var head: Node<V>? = null,
        private var tail: Node<V>? = null,
        var size: Int = 0
) {
    class Node<V>(var data: V, var next: Node<V>?)

    fun addHEAD(value: V) {
        val node = Node(value, null)
        if (this.head == null) {
            this.head = node
            this.tail = node
        } else {
            node.next = this.head
            this.head = node
        }
        size++
    }

    fun addTAIL(value: V) {
        val node = Node(value, null)
        if (this.head == null) {
            this.head = node
            this.tail = node
        } else {
            this.tail?.next = node
            this.tail = node
        }
        size++
    }

    fun printSingleLinkedList() {
        var node = this.head
        while (node != null) {
            print("${node.data}   ")
            node = node.next
        }
    }

}

fun main() {
    val singleLinkedList = SingleLinkedList<Int>()
    singleLinkedList.addTAIL(1)
    singleLinkedList.addTAIL(2)
    singleLinkedList.addTAIL(3)
    singleLinkedList.addTAIL(4)
    singleLinkedList.addTAIL(5)
    singleLinkedList.addTAIL(6)
    singleLinkedList.addHEAD(999)
    singleLinkedList.printSingleLinkedList()
    println()
    print(singleLinkedList.size)
}