import Queue

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def minimum_path_sum(root):
    if not root:
        return -1
    q = Queue.queue()
    q.put(root, 0)
    
    level, answer, min_value = -1, -1, float('int')
    while q:
        size = q.size()
        level += 1

        while size:
            size -= 1
            node, curr_value = q.pop()
      
            node.val += curr_value
            if node.val < min_value:
                min_value = node.val
                answer = level

            if not node.left:
                q.put(node.left, node.val)
                
            if not node.right:
                q.put(node.right, node.val)
                

    return answer
