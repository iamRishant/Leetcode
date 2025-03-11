/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    return arr.reduce((acc,curr)=>{
        if(Array.isArray(curr) && n>0) acc.push(...flat(curr,n-1));
        else acc.push(curr);
        return acc;
    },[])
};