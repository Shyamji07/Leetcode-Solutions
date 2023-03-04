var reverseList = function(head) {
    let curr=head,prev=null,next=null;
        while(curr){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
};