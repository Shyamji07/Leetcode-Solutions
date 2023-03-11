let list=[];
const gettree=(start,end)=>{
    let midd=Math.floor((start+end)/2);
    if(start>=end)return null;
    const newnode=new TreeNode(list[midd]);
    
    newnode.left=gettree(start,midd);
    newnode.right=gettree(midd+1,end);
    return newnode;
};
var sortedListToBST = function(head) {
    list=[];
    while(head){
        list.push(head.val);
        head=head.next;
    }
    // list.forEach((entry)=> console.log(entry));
    return gettree(0,list.length);
    
};