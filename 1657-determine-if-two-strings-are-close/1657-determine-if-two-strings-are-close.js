var closeStrings = function(s1, s2) {
    let map1 = new Array(26);
    let map2 = new Array(26);
    if (s1.length != s2.length)return false;
    for(let i=0;i<26;i++){
        map1[i]=0;
        map2[i]=0;
    }
    for(let i=0;i<s1.length;i++){
        map1[s1.charCodeAt(i)-97]=map1[s1.charCodeAt(i)-97]+1;
        map2[s2.charCodeAt(i)-97]=map2[s2.charCodeAt(i)-97]+1;
    }
    for (let i = 0; i < 26; i++){
        if ((map1[i] != 0 && map2[i] == 0) || (map1[i] == 0 && map2[i] != 0)){
            console.log(i)
            return false;
        }
    }
    map1.sort();
    map2.sort();
    for (let i = 0; i < 26; i++){
        if (map1[i] !=  map2[i]){
            return false;
        }
    }
    return true;
};