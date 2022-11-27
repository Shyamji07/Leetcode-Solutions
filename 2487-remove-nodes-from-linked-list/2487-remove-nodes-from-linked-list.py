var removeNodes = function(head) {
     if(head == null || head.next == null)return head;
        var nextNode = removeNodes(head.next);
        if(nextNode.val > head.val) return nextNode;
        head.next = nextNode;
        return head;
};