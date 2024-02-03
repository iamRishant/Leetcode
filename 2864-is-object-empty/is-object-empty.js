/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    let count=0;
    for(let key in obj){
        count++;
    }
    return !count;
};