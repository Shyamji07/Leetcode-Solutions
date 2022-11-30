var convert=( s)=>{
        let time=((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'))
        return time>720?time:time+1440;
    }
var findMinDifference = function(arr) {
    var list=[]
    for(let i=0;i<arr.length;i++){
        list.push(convert(arr[i]));
    }
    list.sort(function(a, b) {
    return a - b;
    });;
    let mini=list[1]-list[0];
    for(let i=2;i<list.length;i++){
        mini=Math.min(mini,list[i]-list[i-1]);
    }
    mini = Math.min(mini, 1440 + list[0] - list.at(-1));
    return mini;
};