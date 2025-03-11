/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    functions.reverse();
    return function(x) {
        return functions.reduce((acc,curr)=>curr(acc),x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */