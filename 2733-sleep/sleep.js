/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    let promise=new Promise(function (resolve,reject){
        setTimeout(()=>resolve(millis),millis);
    }
    );
    return await promise;

}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */