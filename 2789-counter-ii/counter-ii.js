/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currCount=init;
    return {
        increment:function(){
            return ++currCount;
        },
        decrement:function(){
            return --currCount;
        },
        reset:function(){
            currCount=init;
            return currCount;
        }

    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */