/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let arr2=[];

    for(let i=0;i<arr.length;i+=size){
        arr2.push(arr.slice(i,i+size));
    }
    return arr2;
};
