  - Simple implementation of lockless data structures
This repo will mostly have assignement level code for implementing the lockless data structure. As a future goal I can try to
benchmark with corresponding lock based algorithms.
 - Data structures implemented till now:
      - Linked list
        The addition in linked list in a lockfree way is quite trivial. 
        pseudo code:
        ```
          insert(nodeToInsertAfter, newNode):
              do: #1
               next = nodeToInsertAfter->next
               newNode->next = next
               if (CAS(nodeToInsertAfter->next, next, newNode)) return;
               goto 1
            
        ```
       For deletion I am relying on the fact that on most architectures the memory will be aligned around byte boundaries.
       This means that the lower order bit for all addresses must be 0. I am using this fact to mark a node as "to be deleted"
       pseudo code:
        ```
          delete(nodeToDeleteAfter):
              do: #1
               nodeToDelete = nodeToDeleteAfter->next
               next = nodeToDelete->next
               if (CAS(nodeToDelete->next, next, SetBit(next, 0))):
                  next = UnsetBit(nodeToDelete->next, 0)
                  if (CAS(nodeToDeleteAfter, nodeToDelete, next)):
                    return
                  else:
                    nodeToDelete->next = UnsetBit(nodeToDelete->next, 0)
               goto 1
            
        ```
