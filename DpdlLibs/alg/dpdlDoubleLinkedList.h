# File: alg/dpdlDoubleLinkedList.h
#
# Example: Dpdl code that implements a 'Double Linked List' data structure
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#

class Node {
    object prev = null
    int data
    object next = null

	func Node()
    	println("default constructor")
    end

    func Node(int value)
        prev = null
        data = value
        next = null
    end
}

class LinkedList {

	object head = null
	object tail = null

    func insertAtBeginning(int data)
        class Node temp(data)

        if (head == null)
            head = temp
            tail = temp
        else
            temp.next = head
            head.prev = temp
            head = temp
			println("head->  is of type: " + typeof(head))
        fi
    end

    func insertAtEnd(int data)
        class Node temp(data)
        if (tail == null)
            head = temp
            tail = temp
        else
            tail.next = temp
            temp.prev = tail
            tail = temp
        fi
    end

    func insertAtPosition(int data, int position)
        class Node temp(data)
        if (position == 1)
            insertAtBeginning(data)
        else
            class Node current
            current = head
            int currPosition = 1
            while(current != null && currPosition < position)
                current = current.next
				currPosition=currPosition+1
            endwhile
            if (current == null)
                insertAtEnd(data)
            else
                temp.next = current
                temp.prev = current.prev
				object curr_prev = current.prev
				curr_prev.next = temp
                current.prev = temp
            fi
        fi
    end

    func deleteAtBeginning()
        if (head == null)
            return 0
        fi

        if (head == tail)
            head = null
            tail = null
            return 0
        fi

        class Node temp
		temp = head
        head = head.next
        head.prev = null
        temp.next = null
    end

    func deleteAtEnd()
        if (tail == null)
            return 0
        fi

        if (head == tail)
            head = null
            tail = null
            return 0
        fi

		class Node temp
		temp = tail
        tail = tail.prev
        tail.next = null
        temp.prev = null
    end

    func deleteAtSpecificPosition(int pos)
        if (head == null)
            return 0
        fi

        if (pos == 1)
            deleteAtBeginning()
            return 0
        fi

        class Node current
		current = head
        int count = 1

        while (current != null && count != pos)
            current = current.next
            count=count+1
        endwhile

        if (current == null)
            println("Position wrong")
            return 0
        fi

        if (current == tail)
            deleteAtEnd()
            return 0
        fi

		object curr_prev = current.prev
		object curr_next = current.next
		curr_prev.next = current.next
		curr_next.prev = current.prev
        current.prev = null
        current.next = null
    end

    func display()
		class Node temp
    	temp = head
        while(temp != null)
            print(temp.data + " --> ")
            temp = temp.next
        endwhile
		println("")
    end

}

# now we test it

class LinkedList ll

println("insertion of 5 elements at tail: ")

ll.insertAtEnd(1)
ll.insertAtEnd(2)
ll.insertAtEnd(3)
ll.insertAtEnd(4)
ll.insertAtEnd(5)

ll.display()

println("insertion of 0 at head: ")

ll.insertAtBeginning(0)

ll.display()

println("insertion of 6 at 2nd position: ")

ll.insertAtPosition(6, 2)

ll.display()

println("deletion at the beginning: ")

ll.deleteAtBeginning()

ll.display()

println("deletion at the end: ")

ll.deleteAtEnd()

ll.display()

println( "deletion at 2nd position: ")

ll.deleteAtSpecificPosition(2)

ll.display()

println("finished")
